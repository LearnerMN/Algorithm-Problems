class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=nums.size(),t=0;
        for ( int i=0; i<k; i++){
            if (nums[i] == 0){
                nums.erase(nums.begin()+i);
                k--;
                i--;
                t++;
            }
        }
        for (int i=0; i<t; i++){
            nums.push_back(0);
        }
    }
};