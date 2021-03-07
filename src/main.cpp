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
#include "ObjectManager.hpp"
#include "ObjParser.hpp"
#include "Light.hpp"
#include <memory>

int main(int ac, char **av)
{
	SDLWin win("My window", {1400, 1000});
	std::thread th1 (&SDLWin::launchWin, &win);
	Camera cam({-50, 0, 10}, {1400, 1000});
	ObjectManager man = ObjectManager();

	// std::unique_ptr<Obj> tr(new Triangle({0, 0, 0}, {0, 20, 0}, {0, 20, 20}, {255, 180, 60, 185}));
	std::unique_ptr<Obj> pl(new Plane({0, 0, 1}, {0.0, 0.0, 1}, {255, 180, 60, 185}));
	std::unique_ptr<Obj> sp(new Sphere({0 ,0 , 0}, 10, {255, 0, 0, 255}));
	auto l = Light({0 , 20, 20});
	// man.addObject(std::move(tr));
	man.addObject(std::move(pl));
	man.addObject(std::move(sp));

	// ObjParser objp = ObjParser("./assets/monkey.obj");
	// man._manager = objp.get_objects();
	
	std::cout << "Begin calc" << std::endl;

	for (int i = 0; i < 1400 * 1000; ++i) {
		auto cam_pos = cam.getPos();
		auto cam_vec = cam.getVecAtPixel(i);
		auto tup = man.getClosestIntersection(cam_pos, cam_vec);
		auto obj = std::get<0>(tup);
		auto t = std::get<1>(tup);

		if (t >= 0) {
			auto inter_point = cam_pos + cam_vec * t;
			auto coef = man.getLightCoef(inter_point, *obj.get(), l);
			// std::cout << coef << std::endl;
			auto color = obj->getColor();
			win.setBufferPixel(i, Color(color.getR() * coef, color.getG() * coef, color.getB() * coef, color.getA() * coef));
		}
		// std::cout << i << std::endl;
	}
	win.updateWin();
	th1.join();
	return (0);
}