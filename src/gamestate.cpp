#include "gamestate.hpp"

namespace palla {

GameState::GameState() : current_location(0) { };

GameState::GameState(const GameState& rhs) {
	*current_location = *(rhs.current_location);
};

GameState& GameState::operator =(const GameState& rhs) {
	*current_location = *(rhs.current_location);
	return *this;
};

GameState::~GameState()  {
};

}
