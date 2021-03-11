#ifndef _LIGHT_HPP
	# define _LIGHT_HPP

# include "Obj.hpp"

class Light : public Obj {
public:
	Light(const Vec3<double> &pos, const double intensity) : Obj({255, 255, 255, 255}), _pos(pos), _intensity(intensity) {}
	~Light() = default;
	const Vec3<double> &getPos() { return this->_pos; };
	const double getIntensity() { return this->_intensity; };
	std::unique_ptr<Vec3<double>> getNormalVect(const Vec3<double> &origin) const  { return (std::make_unique<Vec3<double>>(0.0, 0.0, 0.0)); };
private:
	Vec3<double> _pos;
	double _intensity;
};

#endif /* _LIGHT_HPP */