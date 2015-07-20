class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()>b.length())
            return addBinary(b,a);
        int lena=a.length();
        int lenb=b.length();
        int carry=0;
        int j=lenb-1;
        for(int i=lena-1;i>=0;i--,j--){
            int tmp=a[i]-'0'+b[j]-'0'+carry;
            if(tmp==1||tmp==0){
                carry=0;
                b[j]=tmp+'0';
            }
            else if(tmp==2){
                carry=1;
                b[j]='0';
            }
            else{
                carry=1;
                b[j]='1';
            }
        }
        for(;j>=0;j--){
            int tmp=b[j]-'0'+carry;
            if(tmp==1||tmp==0){
                carry=0;
                b[j]=tmp+'0';
            }
            else{
                carry=1;
                b[j]='0';
            }
        }
        if(carry==1)
            b.insert(b.begin(),'1');
        return b;
    }
};