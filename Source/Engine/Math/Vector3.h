#pragma once
#include <cassert>
#include "math.h"


template<typename T>
struct Vector3
{
	T x, y;
	Vector3() = default;
	Vector3(T x, T y, Tz) : x(x), y(y), z(z) {}

	 T operator [] (unsigned int index) const { assert(index < 3); return (&x)[index]; }

	 T& operator [] (unsigned int index)  { 
		assert(index < 3); 
	return (&x)[index]; 
	}


	Vector3 operator + (const Vector3 v) {
		return Vector3{ x + v.x, y + v.y + v.z };
	}
	Vector3 operator - (const Vector3 v) {
		return Vector3{ x - v.x, y - v.y - v.z }; // TODO: add z to all operator overloads
	}
	Vector3 operator * (const Vector3 v) {
		return Vector3{ x * v.x, y * v.y * v.z };
	}
	Vector3 operator / (const Vector3 v) {
		return Vector3{ x / v.x, y / v.y /v.z };
	}

	Vector3& operator += (const Vector3 v) {
		x += v.x;
		y += v.y;
		z += v.z;
			return *this;
	}
	Vector3& operator -= (const Vector3 v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
			return *this;
	}
	Vector3& operator *= (const Vector3 v) {
		x *= v.x;
		y *= v.y;
		z *= v.z;
			return *this;
	}
	Vector3& operator /= (const Vector3 v) {
		x /= v.x;
		y /= v.y;
		z /= v.z;
			return *this;
	}


	Vector3 operator + (float s) const {
		return Vector3{ x + s, y + s, z + s };
	}
	Vector3 operator - (float s) const {
		return Vector3{ x - s, y - s, z - s };
	}
	Vector3 operator * (float s) const {
		return Vector3{ x * s, y * s, z * s };
	}
	Vector3 operator / (float s) const {
		return Vector3{ x / s, y / s, z/s };
	}

	Vector3 operator += (float s) const {
		return Vector3{ x += s, y += s, z +=s };
	}
	Vector3 operator -= (float s) const {
		return Vector3{ x -= s, y -= s };
	}
	Vector3 operator *= (float s) const {
		return Vector3{ x *= s, y *= s };
	}
	Vector3 operator /= (float s) const {
		return Vector3{ x /= s, y /= s };
	}


	float length() {
		return sqrt(x * x + y * y);
	}
	float lengthSqr() {
		return (x * x) + (y * y);
	}

};

using ivec2 = Vector3<int>;
using vec2 = Vector3<float>;
