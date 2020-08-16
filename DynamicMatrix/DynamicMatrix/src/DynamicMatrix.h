#pragma once
#include <iostream>

using namespace std;

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

	friend std::istream& operator>>(std::istream& in, Matrix& matrix);
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


Matrix::Matrix(int rows, int columns) {
	SetRows(rows);
	SetColumns(columns);

	m_matrix = new int*[rows];
	for (int i = 0; i < rows; ++i)
		m_matrix[i] = new int[columns];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			m_matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix& matrix) {
	SetRows(matrix.m_rows);
	SetColumns(matrix.m_columns);

	m_matrix = new int*[matrix.m_rows];
	for (int i = 0; i < matrix.m_rows; ++i)
		m_matrix[i] = new int[matrix.m_columns];

	for (int i = 0; i < matrix.m_rows; ++i)
		for (int j = 0; j < matrix.m_columns; ++j)
			m_matrix[i][j] = matrix.m_matrix[i][j];
}

Matrix::Matrix(Matrix&& matrix) {
	SetRows(matrix.m_rows);
	SetColumns(matrix.m_columns);
	m_matrix = matrix.m_matrix;
	matrix.m_matrix = nullptr;
}

Matrix& Matrix::operator=(const Matrix& matrix) {

	if (matrix.m_rows != m_rows || matrix.m_columns != m_columns)
		throw "To assign matrices, their sizes have to be equal";

	for (int i = 0; i < matrix.m_rows; ++i)
		for (int j = 0; j < matrix.m_columns; ++j)
			m_matrix[i][j] = matrix.m_matrix[i][j];
	return *this;
}

Matrix& Matrix::operator=(Matrix&& matrix) {
	if (matrix.m_rows != m_rows || matrix.m_columns != m_columns)
		throw "To assign matrices, their sizes have to be equal";

	m_matrix = matrix.m_matrix;
	matrix.m_matrix = nullptr;
	return *this;
}

void Matrix::SetRows(int rows) {
	if (rows <= 0)
		throw "Any matrix has to have at least one row";
	m_rows = rows;
}
void Matrix::SetColumns(int columns) {
	if (columns <= 0)
		throw "Any matrix has to have at least one column";
	m_columns = columns;
}
int Matrix::GetRows() const {
	return m_rows;
}
int Matrix::GetColumns() const {
	return m_columns;
}

int& Matrix::operator()(int row, int column) {

	if ((row < 0 || row > m_rows) && (column < 0 || column > m_columns))
		throw "Not exist, please write a valid row number and a valid column number";
	if (row < 0 || row > m_rows)
		throw "This row does not exist, please write a valid row number";
	if (column < 0 || column > m_columns)
		throw "This column does not exist, please write a valid column number";

	return m_matrix[row][column];
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
	for (int i = 0; i < matrix.m_rows; ++i)
		for (int j = 0; j < matrix.m_columns; ++j)
			in >> matrix.m_matrix[i][j];

	std::cout << std::endl;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
	for (int i = 0; i < matrix.m_rows; ++i) {
		for (int j = 0; j < matrix.m_columns; ++j)
			out << matrix.m_matrix[i][j] << ' ';
		out << endl;
	}
	return out;
}

Matrix& operator+(const Matrix& mat1, const Matrix& mat2) {

	if (mat1.m_rows != mat2.m_rows || mat1.m_columns != mat2.m_columns)
		throw "To add matrices, their sizes have to be equal";

	Matrix *resMat = new Matrix(mat1.m_rows, mat1.m_columns);

	for (int i = 0; i < mat1.m_rows; ++i)
		for (int j = 0; j < mat1.m_columns; ++j)
			resMat->m_matrix[i][j] = mat1.m_matrix[i][j] + mat2.m_matrix[i][j];
	return *resMat;
}

Matrix& operator-(const Matrix& mat1, const Matrix& mat2) {

	if (mat1.m_rows != mat2.m_rows || mat1.m_columns != mat2.m_columns)
		throw "To subtract matrices, their sizes have to be equal";

	Matrix *resMat = new Matrix(mat1.m_rows, mat1.m_columns);

	for (int i = 0; i < mat1.m_rows; ++i)
		for (int j = 0; j < mat1.m_columns; ++j)
			resMat->m_matrix[i][j] = mat1.m_matrix[i][j] - mat2.m_matrix[i][j];
	return *resMat;
}

Matrix& operator*(const Matrix & mat1, const Matrix& mat2) {
	if (mat1.m_columns != mat2.m_rows)
		throw "To multiply matrices, the first matrix's number of columns has to be equal to the second matrix's number of rows";

	Matrix *resMat = new Matrix(mat1.m_rows, mat2.m_columns);

	for (int i = 0; i < resMat->m_rows; ++i)
		for (int j = 0; j < resMat->m_columns; ++j)
			for (int k = 0; k < mat1.m_columns; ++k)
				resMat->m_matrix[i][j] += mat1.m_matrix[i][k] * mat2.m_matrix[k][j];
	return *resMat;
}

Matrix& operator*(int constant, const Matrix& mat) {

	Matrix *resMat = new Matrix(mat.m_rows, mat.m_columns);

	for (int i = 0; i < mat.m_rows; ++i)
		for (int j = 0; j < mat.m_columns; ++j)
			resMat->m_matrix[i][j] = constant * mat.m_matrix[i][j];
	return *resMat;
}

Matrix& operator*(const Matrix& mat, int constant) {

	Matrix *resMat = new Matrix(mat.m_rows, mat.m_columns);

	for (int i = 0; i < mat.m_rows; ++i)
		for (int j = 0; j < mat.m_columns; ++j)
			resMat->m_matrix[i][j] = constant * mat.m_matrix[i][j];
	return *resMat;
}

bool operator==(const Matrix& mat1, const Matrix& mat2) {

	if (mat1.m_rows != mat2.m_rows || mat1.m_columns != mat2.m_columns)
		return false;

	for (int i = 0; i < mat1.m_rows; ++i) {
		for (int j = 0; j < mat1.m_columns; ++j) {
			if (mat1.m_matrix[i][j] != mat2.m_matrix[i][j])
				return false;
		}
	}
	return true;
}

Matrix& Matrix::Transpose() const {

	Matrix *transposedMat = new Matrix(m_columns, m_rows);

	for (int i = 0; i < transposedMat->m_rows; ++i)
		for (int j = 0; j < transposedMat->m_columns; ++j)
			transposedMat->m_matrix[i][j] = m_matrix[j][i];
	return *transposedMat;
}

long long Matrix::Trace() const {
	if (!IsSquare())
		throw "A matrix has to be square matrix to compute its trace";
	long long sum = 0;
	for (int i = 0; i < m_rows; ++i)
		sum += m_matrix[i][i];
	return sum;
}

bool Matrix::IsSquare() const {
	return m_rows == m_columns;
}

bool Matrix::IsDiagonal() const {
	bool diagonalNonZero = false;
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_columns; ++j) {
			if (i != j && m_matrix[i][j])
				return false;
			if (i == j && m_matrix[i][j])
				diagonalNonZero = true;
		}
	}
	if (diagonalNonZero)
		return true;
	return false;
}

bool Matrix::IsIdentity() const {
	bool diagonalNonZero = false;
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_columns; ++j) {
			if (i != j && m_matrix[i][j])
				return false;
			if (i == j && m_matrix[i][j] != 1)
				return false;
		}
	}
	return true;
}

bool Matrix::IsZero() const {
	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_columns; ++j) {
			if (m_matrix[i][j])
				return false;
		}
	}
	return true;
}

Matrix::~Matrix() {
	//cout << "destruct\n";
	if (m_matrix) {
		for (int i = 0; i < m_rows; ++i)
			delete[] m_matrix[i];
		delete[] m_matrix;
	}
}