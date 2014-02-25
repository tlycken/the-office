#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "environment.hpp"

namespace palla {
	
class GameState {
public:
	Environment* current_location;	
	
	GameState();

	GameState(const GameState&);
	GameState& operator= (const GameState&);
	~GameState();
};
	
}

#endif
