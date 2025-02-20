#include <bits/stdc++.h>

using namespace std;

int main(){
    string x,y;
    cin>>x>>y;
    int m = x.size();
    int n = y.size();
    int max = 0;
    int idx = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int a = 0;
            while(i+a<m&&j+a<n){
                if(x[i+a]!=y[j+a]){
                    break;
                }
                a++;
            }
            if(a>max){
                max = a;
                idx = i;
            }
        }
    }
    for(int i=idx;i<idx+max;i++){
        cout<<x[i];
    }
    cout<<endl;
    return 0;
}
