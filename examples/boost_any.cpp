#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void example();

int main() {
    std::vector<boost::any> some_values;
    some_values.push_back(10);
    const char* c_str = "Hello there!";
    some_values.push_back(c_str);
    some_values.push_back(std::string("Wow!"));   

    std::string& s = boost::any_cast<std::string&>(some_values.back());
    s += " That is great!\n";
    std::cout << s;

    some_values.push_back(977.8f);

    if (some_values.back().type() == typeid(float)) {
        cout << boost::any_cast<float&> (some_values.back()) << std::endl;
    }

    example();
}

void example() {
    boost::any variable(std::string("Hello world!"));

    // Following method may throw a boost::bad_any_cast exception
    // if actual value in variable is not a std::string.
    std::string s1 = boost::any_cast<std::string>(variable);

    // Never throws. If actual value in variable is not a std::string
    // will return an NULL pointer.
    std::string* s2 = boost::any_cast<std::string>(&variable);

    std::cout << *s2 << std::endl;


    (void)s2; // Supressing warnings about unused variable
    (void)s1;
}
