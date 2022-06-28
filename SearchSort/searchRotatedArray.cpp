class Solution{
public:
    int search(int A[], int l, int h, int key){
        if(l>h){
            return -1;
        }
        int find = l+(h-l)/2;
        if(A[find]==key){
            return find;
        }
        else if(A[find]>=A[l]){
            if(A[find]>=key && key>=A[l]){
                return search(A,l,find-1,key);
            }
            else{
                return search(A,find+1,h,key);
            }
        }
        else{
            if(A[find]<=key && key<=A[h]){
                return search(A,find+1,h,key);
            }
            else{
                return search(A,l,find-1,key);
            }
        }
    }
};