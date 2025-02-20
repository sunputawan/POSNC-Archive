#include <iostream>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <utility>
#include <vector>
#define n 50
#define low -100
#define up 100
#define INTMAX 999999

using namespace std;
vector<pair<pair<int,int>,int>> p,q;

bool x_ascending(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return a.first.first<=b.first.first;
}
bool y_ascending(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return a.first.second<=b.first.second;
}
int square(int x){
    return x*x;
}
int *min(int *x,int *y){
    if(*x<*y)
        return x;
    else
        return y;
}
void generate_point(void){
            srand(time(NULL));
    for(int i=0;i<n;i++){
        int x=rand()%(low-up+1)+low;
        int y=rand()%(low-up+1)+low;
        p.push_back(make_pair(make_pair(x,y),i));
        q.push_back(make_pair(make_pair(x,y),i));
    }
}
void printpoint(vector<pair<pair<int,int>,int>> &point_ref){
    cout<<" {";
    for(auto i:point_ref){
        cout<<" ("<<i.first.first<<","<<i.first.second<<")";
    }
    cout<<"}\n";
}
void sort_point(void){
    sort(p.begin(),p.end(),x_ascending);
    sort(q.begin(),q.end(),y_ascending);
}
void initialize(void){
    generate_point();
    sort_point();
    cout<<"Set of non-descending x :";
    printpoint(p);
    cout<<"Set of non-descending y :";
    printpoint(q);
    cout<<endl;
}
int *bruteforce(int l,int r){
    int *ans = new int[3];
    int minimum=INTMAX;
    int p1,p2;
    for(int i=l;i<r;i++){
        for(int j=i+1;j<=r;j++){
            int d=square(p[i].first.first-p[j].first.first)+square(p[i].first.second-p[j].first.second);
            if(minimum>d){
                minimum=d; p1=i; p2=j;
            }
        }
    }
    *ans = minimum; *(ans+1) = p1; *(ans+2) = p2;
    return ans;
}
int *closest_point(int l,int r){
    if(r-l<=3){
        return bruteforce(l,r);
    }
    int m = (l+r)/2;
    int *dl = closest_point(l,m);
    int *dr = closest_point(m+1,r);
    int *d = min(dl,dr);

    int i=0;
    while(i!=n){
        if(q[i].first.first<m-sqrt(d[0])||q[i].first.first>m+sqrt(d[0])){
            i++;
            continue;
        }
        int j=i+1;
        while(j!=n){
            if(q[j].first.second-q[i].first.second>=sqrt(d[0])){
                j++;
                continue;
            }
            int dis = square(q[i].first.first-q[j].first.first)+square(q[i].first.second-q[j].first.second);
            if(d[0]>dis){
                d[0]=dis;
                d[1]=q[i].second;
                d[2]=q[j].second;
            }
            j++;
        }
        i++;
    }
    return d;
}
void printanswer(int *ans){
    cout<<"Shortest Distance of closest point : "<<sqrt(ans[0]);
    cout<<"  [("<<p[ans[1]].first.first<<","<<p[ans[1]].first.second<<"),("<<p[ans[2]].first.first<<","<<p[ans[2]].first.second<<")]\n";
}
int main(){
    if(n<=1){
        cout<<"The number of points OUT OF RANGE! >>> exit program."<<endl;
        return 1;
    }
    initialize();
    int *ans = closest_point(0,n-1);
    printanswer(ans);
}
