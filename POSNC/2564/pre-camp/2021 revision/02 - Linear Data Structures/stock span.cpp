#include <iostream>
#include <stack>

using namespace std;
stack<int> data,tmp,span;
int data_list[]= {7,9,11,6,8,8,11,7,16};
int n = sizeof(data_list)/sizeof(int);
void count_span(void){
    while(!data.empty()){
        int count=1;
        int ref=data.top();
        data.pop();
        while(data.top()<=ref&&!data.empty()){
            int x=data.top();
            data.pop();
            tmp.push(x);
            count++;
        }
        span.push(count);
        while(!tmp.empty()){
            int x=tmp.top();
            data.push(x);
            tmp.pop();
        }
    }
}
int main(){
    for(int i=0;i<n;i++){
        data.push(data_list[i]);
    }
    count_span();
    while(!span.empty()){
        cout<<span.top()<<' ';
        span.pop();
    }
}
