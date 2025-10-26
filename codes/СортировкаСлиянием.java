Рабочий код на языке программирования Java:

import java.util.Arrays;

public class MergeSortExample {

    public static void mergeSort(int[] array) {
        // Рекурсивная функция сортировки слиянием
        divideAndConquer(array, 0, array.length - 1);
    }

    private static void divideAndConquer(int[] array, int left, int right) {
        // Базовый случай: если левая граница больше или равна правой, ничего делать не нужно
        if (left >= right) {
            return;
        }

        // Нахождение средней точки для разделения массива пополам
        int mid = left + (right - left) / 2;

        // РЕКУРСИЯ: разделение массива на две половины и сортировка каждой половинки
        divideAndConquer(array, left, mid);          // Левая половина
        divideAndConquer(array, mid + 1, right);    // Правая половина

        // ОБЪЕДИНЕНИЕ: объединение отсортированных половинок обратно в единый отсортированный массив
        mergeHalves(array, left, mid, right);
    }

    private static void mergeHalves(int[] array, int leftStart, int mid, int rightEnd) {
        // Создание временного массива для объединения отсортированных половинок
        int tempSize = rightEnd - leftStart + 1;
        int[] tempArr = new int[tempSize];

        // Индексы для левой и правой половинок
        int leftIndex = leftStart;
        int rightIndex = mid + 1;
        int index = 0; // Индекс для временного массива

        // Объединение половинок: выбираем наименьший элемент из обеих половинок и добавляем в tempArr
        while (leftIndex <= mid && rightIndex <= rightEnd) {
            if (array[leftIndex] <= array[rightIndex]) {
                tempArr[index++] = array[leftIndex++];
            } else {
                tempArr[index++] = array[rightIndex++];
            }
        }

        // Копируем оставшиеся элементы из левой половины (если остались)
        while (leftIndex <= mid) {
            tempArr[index++] = array[leftIndex++];
        }

        // Копируем оставшиеся элементы из правой половины (если остались)
        while (rightIndex <= rightEnd) {
            tempArr[index++] = array[rightIndex++];
        }

        // Возвращаем объединённые элементы обратно в исходный массив
        System.arraycopy(tempArr, 0, array, leftStart, tempSize);
    }

    public static void main(String[] args) {
        // Исходный массив
        int[] numbers = {38, 27, 43, 3, 9, 82, 10};

        // Выводим исходный массив
        System.out.println("Исходный массив:");
        System.out.println(Arrays.toString(numbers));

        // Вызываем функцию сортировки слиянием
        mergeSort(numbers);

        // Выводим отсортированный массив
        System.out.println("\nОтсортированный массив:");
        System.out.println(Arrays.toString(numbers));
    }
}

Результат работы программы:
IshodnMass:
[38, 27, 43, 3, 9, 82, 10]
SortedMass:
[3, 9, 10, 27, 38, 43, 82]
