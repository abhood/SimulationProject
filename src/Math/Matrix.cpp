#include "Math/Matrix.h"
#include <stdexcept>

using namespace ELCT350::Math;
using namespace std;

#pragma region Constructors and Destructors
Matrix::Matrix(size_t rowSize, size_t columnSize)
  : _rowSize(rowSize), _columnSize(columnSize), _rows(new Vector[rowSize])
{
  for (size_t i = 0; i < _rowSize; ++i)
    _rows[i] = Vector(columnSize);
}

Matrix::Matrix(const Matrix& original)
  : _rowSize(original._rowSize), _columnSize(original._columnSize),
  _rows(new Vector[original._rowSize])
{
  for (size_t i = 0; i < _rowSize; ++i)
    _rows[i] = original._rows[i];
}

Matrix::Matrix(Matrix&& old) noexcept
  : _rowSize(old._rowSize), _columnSize(old._columnSize), _rows(old._rows)
{
  old._rowSize = 0;
  old._columnSize = 0;
  old._rows = nullptr;
}

Matrix::~Matrix()
{
  if (_rows)
    delete[] _rows;
}
#pragma endregion

#pragma region Modifiers
void Matrix::setColumn(size_t index, const Vector& column)
{
  if (index >= _columnSize)
    throw out_of_range("index is larger than the number of columns");
  if (column.getSize() != _rowSize)
    throw out_of_range("Vector is not the correct size for a column of this matrix");

  for (size_t row = 0; row < _rowSize; ++row)
  {
    _rows[row][index] = column[row];
  }
}
#pragma endregion

#pragma region Observers
size_t Matrix::getRowSize() const
{
  return _rowSize;
}

size_t Matrix::getColumnSize() const
{
  return _columnSize;
}

Vector Matrix::getColumn(size_t index) const
{
  if (index >= _columnSize)
    throw std::out_of_range("index is larger than the number of columns");
  Vector column(_rowSize);
  for (size_t row = 0; row < _rowSize; ++row)
  {
    column[row] = _rows[row][index];
  }

  return column;
}

Matrix Matrix::getInverse() const
{
  //We can only compute the inverse for a square matrix, so we throw an exception if it's not square
  if (_rowSize != _columnSize)
    throw std::domain_error("Matrix must be square to have an inverse");

  //Get LU Decomposition
  Matrix L(_rowSize, _columnSize);
  Matrix U(_rowSize, _columnSize);
  decomposeLU(L, U);

  //Compute the inverse of L and U
  Matrix inverseL(_rowSize, _columnSize);
  Matrix inverseU(_rowSize, _columnSize);

  //We can use the fact that matrices are triangular to compute their inverse in a fairly straight-forward way.
  //Ordinarily, for MNA, we would never actually compute the inverse. A minor modification of the below algorithm
  //can be used to solve directly for x in Ax=b (LUx=b after decomposition). In fact, that's kind of what we're doing
  //here, where b is actually I, the identity matrix (matrix with 1s in the diagonal cells, but 0s elsewhere)
  for (size_t row = 0; row < _rowSize; ++row)
  {
    inverseL[row][row] = static_cast<double>(1) / L[row][row];
    inverseU[row][row] = static_cast<double>(1) / U[row][row];
    for (size_t l = 0; l < row; ++l)
    {
      for (size_t j = 0; j < row; ++j)
      {
        inverseL[row][l] -= (L[row][j] * inverseL[j][l]) / L[row][row];
        inverseU[l][row] -= inverseU[l][j] * U[j][row] / U[row][row];
      }
    }
  }

  //return U^(-1)*L^(-1), which is the inverse of the matrix
  return inverseU * inverseL;
}

void Matrix::decomposeLU(Matrix& L, Matrix& U) const
{
  //We assume that L and U are the same size of this matrix and that the matrix is square.
  //We're not checking because this is a private function, so we can control how it's called
  //(and ensure it's checked before this function is called)

  //Compute the values of U
  for (size_t i = 0; i < _rowSize; ++i)
  {
    for (size_t j = i; j < _rowSize; ++j)
    {
      double sum = double{};
      for (size_t k = 0; k < i; ++k)
      {
        sum += L[i][k] * U[k][j];
      }
      U[i][j] = _rows[i][j] - sum;
    }

    //Compute the values of L
    for (size_t j = i; j < _rowSize; ++j)
    {
      if (i == j)
        L[i][j] = 1;
      else
      {
        double sum = double{};
        for (size_t k = 0; k < i; ++k)
        {
          sum += L[j][k] * U[k][i];
        }

        L[j][i] = (_rows[j][i] - sum) / U[i][i];
      }
    }
  }
}
#pragma endregion

#pragma region Operators
#pragma region Modifiers
Matrix& Matrix::operator=(const Matrix& rhs)
{
  if (_rows)
    delete[] _rows;

  _rowSize = rhs._rowSize;
  _columnSize = rhs._columnSize;
  _rows = new Vector[_rowSize];
  for (size_t i = 0; i < _rowSize; ++i)
    _rows[i] = rhs._rows[i];

  return *this;
}

Vector& Matrix::operator[](size_t index)
{
  if (index >= _rowSize)
    throw out_of_range("index is larger than the number of rows");

  return _rows[index];
}
#pragma endregion

#pragma region Observers
Matrix Matrix::operator+(const Matrix& rhs) const
{
  if ((rhs._rowSize != _rowSize) || (rhs._columnSize != _columnSize))
    throw domain_error("Matrices must be the same size to be added");

  Matrix sum(_rowSize, _columnSize);

  #pragma region Calculate Sum Here!
  #pragma endregion

  return sum;
}

Vector Matrix::operator*(const Vector& rhs) const
{
  if (_columnSize != rhs.getSize())
    throw domain_error("Matrix columns size must match vector size");

  Vector product(_rowSize);
  #pragma region Calculate product here!
  #pragma endregion
  return product;
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
  if (_columnSize != rhs._rowSize)
  {
    throw domain_error("Number of rows in right-hand side needs to match number of columns in left-hand side");
  }

  Matrix product(_rowSize, rhs._columnSize);
  #pragma region Calculate product here!
  #pragma endregion

  return product;
}

const Vector Matrix::operator[](size_t index) const
{
  if (index >= _rowSize)
    throw out_of_range("index is larger than the number of rows");

  return _rows[index];
}
#pragma endregion