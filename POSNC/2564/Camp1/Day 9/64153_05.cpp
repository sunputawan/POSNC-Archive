#include <iostream>

using namespace std;
int a[10000];
int highest=0;
void space(int n){
    for(int i=0;i<n;i++)
        cout<<' ';

}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //a[i]=2*a[i]-1;
        if(highest<a[i])
            highest=a[i];
    }
    for(int l=highest;l>0;l--){
        for(int i=0;i<n;i++){
            if(a[i]<l) space(a[i]);
            else space(l-1);
            if(l<=a[i]) cout<<'/';
            space(2*(a[i]-l));
            if(l<=a[i]) cout<<'\\';
            if(a[i]<l) space(a[i]);
            else space(l-1);
        }
        cout<<endl<<endl;
    }
}
