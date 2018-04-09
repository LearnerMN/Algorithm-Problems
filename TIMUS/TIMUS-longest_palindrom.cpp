//http://acm.timus.ru/problem.aspx?space=1&num=1297
#include <stdio.h>
#include <string.h>
int main(){
    char s[1000];
    int L,best = 1,pos = 0,cont,l,i,j;
    scanf("%s",s);
    L = strlen(s);
    for(i = 1;i < L;++i){
        cont = 0;
        for(j = 1;i-j >= 0 && i+j < L;++j)
            if(s[i-j] == s[i+j])
				++cont;
            else 
				break;
        l = 2 * cont + 1;
        if(l > best)
            best = l,pos = i - cont;
    }
    for(i = 0;i+1 < L;++i)
        if(s[i] == s[i+1]){
            cont = 0;
            for(j = 1;i-j >= 0 && i+1+j < L;++j)
                if(s[i-j] == s[i+1+j])
					++cont;
                else 
					break;
            l = 2 * cont + 2;
            if(l > best || (l == best && i - cont < pos))
                best = l,pos = i - cont;
        }
    for(i = 0;i < best;++i) 
		putchar(s[pos + i]);
    return 0;
}
