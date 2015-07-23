class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visit, int i){
        if(visit[i]==-1)
            return false;
        if(visit[i]==1)
            return true;
        visit[i]=-1;
        for(int i=0;i<graph[i].size();i++)
            if(!dfs(graph,visit,i))
                return false;
        visit[i]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> visit(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        for(int i=0;i<numCourses;i++)
            if(!dfs(graph,visit,i))
                return false;
        return true;
    }
};