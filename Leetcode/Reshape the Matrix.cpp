class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector< vector< int > > res;
        int t = 0;
        int n = nums.size(), m = nums[0].size();
        if (r*c != n*m)
            return nums;
        // while (c > 0){
        //     vector< int > tmp;
        //     for (int k=0; k<r; k++){
        //         tmp.push_back(nums[t/n][t%m]);
        //         t++;
        //         c--;
        //     }
        //     res.push_back(tmp);
        // }
        for (int i=0; i<r; i++){
            vector< int > tmp;
            for (int k=0; k<c; k++){
                tmp.push_back(nums[t/m][t%m]);
                t++;
            }
            
            res.push_back(tmp);
        }
        
        return res;
    }
};