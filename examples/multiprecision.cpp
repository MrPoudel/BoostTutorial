#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int128_t large_product(long long n1, long long n2) {
   int128_t ans = (int128_t) n1 * n2;
   return ans;
}
int main() {
   long long num1 = 98745636214564698;
   long long num2 = 7459874565236544789;
   cout << "Product of " << num1 << " * "<< num2 << " = " <<
   large_product(num1,num2);

   return 0;
}