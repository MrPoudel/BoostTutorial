# About C++ standard
# C++14 features

## 1. Digit separator

```
#include <iostream>
using namespace std;

int main() {

	auto x = 1'000'000;
	cout << x << endl;

	return 0;
}

```

## 2. Binary literals
- GCC compiler had this feature but not standardized, now C++14 have standardized it.
```
#include <iostream>
using namespace std;

int main() {

	int b1 = 0xFF;
	cout << b1 << endl;

	int b2 = 0b11111; // 0b or 0B
	cout << b2 << endl;

	return 0;
}
```

## 3. Depricated attribute/ keyword
- Attributes are allowed to use but discouraged for some reasons
- Compiler gives warning and if string literals are provided they are included in warnings ( explainning the reason)


```
#include <iostream>
using namespace std;

[[deprecated("This function will be replaced with template add function")]]
int add(int a, int b) {
		return a+b;
}

int main() {

	cout << add(1,2);

	return 0;
}
```

- Following can be depricated:

```
class, struct, union
tupedef
variable
non-static data member
function
namespace
enumerarion
enumerator
template specialization
```

## 4. Variable template
- Before C++14 we had function template and cass template, now we have variable template.

```
#include <iostream>
#include <limits>

using namespace std;

template <typename T>
T pi = T(3.1415926535897932384626433L);

int main() {

	cout.precision(std::numeric_limits<long double>::max_digits10);
	std::cout << pi<int> << endl;
	std::cout << pi<float> << endl;
	std::cout << pi<double> << endl;
	std::cout << pi<long double> << endl;

	return 0;
}
```

## 5. Generic lambda
- C++14  have generic/polymorphic lambda
- auto is allowed in the function return type.

```
#include <iostream>
#include <limits>

using namespace std;

int main() {

	auto add = [](auto x, auto y) { return x+y; };

	int a = 1, b = 2;
	std::string str1 = "CppNuts", str2 = "Rupesh";

	cout << add(a,b) << endl;
	cout << add(str1, str2) << endl;

	return 0;
}
```

## 6. Return Type Deduction
- Using an auto return type in C++14, the compiler will attempt to deduce the type for you.
a. auto 
b. decltype(auto)

- decltype(auto) is used if we want to use reference, const, volatile etc. 
  Examples:
  
//  const int x = 0;
//  auto x1 = x; // int
//  decltype(auto) x2 = x; // const int
//  int y = 0
//  int& y1 = y;
//  auto y2 = y1; // int
//  decltype(auto) y3 = y1 //int&

```
#include <iostream>
#include <limits>

using namespace std;

// Example 1
auto add(int a , int b) { return a+b; }

// example 2
decltype(auto) increment(int& a) { a++; return a; }
//auto& increment(int& a) { a++; return a; }

int main() {

	int x = 5;

	int& y = increment(x);
	cout << x << endl;
	cout << y << endl;

	return 0;
}
```

