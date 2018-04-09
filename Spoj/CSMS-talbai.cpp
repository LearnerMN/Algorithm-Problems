//http://www.spoj.com/CSMS/problems/ULS14_5/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <cstdio>

using namespace std;

template<typename T> string toStr(T x) { stringstream ss; ss << x; return ss.str(); }
template<typename T> T pows(T base, T exp){ T res = 1; while (exp > 0){ if (exp % 2 == 1) res = (res * base); exp = exp >> 1; base = (base * base); } return res; }
//shortcuts
#define all(_xx) _xx.begin(), _xx.end()

#define gcd __gcd

#define xx first
#define yy second
#define pb push_back
#define mp make_pair

//print
#define pt(st) (cout<<(st)<<endl);

// loop
#define fr(i,n) for (int i=0; i<(n); i++)
#define fors(i, a, b) for( int i = (a); i < (b); i++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

struct rec{
    int x1,y1,x2,y2,c;
}s[800001],p;

int n,cc=0,h[2];
void Ogt(rec s1,rec s2,int x){
    if ((s2.x1>=s1.x2)||(s2.x2<=s1.x1)||(s2.y1>=s1.y2)||(s2.y2<=s1.y1)) 
		return;
    if (s2.x1<s1.x1&&s2.x2<s1.x2){
        s[++cc]=s1;s[cc].x1=s2.x2;
        s1.x2=s2.x2;s2.x1=s1.x1;
    }
    else if (s2.x1>s1.x1&&s2.x2>s1.x2){
        s[++cc]=s1;s[cc].x2=s2.x1;
        s1.x1=s2.x1;s2.x2=s1.x2;
    }
    else if (s2.x1>=s1.x1&&s2.x2<=s1.x2){
        if (s2.x2<s1.x2) {s[++cc]=s1;s[cc].x1=s2.x2;}
        if (s2.x1>s1.x1) {s[++cc]=s1;s[cc].x2=s2.x1;}
        s1.x1=s2.x1;s1.x2=s2.x2;
    }
    else if (s2.x1<=s1.x1&&s2.x2>=s1.x2){
        s2.x1=s1.x1;s2.x2=s1.x2;
    }
    if (s2.y1<s1.y1&&s2.y2<s1.y2){
        s[++cc]=s1;s[cc].y1=s2.y2;
    }
    else if (s2.y1>s1.y1&&s2.y2>s1.y2){
        s[++cc]=s1;s[cc].y2=s2.y1;
    }
    else if (s2.y1>=s1.y1&&s2.y2<=s1.y2){
        if (s2.y1>s1.y1) {s[++cc]=s1;s[cc].y2=s2.y1;}
        if (s2.y2<s1.y2) {s[++cc]=s1;s[cc].y1=s2.y2;}
    }
    s[x]=s[cc--];
}
int main(){
    scanf("%d",&n);
    ++cc;
    fors (i,1,n+1){
        scanf("%d %d %d %d\n",&p.x1,&p.y1,&p.x2,&p.y2);
        p.c = 2;
        for (int j=cc; j>=1; j--) 
			Ogt(s[j],p,j);
        s[++cc]=p;
    }
    for ( int i=1; i<=cc; i++) 
		h[s[i].c] += (s[i].x2-s[i].x1)*(s[i].y2-s[i].y1);
	pt(h[2])
    return 0;
}

