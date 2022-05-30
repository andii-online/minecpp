#ifndef VECTOR_H
#define VECTOR_H

#include "math.h"

class Vec3{
   public:
      // The three components of the vector 
      float x, y, z;
      // Default constructor initializes to [0,0,0]
      Vec3(): x(0), y(0), z(0) {}
      Vec3(float x, float y, float z): x(x), y(y), z(z) {}
      // Magnitude of the vector3
      float magnitude() {
         return sqrt(x + y + z);
      }
      // Normalized vector3 with length 1.
      Vec3 normalized() {
         return Vec3(x, y, z) / magnitude();
      }
      // Dot product of two vector3
      float dot(const Vec3 other) {
         return (x * other.x) + (y * other.y) + (z * other.z); 
      }
      // ------------------ Operators ---------------------
      // Vec3 + Vec3
      Vec3 operator+(const Vec3 other) {
         return Vec3(x + other.x, y + other.y, z + other.z); 
      }
      // Vec3 - Vec3
      Vec3 operator-(const Vec3 other) {
         return Vec3(x - other.x, y - other.y, z - other.z);
      }
      // Vec3 * float 
      Vec3 operator*(const float other) {
         return Vec3(x * other, y * other, z * other);
      }
      // Vec3 / float 
      Vec3 operator/(const float other) {
         return Vec3(x / other, y / other, z / other);
      }
      // Returns whether the two vectors are identical.
      bool operator==(const Vec3& other) {
         return this->x == other.x && this->y == other.y && this->z == other.z;
      }
      // Returns whether the two vectors are not identical. 
      bool operator!=(const Vec3& other) {
         return this->x != other.x || this->y != other.y || this->z != other.z;
      }
};

#endif // VECTOR_H
