#include <iostream>
#include <cstdlib>

typedef int matrix_cell;

class Matrix {
private:
    size_t row_count;
    size_t col_count;
    matrix_cell **values;

public:
    Matrix(const Matrix &);
    Matrix(size_t, size_t);
    ~Matrix();
    matrix_cell get(size_t, size_t) const;
    friend std::ostream & operator << (std::ostream &, const Matrix &);
    friend std::istream & operator >> (std::istream &, Matrix &);
    Matrix &operator + (const Matrix &) const;
    Matrix &operator * (const Matrix &) const;
    matrix_cell* operator [] (int i) {
        return values[i];
    }
    friend Matrix &operator + (matrix_cell number, const Matrix &matrix);
    friend Matrix &operator + (const Matrix &matrix, matrix_cell number);
    friend Matrix &operator * (matrix_cell number, const Matrix &matrix);
    friend Matrix &operator * (const Matrix &matrix, matrix_cell number);
    void set();
};