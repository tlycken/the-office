#include "environment.hpp"

namespace palla {
	
void Environment::swap(Environment& e) {
	std::swap(*this, e);
};
	
Environment::Environment() : GameObject("default_name", "default description") { 
};

Environment::Environment(const std::string& nme, const std::string& desc) : GameObject(nme, desc) { };

Environment::Environment(const Environment& e) : GameObject(e) {
	for(auto n : e.neighbors) {
		neighbors[n.first] = n.second;
	}
};

Environment& Environment::operator =(const Environment& e) {
	Environment temp(e);
	swap(temp);
	return *this;
};

Environment::~Environment() {
};

}
