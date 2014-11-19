#include <iostream>
using namespace std;
int main() {
	double a, sum;
	sum = 0;
	for(int i=0; i<12; ++i) {
		cin >> a;
		sum += a;
	}
	sum /= 12;
	sum *= 100;
	int base = (int)sum;
	double diff = sum - base;
	if(diff >=0.5) {
		++base;
	}
	cout << "$" << base/100 << "." << (base % 100) / 10 << base % 10 << endl;
}

