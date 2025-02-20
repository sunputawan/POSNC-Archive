#include <bits/stdc++.h>

using namespace std;
int a[11][11];
bool visited[110];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(visited[a[i][j]]){
                cout<<"No\n";
                return 0;
            }
            visited[a[i][j]] = true;
        }
    }
    int sum = 0;
    for(int j=0;j<n;j++)
        sum+=a[0][j];
    for(int i=0;i<n;i++){
        int cursum = 0;
        for(int j=0;j<n;j++){
            cursum+=a[i][j];
        }
        if(sum!=cursum){
            cout<<"No\n";
            return 0;
        }
    }

    for(int j=0;j<n;j++){
        int cursum = 0;
        for(int i=0;i<n;i++){
            cursum+=a[i][j];
        }
        if(sum!=cursum){
            cout<<"No\n";
            return 0;
        }
    }

    int cursum = 0;
    for(int i=0;i<n;i++){
        cursum+=a[i][i];
    }
    if(sum!=cursum){
        cout<<"No\n";
        return 0;
    }

    cursum = 0;
    for(int i=0;i<n;i++){
        cursum+=a[i][n-1-i];
    }
    if(sum!=cursum){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    return 0;
}
