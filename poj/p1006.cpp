#include <iostream>

using namespace std;

int main() {
	int array[4];
	int interval[] = {23, 28, 33};
	int mul = interval[0] * interval[1] * interval[2];
	int root[] = {mul/interval[0], mul/interval[1], mul/interval[2]};
	int base[3];
	for(int i=0; i<3; ++i) {
		base[i] = root[i];
		for(int k = 1; base[i] % interval[i] != 1; ++k, base[i] += root[i]);
	}
	cin >> array[0] >> array[1] >> array[2] >> array[3];
	int caseNo = 1;
	while(array[0] >= 0) {
		array[0] %= 23;
		array[1] %= 28;
		array[2] %= 33;
		int result = 0;
		for(int i=0; i<3; ++i) {
			result += base[i] * array[i];
		}
		result += mul;
		result = result % mul;
		result -= array[3];
		if(result <= 0) {
			result += mul;
		}
		cout << "Case "<< caseNo << ": the next triple peak occurs in " << result << " days."<< endl;
		cin >> array[0] >> array[1] >> array[2] >> array[3];
		++caseNo;
	}
	return 0;
}
