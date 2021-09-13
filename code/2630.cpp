#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int color1=0; int color0=0; 
vector<vector<int> >v;
bool equalArray(int x , int y, int num , int color){
    for(int i=x ; i<x+num ; i++){
        for(int j=y ; j<y+num ;  j++){
            if(v[i][j]!=color)return false;
        }
    }
    return true;
}
void dc(int x , int y, int num){
    //all Num =0 
    if(equalArray(x,y,num,0)){color0++;return;}
    //all Num=1
    if(equalArray(x,y,num,1)){color1++; return;}
    
    //NO
    int dy[4]={0,0,num/2,num/2};
    int dx[4]={0,num/2,0,num/2};
    for(int i=0; i<4 ; i++){
        dc(x+dx[i],y+dy[i],num/2);
    }
}
int main(){
    ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
    
    int N;
    cin>>N;
    for(int i=0 ; i<N ;i++){
        vector<int>vTemp;
        for(int j=0; j<N ; j++){
            int tmp;
            cin>>tmp;
            vTemp.push_back(tmp);
        }
        v.push_back(vTemp);
    }
    dc(0,0,N);
    cout<<color0<<"\n"<<color1;
}