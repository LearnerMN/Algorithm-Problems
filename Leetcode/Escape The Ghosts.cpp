class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for (auto cor : ghosts){
            if (abs(target[0] - cor[0]) +  abs(target[1] - cor[1]) <= abs(target[0]) + abs(target[1])){
                return false;
            }
        }
        return true;
    }
};