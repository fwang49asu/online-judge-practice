#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Strategy{
    int distinct;
    int count;
    int highest;
    int stamps[4];
}Strategy;

int intcmp(const void *a, const void *b) {
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa - *pb;
}

inline void fill(Strategy &a, int count, int* stamps) {
    a.count = count;
    a.distinct = 1;
    for(int i=1; i<count; ++i) {
        bool diff = true;
        for(int k=0; k<i && diff; ++k) {
            if(a.stamps[i] == a.stamps[k]) {
                diff = false;
            }
        }
        if(diff) {
            ++a.distinct;
        }
    }
    a.highest = 0;
    for(int i=0; i<count; ++i) {
        if(stamps[a.stamps[i]] > stamps[a.highest]) {
            a.highest = stamps[a.stamps[i]];
        }
    }
}

inline void copy(Strategy &des, Strategy &src) {
    des.distinct = src.distinct;
    des.highest = src.highest;
    des.count = src.count;
    for(int i=0; i<des.count; ++i) {
        des.stamps[i] = src.stamps[i];
    }
}

inline int compare(Strategy &a, Strategy &b){
    if(a.distinct != b.distinct) {
        return a.distinct - b.distinct;
    }
    if(a.count != b.count) {
        return b.count - a.count;
    }
    return a.highest - b.highest;
}

int distribute(Strategy &result, int* stamps, int stampN, int customer) {
    int count = 0;
    Strategy temp;
    // four stamps
    int sum;
    for(int p = 0; p < stampN; ++p) {
        temp.stamps[0] = p;
        for(int q = p; q < stampN; ++q) {
            temp.stamps[1] = q;
            for(int x = q; x < stampN; ++x) {
                temp.stamps[2] = x;
                for(int y=x; y < stampN; ++y) {
                    temp.stamps[3] = y;
                    sum = 0;
                    for(int i=0; i<4; ++i) {
                        sum += stamps[temp.stamps[i]];
                    }
                    if(sum == customer) {
                        fill(temp, 4, stamps);
                        if(count == 0) {
                            copy(result, temp);
                            count = 1;
                        } else {
                            bool same = true;
                            for(int i=0; i<4 && same; ++i) {
                                if(temp.stamps[i] != result.stamps[i]) {
                                    same = false;
                                }
                            }
                            if(same) {
                                continue;
                            }
                            int diff = compare(temp, result);
                            if(diff == 0) {
                                count = 2;
                            } else if(diff > 0) {
                                count = 1;
                                copy(result, temp);
                            }
                        }
                    }
                }
            }
        }
    }
    // three stamps
    for(int p = 0; p < stampN; ++p) {
        temp.stamps[0] = p;
        for(int q = p; q < stampN; ++q) {
            temp.stamps[1] = q;
            for(int x =q; x < stampN; ++x) {
                temp.stamps[2] = x;
                sum = 0;
                for(int i=0; i<3; ++i) {
                    sum += stamps[temp.stamps[i]];
                }
                if(sum == customer) {
                    fill(temp, 3, stamps);
                    if(count == 0) {
                        copy(result, temp);
                        count = 1;
                    } else {
                        bool same = true;
                        for(int i=0; i<3 && same; ++i) {
                            if(temp.stamps[i] != result.stamps[i]) {
                                same = false;
                            }
                        }
                        if(same) {
                            continue;
                        }
                        int diff = compare(temp, result);
                        if(diff == 0) {
                            count = 2;
                        } else if(diff > 0) {
                            count = 1;
                            copy(result, temp);
                        }
                    }
                }
            }
        }
    }
    // two stamps
    for(int p = 0; p < stampN; ++p) {
        temp.stamps[0] = p;
        for(int q = p; q < stampN; ++q) {
            temp.stamps[1] = q;
            sum = stamps[temp.stamps[0]] + stamps[temp.stamps[1]];
            if(sum == customer) {
                fill(temp, 2, stamps);
                if(count == 0) {
                    copy(result, temp);
                    count = 1;
                } else {
                    bool same = true;
                    for(int i=0; i<2 && same; ++i) {
                        if(temp.stamps[i] != result.stamps[i]) {
                            same = false;
                        }
                    }
                    if(same) {
                        continue;
                    }
                    int diff = compare(temp, result);
                    if(diff == 0) {
                        count = 2;
                    } else if(diff > 0) {
                        count = 1;
                        copy(result, temp);
                    }
                }   
            }
        }
    }

    // one stamp
    for(int p = 0; p < stampN; ++p) {
        temp.stamps[0] = p;
        sum = stamps[temp.stamps[0]];
        if(sum == customer) {
            fill(temp, 1, stamps);
            if(count == 0) {
                copy(result, temp);
                count = 1;
            } else {
                bool same = true;
                for(int i=0; i<1 && same; ++i) {
                    if(temp.stamps[i] != result.stamps[i]) {
                        same = false;
                    }
                }
                if(same) {
                    continue;
                }
                int diff = compare(temp, result);
                if(diff == 0) {
                    count = 2;
                } else if(diff > 0) {
                    count = 1;
                    copy(result, temp);
                }
            }   
        }
    }

    return count;
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

        qsort(stamps, stampN, sizeof(int), intcmp);

        for(int i=0; i<customerN; ++i) {
            int count = distribute(result, stamps, stampN, customers[i]);
            cout << customers[i] << " ";
            switch(count) {
            case 0:
                cout << "---- none" << endl;
                break;
            case 1:
                cout << "(" << result.distinct << "):";
                for(int k=0; k<result.count; ++k) {
                    cout << " " << stamps[result.stamps[k]];
                }
                cout << endl;
                break;
            case 2:
                cout << "(" << result.distinct << "): tie" << endl;
            }
        }
    }
    return 0;
}
