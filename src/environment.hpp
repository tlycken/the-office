#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <map>
#include <string>

#include "gameobject.hpp"

namespace palla {

class Environment : public GameObject {
private:
	void swap(Environment& other);
	
public:
	Environment();
	Environment(const std::string&, const std::string&);
	Environment(const Environment&);
	Environment& operator =(const Environment&);
	~Environment();
	
	std::map<std::string, Environment*> neighbors;	
};

}

#endif
