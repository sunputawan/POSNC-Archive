#include <iostream>
#include <random>
#include <time.h>

using namespace std;
int main(){
    int x;
    srand(time(NULL));
    x=rand();
    cout<<x;
}
