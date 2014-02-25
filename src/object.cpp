#include <string>

#include "object.hpp"

namespace palla {
	
	double Object::weight() const {
		return w;
	}
	
	double Object::volume() const {
		return v;
	}
	
	Object::Object(std::string nme, std::string desc, double vol, double wght) : GameObject(nme, desc) {
		v = vol;
		w = wght;
	}
}
