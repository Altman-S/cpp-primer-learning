#include <iostream>
#include <string>
using namespace std;
class Y;
class X {
public:
	Y *y;
};

class Y {
public:
	X x;
};
