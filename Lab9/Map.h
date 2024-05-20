#pragma once
template<typename K, typename V>
class Map {
	struct element {
		K key;
		V value;
	};
	element* container;
	int count, capacity;
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
	Map()
	{
		element* container = new element[10];
		count = 0;
	}
	~Map()
	{
		delete[] container;
	}
	V& operator[](K key)
	{
		for (int i = 0;i < count;i++)
			if (key == container[i].key)
				return container[i].value;
		if (count == capacity) {
    	    resize();
        }
		count++;
		container[count - 1].key = key;
		return container[count - 1].value;
	}
	void Set(const K& key, const V& value) {
		(*this)[key] = value;
	}
	bool Get(const K& key, V& value) const{
		for(int i=0;i<count;i++)
			if (container[i].key == key)
			{
				value = container[i].value;
				return true;
			}
		return false;
	}
	int Count() {
		return count;
	}
	void Clear() {
		count = 0;
	}
	bool Delete(const K& key) 
	{
		for (int i = 0;i < count;i++)
			if (container[i].key == key)
			{
				for (int j = i;j < count - 1;j++)
					container[j] = container[j + 1];
				count--;
				return true;
			}
		return false;
	}
	bool Includes(const Map<K, V>& map) 
	{
		for (int i = 0;i < map.count;i++)
		{
			int ok = 0;
			for (int j = 0;j < count;j++)
				if (container[j].key == map.container[i].key && container[j].value == map.container[i].value)
					ok = 1;
			if (ok == 0)
				return false;
		}
		return false;
	}
	class Iterator {
		element* c;
		int index, size;
	public:
		Iterator(element* container, int i, int s) : c(container), index(i), size(s) {}
		Iterator& operator++()
		{
			index++;
			return *this;
		}
		bool operator!=(Iterator& i)
		{
			return index != i.index;
		}
		struct elem {
			K& key;
			V& value;
			int index;
			elem(K& k, V& v, int i) : key(k), value(v), index(i) {}
		};
		elem operator*() {
			return { c[index].key, c[index].value, index };
		}
	};
	Iterator begin() {
		return Iterator(container, 0, count);
	}
	Iterator end() {
		return Iterator(container, count, count);
	}
};