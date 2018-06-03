/*
* @Author: carl de gentile
* @Date:   2018-06-02 16:07:48
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-06-03 15:56:56
*/

#include "Sphere.hpp"
#include <math.h>

double Sphere::intersect(const v3<double> &origin, const v3<double> &rd)
{
	v3<double> eqat;
	double delt;
	v3<double> vToObj(_pos._x - origin._x , _pos._y - origin._y, _pos._z - origin._z);

	eqat._x = rd._x * rd._x + rd._y * rd._y + rd._z * rd._z;
  	eqat._y = 2.0 * ((rd._x * vToObj._x) + (rd._y * vToObj._y) + (rd._z * vToObj._z));
	eqat._z = vToObj._x * vToObj._x + vToObj._y * vToObj._y +
		vToObj._z * vToObj._z - _rad * _rad;
	delt = eqat._y * eqat._y - 4.0 * eqat._x * eqat._z;
	if (eqat._x == 0 || delt < 0)
		return (-1);
	return (solvedEq(eqat, delt));
}