#pragma once
#include <iostream>

template<typename T, int rows, int columns>

class Matrix {
private:
	T m_matrix[rows][columns];

public:
	Matrix() {}

	Matrix(const Matrix& matrix) {
		if (this->GetRows() != matrix.GetRows() || this->GetColumns() != matrix.GetColumns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->GetRows(); ++i)
			for (int j = 0; j < this->GetColumns(); ++j)
				m_matrix[i][j] = matrix.m_matrix[i][j];
	}

	Matrix(Matrix&& matrix) {
		if (this->GetRows() != matrix.GetRows() || this->GetColumns() != matrix.GetColumns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->GetRows(); ++i)
			for (int j = 0; j < this->GetColumns(); ++j)
				m_matrix[i][j] = std::move(matrix.m_matrix[i][j]);
	}

	Matrix& operator=(const Matrix& matrix) {
		if (this->GetRows() != matrix.GetRows() || this->GetColumns() != matrix.GetColumns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->GetRows(); ++i)
			for (int j = 0; j < this->GetColumns(); ++j)
				m_matrix[i][j] = matrix.m_matrix[i][j];
		return *this;
	}

	Matrix& operator=(Matrix&& matrix) {
		if (this->GetRows() != matrix.GetRows() || this->GetColumns() != matrix.GetColumns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->GetRows(); ++i)
			for (int j = 0; j < this->GetColumns(); ++j)
				m_matrix[i][j] = std::move(matrix.m_matrix[i][j]);
		return *this;
	}

	constexpr int GetRows() const {
		return rows;
	}

	constexpr int GetColumns() const {
		return columns;
	}

	T& operator()(int r, int col) {
		if ((r < 0 || r > rows) && (col < 0 || col > columns))
			throw "Not exist, please write a valid row number and a valid column number";
		if (r < 0 || r > rows)
			throw "This row does not exist, please write a valid row number";
		if (col < 0 || col > columns)
			throw "This column does not exist, please write a valid column number";

		return m_matrix[r][col];
	}

	friend std::istream& operator>>(std::istream& in, Matrix& matrix) {
		for (int i = 0; i < matrix.GetRows(); ++i)
			for (int j = 0; j < matrix.GetColumns(); ++j)
				in >> matrix.m_matrix[i][j];

		std::cout << std::endl;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
		for (int i = 0; i < matrix.GetRows(); ++i) {
			for (int j = 0; j < matrix.GetColumns(); ++j)
				out << matrix.m_matrix[i][j] << ' ';
			out << std::endl;
		}
		return out;
	}

	friend Matrix<T, rows, columns> operator+(const Matrix<T, rows, columns>& mat1, const Matrix<T, rows, columns>& mat2) {

		Matrix<T, rows, columns> resMat;

		for (int i = 0; i < mat1.GetRows(); ++i)
			for (int j = 0; j < mat1.GetColumns(); ++j)
				resMat.m_matrix[i][j] = mat1.m_matrix[i][j] + mat2.m_matrix[i][j];
		return resMat;
	}

	friend Matrix<T, rows, columns> operator-(const Matrix<T, rows, columns>& mat1, const Matrix<T, rows, columns>& mat2) {

		Matrix<T, rows, columns> resMat;

		for (int i = 0; i < mat1.GetRows(); ++i)
			for (int j = 0; j < mat1.GetColumns(); ++j)
				resMat.m_matrix[i][j] = mat1.m_matrix[i][j] - mat2.m_matrix[i][j];
		return resMat;
	}

	template<typename t, int r, int c, int p>
	friend Matrix<t, r, p> operator*(const Matrix<t, r, c>& mat1, const Matrix<t, c, p>& mat2);

	friend Matrix<T, rows, columns> operator*(int constant, const Matrix& mat) {
		Matrix<T, rows, columns> resMat;

		for (int i = 0; i < mat.GetRows(); ++i)
			for (int j = 0; j < mat.GetColumns(); ++j)
				resMat.m_matrix[i][j] = constant * mat.m_matrix[i][j];
		return resMat;
	}

	friend Matrix operator*(const Matrix& mat, int constant) {
		Matrix<T, rows, columns> resMat;

		for (int i = 0; i < mat.GetRows(); ++i)
			for (int j = 0; j < mat.GetColumns(); ++j)
				resMat.m_matrix[i][j] = constant * mat.m_matrix[i][j];
		return resMat;
	}

	friend bool operator==(const Matrix& mat1, const Matrix& mat2) {
		if (mat1.GetRows() != mat2.GetRows() || mat1.GetColumns() != mat2.GetColumns())
			return false;

		for (int i = 0; i < mat1.GetRows(); ++i) {
			for (int j = 0; j < mat1.GetColumns(); ++j) {
				if (mat1.m_matrix[i][j] != mat2.m_matrix[i][j])
					return false;
			}
		}
		return true;
	}

	Matrix<T, columns, rows> Transpose() const{
		Matrix<T, columns, rows> transposedMat;
		for (int i = 0; i < transposedMat.GetRows(); ++i)
			for (int j = 0; j < transposedMat.GetColumns(); ++j)
				transposedMat(i, j) = m_matrix[j][i];
		return transposedMat;
	}

	long long Trace() const {
		if (!IsSquare())
			throw "A matrix has to be square matrix to compute its trace";

		long long sum = 0;
		for (int i = 0; i < GetRows(); ++i)
			sum += m_matrix[i][i];
		return sum;
	}

	bool IsSquare() const {
		return GetRows() == GetColumns();
	}

	bool IsDiagonal() const {
		bool diagonalNonZero = false;
		for (int i = 0; i < GetRows(); ++i) {
			for (int j = 0; j < GetColumns(); ++j) {
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

	bool IsIdentity() const {
		bool diagonalNonZero = false;
		for (int i = 0; i < GetRows(); ++i) {
			for (int j = 0; j < GetColumns(); ++j) {
				if (i != j && m_matrix[i][j])
					return false;
				if (i == j && m_matrix[i][j] != 1)
					return false;
			}
		}
		return true;
	}

	bool IsZero() const {
		for (int i = 0; i < GetRows(); ++i) {
			for (int j = 0; j < GetColumns(); ++j) {
				if (m_matrix[i][j])
					return false;
			}
		}
		return true;
	}

	void Fill(const T& element) {
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < columns; ++j)
				m_matrix[i][j] = element;
	}

	~Matrix() {}
};

template<typename t, int r, int c, int p>
Matrix<t, r, p> operator*(const Matrix<t, r, c>& mat1, const Matrix<t, c, p>& mat2) {

	Matrix<t, r, p> resMat;
	resMat.Fill(0);

	for (int i = 0; i < resMat.GetRows(); ++i)
		for (int j = 0; j < resMat.GetColumns(); ++j)
			for (int k = 0; k < mat1.GetColumns(); ++k)
				resMat(i, j) += mat1.m_matrix[i][k] * mat2.m_matrix[k][j];
	return resMat;
}

