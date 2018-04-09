class Solution {
public:
    bool judgeCircle(string moves) {
        pair< int,int > p = {0,0};
        for (int i=0; i<moves.size(); i++){
            switch(moves[i]){
                case 'U' : p.first += 1;  break;
                case 'D' : p.first -= 1; break;
                case 'L' : p.second += 1; break;
                case 'R' : p.second -= 1; break;
                default: break;
            }
        }
        
        if (p.first == 0 && p.second == 0){
            return true;
        }
        return false;
    }
};