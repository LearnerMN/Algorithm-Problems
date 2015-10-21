//http://www.spoj.com/CSMS/problems/ULS14_1/
#include <iostream>
#define MAX_N 500
#define MAX_VAL 1000000001
#define MIN_VAL -1000000001 
#define maxv(a, b) ((a) >= (b) ? (a) : (b))
#define minv(a, b) ((a) <= (b) ? (a) : (b))
using namespace std;

int ress=0;
int val[MAX_N + 1];
char op[MAX_N + 1];

int minVal[MAX_N + 1][MAX_N + 1];
int maxVal[MAX_N + 1][MAX_N + 1];
int n;

int maxRes = MIN_VAL;
int maxPos[MAX_N + 1];

void init(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if (i == j) 
                minVal[i][j] = maxVal[i][j] = val[i];
            else{
                minVal[i][j] = MAX_VAL;
                maxVal[i][j] = MIN_VAL;
            }
        }
}

int dpSolve(int p){
    char c;
    int len, i, j, k, index_i, index_j, index_k;
    for(len = 2; len <= n; len++){
        for(i = p; i <= n + p - len; i++)
        {
            j = i + len - 1;
            for(k = i; k < j; k++)
            {
                index_i = i % n;
                index_j = j % n;
                index_k = k % n;

                c = op[(index_k + 1) % n];
                int  minik = minVal[index_i][index_k];
                int  maxik = maxVal[index_i][index_k];
                int  minkj = minVal[(index_k + 1) % n][index_j];
                int  maxkj = maxVal[(index_k + 1) % n][index_j];
                int  minTemp, maxTemp;
                if(c == 'a'){
                    maxTemp = maxik + maxkj;
                    minTemp = minik + minkj;
                }
                else if(c == 'm'){
                    int max1 = maxv(minik * minkj, minik * maxkj);
                    int max2 = maxv(maxik * minkj, maxik * maxkj);
                    maxTemp = maxv(max1, max2);

                    int min1 = minv(minik * minkj, minik * maxkj);
                    int min2 = minv(maxik * minkj, maxik * maxkj);
                    minTemp = minv(min1, min2);
                }
                else{
                    maxTemp = maxv(minik - minkj, minik - maxkj);
                    minTemp = minv(minik - minkj, minik - maxkj);
                }
                maxVal[index_i][index_j] = maxv(maxTemp, maxVal[index_i][index_j]);
                minVal[index_i][index_j] = minv(minTemp, minVal[index_i][index_j]);
                if (maxVal[index_i][index_j]>ress)
					ress=maxVal[index_i][index_j];
                if (minVal[index_i][index_j]>ress)
					ress=minVal[index_i][index_j];
            }
        }
        if (len == n)
        	return maxVal[p][(p + n - 1) % n];
    }
}
int  main(){    
    int hh=0,i;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        cin>>op[i]>>val[i];
    for (int i = 0; i < n; i++){
        init();
        int curVal = dpSolve(i);
        if(curVal > maxRes){
            hh=i;
            maxRes = curVal;
            for(int dd=0;dd<MAX_N + 1;dd++)maxPos[dd]=0;
            maxPos[i] = true;
        }
        else if(curVal == maxRes)
            maxPos[i] = true;
    }
    
    init();
    int curVal = dpSolve(hh);
    if(curVal > maxRes){
        hh=i;
        maxRes = curVal;
        for (int dd=0;dd<MAX_N + 1;dd++)
			maxPos[dd]=0;
        maxPos[i] = true;
    }
    else if(curVal == maxRes)
        maxPos[i] = true;
	printf("%d\n",maxRes);
    return 0;
}
