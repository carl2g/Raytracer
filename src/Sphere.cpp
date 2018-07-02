/*
* @Author: carl de gentile
* @Date:   2018-06-02 16:07:48
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-02 11:14:25
*/

#include "Sphere.hpp"
#include <math.h>

double Sphere::intersect(const Vec3<double> &origin, const Vec3<double> &rd)
{
	Vec3<double> dirSph = _pos - origin;
	Vec3<double> Nrd = rd.normalized();
	double t = (dirSph._x * Nrd._x) + (dirSph._y * Nrd._y) + (dirSph._z * Nrd._z);
	Vec3<double> p = {origin._x + Nrd._x * t, origin._y + Nrd._y * t, origin._z + Nrd._z * t};
	double y = (Vec3<double>(_pos - p)).getLen();
	if (y <= _rad) {
		double x = sqrt((_rad * _rad) - (y * y));
		double t1 = t - x;
		double t2 = t + x;
		return (t1 <= t2 ? t1 : t2);
	}
	return (-1);
}