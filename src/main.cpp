/*
* @Author: carl de gentile
* @Date:   2018-06-01 20:27:05
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-06-21 12:32:35
*/

#include <thread>
#include "SDLWin.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Triangle.hpp"

int main(int ac, char **av)
{
	SDLWin win("My window", {1200, 800});
	std::thread th1 (&SDLWin::launchWin, &win);
	Camera cam({-50, 0, 10}, {1200, 800});
	Sphere sp({0 ,0 , 10}, 20, {255, 0, 0, 255});
	Plane pl({0, 0, 0}, {0, 0, 1}, {255, 180, 60, 185});
	Triangle tr = Triangle({-30, -20, 0}, {-30, 20, 0}, {50, 20, 2});
	for (int i = 0; i < 1200 * 800; ++i) {
		double t = tr.intersect(cam.getPos(), cam.getVecAtPixel(i));

		if (t > 0) {
			win.setBufferPixel(i, pl.getColor());
		}

		double a = sp.intersect(cam.getPos(), cam.getVecAtPixel(i));
		double b = pl.intersect(cam.getPos(), cam.getVecAtPixel(i));

		if (t > 0.0)
			win.setBufferPixel(i, pl.getColor());
		if (a >= 0.0) {
			if (t < 0)
				win.setBufferPixel(i, sp.getColor());
			if (a < t)
				win.setBufferPixel(i, sp.getColor());
		}
	}
	win.updateWin();
	th1.join();
	return (0);
}