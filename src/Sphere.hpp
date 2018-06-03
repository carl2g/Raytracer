#ifndef _SPHERE_HPP
	# define _SPHERE_HPP

# include "Obj.hpp"

class Sphere : public Obj {
public:
	Sphere(const v3<double> &pos, int radius, const Color &c) : Obj(pos, c), _rad(radius) {}
	~Sphere() = default;
	double intersect(const v3<double> &origin, const v3<double> &vdir);
private:
	int 	_rad;
};

#endif /* _SPHERE_HPP */