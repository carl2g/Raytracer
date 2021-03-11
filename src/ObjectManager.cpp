#include "ObjectManager.hpp"

void ObjectManager::addObject(std::unique_ptr<Obj> to_add) {
	_manager.push_back(std::move(to_add));
}

std::tuple<Obj const *, double> ObjectManager::getClosestIntersection(const Vec3<double> &origin, const Vec3<double> &rd) {
	double t = -1.0;
	int f = 0;
	
	for (int i = 0; i < _manager.size(); ++i) {
		auto &&a = _manager[i];
		auto &&tmp = a->intersect(origin, rd);
		if ((tmp >= 0.0 && t > tmp) || (t < 0.0 && tmp >= 0.0)) {
			t = tmp;
			f = i;
		}
	}
	return(std::make_tuple(_manager[f].get(), t));
};

double ObjectManager::getLightCoef(const Vec3<double> &origin, const Obj &obj, Light &l) {
	auto &&rd = l.getPos() - origin;
	auto &&norm = obj.getNormalVect(origin);

	auto &&tup = this->getClosestIntersection(origin + *norm * 0.0001, rd);
	auto &&angle = norm->getAngle(rd);
	auto &&t = std::get<1>(tup);

	auto &&dist_to_light = rd.norm();

	auto &&difuse = (1.0 - (1.75 * angle / M_PI));
	auto &&intensity = l.getIntensity();
	auto &&dist = intensity / (intensity + dist_to_light);
	
	if (t >= 0 && dist_to_light > (rd * t).norm()) {
		return (0.125 * dist);
	}
	
	auto &&coef = difuse * dist; 

	return (coef);
};
