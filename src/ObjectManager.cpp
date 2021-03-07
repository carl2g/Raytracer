#include "ObjectManager.hpp"

void ObjectManager::addObject(std::unique_ptr<Obj> to_add) {
	_manager.push_back(std::move(to_add));
}

std::tuple<std::shared_ptr<Obj>, double> ObjectManager::getClosestIntersection(const Vec3<double> &origin, const Vec3<double> &rd) {
	double t = -1.0;
	auto o = std::shared_ptr<Obj>(nullptr);
	for (int i = 0; i < _manager.size(); ++i) {
		auto a = _manager[i];
		double tmp = a->intersect(origin, rd);
		if ((tmp >= 0.0 && t > tmp) || (t < 0.0 && tmp >= 0.0)) {
			t = tmp;
			o = a;
		}
	}
	return(std::make_tuple(o, t));
};

double ObjectManager::getLightCoef(Vec3<double> &origin, Obj &obj, Light &l) {
	auto rd = l.getPos() - origin;
	auto &&norm = obj.getNormalVect(origin);
	auto angle = norm->getAngle(rd);
	auto tup = this->getClosestIntersection(origin + (*norm) * 0.00001, rd);
	auto &t = std::get<1>(tup);

	if (t >= 0) {
		return (0.5);
	}

	return (1.0 - (angle / M_PI ));
};
