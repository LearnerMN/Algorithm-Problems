class Solution {
public:
    bool isSubSequence(string s, string sub){
        int c = 0;
        for (int i=0; i<s.size(); i++){
            if (sub[c] == s[i]){
                c++;
            }
            if (c == sub.size()) break;
        }
        return c == sub.size();
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int counter = 0;
        map< string,bool > cache;
        
        for (auto word : words){
            if (cache.find(word) == cache.end()){
                cache[word] = isSubSequence(S,word);   
            }
            counter += cache[word];          
        }
        return counter;
    }
};