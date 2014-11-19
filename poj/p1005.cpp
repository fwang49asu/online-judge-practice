#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
using namespace std;

int main() {
	int N;
	double x, y;
	cin >> N;
	for(int i=1; i<=N; ++i) {
		cin >> x >> y;
		double rsq = x*x + y*y;
		double x = M_PI * rsq / 100;
		int result = (int)ceil(x);
		cout << "Property " << i << ": This property will begin eroding in year " << result << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
