#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int Total;int pa;int cnt=0;
vector<int>vir[101];
bool check[101]={false};
void dfs(int num){
    check[num]=true;
    for(int nxt:vir[num]){
        if(!check[nxt]){
            cnt+=1;
            dfs(nxt);
        }
    }
    return;
}
int main(){
    cin>>Total;
    cin>>pa;
    int a=0; int b=0;
    for(int i=0; i<pa; i++){
        cin>>a>>b;
        vir[a].push_back(b);
        vir[b].push_back(a);
    }
    dfs(1);
    cout<<cnt;
}