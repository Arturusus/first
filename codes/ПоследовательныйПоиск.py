Рабочий код на языке программирования Python:

def sequential_search(arr, target):
    """Осуществляет последовательный поиск элемента в списке."""
    # Перебираем все элементы массива поочередно
    for idx, value in enumerate(arr):
        # Если текущий элемент совпадает с искомым значением
        if value == target:
            return idx  # Возвращаем индекс найденного элемента
    return None  # Если элемент не найден, возвращаем None

# Пример использования
if __name__ == "__main__":
    # Заданный список для поиска
    data = [15, 32, 47, 8, 21, 56, 9, 12]
    
    # Значение, которое хотим найти
    search_value = 21
    
    # Вызываем функцию поиска
    result = sequential_search(data, search_value)
    
    # Выводим результат
    if result is not None:
        print(f'Значение {search_value} найдено на позиции {result}')
    else:
        print(f'Значение {search_value} не найдено')def sequential_search(arr, target):
    """Осуществляет последовательный поиск элемента в списке."""
    # Перебираем все элементы массива поочередно
    for idx, value in enumerate(arr):
        # Если текущий элемент совпадает с искомым значением
        if value == target:
            return idx  # Возвращаем индекс найденного элемента
    return None  # Если элемент не найден, возвращаем None

# Пример использования
if __name__ == "__main__":
    # Заданный список для поиска
    data = [15, 32, 47, 8, 21, 56, 9, 12]
    
    # Значение, которое хотим найти
    search_value = 21
    
    # Вызываем функцию поиска
    result = sequential_search(data, search_value)
    
    # Выводим результат
    if result is not None:
        print(f'Значение {search_value} найдено на позиции {result}')
    else:
        print(f'Значение {search_value} не найдено')


Результат работы кода:
Значение 21 найдено на позиции 4
(искалось значение 21 в массиве [15, 32, 47, 8, 21, 56, 9, 12])
