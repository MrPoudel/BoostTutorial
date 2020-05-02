#include <boost/program_options.hpp>
#include <iostream>
#include <exception>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{

    try {
        // Constructing an options describing variable and giving it a
        // textual description "All options".
        opt::options_description descri("All options");

        // When we are adding options, first parameter is a name
        // to be used in command line. Second parameter is a type
        // of that option, wrapped in value<> class. Third parameter
        // must be a short description of that option.
        descri.add_options()
            ("apples", opt::value<int>(), "how many apples do you have")
            ("oranges", opt::value<int>(), "how many oranges do you have")
            ("mangoes", opt::value<int>(), "how many mangoes do you have")
            ("help", "produce help message")
        ;

        // Variable to store our command line arguments.
        opt::variables_map vm;

        // Parsing and storing arguments.
        opt::store(opt::parse_command_line(argc, argv, descri), vm);

        // Must be called after all the parsing and storing.
        opt::notify(vm);

        if (vm.count("help") || (argc <= 3)) {
            std::cout << descri << "\n";
            return 1;
        }

        std::cout << "Fruits count: "
            << vm["apples"].as<int>() + vm["oranges"].as<int>() + vm["mangoes"].as<int>()
            << std::endl;
    }
    catch(exception& e){
        cerr << "error:" << e.what() << endl;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
        return 1;
    }

} // end of `main`

