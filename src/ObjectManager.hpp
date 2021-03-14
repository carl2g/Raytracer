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
	template<typename T, typename ... Args>
		void addObject(Args &&... args) {
			_manager.push_back(std::make_unique<T>(std::forward<Args>(args) ...));
		};
	std::tuple<Obj const *, double> getClosestIntersection(const Vec3<double> &origin, const Vec3<double> &rd);
	double getLightCoef(const Vec3<double> &origin, const Obj &obj, const Light &l);
	const Color getColor(const Vec3<double> &origin, const Vec3<double> &rd, const Light &l, int z = 0);


// private:
	std::vector<std::unique_ptr<Obj>> _manager;
};

#endif /* _OBJ_Manager_HPP */