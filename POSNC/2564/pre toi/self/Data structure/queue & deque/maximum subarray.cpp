#include <bits/stdc++.h>
#define INTMAX 999999999
#define n 20

using namespace std;
vector<int> a;
void generate_input(void){
    srand(time(nullptr));
    for(int i=0;i<n;i++){
        a.push_back(rand()%100-50);
    }
    cout<<"Input : ";
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    generate_input();

    int qsum[n];
    qsum[0] = a[0];
    for(int i=1;i<n;i++){
        qsum[i] = a[i] + qsum[i-1];
    }

    deque<pair<int,int>> dq;
    int maxsum = -INTMAX;
    int lb = INTMAX;
    int rb = INTMAX;

    for(int i=0;i<n;i++){
        while(!dq.empty()&&dq.back().first>=qsum[i])
            dq.pop_back();
        dq.push_back({qsum[i],i});

        if(qsum[i]-dq.front().first>maxsum){
            maxsum = qsum[i]-dq.front().first;
            lb = dq.front().second+1;
            rb = i;
        }
    }
    printf("maxsum : %d [%d,%d]\n",maxsum,lb,rb);
}
