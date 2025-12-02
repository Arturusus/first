Пример кода на языке программированиея Java:

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if not node:
            return Node(key)
        if key < node.key:
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        return node

    def find_path(self, key):
        path = []
        if self._find_path(self.root, key, path):
            return path
        return None

    def _find_path(self, node, key, path):
        if not node:
            return False
        path.append(node.key)
        if node.key == key:
            return True
        if self._find_path(node.left, key, path) or self._find_path(node.right, key, path):
            return True
        path.pop()
        return False

# Пример
bst = BST()
for k in [10, 5, 15, 3, 7, 12, 18]:
    bst.insert(k)
print("Путь до 7:", bst.find_path(7))

Результат работы кода:
Путь до 7: [10, 5, 7]
