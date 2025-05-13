#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    double height;
    double width;
    string color;

public:
    // Конструктор за замовчуванням
    Rectangle() {
        height = 1;
        width = 1;
        color = "white";
    }

    // Конструктор з параметрами
    Rectangle(double h, double w, string c) {
        setHeight(h);
        setWidth(w);
        setColor(c);
    }

    // Функція встановлення висоти
    void setHeight(double h) {
        if (h > 0)
            height = h;
        else
            height = 1; // значення за замовчуванням, якщо передано некоректне
    }

    // Функція встановлення ширини
    void setWidth(double w) {
        if (w > 0)
            width = w;
        else
            width = 1;
    }

    // Функція встановлення кольору
    void setColor(string c) {
        color = c;
    }

    // Функція отримання висоти
    double getHeight() { return height; }

    // Функція отримання ширини
    double getWidth() { return width; }

    // Функція отримання кольору
    string getColor() { return color; }

    // Функція обчислення площі
    double getArea() {
        return height * width;
    }

    // Функція обчислення периметра
    double getPerimeter() {
        return 2 * (height + width);
    }

    // Функція виводу інформації про прямокутник
    void print() {
        cout << "Rectangle:" << endl;
        cout << "Height: " << height << ", Width: " << width << ", Color: " << color << endl;
        cout << "Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

// Основна функція для тестування класу
int main() {
    Rectangle rect1; // Створення прямокутника за замовчуванням
    rect1.print();

    cout << endl;

    Rectangle rect2(5, 10, "blue"); // Створення прямокутника з параметрами
    rect2.print();

    cout << endl;

    // Тестування зміни полів
    rect2.setHeight(-3);  // некоректне значення - має бути замінене на 1
    rect2.setWidth(7);
    rect2.setColor("green");
    rect2.print();

    return 0;
}
