// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    enum state {NV, V, C};
    
    void buildGraph(vector<vector<int>>& prereq, unordered_map<int, vector<int>>& graph){
        for(auto& c: prereq){
            if(graph.find(c[1]) != graph.end()) graph[c[1]].push_back(c[0]);
            else{
                vector<int> T;
                T.push_back(c[0]);
                graph.insert(make_pair(c[1], T));
            }
        }
    }

    bool dfs(int start_course, unordered_map<int, vector<int>>& graph, vector<state>& visited){
        if(visited[start_course] == V) return true;
        if(visited[start_course] == C) return false;
        visited[start_course] = V;
        for(auto& course: graph[start_course])
            if(dfs(course, graph, visited)) return true;
        visited[start_course] = C;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        buildGraph(prerequisites, graph);
        vector<state> visited(numCourses, NV);
        for(int curr = 0; curr < numCourses; curr++)
            if(visited[curr] == NV && dfs(curr, graph, visited)) return false;
        return true;
    }
};