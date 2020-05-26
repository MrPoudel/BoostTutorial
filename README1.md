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

3. Depricated attribute/ keyword
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


