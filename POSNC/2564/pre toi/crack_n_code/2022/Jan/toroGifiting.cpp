#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[505][505];
int qsum[505][505];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            qsum[i][j] = a[i][j] + qsum[i][j-1];
        }
    }
    int mx = 0;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            vector<int> tmp;
            for(int k=1;k<=n;k++){
                tmp.push_back(qsum[k][j]-qsum[k][i-1]);
            }
            int curmx = 0;
            int cursum = 0;
            for(int k=0;k<n;k++){
                cursum+=tmp[k];
                if(curmx<cursum)
                    curmx = cursum;
                if(cursum<0)
                    cursum = 0;
            }

            mx = max(mx,curmx);
        }
    }
    cout<<mx<<endl;
    return 0;
}
