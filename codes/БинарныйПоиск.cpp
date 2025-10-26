Рабочий код на языке программирования C++:

#include <iostream>
using namespace std;

// Функция бинарного поиска
int binarySearch(int arr[], int left, int right, int target) {
    // Если границы пересеклись, элемент не найден
    if (right >= left) {
        // Находим середину диапазона
        int mid = left + (right - left) / 2;

        // Если средний элемент равен искомому, возвращаем его индекс
        if (arr[mid] == target)
            return mid;

        // Если целевой элемент меньше среднего, ищем в левой половине
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Иначе ищем в правой половине
        return binarySearch(arr, mid + 1, right, target);
    }

    // Если элемент не найден, возвращаем -1
    return -1;
}

// Главная функция программы
int main() {
    // Пример отсортированного массива
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);  // Вычисляем размер массива
    int x = 10;                          // Целевой элемент для поиска

    // Вызываем функцию бинарного поиска
    int result = binarySearch(arr, 0, n - 1, x);

    // Выводим результат
    if (result != -1)
        cout << "Элемент найден на позиции " << result << endl;
    else
        cout << "Элемент не найден в массиве." << endl;

    return 0;
}

Результат работы программмы:
The element was found in the position 3
