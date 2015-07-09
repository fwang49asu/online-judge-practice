class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1=version1.length(),len2=version2.length();
        int i=0,j=0;
        while(i<len1||j<len2){
            int a=0,b=0;
            while(i<len1&&version1[i]!='.'){
                a=a*10+version1[i]-'0';
                i++;
            }
            i++;
            while(j<len2&&version2[j]!='.'){
                b=b*10+version2[j]-'0';
                j++;
            }
            j++;
            if(a>b)
                return 1;
            else if(a<b)
                return -1;
        }
        return 0;
    }
};