class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int x,int y,vector<int> &path, vector<vector<int>>& graph){
        if(x == y){
            ans.push_back(path);
            return; 
        }
        for(auto it = graph[x].begin(); it!=graph[x].end();++it){
            path.push_back(*it);
            dfs(*it,y,path,graph);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        vector<int> path;
        path.push_back(0);
        int n = graph.size();
        dfs(0,n-1,path,graph);
        v = ans;
        return v;
    }
};
