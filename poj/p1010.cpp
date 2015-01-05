#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Strategy{
    int distinct;
    int count;
    int highest;
    int stamps[4];
}Strategy;

int distribute(Strategy &result, int* stamps, int stampN, int customer) {
    // four stamps
    // three stamps
    // two stamps
    // one stamp
    return 0;
}

int main(){
    int stamps[100];
    int customers[100];
    int stampN;
    int customerN;
    Strategy result;

    while(cin >> stamps[0]) {
        stampN = 1;
        customerN = 0;
        do{
            cin >> stamps[stampN++];
        } while(stamps[stampN-1] != 0);
        do{
            cin >> customers[customerN++];
        } while(customers[customerN -1 ] != 0);

        --stampN;
        --customerN;

        for(int i=0; i<customerN; ++i) {
            int count = distribute(result, stamps, stampN, customers[i]);
            cout << customers[i] << " ";
            if(count == 0) {
                cout << "---- none" << endl;
            }
        }
    }
    return 0;
}
