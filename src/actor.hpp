#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "gameobject.hpp"


namespace palla {
	
class Actor : public GameObject {
private:
	std::string type;
		
public:
	Actor(std::string, std::string, std::string);
	
};
	
}

#endif
