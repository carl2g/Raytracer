#ifndef _TRIANGLE_HPP
	# define _TRIANGLE_HPP

# include "Obj.hpp"

class Triangle : public Obj {
public:
	Triangle(const Vec3<double> &a, const Vec3<double> &b, const Vec3<double> &c, const Color &col);
	double intersect(const Vec3<double> &origin, const Vec3<double> &vdir);
private:
	Vec3<double> _a;
	Vec3<double> _b;
	Vec3<double> _c;
}

#endif /* _TRIANGLE_HPP */