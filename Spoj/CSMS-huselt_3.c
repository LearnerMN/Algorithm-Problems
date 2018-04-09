//http://www.spoj.com/CSMS/problems/CSMS136/
#include <stdio.h>  
#define ls (now<<1)  
#define rs (now<<1|1)  
#define NN 101000  
#define f(x) ((long long)x*x%mod*x%mod)  
#define mm(x) (x>=48?(x-48):x)  
#define md(x) while(x>=48) x-=48;  
const int mod=95542721;  
  
int n,a[NN];  
int tcnt;  
  
struct segnode{  
    int l,r;  
    int sum[50];  
    int cnt,add;  
}t[NN*4];  
  
void build(int l,int r,int now){  
    int i;  
    t[now].l=l;t[now].r=r;  
    t[now].cnt=t[now].add=0;  
    if (l==r){  
        t[now].sum[0]=a[l];  
        for(i=1;i<48;++i){  
            t[now].sum[i]=f(t[now].sum[i-1]);  
        }  
        return;  
    }  
    int mid=(l+r)/2;  
    build(l,mid,ls);  
    build(mid+1,r,rs);  
    for(i=0;i<48;++i) t[now].sum[i]=(t[ls].sum[i]+t[rs].sum[i])%mod;  
}  
  
void lazy(int now){  
    if (t[now].add==0||t[now].l==t[now].r) return;  
    int k=t[now].add;  
    t[ls].cnt+=k;t[ls].add+=k;  
    t[rs].cnt+=k;t[rs].add+=k;  
    md(t[ls].cnt);md(t[ls].add);  
    md(t[rs].cnt);md(t[rs].add);  
    t[now].add=0;  
}  
  
void update(int l,int r,int now){  
    int i;  
    if (t[now].l==l&&t[now].r==r){  
        t[now].add+=1;  
        t[now].cnt+=1;  
        md(t[now].cnt);md(t[now].add);  
        return;  
    }  
    lazy(now);  
    int mid=(t[now].l+t[now].r)/2;  
    if (r<=mid){update(l,r,ls);}  
    else if (l>mid) {update(l,r,rs);}  
    else {update(l,mid,ls);update(mid+1,r,rs);}  
    t[now].cnt=0;  
    for(i=0;i<48;++i) t[now].sum[i]=(t[ls].sum[mm(i+t[ls].cnt)]+t[rs].sum[mm(i+t[rs].cnt)])%mod;  
}  
  
int query(int l,int r,int now){  
    if (t[now].l==l&&r==t[now].r){  
        return t[now].sum[mm(t[now].cnt)];  
    }  
    lazy(now);  
    int mid=(t[now].l+t[now].r)/2;  
    if (r<=mid) return query(l,r,ls);  
    else if (l>mid) return query(l,r,rs);  
    else {return (query(l,mid,ls)+query(mid+1,r,rs))%mod;}  
}  
int main(){  
    int i,aa,bb,o,q;  
    scanf("%d",&n);  
    for(i=1;i<=n;++i){  
        scanf("%d",&a[i]);  
    }  
    build(1,n,1);  
    scanf("%d",&q);  
    for(i=1;i<=q;++i){  
        scanf("%d%d%d",&o,&aa,&bb);  
        if (o==1) {printf("%d\n",query(aa,bb,1));}  
        else {update(aa,bb,1);}  
    }  
    return 0;  
  
} 
