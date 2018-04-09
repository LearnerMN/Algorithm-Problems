class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        vector< unordered_set<char> > row(3);
        row[0] = {'q','w','e','r','t','y','u','i','o','p'};
        row[1] = {'a','s','d','f','g','h','j','k','l'};
        row[2] = {'z','x','c','v','b','n','m'};
        
        for (auto word : words){
            int c[3] = {0};
            for (auto ch : word){
                for (int i=0; i<3; i++){
                    if (row[i].find(ch) != row[i].end() || row[i].find(ch+('a'-'A')) != row[i].end())
                        c[i]++;
                }
            }
            if (c[0] == word.size() || c[1] == word.size() || c[2] == word.size())
                res.push_back(word);
        }
        
        return res;
    }
};