#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getLongestIncSub(const std::vector<int> &sequence, size_t index, vector< vector< int > > &sub) {
    if(index == 0) {
        sub.push_back(std::vector<int>{sequence[0]});
        return 1;
    }

    size_t longestSubSeq = getLongestIncSub(sequence, index - 1, sub);
    vector< vector< int > > tmpSubSeq;
    for(vector< int > &subSeq : sub) {
        if(subSeq[subSeq.size() - 1] < sequence[index]) {
            std::vector<int> newSeq(subSeq);
            newSeq.push_back(sequence[index]);
            longestSubSeq = std::max(longestSubSeq, newSeq.size());
            tmpSubSeq.push_back(newSeq);
        }
    }
    std::copy(tmpSubSeq.begin(), tmpSubSeq.end(),
              std::back_insert_iterator<std::vector<std::vector<int>>>(sub));

    return longestSubSeq;
}

int getLongestIncSub(const std::vector<int> &sequence) {
    std::vector<std::vector<int>> sub;
    return getLongestIncSub(sequence, sequence.size() - 1, sub);
}


int main()
{
    int n,t;
    cin>>n>>t;
    vector< int > v(n);
    for (int i=0; i<n; i++){
    	cin>>v[i];
	}
	vector< int > c = v;
	for (int i=0; i<t-1; i++)
		v.insert(v.end(), c.begin(), c.end());
	cout<<getLongestIncSub(v)<<endl;
//	
//	if (5<t){
//		int a1 = getLongestIncSub(v);
//		v.insert(v.end(), c.begin(), c.end());
//		int a2 = getLongestIncSub(v);
//		int d = a2 - a1;
//		int l = t - 5;
//		cout<<a1 + d*l<<endl;
//	}else{
//	    cout<< getLongestIncSub( v)<<endl;
//	}
	
    return 0;
}

// 6
// 3 1# 4 2# 3# 1 4# 2 3 1 4# 2 3 1 4# 2 3 1 4# 2 3 1 4# 2
