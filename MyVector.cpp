#include <iostream>
#include <chrono> // Для измерения времени
class MyVector {
private:
    int* data;   // Указатель на массив
    int size;    // Размер массива

public:
    // Обычный конструктор
    MyVector(int size) : size(size) {
        data = new int[size];
        std::cout << "Создан вектор размером " << size << std::endl;
    }

    // Деструктор (освобождает память)
    ~MyVector() {
        delete[] data;
        std::cout << "Вектор удален" << std::endl;
    }

    // Конструктор копирования (копирует данные)
    MyVector(const MyVector& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "Скопирован вектор" << std::endl;
    }

    // Move-конструктор (перемещает данные)
    MyVector(MyVector&& other) {
        data = other.data;   // Берем данные у другого объекта
        size = other.size;
        other.data = nullptr; // Обнуляем чужой указатель
        std::cout << "Перемещен вектор" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "");
    // Создаем большой вектор
    MyVector vec1(1000000);
    

    // Измеряем время копирования
    auto start = std::chrono::high_resolution_clock::now();
    MyVector vec2 = vec1; // Копирование
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Копирование заняло: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " мкс" << std::endl;

    // Измеряем время перемещения
    start = std::chrono::high_resolution_clock::now();
    MyVector vec3 = std::move(vec1); // Перемещение
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Перемещение заняло: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
        << " мкс" << std::endl;

    return 0;
}