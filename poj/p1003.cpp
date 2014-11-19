#include <iostream>
using namespace std;

inline int cards(double a) {
	int result = 1;
	double base = 2.0;
	double sum = 0.5;
	for(; sum < a; ++result, ++base, sum += 1/base);
	return result;
}

int main() {
	double a;
	cin >> a;
	while(a > 0.001) {
		cout << cards(a) << " card(s)" << endl;
		cin >> a;
	}
	return 0;
}
