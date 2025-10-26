Рабочий код на языке программирования C++:

#include <iostream>
using namespace std;

// Функция для преобразования поддерева в кучу (heapify)
void heapify(int arr[], int n, int root) {
    int largest = root;  // Предположительно корень - максимальный элемент
    int leftChild = 2 * root + 1;  // Индекс левого ребенка
    int rightChild = 2 * root + 2; // Индекс правого ребенка

    // Если левый ребенок существует и больше корня
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Если правый ребенок существует и больше самого крупного кандидата
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // Если крупнейший элемент изменился, меняем его с корнем и рекурсивно восстанавливаем структуру
    if (largest != root) {
        swap(arr[root], arr[largest]);  // Меняем местами корень и крупнейший элемент
        heapify(arr, n, largest);      // Рекурсивно вызываем heapify для поддерева
    }
}

// Основная функция для сортировки методом Heap Sort
void heapSort(int arr[], int n) {
    // Строим max-кучу (преобразование массива в кучу)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлекаем элементы из кучи по одному и помещаем их в конец массива
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Меняем первый (корневой) элемент с последним
        heapify(arr, i, 0);    // Восстанавливаем кучность, исключая последний элемент
    }
}

// Вспомогательная функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Основная функция программы
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};  // Наш тестовый массив
    int n = sizeof(arr) / sizeof(arr[0]); // Вычисляем размер массива

    cout << "Исходный массив: ";
    printArray(arr, n);  // Выводим исходный массив

    heapSort(arr, n);    // Вызываем функцию сортировки

    cout << "Отсортированный массив: ";
    printArray(arr, n);  // Выводим отсортированный массив

    return 0;
}#include <iostream>
using namespace std;

// Функция для преобразования поддерева в кучу (heapify)
void heapify(int arr[], int n, int root) {
    int largest = root;  // Предположительно корень - максимальный элемент
    int leftChild = 2 * root + 1;  // Индекс левого ребенка
    int rightChild = 2 * root + 2; // Индекс правого ребенка

    // Если левый ребенок существует и больше корня
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Если правый ребенок существует и больше самого крупного кандидата
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // Если крупнейший элемент изменился, меняем его с корнем и рекурсивно восстанавливаем структуру
    if (largest != root) {
        swap(arr[root], arr[largest]);  // Меняем местами корень и крупнейший элемент
        heapify(arr, n, largest);      // Рекурсивно вызываем heapify для поддерева
    }
}

// Основная функция для сортировки методом Heap Sort
void heapSort(int arr[], int n) {
    // Строим max-кучу (преобразование массива в кучу)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлекаем элементы из кучи по одному и помещаем их в конец массива
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Меняем первый (корневой) элемент с последним
        heapify(arr, i, 0);    // Восстанавливаем кучность, исключая последний элемент
    }
}

// Вспомогательная функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Основная функция программы
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};  // Наш тестовый массив
    int n = sizeof(arr) / sizeof(arr[0]); // Вычисляем размер массива

    cout << "Исходный массив: ";
    printArray(arr, n);  // Выводим исходный массив

    heapSort(arr, n);    // Вызываем функцию сортировки

    cout << "Отсортированный массив: ";
    printArray(arr, n);  // Выводим отсортированный массив

    return 0;
}

Результат работы программы:
IshodnMass: 12 11 13 5 6 7
SortedMass: 5 6 7 11 12 13
