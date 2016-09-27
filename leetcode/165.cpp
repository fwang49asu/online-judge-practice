class Solution {
public:
    int compareVersion(string version1, string version2) {
        int length_1 = version1.length();
        int length_2 = version2.length();
        int pos_1 = 0;
        int pos_2 = 0;
        while(pos_1 < length_1 || pos_2 < length_2) {
            int a;
            int b;
            if(pos_1 >= length_1) {
                a = 0;
            } else {
                int dot_1;
                for(dot_1 = pos_1+1; dot_1 < length_1 && version1[dot_1] != '.'; ++dot_1);
                a = stoi(version1.substr(pos_1, dot_1 - pos_1));
                pos_1 = dot_1 + 1;
            }
            if(pos_2 >= length_2) {
                b = 0;
            } else {
                int dot_2;
                for(dot_2 = pos_2+1; dot_2 < length_2 && version2[dot_2] != '.'; ++dot_2);
                b = stoi(version2.substr(pos_2, dot_2 - pos_2));
                pos_2 = dot_2 + 1;
            }
            if(a > b) {
                return 1;
            }
            if(a < b) {
                return -1;
            }
        }
        return 0;
    }
};
