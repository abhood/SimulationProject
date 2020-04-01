#pragma once
#include "Vector.h"

namespace ELCT350
{
  namespace Math
  {
    class Matrix final
    {
    public:
      #pragma region Constructors and Destructors
      Matrix(size_t rowSize, size_t columnSize);
      Matrix(const Matrix& original);
      Matrix(Matrix&& old) noexcept;
      ~Matrix();
      #pragma endregion

      #pragma region Modifiers
      void setColumn(size_t index, const Vector& column);
      #pragma endregion

      #pragma region Observers
      size_t getRowSize() const;
      size_t getColumnSize() const;
      Vector getColumn(size_t index) const;
      Matrix getInverse() const;
      #pragma endregion

      #pragma region Operators
      #pragma region Modifiers
      Vector& operator[](size_t index);
      Matrix& operator=(const Matrix& rhs);
      #pragma endregion

      #pragma region Observers
      const Vector operator[](size_t index) const;
      Matrix operator+(const Matrix& rhs) const;
      Vector operator*(const Vector& rhs) const;
      Matrix operator*(const Matrix& rhs) const;
      #pragma endregion
      #pragma endregion

    private:
      #pragma region Variables
      size_t _rowSize;
      size_t _columnSize;
      Vector* _rows;
      #pragma endregion

      #pragma region Observers
      void decomposeLU(Matrix& L, Matrix& U) const;
      #pragma endregion
    };
  }
}