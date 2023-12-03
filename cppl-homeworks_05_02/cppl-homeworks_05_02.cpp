#include <iostream>
#include <exception>


template<class T>
class Matrix {
    int row;//количество строк
    int col;//количество столбцов
    T** table;
public:
    //конструктор
    Matrix(int row, int col) : row{ row }, col{ col } {
        this->table = new T * [row];
        if (table == nullptr) {
            throw std::runtime_error("Недостаточно памяти!");
        }
        for (int i = 0; i < row; i++) {
            table[i] = new T[col];
            if (table[i] == nullptr) {
                throw std::runtime_error("Недостаточно памяти!");
            }
        }
    }
    //деструктор
    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] table[i];
        }
        delete[] table;
    }
    //возвращает размер таблицы
    const int Size() {
        return row * col;
    }
    //перегрузка оператора индекса
    const T* operator[](int index) const {
        if (index < 0 || index >= row || index >= col) {
            throw std::range_error("Неверный индекс!");
        }
        return table[index];
    }

    T* operator[](int index) {
        if (index < 0 || index >= col || index >= row) {
            throw std::range_error("Неверный индекс!");
        }
        return table[index];
    }
};

int main() {
    try {
        Matrix<int> table(2, 3);
        //std::cout << table.Size() << std::endl;
        table[0][0] = 4;
        std::cout << table[0][0]; // выводит 4
    }
    catch (std::runtime_error& ex) {
        std::cout << ex.what();
    }
    catch (std::range_error& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}