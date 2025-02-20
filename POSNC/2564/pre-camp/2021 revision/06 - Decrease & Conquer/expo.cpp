#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

int square(int x){
    return x*x;
}
int bruteforce(int a,int n){
    if(n==1)
        return a;
    return a*bruteforce(a,n-1);
}
int dec_and_con(int a,int n){
    if(n==1)
        return a;
    if(n%2==0)
        return square(dec_and_con(a,n/2));
    else
        return a*square(dec_and_con(a,(n-1)/2));
}
int main(){

    ClockTime start = Clock::now();
    int BF = bruteforce(2,10);
    ClockTime end = Clock::now();
    double execution_time_sec = duration_cast<chrono::nanoseconds>(end - start).count();
    cout<<"Brute Force takes : "<<fixed<<setprecision(50)<<execution_time_sec*1e-9<<" sec.\n";

    start = Clock::now();
    int DC = dec_and_con(2,10);
    end = Clock::now();
    execution_time_sec = duration_cast<chrono::nanoseconds>(end - start).count();
    cout<<"Decrease and Conquer takes : "<<fixed<<setprecision(5)<<execution_time_sec<<" sec.\n";

    cout<<endl<<BF<<" "<<DC<<endl;
}
