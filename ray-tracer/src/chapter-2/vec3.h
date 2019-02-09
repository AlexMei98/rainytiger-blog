#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3
{

public:
	vec3() {}
	vec3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

	inline double x() const { return e[0]; }
	inline double y() const { return e[1]; }
	inline double z() const { return e[2]; }

	inline double r() const { return e[0]; }
	inline double g() const { return e[1]; }
	inline double b() const { return e[2]; }

	inline const vec3& operator+() { return *this; }
	inline vec3 operator-() { return vec3(-e[0], -e[1], -e[2]); }
	inline double operator[](int i) const { return e[i]; }
	inline double& operator[](int i) { return e[i]; }

	inline vec3& operator+=(const vec3 &v2);
	inline vec3& operator-=(const vec3 &v2);
	inline vec3& operator*=(const vec3 &v2);
	inline vec3& operator/=(const vec3 &v2);
	inline vec3& operator*=(const double f);
	inline vec3& operator/=(const double f);

	inline double length() const
	{
		return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

	inline double squared_length() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	inline void make_unit_vector();

	double e[3];

};

inline std::istream& operator>>(std::istream &is, vec3 &v)
{
	is >> v.e[0] >> v.e[1] >> v.e[2];
	return is;
}
inline std::ostream& operator<<(std::ostream &os, const vec3 &v)
{
	os << v.e[0] << " " << v.e[1] << " " << v.e[2];
	return os;
}

inline void vec3::make_unit_vector()
{
	double k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline vec3 operator*(const vec3 &v, double f)
{
	return vec3(v.e[0] * f, v.e[1] * f, v.e[2] * f);
}

inline vec3 operator*(double f, const vec3 &v)
{
	return vec3(v.e[0] * f, v.e[1] * f, v.e[2] * f);
}

inline vec3 operator/(const vec3 &v, double f)
{
	return vec3(v.e[0] / f, v.e[1] / f, v.e[2] / f);
}

inline double dot(const vec3 &v1, const vec3 &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3 &v2)
{
	return vec3(
		(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])
	);
}

inline vec3& vec3::operator+=(const vec3 &v2)
{
	e[0] += v2.e[0];
	e[1] += v2.e[1];
	e[2] += v2.e[2];
	return *this;
}

inline vec3& vec3::operator-=(const vec3 &v2)
{
	e[0] -= v2.e[0];
	e[1] -= v2.e[1];
	e[2] -= v2.e[2];
	return *this;
}

inline vec3& vec3::operator*=(const vec3 &v2)
{
	e[0] *= v2.e[0];
	e[1] *= v2.e[1];
	e[2] *= v2.e[2];
	return *this;
}

inline vec3& vec3::operator/=(const vec3 &v2)
{
	e[0] /= v2.e[0];
	e[1] /= v2.e[1];
	e[2] /= v2.e[2];
	return *this;
}

inline vec3& vec3::operator*=(const double f)
{
	e[0] *= f;
	e[1] *= f;
	e[2] *= f;
	return *this;
}

inline vec3& vec3::operator/=(const double f)
{
	double k = 1.0 / f;
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline vec3 unit_vector(vec3 v)
{
	return v / v.length();
}

#endif