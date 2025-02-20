#include <bits/stdc++.h>

using namespace std;
int score[7];
bool qualified[7];
bool descending(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first)
        return a.second<b.second;

    return a.first>b.first;
}
int main(){
    string x;
    memset(qualified,true,sizeof(qualified));
    int n=7;
    while(true){
        cin>>x;
        if(x[0]=='!')
            break;
        for(auto i:x){
            score[i-'A']++;
        }
        int cntmin = 0;
        int minidx = 0;
        int min = 30005;
        for(int i=0;i<7;i++){
            //cout<<score[i]<<" ";
            if(score[i]<min){
                min = score[i];
                minidx = i;
                cntmin = 1;
            }
            else if(score[i]==min){
                cntmin++;
            }
        }
        //cout<<"cntmin,minidx : "<<cntmin<<' '<<minidx<<endl;
        if(cntmin==1&&n>1){
            qualified[minidx]=false;
            score[minidx] = 30005;
            n--;
        }
    }
    vector<pair<int,int>> v;
    for(int i=0;i<7;i++){
        if(qualified[i]){
            v.push_back({score[i],i});
        }
    }
    sort(v.begin(),v.end(),descending);
    cout<<n<<endl;
    for(auto i:v){
        cout<<char(i.second+'A')<<" "<<i.first<<endl;
    }
}
