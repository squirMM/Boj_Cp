#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>dicM;
map<int,string>dic;
int main(){
    ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

    int N,M;string w;
    cin>>N>>M;
    for(int i=1; i<=N ; i++){
        cin>>w;
        dic.insert(make_pair(i,w));
        dicM.insert(pair<string,int>(w,i));
    }
    for(int i=0; i<M; i++){
        string q;
        cin>>q;
        if(isdigit(q[0])){
            int num= stoi(q);
             map<int,string>::iterator it = dic.find(num);
             cout<<it->second<<"\n";
        }
        else{
            map<string,int>::iterator it = dicM.find(q);
            cout<<it->second<<"\n";
        }
       
    }
}
