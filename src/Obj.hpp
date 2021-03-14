#ifndef _OBJ_HPP
	# define _OBJ_HPP

# include <iostream>
# include <math.h>
# include <memory>
# include "Vec3.hpp"

class Color {
public:
	Color(int r, int g, int b, int a) : _r(r), _g(g), _b(b), _a(a) {};
	int getR() const { return _r; };
	int getG() const { return _g; };
	int getB() const { return _b; };
	int getA() const { return _a; };
	const Color operator*(const double t) const { return { (int)(_r * t), (int)(_g * t), (int)(_b * t), (int)(_a * t) }; };
	Color operator+(const Color &col) const { return {this->getR() + col.getR(), this->getG() + col.getG(), this->getB() + col.getB(), this->getA() + col.getA()}; };
private:
	int _r;
	int _g;
	int _b;
	int _a;
};

class Obj {
public:
	Obj(const Color &c, const double reflection_coef = 0) : _color(c), _reflection_coef(reflection_coef) {}
	virtual ~Obj() = default;
	virtual double intersect(const Vec3<double> &origin, const Vec3<double> &vdir) { return (-1.0); }
	virtual std::unique_ptr<Vec3<double>> getNormalVect(const Vec3<double> &origin) const = 0;
	const Color &getColor() const { return (_color); };
	const double getReflection() const { return this->_reflection_coef; };
protected:
	Color _color;
	double _reflection_coef;
};

#endif /* _OBJ_HPP */