/*
* @Author: carl de gentile
* @Date:   2018-06-02 12:13:05
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-06-03 16:24:45
*/

#include "Camera.hpp"

Camera::Camera(const v3<double> &pos, PairInt screenSize) : Obj(pos, {0, 0, 0, 0})
{
	int axis_x = screenSize.first / 2;
	int axis_y = screenSize.second / 2;
	for (int y = -axis_y; y < axis_y; ++y) {
		for (int x = -axis_x; x < axis_x; ++x) {
			_vision.push_back(std::make_unique<v3<double>>(800, x, y));
		}
	}
}

const v3<double> Camera::getRay(const v3<double> &dest)
{
	return {dest._x - _pos._x, dest._y - _pos._y, dest._z - _pos._z};
}

const v3<double> &Camera::getVecAtPixel(int pixel)
{
	return (*_vision[pixel]);
}