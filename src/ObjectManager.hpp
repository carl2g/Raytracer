#ifndef _OBJ_MANAGER_HPP
	# define _OBJ_MANAGER_HPP

#include "Obj.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include <vector>
#include <memory>

class ObjectManager {
public:
	ObjectManager() {};
	~ObjectManager() = default;
	void addObject(std::unique_ptr<Obj> to_add);
	std::tuple<Obj const *, double> getClosestIntersection(const Vec3<double> &origin, const Vec3<double> &rd);
	double getLightCoef(const Vec3<double> &origin, const Obj &obj, Light &l);

// private:
	std::vector<std::unique_ptr<Obj>> _manager;
};

#endif /* _OBJ_Manager_HPP */