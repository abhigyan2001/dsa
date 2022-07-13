#include<vector>
#include<utility>
#include<iostream>
using namespace std;
#define ll long long
pair<long long, long long> getMinMax(vector<ll> a, int n);

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		pair<ll,ll> pp = getMinMax(a,n);
		cout << pp.first << " " << pp.second << endl;
	}
	return 0;
}

pair<long long, long long> getMinMax(vector<ll> a, int n) {
	ll max=a[n-1], min=a[n-1];
	for(int i=0; i<n; i++){
		if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}
	}
	return {min,max};
}
