#include <climits>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            maps[nums[i]]++;
        }
        int maxs = INT_MIN;
        int val = 0;
        for (auto i : maps){
            if (maxs < i.second){
                maxs = i.second;
                val = i.first;
            }
        }
        return val;
    }
private:
    map< int,int > maps;
};