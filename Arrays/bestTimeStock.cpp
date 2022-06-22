#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        int buy=0,sell=1,profit=0,maxprofit=0,n=prices.size();
        while(sell < n){
            profit = prices[sell]-prices[buy];
            if(profit>maxprofit){
                maxprofit = profit;
            }
            if(profit<=0){
                buy=sell;
            }
            sell++;
        }
        return maxprofit;
    }
};