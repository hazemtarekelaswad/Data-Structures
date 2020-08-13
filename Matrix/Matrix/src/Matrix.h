#pragma once
#include <iostream>


class Matrix {
private:
	int m_rows;
	int m_columns;
	int **m_matrix;

	void SetRows(int rows);
	void SetColumns(int columns);

public:

	Matrix(int rows, int columns);
	Matrix(const Matrix& matrix);
	Matrix(Matrix&& matrix);
	Matrix& operator=(const Matrix& matrix);
	Matrix& operator=(Matrix&& matrix);

	int GetRows() const;
	int GetColumns() const;

	int& operator()(int row, int column);

	friend std::istream& operator>>(std::istream& in,  Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

	friend Matrix& operator+(const Matrix& mat1, const Matrix& mat2);
	friend Matrix& operator-(const Matrix& mat1, const Matrix& mat2);
	friend Matrix& operator*(const Matrix& mat1, const Matrix& mat2);
	friend Matrix& operator*(int constant, const Matrix& mat);
	friend Matrix& operator*(const Matrix& mat, int constant);
	friend bool operator==(const Matrix& mat1, const Matrix& mat2);

	Matrix& Transpose() const;
	long long Trace() const;

	bool IsSquare() const;
	bool IsDiagonal() const;
	bool IsIdentity() const;
	bool IsZero() const;

	~Matrix();
};

