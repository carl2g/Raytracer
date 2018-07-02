/*
* @Author: carl de gentile
* @Date:   2018-07-02 11:22:15
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-02 11:23:27
*/

#include "Triangle.hpp"

Triangle::Triangle(const Vec3<double> &a, const Vec3<double> &b, const Vec3<double> &c, const Color &col)
	: Obj(pos, c), _a(a), _b(b), _c(c), _col(col) {}