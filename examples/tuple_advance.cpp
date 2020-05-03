#include <boost/tuple/tuple.hpp>
#include <iostream>

using namespace std;

template <int I>
struct printer {
    printer() { std::cout << I; }

    void display(){
        cout << "Hey, there" << endl;
    }
};

int main() {
    // Outputs 012
    boost::tuple<printer<0>, printer<1>, printer<2> > t;

    printer<0> p = boost::get<0>(t);
    p.display();
    
    return 0;
}
