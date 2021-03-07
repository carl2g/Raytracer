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
	Vec3<double> norm_vec = (_b - _a).cross(_c - _a);
	double dot1 = norm_vec.dot(origin - _c);
	double dot3 = norm_vec.dot(rd);

	if (dot3 == 0.0) {
		return (-1);
	}

	double t = -dot1 / dot3;

	Vec3<double> g	= origin + rd * t;

	double bac = acos((_b-_a).dot(_c-_a) / ((_b-_a).norm() * (_c-_a).norm()));
	double bag = acos((_b-_a).dot(g-_a) / ((_b-_a).norm() * (g-_a).norm()));

	double acb = acos((_a-_c).dot(_b-_c) / ((_a-_c).norm() * (_b-_c).norm()));
	double acg = acos((_a-_c).dot(g-_c) / ((_a-_c).norm() * (g-_c).norm()));

	double cba = acos((_c-_b).dot(_a-_b) / ((_c-_b).norm() * (_a-_b).norm()));
	double cbg = acos((_c-_b).dot(g-_b) / ((_c-_b).norm() * (g-_b).norm()));

	if (bac >= bag && acb >= acg && cba >= cbg) {
		return (t);
	}
	return (-1);
}