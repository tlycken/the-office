#include <iostream>
#include <sstream>
#include <vector>

#include "iointerface.hpp"
#include "controller.hpp"
#include "model.hpp"

using namespace std;
using namespace palla;
int main() {
	Model m;

	Controller c;

	c.play_game();

    return 0;
}
