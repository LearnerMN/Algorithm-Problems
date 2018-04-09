class Solution {
    map< char,int > maps = {{'M', 1000}, {'D' , 500}, {'C' , 100}, {'L' , 50}, {'X' , 10}, {'V' , 5}, {'I' , 1}};
public:
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        int res = maps[s[s.size()-1]];
        
        for (int i=s.size()-2; i>=0; i--){
            int last = maps[s[i+1]];
            int current = maps[s[i]];
            cout<<last<<" "<<current<<endl;
            if (last > current) {
				res -= current;
			} else {
				res += current;
			}
        }
        return res;
    }
};