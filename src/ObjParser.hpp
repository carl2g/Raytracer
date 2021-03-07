#ifndef _OBJ_PARSER
	#define _OBJ_PARSER

#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include "Obj.hpp"
#include "Vec3.hpp"
#include "Triangle.hpp"

class ObjParser {
public:
	ObjParser(const std::string &file) : _file(file) {};
	~ObjParser() = default;
	std::vector<std::shared_ptr<Obj>> get_objects();
private:
	std::string _file;
};

#endif // _OBJ_PARSER