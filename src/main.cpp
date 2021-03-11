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
	SDLWin win("My window", {1400, 800});
	Camera *cam = new Camera({-80, 0, 10}, {1400, 800});
	ObjectManager &&man = ObjectManager();

	// std::unique_ptr<Obj> tr(new Triangle({0, 0, 0}, {0, 20, 0}, {0, 20, 20}, {255, 180, 60, 185}));
	std::unique_ptr<Obj> pl1(new Plane({0, 0, -10}, {0.0, 0.0, 1}, {35, 180, 60, 185}));
	std::unique_ptr<Obj> pl2(new Plane({0, 0, 40}, {0.0, 0.0, -1}, {255, 188, 34, 255}));
	std::unique_ptr<Obj> pl3(new Plane({40, 0, 0}, {-1.0, 0.0, 0}, {255, 255, 255, 255}));
	std::unique_ptr<Obj> pl4(new Plane({0, -30, 0}, {0.0, 1.0, 0}, {183, 23, 183, 129}));
	std::unique_ptr<Obj> pl5(new Plane({0, 20, 0}, {0.0, -1.0, 0}, {55, 10, 160, 205}));
	std::unique_ptr<Obj> sp(new Sphere({0 ,0 , 0}, 10, {255, 0, 0, 255}));
	auto l = Light({-20 , -15, 5}, 30);

	ObjParser objp = ObjParser("./assets/cube.obj");
	// man._manager = objp.get_objects();
	man.addObject(std::move(pl1));
	man.addObject(std::move(pl2));
	man.addObject(std::move(pl3));
	man.addObject(std::move(pl4));
	man.addObject(std::move(pl5));
	man.addObject(std::move(sp));


	while (!win._quitWin) {
		win.windowBlock(*cam);
		if (win._update) {
			for (int i = 0; i < 1400 * 800; ++i) {
				auto &&cam_pos = cam->getPos();
				auto &&cam_vec = cam->getVecAtPixel(i);
				auto &&tup = man.getClosestIntersection(cam_pos, cam_vec);
				auto &&obj = std::get<0>(tup);
				auto &&t = std::get<1>(tup);

				if (t >= 0) {
					auto &&inter_point = cam_pos + cam_vec * t;
					auto &&coef = man.getLightCoef(inter_point, *obj, l);
					auto &&color = obj->getColor();
					win.setBufferPixel(i, Color(color.getR() * coef, color.getG() * coef, color.getB() * coef, color.getA() * coef));
					// win.setBufferPixel(i, Color(color.getR(), color.getG(), color.getB(), color.getA()));
				} else {
					win.setBufferPixel(i, Color(0, 0, 0, 0));
				}
			}
			std::cout << "update" << std::endl;
			win.updateWin();
			win._update = false;
		}
	}
	// th1.join();
	return (0);
}