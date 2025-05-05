#include <iostream>
#include <string>

//меняет местами два значения
template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "");
    int x = 5, y = 10;
    mySwap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl; // x=10, y=5

    std::string s1 = "Привет", s2 = "Мир";
    mySwap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl; // s1=Мир, s2=Привет

    return 0;
}