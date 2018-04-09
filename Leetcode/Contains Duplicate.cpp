class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (auto i : nums){
            s.insert(i);
        }
        return s.size() != nums.size();
    }
    
private:
    set< int > s;
};