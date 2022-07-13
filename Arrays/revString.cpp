#include<iostream>
#include<string>
using namespace std;

string reverseWord(string str);

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin >> s;
		cout << reverseWord(s) << endl;
	}
	return 0;
}

string reverseWord(string str){
	string ret=str;
	int n = str.length();
	for(int i = 0; i < n; i++){
		ret[i]=str[n-i-1];
	}
	return ret;
}
