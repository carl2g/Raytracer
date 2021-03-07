/*
* @Author: carl de gentile
* @Date:   2018-06-02 23:34:40
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-01 13:03:46
*/

#include "Plane.hpp"

double Plane::intersect(const Vec3<double> &origin, const Vec3<double> &rd)
{
	double dot1 = this->_norm_vec.dot(origin - this->_pos);
	double dot2 = this->_norm_vec.dot(rd);

	if (dot2 == 0.0 || dot1 == 0.0) {
		return (-1);
	}

	return (-dot1) / dot2;
}

std::unique_ptr<Vec3<double>> Plane::getNormalVect(const Vec3<double> &origin) { 
	return std::unique_ptr<Vec3<double>> (
		new Vec3<double>(
			this->_norm_vec.normalized()
		)
	);
}