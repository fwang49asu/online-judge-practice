#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
using namespace std;

inline int hash(char* str) {
	int result = 0;
	for(int i=0; str[i] != '\0'; ++i) {
		result = result * 26 + str[i];
	}
	return result;
}

int main() {
	map<int, int> haabMonthMap;
	char* haabArray[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

	char* tzolkinArray[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	for(int i=0; i<19; ++i) {
		haabMonthMap.insert(pair<int, int>(hash(haabArray[i]), i));
	}
	int n;
	cin >> n;
	cout << n << endl;
	for(int i=0; i<n; ++i) {
		char haabDayStr[10];
		char haabMonthStr[10];
		int haabYear;
		int haabDay;

		cin >> haabDayStr >> haabMonthStr >> haabYear;
		haabDayStr[strlen(haabDayStr) - 1] = '\0';
		haabDay = atoi(haabDayStr);
		int haabMonth = haabMonthMap.find(hash(haabMonthStr))->second;
		int day = haabYear * 365 + haabMonth * 20 + haabDay;

		int tzolkinDay = day % 13;
		int tzolkinMonth = day % 20;
		int tzolkinYear = day / 260;

		cout << tzolkinDay + 1 << " " << tzolkinArray[tzolkinMonth] << " " << tzolkinYear << endl;
	}
	return 0;
}
