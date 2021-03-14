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
	Camera *cam = new Camera({-100, 0, 10}, {1400, 800});
	ObjectManager &&man = ObjectManager();

	auto l = Light({-20 , -15, 15}, 1000);

	// ObjParser objp = ObjParser("./assets/cube.obj");
	// man._manager = objp.get_objects();
	man.addObject<Plane>(Vec3<double>(0, 0, -10), Vec3<double>(0.0, 0.0, 1), Color(35, 180, 60, 185), 0.3);
	// man.addObject<Plane>(Vec3<double>(0, 0, 40), Vec3<double>(0.0, 0.0, -1.0), Color(255, 188, 34, 255), 0.0);
	// man.addObject<Plane>(Vec3<double>(40, 0, 0), Vec3<double>(-1.0, 0.0, 0), Color(255, 255, 255, 255), 0.0);
	// man.addObject<Plane>(Vec3<double>(0, -50, 0), Vec3<double>(0.0, 1.0, 0), Color(183, 23, 183, 129), 0.0);
	// man.addObject<Plane>(Vec3<double>(0, 20, 0), Vec3<double>(0.0, -1.0, 0), Color(55, 10, 160, 205), 0.0);
	man.addObject<Sphere>(Vec3<double>(0 ,0 , 0), 10, Color(255, 0, 0, 255), 0.0);

	while (!win._quitWin) {
		win.windowBlock(*cam);
		if (win._update) {
			for (int i = 0; i < 1400 * 800; ++i) {
				auto &&cam_pos = cam->getPos();
				auto &&cam_vec = cam->getVecAtPixel(i);

				auto &&color = man.getColor(cam_pos, cam_vec, l);
				win.setBufferPixel(i, color);
			}
			std::cout << "update" << std::endl;
			win.updateWin();
			win._update = false;
		}
	}
	// th1.join();
	return (0);
}