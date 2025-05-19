/*
How it works:
- Doesn't create a new, distinct type.
- Instead it simply introduces a new name for an exsisting type.
*/

#include <iostream>
using Miles = long;
using Speed = long;

int main() {
	Miles dist{5};
	Speed mhz{3200};

	dist = mhz; // Seems confusing but since they're both type long we can do this.
	
	return 0;
}

// Use them for readability, maintainability, and portability
// - Especially because diff OS have diff sizes for their types.

// Can also use typedefs instead
/*
typedef int Age;
Age myAge = 30; // Equivalent to int myAge = 30;
*/