#ifndef _CAMERA_HPP
	# define _CAMERA_HPP

# include <memory>
# include <utility>
# include <vector>
# include "Obj.hpp"

using PairInt = std::pair<int, int>;

class Camera : public Obj {
public:
	Camera(const Vec3<double> &pos, PairInt screenSize);
	~Camera() = default;
	const Vec3<double> &getVecAtPixel(int pixel);
	double intersect(const Vec3<double> &origin, const Vec3<double> &vdir) { return (-1.0); }
	const Vec3<double> getRay(const Vec3<double> &dest);
	const Vec3<double> &getPos() const { return (_pos); }
	void rotate_horizontal(const double angle);
	void rotate_vertical(const double angle);
	std::unique_ptr<Vec3<double>> getNormalVect(const Vec3<double> &origin) const  { return (std::make_unique<Vec3<double>>(0.0, 0.0, 0.0)); };
	std::vector<std::unique_ptr<Vec3<double>>> _vision;
private:
	Vec3<double> _pos;
};

#endif /* _CAMERA_HPP */