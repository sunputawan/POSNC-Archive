#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;
int n = 6;
char first[] = {'a','b','c','d','e','f'};
int second[] = {45,13,12,16,9,5};
struct node{
    char name;
    int freq;
    node *l,*r;
    node(char name, int freq){
        l=NULL; r =NULL;
        this->name = name;
        this->freq = freq;
    }
};
struct cmp{
    bool operator()(const node* a,const node* b){
        return a->freq>=b->freq;
    }
};
priority_queue<node*,vector<node*>,cmp> minheap;
void input(void){
    for(int i=0;i<n;i++){
        minheap.push(new node(first[i],second[i]));
    }
}
void print_data_ref(priority_queue<node*,vector<node*>,cmp> q){
    cout<<"Data ref : ";
    while(!q.empty()){
        cout<<q.top()->name<<":"<<q.top()->freq<<", ";
        q.pop();
    }
    cout<<endl;
}
void HuffmanCodes(void){
    node *left,*right,*top;
    while(minheap.size()!=1){
        left = minheap.top(); minheap.pop();
        right = minheap.top(); minheap.pop();
        top = new node(' ',left->freq+right->freq);
        top->l = left; top->r = right;

        minheap.push(top);
    }
}
void printcode(node* root,string str){
    if(root==NULL)
        return;
    if(root->name!=' ')
        cout<<root->name<<" : "<<str<<endl;
    printcode(root->l,str+"0");
    printcode(root->r,str+"1");
}
string generate_code(int size){
    string str;
    srand(time(NULL));
    for(int i=0;i<size;i++){
        int x = rand();
        if(x%2==0)
            str.push_back('0');
        else
            str.push_back('1');
    }
    return str;
}
void decode(string str){
    cout<<"\ncode ref : "<<str<<endl<<"Decode : ";
    int i=0;
    node* p = minheap.top();
    while(i!=str.size()+1){
        if(p->name!=' '){
            cout<<p->name;
            p=minheap.top();
            continue;
        }
        if(str[i]=='0')
            p=p->l;
        else if(str[i]=='1')
            p=p->r;
        i++;
    }
    cout<<endl;
}
int main(){
    input();
    print_data_ref(minheap);
    HuffmanCodes();
    printcode(minheap.top(),"");
    string code = generate_code(20);
    decode(code);
}
