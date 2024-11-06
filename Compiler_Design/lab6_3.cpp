#include <bits/stdc++.h>
using namespace std;
void error(string s,int n){
cout<<"Error at position:"<<n+1<<endl;
}


bool A(string s,int&n){
	cout<<"A()";
    if(s[n]=='a'){
        n++;
        if(s[n]=='b'){
            n++;
            return true;
        }
        else{
            return true;
        }
    }
    error(s,n);
    return false;
}

bool S(string s,int &n){
	cout<<"S()";
    if(s[n]=='c'){
        n++;
        if(A(s,n) && s[n]=='d' && n==(s.size()-1)) {
            return true;
	}

        error(s,n);
        return false;
    }
    else{
        error(s,n);
        return false;
    }
}



int main(){
    cout<<"Enter the string:";
    string s;
    cin>>s;
    int n=0;
    if(S(s,n)){
        cout<<"\nString is accepted"<<endl;
    }
    else{
    cout<<"\nString not accepted :("<<endl;
    }
    return 0;
}
