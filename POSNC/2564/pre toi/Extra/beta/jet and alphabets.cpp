#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char c = 'A';
    while(n--){
        int k = m;
        while(k--){
            if(c=='Z'+1)
                c = 'A';
            printf("%c",c++);
        }
        printf("\n");
    }
}
