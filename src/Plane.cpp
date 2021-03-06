/*
* @Author: carl de gentile
* @Date:   2018-06-02 23:34:40
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-01 13:03:46
*/

#include "Plane.hpp"

double Plane::intersect(const Vec3<double> &origin, const Vec3<double> &rd)
{
	double dot1 = this->_norm_vec.dot(origin);
	double dot3 = this->_norm_vec.dot(rd);

	if (dot3 == 0.0 || dot1 == 0.0) {
		return (-1);
	}

	return -dot1 / dot3;
}