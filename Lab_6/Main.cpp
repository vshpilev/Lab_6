#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// ������ �������������� ����������� ������� �� �����
std::vector<int> readVectorFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ����" << std::endl;
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
    // 1. ������ �� �����
    std::vector<int> vec = readVectorFromFile("input.txt");
    if (vec.empty()) {
        return 1; // ��������� ������ ��� ������ �����
    }

    // 2. ��������������
    std::reverse(vec.begin(), vec.end());

    // 3. ����� ������������ ��������
    int minElement = *std::min_element(vec.begin(), vec.end());

    // 4. �������� ������ ���������
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    // 5. ����������
    std::sort(vec.begin(), vec.end()); // �� �����������
    // std::sort(vec.begin(), vec.end(), std::greater<int>()); // �� ��������

    // 6. ������� ��������
    int elementToInsert = 100;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), elementToInsert), elementToInsert); // �������, �� ���������� ����������

    // 7. ����������� ������� ��������
    int searchElement = 42;
    auto it = std::find(vec.begin(), vec.end(), searchElement);
    int index = (it != vec.end()) ? std::distance(vec.begin(), it) : -1;

    // 8. �������� ����������
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // ����� ����������
    std::cout << "���������:" << std::endl;
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
