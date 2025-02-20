#include <iostream>
#include <vector>
#include <time.h>
#define n 10000

using namespace std;
vector<int> arr;
void generate_input(void){
    srand(time(NULL));
    for(int i=0;i<n;i++)
        arr.push_back(rand()%2000-1000);
    cout<<"List ref : ";
    for(auto i:arr)
        cout<<i<<" ";
}
int *crosssolve(int l,int mid,int r){
    int sum = 0;
    int maxleftsum = 0;
    int maxrightsum = 0;
    int leftbound = mid;
    int rightbound  = mid;

    for(int i=mid;i>=l;i--){
        sum+=arr[i];
        if(maxleftsum<sum){
            maxleftsum = sum;
            leftbound = i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=r;i++){
        sum+=arr[i];
        if(maxrightsum<sum){
            maxrightsum = sum;
            rightbound = i;
        }
    }
    int *ans = new int[3];
    ans[0] = maxleftsum + maxrightsum;
    ans[1] = leftbound; ans[2]=  rightbound;
    return ans;
}
int* divide(int l,int r){
    if(l==r){
        int *ans = new int[3];
        ans[0] = arr[l];
        ans[1] = l; ans[2] = r;
        return ans;
    }
    int *left = new int[3];
    int *right = new int[3];
    int *cross = new int[3];
    int mid = (l+r)/2;

    left = divide(l,mid);
    right = divide(mid+1,r);
    cross = crosssolve(l,mid,r);

    if(left[0]>right[0]&&left[0]>cross[0])
        return left;
    else if(right[0]>left[0]&&right[0]>cross[0])
        return right;
    else
        return cross;
}
int main(){
    ios_base::sync_with_stdio(false);
    generate_input();
    int *ans = new int[3];
    ans = divide(0,n-1);
    cout<<"\nMaximum subarray sum : "<<ans[0];
    cout<<" ["<<ans[1]<<","<<ans[2]<<"]"<<endl;
}
