#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;

    for(int i = 0;i < str.length();i++){
        if(i % 2 == 0 && i != 0) str[i] = 'a';
    }

    cout<<endl;

    cout<<str;
}