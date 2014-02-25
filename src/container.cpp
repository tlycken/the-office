#include <string>
#include <vector>

#include "container.hpp"

namespace palla {
	
	Container::Container(std::string nme, std::string desc, double wght, double vol, double wght_cap, double vol_cap, bool h) : Object(nme, desc, wght, vol) {
		weight_capacity = wght_cap;
		volume_capacity = vol_cap;
		hard = h;
	}
	
	double Container::weight() const {
		double totw = w;
		
		for (auto it = contents.begin(); it != contents.end(); ++it) {
			totw += (*it)->weight();
		}
		
		return totw;
	}
	
	double Container::volume() const {
		if (hard) {
			return v;
		}
		
		double totv = v;
		
		for (auto it = contents.begin(); it != contents.end(); ++it) {
			totv += (*it)->volume();
		}
		
		return totv;
	}
	
	bool add(Object o) {
		return false;
	}

	bool remove(Object o) {
		return false;
	}
}
