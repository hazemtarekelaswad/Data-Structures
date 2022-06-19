#pragma once
#include <iostream>

template<typename T, int rows, int columns>

class Matrix {
private:
	T m_matrix[rows][columns];

public:
	Matrix() {}

	Matrix(const Matrix& matrix) {
		if (this->get_rows() != matrix.get_rows() || this->get_columns() != matrix.get_columns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->get_rows(); ++i)
			for (int j = 0; j < this->get_columns(); ++j)
				m_matrix[i][j] = matrix.m_matrix[i][j];
	}

	Matrix(Matrix&& matrix) {
		if (this->get_rows() != matrix.get_rows() || this->get_columns() != matrix.get_columns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->get_rows(); ++i)
			for (int j = 0; j < this->get_columns(); ++j)
				m_matrix[i][j] = std::move(matrix.m_matrix[i][j]);
	}

	Matrix& operator=(const Matrix& matrix) {
		if (this->get_rows() != matrix.get_rows() || this->get_columns() != matrix.get_columns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->get_rows(); ++i)
			for (int j = 0; j < this->get_columns(); ++j)
				m_matrix[i][j] = matrix.m_matrix[i][j];
		return *this;
	}

	Matrix& operator=(Matrix&& matrix) {
		if (this->get_rows() != matrix.get_rows() || this->get_columns() != matrix.get_columns())
			throw "The matrices' sizes have to be equal";

		for (int i = 0; i < this->get_rows(); ++i)
			for (int j = 0; j < this->get_columns(); ++j)
				m_matrix[i][j] = std::move(matrix.m_matrix[i][j]);
		return *this;
	}

	constexpr int get_rows() const {
		return rows;
	}

	constexpr int get_columns() const {
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
		for (int i = 0; i < matrix.get_rows(); ++i)
			for (int j = 0; j < matrix.get_columns(); ++j)
				in >> matrix.m_matrix[i][j];

		std::cout << std::endl;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
		for (int i = 0; i < matrix.get_rows(); ++i) {
			for (int j = 0; j < matrix.get_columns(); ++j)
				out << matrix.m_matrix[i][j] << ' ';
			out << std::endl;
		}
		return out;
	}

	friend Matrix operator+(const Matrix& mat1, const Matrix& mat2) {

		Matrix resMat;

		for (int i = 0; i < mat1.get_rows(); ++i)
			for (int j = 0; j < mat1.get_columns(); ++j)
				resMat.m_matrix[i][j] = mat1.m_matrix[i][j] + mat2.m_matrix[i][j];
		return resMat;
	}

	friend Matrix operator-(const Matrix& mat1, const Matrix& mat2) {

		Matrix resMat;

		for (int i = 0; i < mat1.get_rows(); ++i)
			for (int j = 0; j < mat1.get_columns(); ++j)
				resMat.m_matrix[i][j] = mat1.m_matrix[i][j] - mat2.m_matrix[i][j];
		return resMat;
	}

	template<typename T, int rows, int columns, int p>
	friend Matrix<T, rows, p> operator*(const Matrix<T, rows, columns>& mat1, const Matrix<T, columns, p>& mat2);

	friend Matrix operator*(int constant, const Matrix& mat) {
		Matrix resMat;

		for (int i = 0; i < mat.get_rows(); ++i)
			for (int j = 0; j < mat.get_columns(); ++j)
				resMat.m_matrix[i][j] = constant * mat.m_matrix[i][j];
		return resMat;
	}

	friend Matrix operator*(const Matrix& mat, int constant) {
		Matrix resMat;

		for (int i = 0; i < mat.get_rows(); ++i)
			for (int j = 0; j < mat.get_columns(); ++j)
				resMat.m_matrix[i][j] = constant * mat.m_matrix[i][j];
		return resMat;
	}

	friend bool operator==(const Matrix& mat1, const Matrix& mat2) {
		if (mat1.get_rows() != mat2.get_rows() || mat1.get_columns() != mat2.get_columns())
			return false;

		for (int i = 0; i < mat1.get_rows(); ++i) {
			for (int j = 0; j < mat1.get_columns(); ++j) {
				if (mat1.m_matrix[i][j] != mat2.m_matrix[i][j])
					return false;
			}
		}
		return true;
	}

	Matrix<T, columns, rows> transpose() const{
		Matrix<T, columns, rows> transposedMat;
		for (int i = 0; i < transposedMat.get_rows(); ++i)
			for (int j = 0; j < transposedMat.get_columns(); ++j)
				transposedMat(i, j) = m_matrix[j][i];
		return transposedMat;
	}

	long long trace() const {
		if (!is_square())
			throw "A matrix has to be square to compute its trace";

		long long sum = 0;
		for (int i = 0; i < get_rows(); ++i)
			sum += m_matrix[i][i];
		return sum;
	}

	bool is_square() const {
		return get_rows() == get_columns();
	}

	bool is_diagonal() const {
		bool diagonalNonZero = false;
		for (int i = 0; i < get_rows(); ++i) {
			for (int j = 0; j < get_columns(); ++j) {
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

	bool is_identity() const {
		bool diagonalNonZero = false;
		for (int i = 0; i < get_rows(); ++i) {
			for (int j = 0; j < get_columns(); ++j) {
				if (i != j && m_matrix[i][j])
					return false;
				if (i == j && m_matrix[i][j] != 1)
					return false;
			}
		}
		return true;
	}

	bool is_zero() const {
		for (int i = 0; i < get_rows(); ++i) {
			for (int j = 0; j < get_columns(); ++j) {
				if (m_matrix[i][j])
					return false;
			}
		}
		return true;
	}

	void fill(const T& element) {
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < columns; ++j)
				m_matrix[i][j] = element;
	}

	~Matrix() {}
};

template<typename T, int rows, int columns, int p>
Matrix<T, rows, p> operator*(const Matrix<T, rows, columns>& mat1, const Matrix<T, columns, p>& mat2) {

	Matrix<T, rows, p> resMat;
	resMat.fill(0);

	for (int i = 0; i < resMat.get_rows(); ++i)
		for (int j = 0; j < resMat.get_columns(); ++j)
			for (int k = 0; k < mat1.get_columns(); ++k)
				resMat(i, j) += mat1.m_matrix[i][k] * mat2.m_matrix[k][j];
	return resMat;
}

