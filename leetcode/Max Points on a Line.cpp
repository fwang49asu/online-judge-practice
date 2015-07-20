/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float, int> statistic;
        int maxnum=0;
        for(int i=0;i<points.size();i++){
            statistic.clear();
            statistic[INT_MAX]=0;
            int dup=1;
            for(int j=0;j<points.size();j++){
                if(i==j)
                    continue;
                if(points[i].y==points[j].y&&points[i].x==points[j].x){
                    dup++;
                    continue;
                }
                float k=(points[i].x-points[j].x)==0?INT_MAX:(float)(points[i].y-points[j].y)/(points[i].x-points[j].x);
                statistic[k]++;
            }
            for(unordered_map<float,int>::iterator it=statistic.begin();it!=statistic.end();it++){
                maxnum=max(maxnum,it->second+dup);
            }
        }
        return maxnum;
    }
};