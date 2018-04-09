class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& t) {
        unordered_map< int,int > mp;
        unordered_map< int,int > counter_map;
        vector< int > nums;
        for (int i=0; i<t.size(); i++){
            if (counter_map[t[i]] > 10) continue;
            counter_map[t[i]]++;
            mp[t[i]*-1] = i;
            nums.push_back(t[i]);
        }
        set< vector< int> > result;
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                int tmp = nums[i] + nums[j];
                if (mp.find(tmp) != mp.end() && (mp[tmp] != i && mp[tmp] != j)){
                    vector< int > vt = { nums[i], nums[j], tmp*-1};
                    sort(vt.begin(), vt.end());
                    result.insert(vt);
                }
            }
        }
        vector< vector< int> > comp;
        for (auto v : result){
            comp.push_back(v);
        }
        return comp;
    }
};