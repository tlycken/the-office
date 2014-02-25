#ifndef IOINTERFACE_HPP
#define IOINTERFACE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>


namespace palla {


template <typename T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

class IOInterface {
public:
	long COL_W = 15;
			
    struct command {
        std::string name;
        std::vector<std::string> args;
    };

    template<typename T>
    void println(const T& s) {
        println(to_string(s));
    }

    void println(std::string s = "") {
        std::cout << s << std::endl;
    }

    command getcmd() {
        // Give some output that shows that we're waiting for input
        std::cout << "> ";

		// Instantiate the struct
        command cmd;
        
        // Fetch command name (i.e. the first word of input)
        std::cin >> cmd.name;

		// Fetch comamnd arguments (i.e. remaining parts of input)
        std::string input;
        std::getline(std::cin, input);

        // Split commands into vector
        // Code snippet below taken from http://stackoverflow.com/a/237280/38055
        std::istringstream iss(input);
        std::copy(std::istream_iterator<std::string>(iss),
                  std::istream_iterator<std::string>(),
                  std::back_inserter<std::vector<std::string> >(cmd.args));

		// Return
        return cmd;
    }
    
    
};

}

namespace std {
inline string pad(string s, int w) {
	stringstream ss;
	ss << left << setw(w) << s;
	return ss.str();
};
}
#endif
