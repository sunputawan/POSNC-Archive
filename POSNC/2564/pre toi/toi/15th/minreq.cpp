#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,x;
struct lift{
    int l;
    int w;
    int aw;
    int left;
    int right;
};
vector<lift> elev;
vector<int> a;
vector<bool> ans;
int s[10000005];
int qsum[10000005];
int t[11];
int h[11];
bool ascending_by_space(const lift &a, const lift &b){
    return a.l-a.w<=b.l-b.w;
}
bool ascending(int a,int b){
    return a<=b;
}
void debugelev(void){
    for(auto lif:elev){
        cout<<lif.l<<" "<<lif.w<<" ";
        cout<<lif.l-lif.w<<"   ";
        cout<<lif.left<<" "<<lif.right<<" ";
        cout<<endl;
    }
}
int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin>>n>>m>>x;
    elev.resize(n+1);
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>elev[i].l;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsum[0] = 0;
    for(int i=1;i<=m;i++){
        cin>>s[i];
        qsum[i] = s[i]+qsum[i-1];
    }
    for(int i=1;i<=x;i++) cin>>t[i];

    sort(a.begin()+1,a.end(),ascending);
    int k = 1;
    while(k!=x+1){
        for(int i=1;i<=n;i++) cin>>h[i];

        for(int i=1;i<n;i++){
            elev[i].w = qsum[h[i+1]-1]-qsum[h[i]-1];
            elev[i].left = h[i];
            elev[i].right = h[i+1]-1;
        }
        elev[n].w = qsum[m]-qsum[h[n]-1];
        elev[n].left = h[n];
        elev[n].right = m;
        sort(elev.begin()+1,elev.end(),ascending_by_space);
        bool valid = true;
        //debugelev();
        for(int i=1;i<=n;i++){
            //cout<<a[i]<<" ";
            int total = a[i];
            int time = 0;
            for(int j=elev[i].left;j<=elev[i].right;j++){
                if(!valid) break;
                if(a[i]+s[j]>elev[i].l) valid = false;
                total+=s[j];
                if(total>elev[i].l){
                    time++;
                    if(time>t[k]) valid = false;
                    total = a[i]+s[j];
                }
            }
            if(total>elev[i].l) time++;
            if(time>t[k]) valid = false;
            if(!valid) break;
        }
        ans.push_back(valid);
        k++;
    }
    for(bool i:ans){
        if(i) cout<<"P\n";
        else cout<<"F\n";
    }
}
