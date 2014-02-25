#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

#include "gameobject.hpp"

namespace palla {
	
	class Object : GameObject {
		protected:
			double v;
			double w;
			
		public:
			virtual double volume() const;
			virtual double weight() const;
			
			Object(std::string, std::string, double, double);
	};
	
}
#endif
