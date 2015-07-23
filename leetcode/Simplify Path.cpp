class Solution {
public:
    string simplifyPath(string path) {
        string res="",tmp;
        vector<string> stack;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp==""||tmp==".")
                continue;
            if(tmp==".."&&!stack.empty())
                stack.pop_back();
            else if(tmp!="..")
                stack.push_back(tmp);
        }
        for(int i=0;i<stack.size();i++)
            res+="/"+stack[i];
        return res.empty()?"/":res;
    }
};