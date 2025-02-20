#include <iostream>

using namespace std;
struct date{
    int day;
    int month;
    int year;
};
struct student{
    int id;
    int age;
    date birth;
    char name[50];
}s[]={10001,16,{1,1,2006},"John",
     10002,18,{10,1,2004},"David",
     10003,17,{17,1,2005},"Lisa",
     10004,19,{4,3,2003},"Rachel",
     10005,18,{21,3,2004},"William"};
int main(){
    int m;
    printf("Enter month : "); scanf("%d",&m);
    printf("  id\tage   birtd date    name\n");
    for(int i=0;i<5;i++){
        if(s[i].birth.month==m)
            printf("%3d%5d%6d/%d/%d     %s\n",s[i].id,s[i].age,s[i].birth.day,s[i].birth.month,s[i].birth.year,s[i].name);
    }
}
