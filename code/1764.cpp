#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector <string> ans;
vector <string> ds;
vector<string>::iterator it;
int main(){
    ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

    int N ; int M;
    cin>>N>>M; 

    ds.resize(N);
    for(int i=0 ;  i< N ; i++){cin>>ds[i];}
    sort(ds.begin(),ds.end());

    string tmp;
    while(M--){
        cin>>tmp;
        if(binary_search(ds.begin(),ds.end(),tmp)){ans.push_back(tmp);}
    }
    sort(ans.begin(),ans.end());

    cout<<ans.size()<<"\n";
    for(int i=0 ; i<ans.size();i++){cout<<ans[i]<<"\n";}
}