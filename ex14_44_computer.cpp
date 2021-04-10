#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


// add a to b
int add(int a, int b)
{
	return a + b;
}

map<string, function<int (int, int)>> binops = {
	{"+", add},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"*", [](int i, int j) { return i * j; }},
    {"%", modulus<int>()}
};

int main() 
{
	int left, right;
	string fu;
	cin >> left >> fu >> right;
    cout << binops[fu](left, right) << endl;
    return 0;
}