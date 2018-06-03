#ifndef _CAMERA_HPP
	# define _CAMERA_HPP

# include <memory>
# include <utility>
# include <vector>
# include "Obj.hpp"

using PairInt = std::pair<int, int>;

class Camera : public Obj {
public:
	Camera(const v3<double> &pos, PairInt screenSize);
	~Camera() = default;
	const v3<double> &getVecAtPixel(int pixel);
	double intersect(const v3<double> &origin, const v3<double> &vdir) {}
	const v3<double> getRay(const v3<double> &dest);
private:
	std::vector<std::unique_ptr<v3<double>>> _vision;
};

#endif /* _CAMERA_HPP */