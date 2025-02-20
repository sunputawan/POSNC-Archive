#include <iostream>
#include <vector>
#define inf 1000000
using namespace std;
vector<int> node[1000000];
int line[500][500];
int main(){
    int n, m, s, in;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            line[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++){
        cin>>s;
        for(int j = 0; j < s; j++){
            cin>>in;
            node[in].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < node[i].size(); j++){
            for(int k = j+1; k < node[i].size(); k++){
                line[node[i][j]][node[i][k]] = 1;
                line[node[i][k]][node[i][j]] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        line[i][i] = 0;
    }
    for(int k = 0; k < m; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                line[i][j] = min(line[i][j], line[i][k]+line[k][j]);
            }
        }
    }
    int q1, q2;
    int Q;
    int ans;
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        cin >> q1 >> q2;
        ans = 1000000;
        for(int i = 0; i < node[q1].size(); i++){
            for(int j = 0; j < node[q2].size(); j++){
                ans = min(line[node[q1][i]][node[q2][j]], ans);
            }
        }
        if(ans >= 1000000){
            cout << "impossible" << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}
