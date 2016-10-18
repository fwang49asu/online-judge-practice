class Solution {
public:
    string numberToWords(int num) {
        string result = "";
        dic = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        tens = {"xx", "xx", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> scales = {" Billion", " Million", " Thousand", ""};
        vector<int> segments = {num / 1000000000, num % 1000000000 / 1000000, num % 1000000 / 1000, num % 1000};
        for(int i=0; i<4; ++i) {
            if(segments[i] > 0) {
                if(result != "") {
                    result += " ";
                }
                result += helper(segments[i]) + scales[i];
            }
        }
        if(result == "") {
            result = "Zero";
        }
        return result;
    }
private:
    vector<string> dic;
    vector<string> tens;
    string helper(int num) {
        if(num < 20) {
            return dic[num];
        }
        if(num < 100) {
            string str = tens[num/10];
            if(num % 10 != 0) {
                str += " " + dic[num % 10];
            }
            return str;
        }
        string str = dic[num / 100] + " Hundred";
        if(num % 100 != 0) {
            str += " " + helper(num % 100);
        }
        return str;
    }
};
