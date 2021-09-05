#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Num=0; int N=0;
vector<int>home;
bool check[25][25]={false};
int city[25][25]={0};
int NX[4]={0,1,0,-1};
int NY[4]={1,0,-1,0};

bool ch(int nx, int ny){
    if(nx<0 || ny<0 || nx>=N || ny>=N)return false;
    else return true;
}
void dfs(int x , int y){
    if(check[x][y])return;  
    check[x][y]=true;
    home[Num]+=1;
    for(int i=0;i<4;i++){
        int nx = x + NX[i];
        int ny = y + NY[i];
        if(city[nx][ny]!=0 &&ch(nx,ny))dfs(nx,ny);
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            scanf("%1d", &city[i][j]);
        }
    }
    home.push_back(0);
     for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            if(!check[i][j]&&city[i][j]==1){
                Num+=1;
                home.push_back(0);
                dfs(i,j);
            }
        }
    }
    cout<<Num<<"\n";
    sort(home.begin(),home.end());
    for(int i=1; i<home.size();i++){
        cout<<home[i]<<"\n";
    }
}