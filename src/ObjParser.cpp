#include "ObjParser.hpp"

std::vector<std::unique_ptr<Obj>> ObjParser::get_objects() {

	std::ifstream infile(this->_file);
	std::vector<std::unique_ptr<Obj>> objs;
	std::vector<Vec3<double>> vec;
	
	double a, b, c = 0.0;
	
	std::string s = "";

	while (getline(infile, s)) {
		std::string tmp = s.substr(0, s.find(' '));
		if (tmp == "v") {
			s.erase(0, s.find(' ') + 1);
			a = std::stod(s.substr(0, s.find(' ')));
			s.erase(0, s.find(' ') + 1);
			b = std::stod(s.substr(0, s.find(' ')));
			s.erase(0, s.find(' ') + 1);
			c = std::stod(s.substr(0, s.find(' ')));

			vec.push_back(
				Vec3<double>(a, b, c)
			);
		} else if (tmp == "f") {
			
			s.erase(0, s.find(' ') + 1);
			auto info1 = s.substr(0, s.find(' '));
			int i1 = std::stoi(info1.substr(0, s.find('/')));
			
			s.erase(0, s.find(' ') + 1);
			auto info2 = s.substr(0, s.find(' '));
			int i2 = std::stoi(info2.substr(0, s.find('/')));

			s.erase(0, s.find(' ') + 1);
			auto info3 = s.substr(0, s.find(' '));
			int i3 = std::stoi(info3.substr(0, s.find('/')));

			objs.push_back(
				std::unique_ptr<Triangle>(new Triangle(vec[i1-1], vec[i2-1], vec[i3-1], {255, 180, 60, 185}))
			);
		}
	}
	return (std::move(objs));
}
