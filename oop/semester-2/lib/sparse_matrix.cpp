#include <cstdio>

#include "../include/sparse_matrix.h"

template<typename T>
SparseMatrix<T>::SparseMatrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;

    this->points = new Slice<Point<T>>;
}

template<typename T>
SparseMatrix<T>::SparseMatrix() {
    this->rows = 1;
    this->columns = 1;
    this->points = new Slice<Point<T>>;
}

template<typename T>
SparseMatrix<T>::SparseMatrix(SparseMatrix &other) {
    this->rows = other.rows;
    this->columns = other.columns;
    this->points = other.points;
}

template<typename T>
SparseMatrix<T>::SparseMatrix(SparseMatrix &&other) {
    this->rows = other.rows;
    this->columns = other.columns;
    this->points = other.points;
}

template<typename T>
void SparseMatrix<T>::set(Point<T> p) {
    if (p.x >= this->columns || p.y >= this->rows || p.x < 0 || p.y < 0) {
        throw "Недопустимые координаты";
    }

    int i = this->IndexOf(p.x, p.y);
    if (i != -1 && p.value > 0) {
        this->points->Array()[i].value = p.value;
    } else if (i != -1 && p.value == 0) {
        this->points->Remove(i);
    } else if (p.value > 0) {
        this->points->Append(p);
    }
}

SparseMatrix<int> scan_sparse_matrix() {
    int rows, columns;
    printf("Введите размерность матрицы (через пробел)\n> ");
    if (scanf("%i %i", &rows, &columns) != 2) {
        throw "Невалидный ввод\n";
    }

    auto result = SparseMatrix<int>(rows, columns);

    int points;
    printf("Введите количество ненулевых элементов матрицы\n> ");
    if (scanf("%i", &points) != 1) {
        throw "Невалидный ввод\n";
    }

    for (int i = 0; i < points; i++) {
        result.set(scan_point());
    }

    return result;
}


template<typename T>
void SparseMatrix<T>::Print() {
    for (int j = 0; j < this->rows; j++) {
        for (int i = 0; i < this->columns; i++) {
            printf("%i%s", this->At(i, j), "\t");
        }
        printf("\n");
    }
    printf("\n");
}

template<typename T>
T SparseMatrix<T>::At(int x, int y) {
    int i = IndexOf(x, y);
    if (i != -1) {
        return this->points->Array()[i].value;
    }
    return 0;
}


template<typename T>
int SparseMatrix<T>::IndexOf(int x, int y) {
    for (int i = 0; i < this->points->Length(); i++) {
        auto point = this->points->Array()[i];
        if (point.x == x && point.y == y) {
            return i;
        }
    }

    return -1;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Transpose() {
    auto next = SparseMatrix<T>(this->columns, this->rows);

    for (int i = 0; i < this->points->Length(); i++) {
        auto p = this->points->Array()[i];
        next.points->Append(p.transpose());
    }

    return next;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Multiply(int multiplier) {
    auto result = SparseMatrix(this->rows, this->columns);

    for (int i = 0; i < this->points->Length(); i++) {
        result.set(points->Array()[i].multiply(multiplier));
    }

    return result;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix<T> other) {
    if (this->columns != other.rows) {
        throw "Доступно только умножение матрицы MxL на LxN";
    }

    auto result = SparseMatrix<T>(this->rows, other.columns);

    for (int x = 0; x < result.rows; x++) {
        for (int y = 0; y < result.columns; y++) {
            T value = 0;

            for (int i = 0; i < this->columns; i++) {
                auto a = this->At(i, y);
                if (a == 0) {
                    continue;
                }

                value += a * other.At(x, i);
            }

            auto p = Point<T>(x, y, value);
            result.set(p);
        }
    }

    return result;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T> other) {
    if (this->rows != other.rows || this->columns != other.columns) {
        throw "Достуно сложение только матриц одинакового размера";
    }

    auto result = SparseMatrix<T>(this->rows, this->columns);

    for (int x = 0; x < result.columns; x++) {
        for (int y = 0; y < result.rows; y++) {
            T value = this->At(x, y) + other.At(x, y);
            auto p = Point<T>(x, y, value);
            result.set(p);
        }
    }

    return result;
}

template<typename T>
bool SparseMatrix<T>::Equal(SparseMatrix<T> other) {
    if (this->rows != other.rows || this->columns != other.columns) {
        return false;
    }

    if (this->points->Length() != other.points->Length()) {
        return false;
    }

    for (int i = 0; i < this->points->Length(); i++) {
        auto p = this->points->Array()[i];
        if (other.At(p.x, p.y) != p.value) {
            return false;
        }
    }

    return true;
}
