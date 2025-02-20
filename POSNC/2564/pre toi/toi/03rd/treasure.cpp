#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    getline(cin,s);
    int i=0;
    double x=0,y=0;
    double sq = sqrt(2);
    while(s[i]!='*'){
        double num=0;
        while('0'<=s[i]&&s[i]<='9'){
            num = (num*10)+s[i]-48;
            i++;
        }
        if(s[i+1]==' '){ //N S E W
            if(s[i]=='N')
                y+=num;
            else if(s[i]=='S')
                y-=num;
            else if(s[i]=='E')
                x+=num;
            else if(s[i]=='W')
                x-=num;
            i+=2;
        }
        else{
            double val = num/sq;
            if(s[i]=='N'){
                if(s[i+1]=='E'){
                    x+=val;
                    y+=val;
                }
                else{
                    x-=val;
                    y+=val;
                }
            }
            if(s[i]=='S'){
                if(s[i+1]=='E'){
                    x+=val;
                    y-=val;
                }
                else{
                    x-=val;
                    y-=val;
                }
            }
            i+=3;
        }
    }
    printf("%.3f %.3f\n%.3f",x,y,sqrt(x*x+y*y));
    return 0;
}
