#ifndef _PLANE_HPP
	# define _PLANE_HPP

# include "Obj.hpp"

class Plane : public Obj {
public:
	template<typename ... Args>
	Plane(const Vec3<double> &pos, const Vec3<double> &norm_vec, Args &&... args) : Obj(std::forward<Args>(args) ...), _pos(pos), _norm_vec(norm_vec) {}
	~Plane() = default;
	double intersect(const Vec3<double> &origin, const Vec3<double> &vdir);
	std::unique_ptr<Vec3<double>> getNormalVect(const Vec3<double> &origin) const;

private:
	Vec3<double> _norm_vec;
	Vec3<double> _pos;
};

#endif /* _PLANE_HPP */