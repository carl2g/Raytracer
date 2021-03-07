#ifndef _Vec3D_HPP
	# define _Vec3D_HPP

#include <math.h>

template<typename T1>
class Vec3 {
public:
	Vec3() = default;
	Vec3(T1 x, T1 y, T1 z) : _x(x), _y(y), _z(z) {};
	Vec3(const Vec3<T1> &v) : _x(v._x), _y(v._y), _z(v._z) {};
	inline double norm() const { return sqrt((_x * _x) + (_y * _y) + (_z * _z)); }
	inline Vec3<T1> operator-(const Vec3<T1> &op) const { return Vec3<T1>(_x - op._x, _y - op._y, _z - op._z); }
	inline Vec3<T1> operator-(double t) const { return Vec3<T1>(_x - t, _y - t, _z - t); }
	inline Vec3<T1> operator+(const Vec3<T1> &op) const { return Vec3<T1>(_x + op._x, _y + op._y, _z + op._z); }
	inline Vec3<T1> operator*(double t) const { return Vec3<T1>(_x * t, _y * t, _z * t); }
	inline double dot(const Vec3<T1> &op) const { return  (_x * op._x + _y * op._y + _z * op._z); }
	inline double getAngle(const Vec3<T1> &op) const { return  (acos(this->dot(op) / ((op).norm() * this->norm()))); }
	inline Vec3<T1> cross(const Vec3<T1> &op) const { return Vec3<T1>(_y * op._z - _z * op._y, _z * op._x - _x * op._z, _x * op._y - _y * op._x); }
	inline Vec3<T1> normalized() const { return Vec3<T1>(_x / this->norm(), _y / this->norm(), _z / this->norm()); }
	~Vec3() = default;
	T1 	_x;
	T1 	_y;
	T1 	_z;
};

#endif /* _Vec3D_HPP */