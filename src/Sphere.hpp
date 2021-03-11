#ifndef _SPHERE_HPP
	# define _SPHERE_HPP

# include "Obj.hpp"

class Sphere : public Obj {
public:
	Sphere(const Vec3<double> &pos, int radius, const Color &c) : Obj(c), _pos(pos), _rad(radius) {}
	~Sphere() = default;
	double intersect(const Vec3<double> &origin, const Vec3<double> &vdir);
	std::unique_ptr<Vec3<double>> getNormalVect(const Vec3<double> &origin) const;

private:
	int 	_rad;
	Vec3<double> _pos;
};

#endif /* _SPHERE_HPP */