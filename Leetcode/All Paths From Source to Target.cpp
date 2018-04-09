class Solution {
public:
    void dfs(vector<vector<int>> &graph, 
             vector<vector<int>> &result, 
             vector<bool> &visit,
             vector<int> &tmp,
             int startPoint,
             int endPoint){
        if (startPoint == endPoint){
            result.push_back(tmp);
        }else{
            for (int i=0; i<graph[startPoint].size(); i++){
                if (!visit[graph[startPoint][i]]){
                    visit[graph[startPoint][i]] = true;
                    tmp.push_back(graph[startPoint][i]);
                    dfs(graph, result, visit, tmp, graph[startPoint][i], endPoint);
                    tmp.pop_back();
                    visit[graph[startPoint][i]] = false;
                }
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visit;
        for (int i=0; i<graph.size(); i++){
            visit.push_back(false);
        }
        vector<vector<int>> result;
        visit[0] = true;
        vector< int > tmp = { 0 };
        dfs(graph, result, visit, tmp, 0, graph.size() - 1);
        return result;
    }
};