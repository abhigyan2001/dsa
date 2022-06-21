#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxsum=INT_MIN;
        for (int num : nums){
            cursum += num;
            if(cursum>maxsum){
                maxsum = cursum;
            }
            if(cursum<0){
                cursum=0;
            }
        }
        return maxsum;
    }
};

int main(){
	int t;
	cin >> t;
    Solution s;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int sum = s.maxSubArray(a);
		cout << sum << endl;
	}
	return 0;
}