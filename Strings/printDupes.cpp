#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
class printDupes{
	public:
	void printDupeLetters(string s){
		int n = s.length();
		unordered_map<char,int> counts;
		string rpts = "";
		for(int i = 0; i<n; i++){
			if(counts.find(s[i])!=counts.end()){
				counts[s[i]]++;
			}
			else{
				counts[s[i]]=1;
				rpts+=s[i];
			}
		}
		for(int i=0; i<rpts.length(); i++){
			if(counts[rpts[i]]!=1){
				cout << rpts[i] << " occurs " << counts[rpts[i]] << " times" << endl;
			}
		}
	}
};
/* Driver Code */
int main(){
	printDupes p;
	string t;
	getline(cin, t);
	p.printDupeLetters(t);
	return 0;
}
