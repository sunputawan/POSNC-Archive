#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
int n = 10000;
vector<int> v;
void generate_list(void){
    srand(time(NULL));
    cout<<"List ref : ";
    for(int i=0;i<n;i++){
        int x = (rand())%100000+1;
        v.push_back(x);
        cout<<x<<", ";
    }
    cout<<endl;
}
int maximum(int i,int max){
    if(i==n)
        return max;
    if(v[i]>max)
        max=v[i];
    maximum(i+1,max);
}
int main(){
    ios_base::sync_with_stdio(false);
    generate_list();
    cout<<"\nMax : "<<maximum(0,0);
}
