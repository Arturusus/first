Пример кода на языке программирования Java:
class Node {
    int key;
    Node left, right;
    Node(int key) { this.key = key; }
}

class BST {
    Node root;

    void insert(int key) {
        root = insertRec(root, key);
    }

    Node insertRec(Node node, int key) {
        if (node == null) return new Node(key);
        if (key < node.key) node.left = insertRec(node.left, key);
        else if (key > node.key) node.right = insertRec(node.right, key);
        return node;
    }

    java.util.List<Integer> findPath(int key) {
        java.util.ArrayList<Integer> path = new java.util.ArrayList<>();
        if (findPathRec(root, key, path)) return path;
        return null;
    }

    boolean findPathRec(Node node, int key, java.util.List<Integer> path) {
        if (node == null) return false;
        path.add(node.key);
        if (node.key == key) return true;
        if (findPathRec(node.left, key, path) || findPathRec(node.right, key, path)) return true;
        path.remove(path.size() - 1);
        return false;
    }

    public static void main(String[] args) {
        BST bst = new BST();
        int[] keys = {10, 5, 15, 3, 7, 12, 18};
        for (int k : keys) bst.insert(k);
        System.out.println("Путь до 7: " + bst.findPath(7));
    }
}

Результат работы программы:
Путь до 7: [10, 5, 7]
