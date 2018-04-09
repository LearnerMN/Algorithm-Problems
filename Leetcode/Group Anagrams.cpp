class Solution {
public:
    static bool cmp( vector<string> &a,  vector<string> &b){
        if (a.size() != b.size()){
            return a.size() < b.size();
        }
        return a[0] < b[0];
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map< map< char,int >, vector< string > > mp;
        for (auto word : strs){
            map< char, int > tmp_map;
            for (auto ch : word){
                tmp_map[ch]++;
            }
            mp[tmp_map].push_back(word);
        }
        vector<vector<string>> result;
        for (auto p : mp){
            sort(p.second.begin(), p.second.end());
            result.push_back(p.second);
        }
        sort(result.begin(), result.end(), cmp);
        return result;
    }
};