/*
* @Author: carl de gentile
* @Date:   2018-06-01 20:27:05
* @Last Modified by:   carl de gentile
* @Last Modified time: 2018-06-03 16:21:36
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
	Camera cam({0, 0, 0}, {1200, 800});
	Plane pl({0, 0, -5});
	Sphere sp({-50 ,0 ,0}, 10, {255, 0, 0, 255});
	for (int i = 0; i < 1200 * 800; ++i) {
		if (sp.intersect(cam.getPos(), cam.getVecAtPixel(i)) >= 0)
			win.setBufferPixel(i, sp.getColor());
		if (pl.intersect(cam.getPos(), cam.getVecAtPixel(i)) >= 0)
			win.setBufferPixel(i, pl.getColor());
	}
	win.updateWin();
	th1.join();
	return (0);
}