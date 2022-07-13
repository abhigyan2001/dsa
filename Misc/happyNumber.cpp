using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int d, sumSq=0;
        while(n!=4){
            while(n!=0){
                d = n%10;
                sumSq += d*d;
                n /= 10;
            }
            if(sumSq==1){
                return true;
            }
            n = sumSq;
            sumSq = 0;
        }
        return false;
    }
};