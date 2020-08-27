#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>
#include <unordered_map>

using namespace std;

double distance(pair<int,int> &a, pair<int,int> &b){
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x*x + y*y);
}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

double minPair(vector< pair< int,int > > &vx, pair< int,int > &p, bool Y){
	int l = 0, r = vx.size() - 1;
	double minDis = distance(vx.front(), p);
	while (l < r){
		int mid = (l+r)/2;
		if (Y){
			if (vx[mid].second < p.second){
				l = mid+1;
			}else{
				r = mid;
			}
		}else{
			if (vx[mid].first < p.first){
				l = mid+1;
			}else{
				r = mid;
			}	
		}
		minDis = min(minDis, distance(vx[mid-1], p));
		minDis = min(minDis, distance(vx[mid], p));
		minDis = min(minDis, distance(vx[mid+1], p));
	}
	minDis = min(minDis, distance(vx[l], p));
	minDis = min(minDis, distance(vx[r], p));
	return minDis;
}

bool cmp(const pair< int,int > &a, const pair< int,int > &b){
	return a.second < b.second || (a.second == b.second && a.first < b.first);
}
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--){
		int x, y;
		scanf("%d %d", &x, &y);
		int n, m, k, a, b;
		scanf("%d %d %d", &n, &m, &k);
		vector< pair< int,int > > vn, vm, vk;
		unordered_map< pair< int,int >, double, hash_pair > mpA;
		unordered_map< pair< int,int >, double, hash_pair > mpB;

		for (int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			vn.push_back(make_pair(a, b));
			mpB[make_pair(a,b)] = LONG_MAX;
		}
		for (int i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			vm.push_back(make_pair(a, b));
			mpA[make_pair(a,b)] = LONG_MAX;
		}
		for (int i=0; i<k; i++){
			scanf("%d %d", &a, &b);
			vk.push_back(make_pair(a, b));
		}
		
		auto p = make_pair(x,y);
		for (auto i : vn){
			for (auto j : vm){
				auto dis = distance(i, j);
				mpA[j] = min(mpA[j], dis + distance(p, i));
				mpB[i] = min(mpB[i], dis + distance(p, j));
			}
		}

		double res = LONG_MAX;

		sort(vk.begin(), vk.end());
		for (auto j : vm){
			res = min(res, mpA[j] + minPair(vk, j, false));
		}
		for (auto j : vn){
			res = min(res, mpB[j] + minPair(vk, j, false));
		}
		sort(vk.begin(), vk.end(), cmp);
		for (auto j : vm){
			res = min(res, mpA[j] + minPair(vk, j, true));
		}
		for (auto j : vn){
			res = min(res, mpB[j] + minPair(vk, j, true));
		}
		
		printf("%.10f\n", res);
	}
 return 0;
}