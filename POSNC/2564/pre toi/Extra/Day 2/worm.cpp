#include <bits/stdc++.h>


using namespace std;
vector<pair<double ,double>> v;

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        double a,b; cin>>b>>a;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    double mxsum = 0;
    double cost = 0;
    double sum = 0;

    double mx = -1;

    for(auto x:v){
        sum+=x.second;

        if(mx<sum/x.first){
            mx = sum/x.first;
            mxsum = sum;
            cost = x.first;
        }
    }
    cout<<fixed<<setprecision(0)<<mxsum<<" "<<cost;
    return 0;
}
