#include <cmath>
#include <Windows.h>
#include <d3d9types.h>
#include <iostream>

class Vector3 {
public:
	Vector3();
	Vector3(float, float, float);
	~Vector3();

	float x{ }, y{ }, z{ };

	void make_absolute() {
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
	}

	Vector3& operator+=(const Vector3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3& operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3& operator*=(const float v) {
		x *= v;
		y *= v;
		z *= v;
		return *this;
	}

	Vector3 operator+(const Vector3& v) {
		return Vector3{ x + v.x, y + v.y, z + v.z };
	}

	Vector3 operator-(const Vector3& v) {
		return Vector3{ x - v.x, y - v.y, z - v.z };
	}

	Vector3& operator+(const float& v) {
		x = x + v;
		y = y + v;
		z = z + v;
		return *this;
	}

	Vector3& operator-(const float& v) {
		x = x - v;
		y = y - v;
		z = z - v;
		return *this;
	}

	Vector3 operator*(const float v) {
		return Vector3{ x * v, y * v, z * v };
	}

	Vector3 operator/(const float fl) const {
		return Vector3(x / fl, y / fl, z / fl);
	}

	Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	bool operator==(const Vector3& v) const {
		return x == v.x && y == v.y && z == v.z;
	}

	bool operator!=(const Vector3& v) const {
		return x != v.x || y != v.y || z != v.z;
	}

	Vector3 operator*(const float fl) const {
		return Vector3(x * fl, y * fl, z * fl);
	}

	Vector3 operator*(const Vector3& v) const {
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3& operator/=(const float fl) {
		x /= fl;
		y /= fl;
		z /= fl;
		return *this;
	}

	float operator[](const int i) const {
		// ReSharper disable CppCStyleCast
		return ((float*)this)[i];
		// ReSharper restore CppCStyleCast
	}

	float& operator[](const int i) {
		return reinterpret_cast<float*>(this)[i];
	}


	inline float SpoofRuntime_fixed_sqrtf_A(float number)
	{
		float temp, mysqrt;
		mysqrt = number / 2;
		temp = 0;
		while (mysqrt != temp) {
			temp = mysqrt;
			mysqrt = (number / temp + temp) / 2;
		}
		return mysqrt;
	}

	typedef struct {
		float Pitch;
		float Yaw;
		float Roll;
	} FRotator;

	//SDK::Structs::FVector Location;
	FRotator Rotation;
	float FOV;
	float OrthoWidth;
	float OrthoNearClipPlane;
	float OrthoFarClipPlane;
	float AspectRatio;

	double Custompowf_(double x, int y)
	{
		double temp;
		if (y == 0)
			return 1;
		temp = Custompowf_(x, y / 2);
		if ((y % 2) == 0) {
			return temp * temp;
		}
		else {
			if (y > 0)
				return x * temp * temp;
			else
				return (temp * temp) / x;
		}
	}

	inline float Distance(Vector3 v) {
		return float(SpoofRuntime_fixed_sqrtf_A(Custompowf_(v.x - x, 2.0) + Custompowf_(v.y - y, 2.0) + Custompowf_(v.z - z, 2.0)));
	}

	void clamp() {
		if (x < 0.f)
			x += 360.f;

		if (x > 360.f)
			x -= 360.f;

		if (y < 0.f) y += 360.f;
		if (y > 360.f) y -= 360.f;
		z = 0.f;
	}

	inline double Length() {
		return (double)(SpoofRuntime_fixed_sqrtf_A(x * x + y * y + z * z));
	}

	/*
	void normalize() {
		while (this->x > 89.0f)
			this->x -= 180.0f;

		while (this->x < -89.0f)
			this->x += 180.0f;

		while (this->y > 180.0f)
			this->y -= 360.0f;

		while (this->y < -180.0f)
			this->y += 360.0f;
	}
	*/
	/*
	[[nodiscard]] float dot(const Vector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}
	*/
	[[nodiscard]] bool empty() const {
		return x == 0 || y == 0 || z == 0;
	}
	/*
	void init(const float ix = 0.0f, const float iy = 0.0f, const float iz = 0.0f) {
		x = ix;
		y = iy;
		z = iz;
	}
	*/
};