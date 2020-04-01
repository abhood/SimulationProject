#include "Math/Vector.h"
#include <stdexcept>

using namespace ELCT350::Math;
using namespace std;

#pragma region Constructors and Destructors
Vector::Vector(size_t vectorSize)
  : _size(vectorSize), _values(new double[vectorSize])
{
  for (size_t i = 0; i < _size; ++i)
    _values[i] = 0.0;
}

Vector::Vector(const Vector& original)
  : _size(original._size), _values(new double[original._size])
{
  for (size_t i = 0; i < _size; ++i)
    _values[i] = original._values[i];
}

Vector::Vector(Vector&& old) noexcept
  : _size(old._size), _values(old._values)
{
  old._size = 0;
  old._values = nullptr;
}

Vector::~Vector()
{
  if (_values)
    delete[] _values;
}
#pragma endregion

#pragma region Observers
size_t Vector::getSize() const
{
  return _size;
}
#pragma endregion

#pragma region Operators
#pragma region Modifiers
Vector& Vector::operator=(const Vector& rhs)
{
  if (_values)
    delete[] _values;

  _size = rhs._size;
  _values = new double[_size];
  for (size_t i = 0; i < _size; ++i)
    _values[i] = rhs._values[i];

  return *this;
}

double& Vector::operator[](size_t index)
{
  if (index >= _size)
    throw out_of_range("index is larger than the number of rows");

  return _values[index];
}
#pragma endregion

#pragma region Observers
Vector Vector::operator+(const Vector& rhs) const
{
  if (rhs._size != _size)
    throw domain_error("Vectors must be the same size to be added");

  Vector sum(_size);
  for (size_t i = 0; i < _size; ++i)
  {
    sum[i] = _values[i] + rhs._values[i];
  }

  return sum;
}

double Vector::operator*(const Vector& rhs) const
{
  if (rhs._size != _size)
    throw domain_error("Vectors must be the same size to compute the dot product");

  double product = 0;
  for (size_t i = 0; i < _size; ++i)
    product += _values[i] * rhs._values[i];
  return product;
}

double Vector::operator[](size_t index) const
{
  if (index >= _size)
    throw out_of_range("index is larger than the number of rows");

  return _values[index];
}
#pragma endregion
#pragma endregion