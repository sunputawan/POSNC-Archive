#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <math.h>
using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;
int brute(int a,int n){
    if(n>0)
        return a*brute(a,n-1);
    else
        return 1;
}
int decrease_conquer(int a,int n){
    if(n==1)
        return a;
    else if(n%2==0)
        return pow(decrease_conquer(a,n/2),2);
    else
        return pow(decrease_conquer(a,(n-1)/2),2)*a;
}
int main(){
    int a=2,n=10;
    ClockTime start_time = Clock::now();
    cout<<brute(a,n)<<endl;
    ClockTime end_time = Clock::now();

    double execution_time_sec = duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Brute force takes " << setprecision(5) << execution_time_sec*1e-9 << " seconds" << endl;

    start_time = Clock::now();
    cout<<decrease_conquer(a,n)<<endl;
    end_time = Clock::now();

    execution_time_sec = duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "decrease and conquer takes " << setprecision(5) << execution_time_sec*1e-9 << " seconds" << endl;

    start_time = Clock::now();
    cout<<pow(a,n)<<endl;
    end_time = Clock::now();

    execution_time_sec = duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "pow takes " << setprecision(5) << execution_time_sec*1e-9 << " seconds" << endl;
}
