#include <string>

#include "gameobject.hpp"

namespace palla {

const std::string GameObject::name() const {
    return n;
};
const std::string GameObject::description() const {
    return d;
};

GameObject::GameObject(const std::string& nme, const std::string& desc) : n(nme), d(desc) { };

GameObject::GameObject(const GameObject& o) : n(o.name()), d(o.description()) { };

}
