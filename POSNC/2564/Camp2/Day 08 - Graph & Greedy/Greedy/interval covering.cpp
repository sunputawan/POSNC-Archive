#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define n 10
#define INTMAX 9999999

using namespace std;
vector<pair<int,int>> a;
int tx,ty;
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool sort_by_sec(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<=b.second;
}
void generate_point(void){
    for(int i=0;i<n;i++){
        int x=rand()%100+1;
        int y=rand()%100+1;
        if(x>y) swap(&x,&y);
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    cout<<"Input : {";
    for(auto i:a){
        cout<<"["<<i.first<<","<<i.second<<"] ";
    }
    cout<<"}\n";
    tx = rand()%100+1;
    ty = rand()%100+1;
    if(tx>ty) swap(&tx,&ty);
    cout<<"Target : ["<<tx<<','<<ty<<"]\n";
}

int main(){
    //generate_point();
    //a = {{{1,3},{2,4},{2,10},{2,3},{1,1}}};
    a = {{1,10}};
    tx = 1,ty = 10;
    sort(a.begin(),a.end());
    cout<<"Input : {";
    for(auto i:a){
        cout<<"["<<i.first<<","<<i.second<<"] ";
    }
    cout<<endl;
    cout<<"Target : ["<<tx<<','<<ty<<"]\n";
    //a.push_back({INTMAX,INTMAX});
    int start = tx;
    int end = start-1;
    int count = 0;
    int i;
    for(i=0;i<a.size();i++){
        if(a[i].first<=start)
            end = max(end,a[i].second);
        if(a[i].first>start){
            cout<<"start,end, : ";
            cout<<start<<" "<<end<<" ";
            cout<<"first,sec : ";
            cout<<a[i].first<<" "<<a[i].second<<endl;
            start = a[i].first;
            end = a[i].second;
            count++;
            if(a[i].first>end || a[i].second>end){
                break;
            }
        }
    }
    if(end<a[i].second) cout<<-1;
    else cout<<count;
}
