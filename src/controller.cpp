#include <cstdlib>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

#include "controller.hpp"
#include "iointerface.hpp"

namespace palla {

Controller::player_command::player_command(const Controller::cmd_t& c, const help_message& h) : cmd(c), help(h) { };

Controller::help_message::help_message(const std::string& s, const std::string& d) : summary(s), details(d) { };

Controller::Controller() : commands() {
    // Initialize the command map. This is where we define all available commands.
    add_cmd("?", &palla::Controller::help, "Visa denna hjälptext");
    add_cmd("quit", &palla::Controller::quit, "Avsluta spelet");
    add_cmd("setw", &palla::Controller::setw, "Sätt bredd på första kolumnen", "setw <width>\nSätter bredd på första kolumnen i hjälpmeddelandet till antalet tecken specificerat av parametern <width>.");
    add_cmd("look", &palla::Controller::look, "Se dig omkring");
};

void Controller::initialize_game(Model& m) {
    model = m;
};

void Controller::play_game() {
    // Ask for new commands until the quit command is given (it exits with status code 0)
    while(action() && !model.game_over())
		;
};

bool Controller::action() {
    // Handle one game turn
    IOInterface::command cmd = io.getcmd();

    auto it = commands.find(cmd.name);
    if (it != commands.end()) {
        return (this->*((it->second).cmd))(cmd.args);
    } else {
        unknown_cmd();
		return false;
    }
};

bool Controller::help(const Controller::args_t& args) {
    if (args.size() > 0) {
        // If an argument was given, display the specific help for that command
        auto pred = [args] (std::pair<std::string, player_command> p) -> bool { return p.first == args[0]; };
        auto p = std::find_if(
                     commands.begin(),
                     commands.end(),
                     pred);
        if (p != commands.end()) {

            io.println(p->second.help.summary);
            io.println();
            io.println(p->second.help.details);
        } else {
            unknown_cmd();
        }
    } else {
        // If no argument was given, loop through all commands and output their names and help texts
		for (auto pair : commands) {
            io.println(std::pad(pair.first, io.COL_W) + pair.second.help.summary);
        }
    }
    return true;
};

bool Controller::look(const Controller::args_t& args) {
    // BUG: this currently types out an empty line
    io.println(model.get_current_location()->description());
    return true;
};

bool Controller::setw(const Controller::args_t& args) {
    // Debug function for testing what padding widths are appropriate for help
    if (args.size() < 1) {
        unknown_cmd();
        return true;
    }

    //~ io.COL_W = std::strtol(args[0].c_str(), 0, 0);
    io.COL_W = atoi(args[0].c_str());
    if (io.COL_W < 1) {
        io.COL_W = 15;
    }
    
    return true;
};

bool Controller::quit(const Controller::args_t& args) {
    // Is there a nicer way to do this?
    // Preferably one that doesn't require every action method to return a boolean...
    return false;
};

void Controller::add_cmd(const std::string& name, const Controller::cmd_t& cmd, const std::string& helptext) {
    add_cmd(name, cmd, helptext, "");
};

void Controller::add_cmd(const std::string& name, const Controller::cmd_t& cmd, const std::string& helptext, const std::string& details) {
    help_message hlp(helptext, details);
    add_cmd(name, cmd, hlp);
};

// Helper method for adding commands to map
void Controller::add_cmd(const std::string& name, const Controller::cmd_t& cmd, const Controller::help_message& help) {
    commands.insert(std::make_pair(name, player_command(cmd, help)));
};

void Controller::unknown_cmd() {
    // This method can be called whenever we don't understand input
    io.println("Jag förstår inte - skriv ? för hjälp.");
};

}
