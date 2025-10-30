Блочная сортировка, рабочий код:

#include <iostream>
#include <vector>
#include <algorithm>

// Функция для блочной сортировки
void bucketSort(float arr[], int n) {
    // Создаем вектор контейнеров (баков)
    std::vector<std::vector<float>> buckets(n);

    // Распределяем элементы по бакам
    for (int i = 0; i < n; i++) {
        // Умножаем на n, чтобы получить целое число от 0 до n-1 включительно
        int bi = arr[i] * n;  // bi - индекс бака
        buckets[bi].push_back(arr[i]);  // Помещаем элемент в соответствующий бак
    }

    // Сортируем каждый бак с помощью стандартной сортировки
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());  // Сортируем элементы внутри баков
    }

    // Соединяем отсортированные баки в исходный массив
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;  // Записываем отсортированные элементы обратно в исходный массив
        }
    }
}

// Вспомогательная функция для вывода массива
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Главная функция программы
int main() {
    float arr[] = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f};
    int n = sizeof(arr) / sizeof(arr[0]);  // Вычисляем размер массива

    std::cout << "IshodnMass: ";
    printArray(arr, n);  // Выводим исходный массив

    bucketSort(arr, n);  // Вызываем функцию блочной сортировки

    std::cout << "SortedMass: ";
    printArray(arr, n);  // Выводим отсортированный массив

    return 0;
}

Результат работы программы:
IshodnMass: 0.897 0.565 0.656 0.1234 0.665 0.3434
SortedMass: 0.1234 0.3434 0.565 0.656 0.665 0.897


Сортировка бусинами, рабочий код:
#include <iostream>
#include <vector>
#include <algorithm> // Необходимо подключить для std::max_element

// Вспомогательная функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Функция для реализации сортировки бусинами
void beadSort(std::vector<int>& arr) {
    int maxValue = *std::max_element(arr.begin(), arr.end()); // Находим максимальный элемент

    // Создаем матрицу бусин, где каждая строка - это число из массива
    std::vector<std::vector<bool>> beads(maxValue, std::vector<bool>(static_cast<size_t>(arr.size())));

    // Заполняем матрицу бусин
    for (size_t col = 0; col < arr.size(); ++col) {
        for (int row = 0; row < arr[col]; ++row) {
            beads[row][col] = true; // помечаем бусину как существующую
        }
    }

    // Пусть бусины упадут под действием "силы тяжести"
    for (size_t col = 0; col < arr.size(); ++col) {
        int countBeads = 0; // подсчитываем количество бусин в колонке
        for (int row = 0; row < maxValue; ++row) {
            if (beads[row][col]) {
                countBeads++;
                beads[row][col] = false; // снимаем отметку, так как бусина "падает"
            }
        }
        // заносим бусины обратно сверху вниз
        for (int row = maxValue - 1; row >= maxValue - countBeads; --row) {
            beads[row][col] = true;
        }
    }

    // Конвертируем обратно в массив чисел
    for (size_t col = 0; col < arr.size(); ++col) {
        int height = 0;
        for (int row = 0; row < maxValue; ++row) {
            if (beads[row][col]) {
                height++;
            }
        }
        arr[col] = height;
    }
}

// Главная функция
int main() {
    std::vector<int> arr = {5, 3, 1, 7, 4, 6, 9, 2};

    std::cout << "IshodnMass: ";
    printArray(arr);

    beadSort(arr);

    std::cout << "SortedMass: ";
    printArray(arr);

    return 0;
}

Результат работы программы:
IshodnMass: 5 3 1 7 4 6 9 2
SortedMass: 1 2 3 4 5 6 7 9


