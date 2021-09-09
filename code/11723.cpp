#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector <int>s;
vector<string>strArr;
void command(string c, int n){
    vector<int>::iterator it;
    if(c=="empty"){
        s.clear();
    }
    else if(c=="all"){
        s.clear();
        for(int i=1 ; i<=20 ; i++)s.push_back(i);
    }
    else{
        it=find(s.begin(),s.end(),n);
        //yes
        if(it!=s.end()){
            if(c=="remove"||c=="toggle")s.erase(it);
            if(c=="check")cout<<1<<"\n";
        }
        //no
        else{
            if(c=="add"||c=="toggle")s.push_back(n);
            if(c=="check")cout<<0<<"\n";
        } 
    }
}
int main(){
    int Num;
    cin>>Num;
    string comm;
    int n;
    while(Num--){
        // getline(cin,comm);
        // strArr.clear();

        // char *buffer = new char[1000];
	    // strcpy(buffer, comm.c_str());
        
        // char *tok = strtok(buffer, " ");
	    // while(tok != NULL) {
        //     strArr.push_back(string(tok));
        //     tok = strtok(NULL, " ");
	    // }
        // if(strArr.size()==2)command(strArr[0],stoi(strArr[1]));
        // if(strArr.size()==1)command(strArr[0],-1);
       cin>>comm;
       if(comm=="all"||comm=="empty"){
           command(comm,-1);
           continue;
       }
       cin>>n;
       command(comm,n);
    }
}