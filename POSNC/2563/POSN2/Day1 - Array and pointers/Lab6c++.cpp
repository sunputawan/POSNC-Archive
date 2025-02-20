#include <string.h>
#include <iostream>
using namespace std;
struct Student
{
string name;
    int id;
    int *mark;
};
typedef struct Student STD;
void inputStudent(Student* ptr,int m){
    cout<<"Please enter a name: ";
    cin>>ptr->name;
    cout<<"Please enter an id: ";
    cin>>ptr->id;
    ptr->mark=new int[m];
    for(int i=0;i<m;i++){
        cout<<"Please enter a mark: ";
        cin>>ptr->mark[i];
    }
}
void printStudent(STD* ptr,int m){
    cout<<endl<<"Name: "<<ptr->name<<endl<<"Id: "<<ptr->id<<endl;
        for(int i=0;i<m;i++)
            cout<<"Mark "<<i<<": "<<ptr->mark[i]<<endl;
}
int main ()
{
    int n,m;
    cout<<"How many students are there? :";
    cin>>n;
    cout<<"How many subjects are there? :";
    cin>>m;
    STD stu[n],*pstu;
    pstu=stu;
    for(int i=0;i<n;i++){
        cout<<endl;
        inputStudent(pstu,m);
        pstu++;
    }
    pstu=stu;
    cout<<endl<<"Student info: "<<endl;
    for(int j=0;j<n;j++){
        printStudent(pstu,m);
        delete(pstu->mark);
        pstu++;
    }
    return 0;
}
