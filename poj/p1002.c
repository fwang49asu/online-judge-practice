#include <stdio.h>
#include <math.h>
#include <stdlib.h>


inline int char2code(char code)
{
	if(code <= '9' && code >= '0') {
		return code - '0';
	}
	return (code - 'A' - (code > 'Q'? 1:0)) / 3 + 2;
}
inline int str2code(char* str) {
	int result = 0;
	int base = 1000000;
	int i;
	for(i=0; str[i] != '\0'; ++i) {
		if(str[i] != '-') {
			result += base * char2code(str[i]);
			base /= 10;
		}
	}
	return result;
}

int cmpInt(const void *a, const void *b) {
	return (*(int*)a) - (*(int*)b);
}

int main() {
	int N;
	char str[200];
	int array[100000];
	int i;
	scanf("%d", &N);
	for(i=0; i<N; ++i) {
		scanf("%s", str);
		array[i] = str2code(str);
	}
	array[N] = -1;
	qsort(array, N, sizeof(int), cmpInt);
	int noduplicates = 1;
	int count = 1;
	int temp = array[0];
	for(i=1; i<=N; ++i) {
		if(array[i] == temp) {
			++count;
		} else {
			if(count > 1) {
				printf("%03d-%04d %d\n", temp / 10000, temp %10000, count);
				noduplicates = 0;
			}
			count = 1;
			temp = array[i];
		}
	}
	if(noduplicates) {
		printf("No duplicates.\n");
	}
	return 0;
}

