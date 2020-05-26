# About C++ standard
# C++14 features

1. Digit separator

```
#include <iostream>
using namespace std;

int main() {

	auto x = 1'000'000;
	cout << x << endl;

	return 0;
}

```

2. Binary literals
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
