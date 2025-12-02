Пример кода на языке программирования C++:
#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;
    Node* insertRec(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) node->left = insertRec(node->left, key);
        else if (key > node->key) node->right = insertRec(node->right, key);
        return node;
    }
    bool findPathRec(Node* node, int key, std::vector<int>& path) {
        if (!node) return false;
        path.push_back(node->key);
        if (node->key == key) return true;
        if (findPathRec(node->left, key, path) || findPathRec(node->right, key, path)) return true;
        path.pop_back();
        return false;
    }
public:
    BST() : root(nullptr) {}
    void insert(int key) { root = insertRec(root, key); }
    std::vector<int> findPath(int key) {
        std::vector<int> path;
        if (findPathRec(root, key, path)) return path;
        return {};
    }
};

int main() {
    BST bst;
    int keys[] = {10, 5, 15, 3, 7, 12, 18};
    for (int k : keys) bst.insert(k);
    auto path = bst.findPath(7);
    std::cout << "Put' do 7: ";
    for (int p : path) std::cout << p << " ";
    std::cout << std::endl;
    return 0;
}

Результат работы кода:
Put' do 7: 10 5 7
