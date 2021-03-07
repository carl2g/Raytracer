#ifndef _OBJ_MANAGER_HPP
	# define _OBJ_MANAGER_HPP

#include "Obj.hpp"
#include "Camera.hpp"
#include <vector>
#include <memory>

class ObjectManager {
public:
	ObjectManager() {};
	~ObjectManager() = default;
	void addObject(std::unique_ptr<Obj> to_add);
	std::tuple<std::shared_ptr<Obj>, double> getClosestIntersection(Camera &cam, int pixel);
// private:
	std::vector<std::shared_ptr<Obj>> _manager;
};

#endif /* _OBJ_Manager_HPP */