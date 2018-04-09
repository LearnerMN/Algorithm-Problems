class Solution {
public:
    vector<int> countBits(int num) {
        vector< int > res;
        for (int i=0; i<=num; i++){
            int tmp = i;
            int c = 0;
            while (tmp > 0){
                c += tmp%2;
                // cout<<tmp<<"*"<<endl;
                tmp = tmp / 2;
                // cout<<tmp<<"*"<<endl;
            }
            res.push_back(c);
        }
        return res;
    }
};