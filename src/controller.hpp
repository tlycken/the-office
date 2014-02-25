#ifndef CONTROLLER2_HPP
#define CONTROLLER2_HPP

#include <string>
#include <map>
#include <vector>

#include "iointerface.hpp"
#include "model.hpp"

namespace palla {

class Controller {
	// Types for arguments and command function
    typedef std::vector<std::string> args_t;
    typedef bool (palla::Controller::*cmd_t)(const args_t&);

	// Struct for help messages
	struct help_message {
		std::string summary;
		std::string details;
		help_message(const std::string&, const std::string&);
	};

	// Struct for command including name, function ptr and help text
	struct player_command {
		cmd_t cmd;
		help_message help;
		player_command(const cmd_t&, const help_message&);
	};

	// Type for map
    typedef std::map<std::string, player_command> cmd_map;

private:
    IOInterface io;
    cmd_map commands;
    Model model;

    bool action();
    void unknown_cmd();
    void add_cmd(const std::string&, const cmd_t&, const std::string&);
    void add_cmd(const std::string&, const cmd_t&, const std::string&, const std::string&);
    void add_cmd(const std::string&, const cmd_t&, const help_message&);

public:
    Controller();

	void initialize_game(Model&);
    void play_game();

    bool help(const args_t&);
    bool look(const args_t&);
    bool quit(const args_t&);
    bool setw(const args_t&);
};

}

#endif
