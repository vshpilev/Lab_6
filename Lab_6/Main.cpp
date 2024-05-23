#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Чтение целочисленного одномерного вектора из файла
std::vector<int> readVectorFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return {};
    }

    std::vector<int> vec;
    int value;
    while (file >> value) {
        vec.push_back(value);
    }

    file.close();
    return vec;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // 1. Чтение из файла
    std::vector<int> vec = readVectorFromFile("input.txt");
    if (vec.empty()) {
        return 1; // Произошла ошибка при чтении файла
    }

    // 2. Реверсирование
    std::reverse(vec.begin(), vec.end());

    // 3. Поиск минимального элемента
    int minElement = *std::min_element(vec.begin(), vec.end());

    // 4. Удаление четных элементов
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    // 5. Сортировка
    std::sort(vec.begin(), vec.end()); // По возрастанию
    // std::sort(vec.begin(), vec.end(), std::greater<int>()); // По убыванию

    // 6. Вставка элемента
    int elementToInsert = 100;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), elementToInsert), elementToInsert); // Вставка, не нарушающая сортировку

    // 7. Определение индекса элемента
    int searchElement = 42;
    auto it = std::find(vec.begin(), vec.end(), searchElement);
    int index = (it != vec.end()) ? std::distance(vec.begin(), it) : -1;

    // 8. Удаление дубликатов
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // Вывод результата
    std::cout << "Результат:" << std::endl;
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
