class Solution {
public:
    vector<string> split(const string& str, const string& delim){
        vector<string> tokens;
        size_t prev = 0, pos = 0;
        do{
            pos = str.find(delim, prev);
            if (pos == string::npos) pos = str.length();
            string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
        } while (pos < str.length() && prev < str.length());
        
        return tokens;
    }
    
    string reverseWords(string s) {
        string res = "";
        vector<string> v = split(s," ");
        for (int i=0; i<v.size(); i++){
            if (i != 0)
                res += " ";
            reverse(v[i].begin(),v[i].end());
            res += v[i];
        }
        return res;
    }
};