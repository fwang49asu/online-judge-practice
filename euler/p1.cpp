#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	int result = 0;
	for(int i = 2; i < n; ++i) {
		if( i%3 == 0 || i%5 == 0) {
			result += i;
		}
	}
	cout << result << endl;
}
