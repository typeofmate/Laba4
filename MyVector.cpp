#include <iostream>
#include <chrono> // ��� ��������� �������
class MyVector {
private:
    int* data;   // ��������� �� ������
    int size;    // ������ �������

public:
    // ������� �����������
    MyVector(int size) : size(size) {
        data = new int[size];
        std::cout << "������ ������ �������� " << size << std::endl;
    }

    // ���������� (����������� ������)
    ~MyVector() {
        delete[] data;
        std::cout << "������ ������" << std::endl;
    }

    // ����������� ����������� (�������� ������)
    MyVector(const MyVector& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "���������� ������" << std::endl;
    }

    // Move-����������� (���������� ������)
    MyVector(MyVector&& other) {
        data = other.data;   // ����� ������ � ������� �������
        size = other.size;
        other.data = nullptr; // �������� ����� ���������
        std::cout << "��������� ������" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "");
    // ������� ������� ������
    MyVector vec1(1000000);
    

    // �������� ����� �����������
    auto start = std::chrono::high_resolution_clock::now();
    MyVector vec2 = vec1; // �����������
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "����������� ������: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " ���" << std::endl;

    // �������� ����� �����������
    start = std::chrono::high_resolution_clock::now();
    MyVector vec3 = std::move(vec1); // �����������
    end = std::chrono::high_resolution_clock::now();
    std::cout << "����������� ������: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " ���" << std::endl;

    return 0;
}