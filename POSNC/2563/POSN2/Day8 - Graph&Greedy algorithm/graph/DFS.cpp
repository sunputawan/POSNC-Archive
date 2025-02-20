#include <iostream>
#include <vector>
char name[9]={'S','A','B','C','D','E','F','G','H'};
int edge[9][9]={0,3,2,5,0,0,0,0,0,
               0,0,0,3,0,0,0,2,0,
               0,5,0,0,6,0,0,0,0,
               0,0,4,0,0,0,0,0,3,
               0,0,0,0,0,2,3,0,0,
               0,0,0,0,0,0,5,0,0,
               0,0,0,0,0,0,0,0,0,
               0,0,0,0,4,5,0,0,0,
               0,4,0,0,4,0,0,0,0};
using namespace std;

vector<char> Open={'S'};
vector<char> Visited;
vector<char> Path;

int searchname(char a){
    for(int i=0;i<9;i++){
        if(name[i]==a)
            return i;
    }
}
bool is_in_open(char a){
    for(int i=0;i<Open.size();i++){
        if(Open[i]==a)
            return true;
    }
    return false;
}
bool is_in_visited(char a){
    for(int i=0;i<Visited.size();i++){
        if(Visited[i]==a)
            return true;
    }
    return false;
}
void printvec(vector<char> a){
    for(int i=0;i<a.size()-1;i++)
        cout<<a[i]<<"("<< edge[searchname(a[i])][searchname(a[i+1])]<<") "<<"-> ";
}
void depth_first_search(char goal){
    while(Open.size()!=0){
        char q=Open[Open.size()-1];
        int n=searchname(q);
        int nothing=1;
        Open.pop_back();
        Visited.push_back(q);
        if(q==goal){
            Path.push_back(q);
            printvec(Path);
            cout<<char(q) << " --->";
            cout<<"END";
            return;
        }
        for(int i=0;i<9;i++){
            if((edge[n][i])&&(!is_in_visited(name[i]))&&(!is_in_open(name[i]))){
                Open.push_back(name[i]);
                nothing=0;
            }
        }
        if(!nothing)
            Path.push_back(q);
    }
}
int main(){
    char goal='F';
    depth_first_search(goal);

}

