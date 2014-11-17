#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

bool ispalidrome(int n) {
	ostringstream convert;
	convert << n;
	string str = convert.str();
	int len = str.length();
	int half = len / 2;
	for(int i=0; i<half; ++i) {
		if(str[i] != str[len - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int result = 0;
	int low = 100;
	int high = 1000;
	for(int i=low; i<high; i++) {
		for(int k=low; k<high; k++) {
			int temp = i * k;
			if(temp > result && ispalidrome(temp)) {
				result = temp;
			}
		}
	}
	cout << result << endl;
	return 0;
}
