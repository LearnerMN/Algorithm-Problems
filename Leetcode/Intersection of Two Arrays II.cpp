class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for (auto i : nums1){
            maps[i]++;
        }
        vector< int > res;
        for (auto i : nums2){
            if (maps[i]>0){
                maps[i]--;
                res.push_back(i);
            }
        }
        return res;
    }
private:
    map< int,int > maps;
};