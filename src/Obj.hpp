#ifndef _OBJ_HPP
	# define _OBJ_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

class Color {
public:
	Color(int r, int g, int b, int a) : _r(r), _g(g), _b(b), _a(a) {}
	int getR() const { return _r; }
	int getG() const { return _g; }
	int getB() const { return _b; }
	int getA() const { return _a; }
private:
	int _r;
	int _g;
	int _b;
	int _a;
};

class Obj {
public:
	Obj(const Vec3<double> &pos, const Color &c) : _pos(pos), _color(c) {}
	virtual ~Obj() = default;
	const Vec3<double> &getPos() { return (_pos); }
	virtual double intersect(const Vec3<double> &origin, const Vec3<double> &vdir) = 0;
	const Color &getColor() const { return (_color); }
protected:
	Color _color;
	Vec3<double> _pos;
};

#endif /* _OBJ_HPP */