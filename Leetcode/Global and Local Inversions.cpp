
class Solution {
    
public:
    bool isIdealPermutation(vector<int>& A) {
        if (A.size() < 3){
            return true;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int> > q;
        q.push(A[A.size()-1]);
        for (int i=A.size()-3; i>=0; i--){
            if (q.top() < A[i])
                return false;
            q.push(A[i+1]);
        }
        return true;
    }
    
};