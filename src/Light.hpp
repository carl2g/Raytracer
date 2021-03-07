#ifndef _LIGHT_HPP
	# define _LIGHT_HPP

# include "Obj.hpp"

class Light : public Obj {
public:
	Light(const Vec3<double> &pos) : Obj({255, 255, 255, 255}), _pos(pos) {}
	~Light() = default;
	const Vec3<double> &getPos() { return this->_pos; };
private:
	Vec3<double> _pos;
};

#endif /* _LIGHT_HPP */