#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<vector<int>> current_member;
vector<int> class_order;
unordered_map<int,int> cl;
vector<int> ans;
int main(){
    int m,n;
    cin>>m>>n;
    current_member.resize(m);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cl[b]=a;
    }
    char menu;
    while(menu!='X'){
        cin>>menu;
        switch(menu){
            case 'E':{
                int student;
                cin>>student;
                bool have_class_head=false;
                for(auto i:class_order)
                    if(i==cl[student]){
                        have_class_head=true;
                        break;
                    }
                if(!have_class_head)
                    class_order.push_back(cl[student]);
                current_member[cl[student]-1].push_back(student);
                break;
            }
            case 'D':{
                ans.push_back(current_member[class_order[0]-1][0]);
                current_member[class_order[0]-1].erase(current_member[class_order[0]-1].begin());
                            if(current_member[class_order[0]-1].empty()) class_order.erase(class_order.begin());
            }
        }
    }
    for(auto i:ans)
        cout<<i<<endl;
    cout<<0;
}
