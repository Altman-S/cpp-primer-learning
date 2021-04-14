#include <iostream>
#include <vector>
using namespace std;

int fuc1(int a, int b) {
    return a + b;
}
int fuc2(int a, int b) {
	return a - b;
}
int fuc3(int a, int b) {
	return a * b;
}
int fuc4(int a, int b) {
	return a / b;
}

//必须要用decltype，不然会报错
int main() {
    decltype(fuc1) *p1 = fuc1, *p2 = fuc2, *p3 = fuc3, *p4 = fuc4;
    vector<decltype(fuc1)*> fs = {p1, p2, p3, p4};
    int x, y;
    cout << "Please enter two numbers:";
    cin >> x >> y;
   
    for (auto i = fs.begin(); i != fs.end(); ++i) {
    	cout << (*i)(x, y) << endl;
    }
    return 0;
}