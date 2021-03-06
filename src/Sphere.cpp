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
	double a = powl(rd._x, 2) + powl(rd._y, 2) + powl(rd._z, 2);
	double b = -2.0 * rd._x * this->_pos._x + 2.0 * rd._x * origin._x
	- 2.0 * rd._y * this->_pos._y + 2.0 * rd._y * origin._y
	- 2.0 * rd._z * this->_pos._z + 2.0 * rd._z * origin._z;
	double c = powl(this->_pos._x, 2) - 2 * this->_pos._x * origin._x + powl(origin._x, 2)
	+ powl(this->_pos._y, 2) - 2 * this->_pos._y * origin._y + powl(origin._y, 2)
	+ powl(this->_pos._z, 2) - 2 * this->_pos._z * origin._z + powl(origin._z, 2) 
	- powl(_rad, 2);
		
	double delt = (powl(b, 2) - (4.0 * a * c));
	
	if (delt < 0)
		return (-1);
	else if (delt == 0)
		return (-b / (2 * a));

	double x1 = (-b - sqrtl(delt)) / (2 * a);
	double x2 = (-b + sqrtl(delt)) / (2 * a);

	return ((x1 <= x2 ? x1 : x2));
}