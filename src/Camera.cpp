/*
* @Author: carl de gentile
* @Date:   2018-06-02 12:13:05
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-07-01 13:03:46
*/

#include "Camera.hpp"

Camera::Camera(const Vec3<double> &pos, PairInt screenSize) : Obj({0, 0, 0, 0}), _pos(pos)
{
	int axis_x = screenSize.first / 2;
	int axis_y = screenSize.second / 2;

	for (int z = -axis_y; z < axis_y; ++z) {
		for (int y = -axis_x; y < axis_x; ++y) {
			_vision.push_back(std::make_unique<Vec3<double>>(800, y, -z));
		}
	}
}

const Vec3<double> Camera::getRay(const Vec3<double> &dest)
{
	return {_pos._x + dest._x, _pos._y + dest._y, _pos._z + dest._z};
}

const Vec3<double> &Camera::getVecAtPixel(int pixel)
{
	return (*_vision[pixel]);
}