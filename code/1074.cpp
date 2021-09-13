#include<iostream>
#include <cmath>
using namespace std;
int cnt=0,N,R,C;
void dq(int x, int y, int N){
    if(N==1){cout<<cnt; return;}
    int nx=x+N/2; int ny=y+N/2;
    //PART 1
    if(R<nx && C<ny)dq(x,y,N/2);
    //PART 2
    if(R<nx && C>=ny){cnt+=(N/2)*(N/2);dq(x,ny,N/2);}
    //PART 3
    if(R>=nx && C<ny){cnt+=2*(N/2)*(N/2);dq(nx,y,N/2);}
    //PART 4
    if(R>=nx && C>=ny){cnt+=3*(N/2)*(N/2);dq(nx,ny,N/2);}

}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    
    cin>>N>>R>>C;
    N=(int)pow(2,N);
    dq(0,0,N);
}