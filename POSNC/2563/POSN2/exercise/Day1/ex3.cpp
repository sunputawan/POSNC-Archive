#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int>v={10, 12, 15, 19, 20, 1, -3, -7, 8, 14, 12, 30, 58, -100, 44};
bool increasing_comparator(int i,int j){
    return (i<j);
}
bool decreasing_comparator(int i,int j){
    return (i>j);
}
void print_vec(void){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl<<endl;
}
int main(){
    std::sort(v.begin(),v.end(),increasing_comparator);
    print_vec();
    std::sort(v.begin(),v.end(),decreasing_comparator);
    print_vec();
    cout<<"Max : "<< *std::max_element(v.begin(),v.end())<<endl;
    cout<<"Min : "<< *std::min_element(v.begin(),v.end())<<endl;
    int a=7;
    if(std::binary_search(v.begin(),v.end(),7)){
        std::cout<<"\""<<a<<"\" detected in this list."<<endl;
    }
    else
        std::cout<<"\""<<a<<"\" not detected in this list."<<endl;
    a=-7;
    if(std::binary_search(v.begin(),v.end(),-7),decreasing_comparator){
        std::cout<<"\""<<a<<"\" detected in this list."<<endl;
    }
    else
        std::cout<<"\""<<a<<"\" not detected in this list."<<endl;
    std::sort(v.begin(),v.end());
    auto low=std::lower_bound(v.begin(), v.end(),0);
    auto up=std::upper_bound(v.begin(),v.end(),40);
    for(auto i=low;i<v.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i=up-1;i>=v.begin();i--){
        cout<<*i<<" ";
    }
}
