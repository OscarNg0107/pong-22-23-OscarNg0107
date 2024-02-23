//
// Created by st2-ng on 01/12/2022.
//
#include "Vector.h"
#include <cmath>
Vector::Vector()
{
  x = 2.0;
  y = 3.0;
}

Vector::Vector(float val_x, float val_y)
{
  x = val_x;
  y = val_y;
}
Vector::~Vector()
{

}

void Vector::normalise()
{
  x = x / sqrt(x * x + y * y);
  y = y / sqrt(x * x + y * y);
}

void Vector::mult_scaler()
{
  x *= 1.05;
  y *= 1.05;
}