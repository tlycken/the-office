#include "actor.hpp"

namespace palla {
	
Actor::Actor(std::string n, std::string t, std::string d) : GameObject(n, d) {
	type = t;
};

}
