#pragma once

namespace ELCT350
{
  namespace Math
  {
    class Vector final
    {
    public:
      #pragma region Constructors and Destructors
      Vector(size_t vectorSize = 0);
      Vector(const Vector& original);
      Vector(Vector&& old) noexcept;
      ~Vector();
      #pragma endregion

      #pragma region Observers
      size_t getSize() const;
      #pragma endregion

      #pragma region Operators
      #pragma region Modifers
      double& operator[](size_t index);
      Vector& operator=(const Vector& rhs);
      #pragma endregion

      #pragma region Observers
      double operator[](size_t index) const;
      Vector operator+(const Vector& rhs) const;
      double operator*(const Vector& rhs) const;
      #pragma endregion
      #pragma endregion
    private:
      #pragma region Variables
      size_t _size;
      double* _values;
      #pragma endregion
    };
  }
}