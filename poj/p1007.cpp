#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct DNA{
	int inversion;
	char str[51];
}DNA;

int cmp(const void *a, const void *b) {
	return ((DNA*)a)->inversion - ((DNA*)b)->inversion;
}

int main() {
	int n, m;
	DNA dna[100];
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> dna[i].str;
		dna[i].inversion = 0;
		for(int k=0; k<n; ++k) {
			for(int p=k+1; p<n; ++p) {
				if(dna[i].str[p] < dna[i].str[k]) {
					++dna[i].inversion;
				}
			}
		}
	}
	qsort(dna, m, sizeof(DNA), cmp);
	for(int i=0; i<m; ++i) {
		cout << dna[i].str << endl;
	}
	return 0;
}
