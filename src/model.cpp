#include <algorithm>

#include "model.hpp"
#include "gamestate.hpp"
#include "environment.hpp"

namespace palla {

void Model::connect_neighbors(const std::string& d1, Environment& e1, const std::string& d2, Environment& e2) {
	e1.neighbors[d1] = &e2;
	e2.neighbors[d2] = &e1;
};

void Model::swap(Model& other) {
	std::swap(*this, other);
};

Model::Model() {
	auto pavement = new Environment("trottoar", "Trottoaren utanför Gustavssons hus.");
	auto crossing = new Environment("övergångsställe", "Ett övergångsställe en bit ner för vägen.");
	auto otherside = new Environment("trottoar2", "Andra sidan gatan.");
	
	connect_neighbors("ö", *pavement, "v", *crossing);
	connect_neighbors("s", *crossing, "n", *otherside);
	
	locations.push_back(pavement);
	locations.push_back(crossing);
	locations.push_back(otherside);
	
	state.current_location = pavement;
};

Model::Model(const Model& rhs) {
	// Copy all locations, ignore neighbor relations for now
	for (auto l : rhs.locations) {
		locations.push_back(new Environment(*l));
	}
	
	// Make sure all neighbor relations point to locations on this model
	for (auto location : locations) {
		for (auto neighbor : location->neighbors) {
			Environment* correct_neighbor = *find_if(locations.begin(), locations.end(),
											[neighbor](Environment* loc)-> bool { return neighbor.second->name() == loc->name(); });
			neighbor.second = correct_neighbor;
		}
	}
};
Model& Model::operator =(const Model& rhs) {
	Model temp(rhs);
	swap(temp);
	return *this;
};

Model::~Model() {
	for (auto l : locations) {
		delete l;
	}
};

Environment* Model::get_current_location() {
	return state.current_location;
};

Environment* Model::get_location(const std::string& name) {
	auto en = *find_if(locations.begin(), locations.end(), [name](Environment* l) -> bool { return l->name() == name; });
	return en;
};

}
