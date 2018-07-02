#ifndef _Vec3D_HPP
	# define _Vec3D_HPP

template<typename T1>
class Vec3 {
public:
	Vec3() = default;
	Vec3(T1 x, T1 y, T1 z) : _x(x), _y(y), _z(z) {}
	double getLen() const { return sqrt((_x * _x) + (_y * _y) + (_z * _z)); }
	Vec3<T1> operator-(const Vec3<T1> &op) const { return Vec3<T1>(_x - op._x, _y - op._y, _z - op._z); }
	Vec3<T1> operator+(const Vec3<T1> &op) const { return Vec3<T1>(_x + op._x, _y + op._y, _z + op._z); }
	Vec3<T1> normalized() const { return Vec3<T1>(_x / getLen(), _y / getLen(), _z / getLen()); }
	~Vec3() = default;
	T1 	_x;
	T1 	_y;
	T1 	_z;
};

#endif /* _Vec3D_HPP */