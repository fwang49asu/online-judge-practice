#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
	int len = atoi(argv[1]);
	string str;
	cin >> str;
	int stop = str.length() - len;
	long long cMax = 0;
	for(int i=0; i<stop; ++i) {
		long long temp = 1;
		for(int k=0; k<len; k++) {
			temp *= (str[i+k] - '0');
		}
		if(temp > cMax) {
			cMax = temp;
		}
	}
	cout << cMax << endl;
	return 0;
}
