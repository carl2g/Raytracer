#include "ObjectManager.hpp"

void ObjectManager::addObject(std::unique_ptr<Obj> to_add) {
	_manager.push_back(std::move(to_add));
}

std::tuple<std::shared_ptr<Obj>, double> ObjectManager::getClosestIntersection(Camera &cam, int pixel) {
	double t = -1.0;
	auto o = std::shared_ptr<Obj>(nullptr);
	for (int i = 0; i < _manager.size(); ++i) {
		auto a = _manager[i];
		double tmp = a->intersect(cam.getPos(), cam.getVecAtPixel(pixel));

		if ((tmp >= 0.0 && t > tmp) || (t < 0.0 && tmp >= 0.0)) {
			t = tmp;
			o = a;
		}
	}
	return(std::make_tuple(o, t));
};
