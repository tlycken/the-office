#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>

namespace palla {

class GameObject {
private:
	std::string n;
    std::string d;

public:
	const std::string name() const;
	const std::string description() const;

protected:
    GameObject(const std::string&, const std::string&);
    GameObject(const GameObject&);
};

}

#endif
