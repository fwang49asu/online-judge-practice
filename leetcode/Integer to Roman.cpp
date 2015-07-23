class Solution {
public:
    string intToRoman(int num) {
        string res;
        if(num/1000){
            for(int i=0;i<num/1000;i++)
                res+="M";
            num%=1000;
        }
        if(num/900){
            res+="CM";
            num%=900;
        }
        if(num/100){
            if(num/100>=5){
                res+="D";
                for(int i=0;i<num/100-5;i++)
                    res+="C";
            }
            else if(num/100==4){
                res+="CD";
            }
            else{
                for(int i=0;i<num/100;i++)
                    res+="C";
            }
        }
        num%=100;
        if(num/90){
            res+="XC";
            num%=90;
        }
        if(num/10){
            if(num/10>=5){
                res+="L";
                for(int i=0;i<num/10-5;i++)
                    res+="X";
            }
            else if(num/10==4){
                res+="XL";
            }
            else{
                for(int i=0;i<num/10;i++)
                    res+="X";
            }
        }
        num%=10;
        if(num/9){
            res+="IX";
            num%=9;
        }
        if(num/1){
            if(num/1>=5){
                res+="V";
                for(int i=0;i<num/1-5;i++)
                    res+="I";
            }
            else if(num/1==4){
                res+="IV";
            }
            else{
                for(int i=0;i<num/1;i++)
                    res+="I";
            }
        }
        return res;
    }
};