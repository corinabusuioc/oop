#pragma once
template<typename K, typename V>
class Map {
    struct element {
        K key;
        V value;
    };

    element* container;
    int count;
    int capacity;

    void resize() {
        capacity *= 2;
        element* new_container = new element[capacity];
        for (int i = 0; i < count; ++i) {
            new_container[i] = container[i];
        }
        delete[] container;
        container = new_container;
    }

public:
    Map() : count(0), capacity(10) {
        container = new element[capacity];
    }

    ~Map() {
        delete[] container;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < count; ++i) {
            if (container[i].key == key) {
                return container[i].value;
            }
        }
        if (count == capacity) {
            resize();
        }
        container[count].key = key;
        return container[count++].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < count; ++i) {
            if (container[i].key == key) {
                value = container[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < count; ++i) {
            if (container[i].key == key) {
                for (int j = i; j < count - 1; ++j) {
                    container[j] = container[j + 1];
                }
                --count;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const {
        for (int i = 0; i < map.count; ++i) {
            bool found = false;
            for (int j = 0; j < count; ++j) {
                if (container[j].key == map.container[i].key && container[j].value == map.container[i].value) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    class Iterator {
        element* c;
        int index;
    public:
        struct Item {
            K& key;
            V& value;
            int index;
        };

        Iterator(element* container, int idx) : c(container), index(idx) {}

        Iterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& i) const {
            return index != i.index;
        }

        Item operator*() const {
            return { c[index].key, c[index].value, index };
        }
    };

    Iterator begin() {
        return Iterator(container, 0);
    }

    Iterator end() {
        return Iterator(container, count);
    }
};
