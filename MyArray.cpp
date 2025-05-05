#include <iostream>

// ��� ������������ ������� 
template <typename T, int N>
class MyArray {
private:
    T data[N]; // ������ �������������� �������

public:
    //������� �� �������
    T& get(int index) {
        return data[index];
    }

    // ������� �� ��� � ��
    void print() {
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "");
    MyArray<int, 5> arr; // ������ �� 5 ����� �����
    arr.get(0) = 10;
    arr.get(1) = 20;
    arr.print(); // 10 20 0 0 0 

    MyArray<std::string, 3> words; // ������ �� 3 �����
    words.get(0) = "C++";
    words.get(1) = "Python";
    words.print(); // C++ Python  

    return 0;
}