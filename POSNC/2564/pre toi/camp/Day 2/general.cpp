#include <bits/stdc++.h>

using namespace std;
int p[100005];
int a[100005];
int findroot(int i){
    if(p[i]==i)
        return i;
    return p[i]=findroot(p[i]);
}
int main(){
    int n,m,i,j,pi,pj;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        p[i]=i;
        scanf("%d",&a[i]);
    }
    while(m--){
        scanf("%d %d",&i,&j);
        pi = findroot(i);
        pj = findroot(j);
        if(pi==pj)
            printf("-1\n");
        else if(a[pi]>a[pj]){
            printf("%d\n",pi);
            a[pi]+=a[pj]/2;
            p[pj]=pi;
        }
        else if(a[pj]>a[pi]){
            printf("%d\n",pj);
            a[pj]+=a[pi]/2;
            p[pi]=pj;
        }
        else if(pi<pj){
            printf("%d\n",pi);
            a[pi]+=a[pj]/2;
            p[pj]=pi;
        }
        else{
            printf("%d\n",pj);
            a[pj]+=a[pi]/2;
            p[pi]=pj;
        }
    }

    return 0;
}
