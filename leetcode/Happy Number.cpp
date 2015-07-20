class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        int cur=n;
        int next=0;
        while(visited.find(cur)==visited.end()){
            visited.insert(cur);
            next=0;
            while(cur>0){
                next+=(cur%10)*(cur%10);
                cur/=10;
            }
            if(next==1)
                return true;
            else
                cur=next;
        }
        return false;
    }
};