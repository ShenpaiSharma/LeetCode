class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        set<int> s;
        vector<int> adj[N];
        s.insert(0);
        for(int i : rooms[0])
        {
            adj[0].push_back(i);
            //adj[i].push_back(0);
            s.insert(i);
        }
        bool vis[N];
        memset(vis,false,sizeof(vis));
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(auto it = adj[x].begin();it != adj[x].end(); ++it)
            {
                if(!vis[*it])
                {
                    vis[*it] = true;
                    for(int i : rooms[*it])
                    {
                        if(s.find(i) == s.end())
                            adj[*it].push_back(i);
                            //adj[i].push_back(*it);
                            s.insert(i);
                    }
                    q.push(*it);
                }
            }
        }
        if(s.size() == N) return true;
        else return false;
    }
};
