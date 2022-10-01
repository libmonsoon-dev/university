#include <cstdio>

#include "../include/sparse_matrix.h"

SparseMatrix::SparseMatrix(int rows, int columns) {
    if (rows < 1 || columns < 1) {
        throw "Размерность стороны должна быть 1 и более";
    }

    this->rows = rows;
    this->columns = columns;

    this->points = new Slice;
}

SparseMatrix::SparseMatrix() {
    this->rows = 1;
    this->columns = 1;
    this->points = new Slice;
}

SparseMatrix::SparseMatrix(SparseMatrix &other) {
    this->rows = other.rows;
    this->columns = other.columns;
    this->points = other.points;
}

SparseMatrix::SparseMatrix(SparseMatrix &&other) {
    this->rows = other.rows;
    this->columns = other.columns;
    this->points = other.points;
}

void SparseMatrix::set(Point p) {
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

SparseMatrix scan_sparse_matrix() {
    int rows, columns;
    printf("Введите размерность матрицы (через пробел)\n> ");
    if (scanf("%i %i", &rows, &columns) != 2) {
        throw "Невалидный ввод\n";
    }

    auto result = SparseMatrix(rows, columns);

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


void SparseMatrix::Print() {
    for (int j = 0; j < this->rows; j++) {
        for (int i = 0; i < this->columns; i++) {
            printf("%i%s", this->At(i, j), "\t");
        }
        printf("\n");
    }
    printf("\n");
}

int SparseMatrix::At(int x, int y) {
    int i = IndexOf(x, y);
    if (i != -1) {
        return this->points->Array()[i].value;
    }
    return 0;
}


int SparseMatrix::IndexOf(int x, int y) {
    for (int i = 0; i < this->points->Length(); i++) {
        auto point = this->points->Array()[i];
        if (point.x == x && point.y == y) {
            return i;
        }
    }

    return -1;
}

SparseMatrix SparseMatrix::Transpose() {
    auto next = SparseMatrix(this->columns, this->rows);

    for (int i = 0; i < this->points->Length(); i++) {
        auto p = this->points->Array()[i];
        next.points->Append(p.transpose());
    }

    return next;
}

SparseMatrix SparseMatrix::Multiply(int multiplier) {
    auto result = SparseMatrix(this->rows, this->columns);

    for (int i = 0; i < this->points->Length(); i++) {
        result.set(points->Array()[i].multiply(multiplier));
    }

    return result;
}

SparseMatrix SparseMatrix::Multiply(SparseMatrix other) {
    if (this->columns != other.rows) {
        throw "Доступно только умножение матрицы MxL на LxN";
    }

    auto result = SparseMatrix(this->rows, other.columns);

    for (int x = 0; x < result.rows; x++) {
        for (int y = 0; y < result.columns; y++) {
            int value = 0;

            for (int i = 0; i < this->columns; i++) {
                auto a = this->At(i, y);
                if (a == 0) {
                    continue;
                }

                value += a * other.At(x, i);
            }

            auto p = Point(x, y, value);
            result.set(p);
        }
    }

    return result;
}

SparseMatrix SparseMatrix::Add(SparseMatrix other) {
    if (this->rows != other.rows || this->columns != other.columns) {
        throw "Достуно сложение только матриц одинакового размера";
    }

    auto result = SparseMatrix(this->rows, this->columns);

    for (int x = 0; x < result.columns; x++) {
        for (int y = 0; y < result.rows; y++) {
            int value = this->At(x, y) + other.At(x, y);
            auto p = Point(x, y, value);
            result.set(p);
        }
    }

    return result;
}

bool SparseMatrix::Equal(SparseMatrix other) {
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
