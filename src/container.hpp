#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <string>
#include <vector>

#include "object.hpp"

namespace palla {
	
	class Container : Object {
		private:
			std::vector<Object*> contents;
			double weight_capacity;
			double volume_capacity;
			bool hard;
			
		public:
			Container(std::string, std::string, double, double, double, double, bool);
			
			double weight() const;
			double volume() const;
			
			bool add(Object);
			bool remove(Object);
	};
	
}

#endif
