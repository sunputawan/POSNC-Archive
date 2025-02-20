#include <iostream>
#include <vector>
#include <utility>
#include<iomanip>

using namespace std;
vector<pair<int,int>> p;
float absolute(float x){
    if(x>=0)
        return x;
    else
        return -x;
}
float area(int p1,int p2,int p3){
    return float(absolute(p[p1].first*p[p2].second + p[p2].first*p[p3].second + p[p3].first*p[p1].second - p[p1].second*p[p2].first - p[p2].second*p[p3].first - p[p3].second*p[p1].first))/2;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    float max_area=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<j;k++){
                if(max_area<area(i,j,k))
                    max_area=area(i,j,k);
            }
        }
    }
    cout<<fixed<<setprecision(3)<<float(max_area);
}
