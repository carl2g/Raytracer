#ifndef _PLANE_HPP
	# define _PLANE_HPP

# include "Obj.hpp"

class Plane : public Obj {
public:
	Plane(const Vec3<double> &pos, const Vec3<double> &norm_vec, const Color &c = {255, 255, 255, 255}) : Obj(c), _pos(pos), _norm_vec(norm_vec) {}
	~Plane() = default;
	double intersect(const Vec3<double> &origin, const Vec3<double> &vdir);
	std::unique_ptr<Vec3<double>> getNormalVect(const Vec3<double> &origin);

private:
	Vec3<double> _norm_vec;
	Vec3<double> _pos;
};

#endif /* _PLANE_HPP */