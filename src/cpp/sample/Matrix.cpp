#include "Matrix.h"
#include <cstring>

Matrix::Matrix(const Matrix &m) {
    this->row_count = m.row_count;
    this->col_count = m.col_count;

    this->values = new matrix_cell *[row_count];
    for (size_t i = 0; i < this->col_count; ++i) {
        this->values[i] = new matrix_cell[this->row_count];
        std::memcpy(this->values[i], m.values[i], col_count * sizeof(matrix_cell));
    }
}

Matrix::Matrix(size_t row_count, size_t col_count):
        row_count(row_count), col_count(col_count)  {
    this->values = new matrix_cell *[this->row_count];
    for (size_t i = 0; i < this->row_count; ++i) {
        this->values[i] = new matrix_cell[this->col_count];
    }

    for (size_t row = 0; row < this->row_count; ++row) {
        for (size_t col = 0; col < this->col_count; ++col) {
            this->values[row][col] = 0;
        }
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < this->row_count; ++i) {
        delete[] this->values[i];
    }
}

matrix_cell Matrix::get(size_t row, size_t col) const {
    return this->values[row][col];
}

std::ostream &operator << (std::ostream &out, const Matrix &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            out << matrix.values[row][col] << ' ';
        }
        out << '\n';
    }
    return out;
}

std::istream &operator >> (std::istream &in, Matrix &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            in >> matrix.values[row][col];
        }
    }

    return in;
}

void Matrix::set() {
    for (size_t row = 0; row < this->row_count; ++row) {
        for (size_t col = 0; col < this->col_count; ++col) {
            std::cin >> this->values[row][col];
        }
    }
}

Matrix &Matrix::operator + (const Matrix &matrix) const {
    Matrix *temp_matrix = new Matrix(this->row_count, this->col_count);

    for (size_t row = 0; row < this->row_count; ++row) {
        for (size_t col = 0; col < this->col_count; ++col) {
            temp_matrix->values[row][col] = this->values[row][col] + matrix.values[row][col];
        }
    }

    return *temp_matrix;
}

Matrix &operator + (matrix_cell number, const Matrix &matrix) {
    Matrix *temp_matrix = new Matrix(matrix.row_count, matrix.col_count);

    for (size_t row = 0; row < matrix.row_count; ++row) {
        for (size_t col = 0; col < matrix.col_count; ++col) {
            temp_matrix->values[row][col] = matrix.values[row][col] + number;
        }
    }

    return *temp_matrix;
}

Matrix &operator + (const Matrix &matrix, matrix_cell number) {
    return (number + matrix);
}

Matrix &operator * (matrix_cell number, const Matrix &matrix) {
    Matrix *temp_matrix = new Matrix(matrix.row_count, matrix.col_count);

    for (size_t row = 0; row < matrix.row_count; ++row) {
        for (size_t col = 0; col < matrix.col_count; ++col) {
            temp_matrix->values[row][col] = matrix.values[row][col] * number;
        }
    }

    return *temp_matrix;
}

Matrix &operator * (const Matrix &matrix, matrix_cell number) {
    return (number * matrix);
}

Matrix &Matrix::operator * (const Matrix &matrix) const {
    if (this->col_count == matrix.row_count) {
        Matrix *temp_matrix = new Matrix(this->row_count, matrix.col_count);

        for (size_t row = 0; row < this->row_count; ++row) {
            for (size_t col = 0; col < matrix.col_count; ++col) {
                for (size_t i = 0; i < this->col_count; ++i) {
                    temp_matrix->values[row][col] += this->values[row][i] * matrix.values[i][col];
                }
            }
        }

        return *temp_matrix;
    }
    else {
        Matrix *temp_matrix = new Matrix(0, 0);
        return *temp_matrix;
    }
}