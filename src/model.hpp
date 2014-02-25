#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>

#include "gamestate.hpp"
#include "environment.hpp"

namespace palla {

class Model {

private:
	std::vector<Environment*> locations;
	GameState state;
	
	// Init helpers
	void connect_neighbors(const std::string&, Environment&, const std::string&, Environment&);

	// Uses the copy-and-swap idiom
	// http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Copy-and-swap
	void swap(Model&);

public:
	Model();
	Model(const Model&);
	Model& operator = (const Model&);
	~Model();
	
	Environment* get_current_location();
	Environment* get_location(const std::string&);
	bool game_over();
};

}

#endif
