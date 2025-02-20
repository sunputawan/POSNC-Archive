#include <bits/stdc++.h>

using namespace std;
unordered_map<int,int> classof;
vector<int> ans;
vector<int> v;
int main(){
    int c,s; cin>>c>>s;
    for(int i=0;i<s;i++){
        int a,b; cin>>a>>b;
        classof[b] = a;
    }
    char ch;
    while(true){
        cin>>ch;
        if(ch=='X')
            break;
        else if(ch=='E'){
            int x; cin>>x;
            int i=0;
            while(i!=v.size()&&classof[x]!=classof[v[i]])
                i++;
            while(i!=v.size()&&classof[x]==classof[v[i]])
                i++;
            if(i==v.size())
                v.push_back(x);
            else
                v.insert(v.begin()+i,x);
        }
        else if(ch=='D'){
            if(v.empty())
                cout<<"empty\n";
            else{
                cout<<v[0]<<endl;
                v.erase(v.begin());
            }
        }
    }
    cout<<0<<endl;
    return 0;
}
