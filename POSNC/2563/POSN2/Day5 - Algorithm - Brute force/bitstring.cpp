#include <iostream>
#include <vector>
using namespace std;
#define N 4 //number of items
vector<string> results;
void add_bitstring_to_vector(int value){
    char buf[N+1];
    char *p = buf;

    for(int i=0;i<N;i++){
        if(value & (1<<N))
            *p='1';
        else
            *p='0';
        p++;
    }
    *p='\0';
    results.push_back(string(buf));
}
int main(){
    for(int i=0;i<(1<<N);i++)
        add_bitstring_to_vector(i);
    for(auto v: results)
        cout << v << endl;
}
