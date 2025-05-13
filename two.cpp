#include <iostream>
using namespace std;

class Vector {
private:
    short* data;     // вказівник на масив short
    int size;        // кількість елементів
    int state;       // стан (0 - все добре, 1 - помилка пам’яті)

public:
    // Конструктор без параметрів
    Vector() {
        size = 1;
        data = new(nothrow) short[size];
        if (data == nullptr) {
            state = 1;  // помилка виділення пам'яті
        }
        else {
            data[0] = 0;
            state = 0;
        }
    }

    // Конструктор з одним параметром (розмір)
    Vector(int n) {
        size = n;
        data = new(nothrow) short[size];
        if (data == nullptr) {
            state = 1;
        }
        else {
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
            state = 0;
        }
    }

    // Конструктор з розміром і значенням
    Vector(int n, short value) {
        size = n;
        data = new(nothrow) short[size];
        if (data == nullptr) {
            state = 1;
        }
        else {
            for (int i = 0; i < size; i++) {
                data[i] = value;
            }
            state = 0;
        }
    }

    // Функція для виводу
    void print() {
        if (state != 0) {
            cout << "Error: memory problem." << endl;
            return;
        }
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }
};

// Тестування
int main() {
    Vector v1;              // без параметрів
    Vector v2(5);           // з розміром
    Vector v3(4, 7);        // з розміром і значенням

    cout << "v1 = "; v1.print();
    cout << "v2 = "; v2.print();
    cout << "v3 = "; v3.print();

    return 0;
}
