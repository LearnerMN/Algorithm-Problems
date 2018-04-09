class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set< int > s;
        for (auto c : candies){
            s.insert(c);
        }
        
        return s.size() >= candies.size()/2 ? candies.size()/2 : s.size();
    }
};