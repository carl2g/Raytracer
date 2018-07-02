/*
* @Author: carl de gentile
* @Date:   2018-06-02 23:34:40
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-01 13:03:46
*/

#include "Plane.hpp"

double Plane::intersect(const Vec3<double> &origin, const Vec3<double> &rd)
{
	double	k = -1.0;
	Vec3<double> objR(_pos._x - origin._x , _pos._y - origin._y, _pos._z - origin._z);

	if (rd._z == 0.0)
		return (k);
	k = (-objR._z) / (rd._z);
	if (k <= 0.0)
		return (-1.0);
	return (k);
}