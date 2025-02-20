#include <bits/stdc++.h>

using namespace std;
int a[10][10];
int x,y;
char c;
int di[] = {-1,-1,-1,0,0,1,1,1};
int dj[] = {-1,0,1,-1,1,-1,0,1};
void print(void){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            switch(a[i][j]){
                case 0:
                    cout<<'.';
                    break;
                case 1:
                    cout<<'O';
                    break;
                case 2:
                    cout<<'X';
                    break;
            }
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
bool fil(int x,int y,int num){
    bool check = false;
    a[x][y] = num;
    for(int j=0;j<8;j++){
        int xx = x+di[j];
        int yy = y+dj[j];
        bool detected = false;
        while(a[xx][yy]!='.'&&a[xx][yy]!=0&&xx>=1&&xx<=8&&yy>=1&&yy<=8){
            if(a[xx][yy]==num){
                detected = true;
                break;
            }
            xx += di[j];
            yy += dj[j];
        }
        if(detected&&(xx!=x+di[j]||yy!=y+dj[j])){
            xx -= di[j];
            yy -= dj[j];
            check = true;
            while(xx!=x||yy!=y){
                a[xx][yy] = num;
                xx -= di[j];
                yy -= dj[j];
            }
        }
    }
    return check;
}
int main(){
    int q; cin>>q;
    a[4][4] = a[5][5] = 1;
    a[4][5] = a[5][4] = 2;
    for(int i=0;i<q;i++){
        cin>>c>>x;
        y = c-'a'+1;
        int num = (i+1)%2+1;
        bool check = false;
        if(!fil(x,y,num)){
            fil(x,y,num%2+1);
            i++;
            q++;
        }
    }
    print();
    return 0;
}
