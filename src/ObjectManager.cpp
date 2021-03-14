#include "ObjectManager.hpp"


const Color ObjectManager::getColor(const Vec3<double> &origin, const Vec3<double> &rd, const Light &l, int z) {

	auto &&tup = this->getClosestIntersection(origin, rd);

	auto &&obj = std::get<0>(tup);
	auto &&t = std::get<1>(tup);
	

	if (t >= 0) {

		auto &&hit_point = origin + rd * t;
		auto &&coef = getLightCoef(hit_point, *obj, l);
		auto &color = obj->getColor() * coef;
		
		if (z > 5) {
			return color;
		}
		
		auto &&obj_norm = obj->getNormalVect(hit_point);
		
		auto &&adj = *obj_norm * rd.dot(*obj_norm);
		auto &&ref_vect = rd - adj * 2;
		auto &&ref_coef = obj->getReflection();
		if (ref_coef > 0) {
			return (color * (1.0 - ref_coef) + getColor(hit_point + *obj_norm * 0.0001, ref_vect, l, z+1) * ref_coef);
		}
		// std::cout << z << " " << tmp.getR() << " " << tmp.getG() << " " << tmp.getB() << " " << tmp.getA() << std::endl;
		return (color);
	}
	return {0, 0, 0, 0};
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

double ObjectManager::getLightCoef(const Vec3<double> &origin, const Obj &obj, const Light &l) {
	auto &&rd = l.getPos() - origin;
	auto &&norm = obj.getNormalVect(origin);

	auto &&angle = norm->getAngle(rd);
	auto &&tup = this->getClosestIntersection(origin + *norm * 0.0001, rd);
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
