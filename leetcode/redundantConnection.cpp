// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    int find(int u, vector<pair<int,int>> &par){
        if(par[u].first == u)
            return u;
        return par[u].first = find(par[u].first, par);
    }
    
    void unionsets(int u, int v, vector<pair<int,int>> &par){
        int par_u = find(u, par);
        int par_v = find(v, par);
        if(par[par_u].second < par[par_v].second)
            par[par_u].first = v;
        else if(par[par_u].second > par[par_v].second)
            par[par_v].first = u;
        else{
            par[par_v].first = u;
            par[par_u].second++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<pair<int,int>> par(1001);
        for(int i = 0;i < 1001;i++){
            par[i].first = i;
            par[i].second = 1;
        }
        vector<int> ans;
        for(int i = 0;i < edges.size();i++){
            if(find(edges[i][0],par) == find(edges[i][1],par)){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }else
                unionsets(edges[i][0],edges[i][1],par);
        }
        return ans;
    }
};