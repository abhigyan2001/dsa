#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0,i;
        for(i = digits.size()-1; i >=0; i--){
            if(digits[i]==9){
                digits[i]=0;
                carry=1;
            }
            else{
                digits[i]++;
                carry=0;
                break;
            }
        }
        //cout << i << endl;
        if(i==-1 && carry==1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};