/*
* @Author: carl de gentile
* @Date:   2018-07-02 11:22:15
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-02 11:23:27
*/

#include "Triangle.hpp"
#include <math.h>

Triangle::Triangle(const Vec3<double> &a, const Vec3<double> &b, const Vec3<double> &c, const Color &color)
	: Obj(color), _a(a), _b(b), _c(c) {}

double Triangle::intersect(const Vec3<double> &origin, const Vec3<double> &rd) {
	auto norm_vec = (_b - _a).cross(_c - _a);
	double dot1 = norm_vec.dot(origin - _c);
	double dot3 = norm_vec.dot(rd);

	if (dot3 == 0.0) {
		return (-1);
	}

	double t = -dot1 / dot3;

	auto g	= origin + rd * t;

	double bac = (_b-_a).getAngle(_c-_a);
	double bag = (_b-_a).getAngle(g-_a);

	double acb = (_a-_c).getAngle(_b-_c);
	double acg = (_a-_c).getAngle(g-_c);

	double cba = (_c-_b).getAngle(_a-_b);
	double cbg = (_c-_b).getAngle(g-_b);

	if (bac >= bag && acb >= acg && cba >= cbg) {
		return (t);
	}
	return (-1);
}

std::unique_ptr<Vec3<double>> Triangle::getNormalVect(const Vec3<double> &origin) { 
	return std::unique_ptr<Vec3<double>> (
		new Vec3<double>(
			(origin - this->_a).cross(origin - _a).normalized()
		)
	);
}