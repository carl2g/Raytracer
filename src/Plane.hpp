#ifndef _PLANE_HPP
	# define _PLANE_HPP

# include "Obj.hpp"

class Plane : public Obj {
public:
	Plane(const Vec3<double> &pos, const Color &c = {255, 255, 255, 255}) : Obj(pos, c) {}
	~Plane() = default;
	double intersect(const Vec3<double> &origin, const Vec3<double> &vdir);
private:
};

#endif /* _PLANE_HPP */