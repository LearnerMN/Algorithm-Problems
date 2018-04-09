class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for (auto i : nums1){
            maps[i]++;
        }
        vector< int > res;
        for (auto i : nums2){
            if (maps[i]>0){
                res.push_back(i);
                maps[i] = 0;
            }
        }
        return res;
    }
    
private:
    map< int,int > maps;
};