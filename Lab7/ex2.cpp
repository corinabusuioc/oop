#include <iostream>

bool compare(const int& a, const int& b) {
    return a < b;
}

template<typename T>
class TreeNode {
    T value;
    TreeNode* parent;
    TreeNode** children;
    int child_count;
public:
    TreeNode(const T& value) : value(value), parent(nullptr), children(nullptr), child_count(0) {}

    void add_node(TreeNode* child) {
        if (children == nullptr) {
            children = new TreeNode * [1];
            children[0] = child;
            child_count = 1;
        }
        else {
            TreeNode** new_children = new TreeNode * [child_count + 1];
            for (int i = 0; i < child_count; ++i) {
                new_children[i] = children[i];
            }
            new_children[child_count] = child;
            delete[] children;
            children = new_children;
            ++child_count;
        }
        child->parent = this;
    }

    TreeNode& get_node(TreeNode* parent) {
        if (parent == nullptr)
            return *this;
        for (int i = 0; i < child_count; ++i) {
            if (children[i] == parent)
                return *children[i];
            auto& found = children[i]->get_node(parent);
            if (&found != nullptr)
                return found;
        }
        std::cout<<"Node not found in tree.";
    }

    void delete_node(TreeNode* node) {
        for (int i = 0; i < child_count; ++i) {
            if (children[i] == node) {
                delete children[i];
                for (int j = i; j < child_count - 1; ++j) {
                    children[j] = children[j + 1];
                }
                --child_count;
                children[child_count] = nullptr; 
                return; 
            }
        }
        std::cout<<"Node is not a child of this node.";
    }

    TreeNode<T>* find(const T& value) {
        if (this->value == value)
            return this;
        for (size_t i = 0; i < child_count; ++i) {
            auto found = children[i]->find(value);
            if (found != nullptr)
                return found;
        }
        return nullptr;
    }

    void insert(TreeNode* node, int index) {
        if (index > child_count)
            std::cout<<"Index out of range.";
        TreeNode** new_children = new TreeNode * [child_count + 1];
        for (int i = 0; i < index; ++i) {
            new_children[i] = children[i];
        }
        new_children[index] = node;
        for (int i = index; i < child_count; ++i) {
            new_children[i + 1] = children[i];
        }
        delete[] children;
        children = new_children;
        ++child_count;
    }

    void sort(bool (*compare)(const T&, const T&)) {
        for (int i = 0; i < child_count - 1; ++i) {
            for (int j = 0; j < child_count - i - 1; ++j) {
                if (compare(children[j]->value, children[j + 1]->value)) {
                    TreeNode* temp = children[j];
                    children[j] = children[j + 1];
                    children[j + 1] = temp;
                }
            }
        }
    }

    int count() const {
        int cnt = child_count;
        for (int i = 0; i < child_count; ++i) {
            cnt += children[i]->count();
        }
        return cnt;
    }

    ~TreeNode() {
        for (int i = 0; i < child_count; ++i) {
            delete children[i];
        }
        delete[] children;
    }
};

int main() 
{
    TreeNode<int> root(1);
    TreeNode<int> child1(2);
    TreeNode<int> child2(3);
    TreeNode<int> child3(4);

    root.add_node(&child1);
    root.add_node(&child2);
    root.add_node(&child3);
    root.delete_node(&child3);
    root.insert(&child3, 1);
    TreeNode<int>& node = root.get_node(nullptr); 
    root.sort(compare);
    TreeNode<int>* foundNode = root.find(2);
    std::cout << "Total children of root: " << root.count() << std::endl;
    return 0;
}
