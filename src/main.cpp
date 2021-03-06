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

int main(int ac, char **av)
{
	SDLWin win("My window", {1200, 800});
	std::thread th1 (&SDLWin::launchWin, &win);
	Camera cam({-50, 0, 10}, {1200, 800});
	Sphere sp({0 ,0 , 0}, 20, {255, 0, 0, 255});
	Plane pl({0, 0, 0}, {0, 0, 1}, {255, 180, 60, 185});
	for (int i = 0; i < 1200 * 800; ++i) {
		double a = sp.intersect(cam.getPos(), cam.getVecAtPixel(i));
		double b = pl.intersect(cam.getPos(), cam.getVecAtPixel(i));
		
		if (b >= 0.0)
			win.setBufferPixel(i, pl.getColor());
		if (a >= 0.0) {
			if (b < 0)
				win.setBufferPixel(i, sp.getColor());
			if (a < b)
				win.setBufferPixel(i, sp.getColor());
		}
	}
	win.updateWin();
	th1.join();
	return (0);
}