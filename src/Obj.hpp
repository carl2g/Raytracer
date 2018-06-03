#ifndef _OBJ_HPP
	# define _OBJ_HPP

# include <iostream>
# include <math.h>

template<typename T1>
class v3 {
public:
	v3() = default;
	v3(T1 x, T1 y, T1 z) : _x(x), _y(y), _z(z) {}
	~v3() = default;
	T1 	_x;
	T1 	_y;
	T1 	_z;
};

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
	Obj(const v3<double> &pos, const Color &c) : _pos(pos), _color(c) {}
	virtual ~Obj() = default;
	const v3<double> &getPos() { return (_pos); }
	virtual double intersect(const v3<double> &origin, const v3<double> &vdir) = 0;
	double solvedEq(const v3<double> &eq, double delt) {
		double 	root1;
		double 	root2;

		root1 = (-eq._y + sqrtf(delt)) / (2.0 * eq._x);
	      	root2 = (-eq._y - sqrtf(delt)) / (2.0 * eq._x);
	      	if (root1 < 0 && root2 < 0)
	      		return (-1);
	      	if (root1 < 0 || root2 < 0)
	      		return (root1 < root2 ? root2 : root1);
	      	return (root1 > root2 ? root2 : root1);
	}
	const Color &getColor() const { return (_color); }
protected:
	Color _color;
	v3<double> _pos;
};

#endif /* _OBJ_HPP */