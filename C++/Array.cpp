#include <iostream>
using namespace std;
template <typename T>
class Array {
    private:
        T *arr;
        int len = 0; //length the user thinks the array is
        int capacity = 0; //actual array capacity
    public:
        Array(int cap=16){
            if (cap<0){
                throw invalid_argument("Illegal Capacity: "+to_string(cap));
            }
            capacity = cap;
            arr = new T[cap];
            for(int i=0; i<capacity; i++){
                arr[i] = 0;
            }
            
        }
        ~Array(){ delete [] arr; }
        T& operator[](int index){ return arr[index]; }
        
        int size(){ return len; }
        
        bool isEmpty(){ return size() == 0; }

        T get(int index){ return arr[index]; }
        
        void set(int index, T elem){ 
            if (index >= capacity){
                add(elem);
            }
            else{
                arr[index] = elem;
                len++;
            }
        }
        
        void clear(){
            for(int i = 0; i < capacity; i++)
                arr[i] = 0;
            len = 0;
        }
        void add(T elem){
            if (len+1 > capacity){
                if (capacity == 0) capacity = 1;
                else capacity*=2;
                T *newarr = new T[capacity];
                for (int i = 0; i < len; i++){
                    newarr[i] = arr[i];
                }
                delete [] arr;
                arr = newarr;
            }
            arr[len++]=elem;
        }
        T removeAt(int rmIndex){
            if (rmIndex >= len || rmIndex < 0) throw out_of_range(to_string(rmIndex) +" out of range for len " + std::to_string(len));
            T data = arr[rmIndex];
            T *newarr = new T[len-1];
            for (int i=0, j=0; i < len; i++, j++){
                if (i==rmIndex){
                    j--;
                }
                else{
                    newarr[j]=arr[i];
                }
            }
            delete [] arr;
            arr = newarr;
            capacity = --len;
            return data;
        }
        bool remove(T t){
            for (int i=0; i<len; i++){
                if (arr[i]==t){
                    removeAt(i);
                    return true;
                }
            }
            return false;
        }
        int indexOf(T t){
            for (int i=0; i<len; i++){
                if (arr[i]==t){
                    return i;
                }
            }
            return -1;
        }
        bool contains(T t){ return indexOf(t) != -1; }
};
int main()
{
    cout << "hello" <<endl;
    Array<float>z(122);
    for (int i = 0; i < 127; i++){
        z.set(i,(float)i);
    }
    for (int i = 0; i < z.size(); i++){
        cout << z.get(i) <<endl;
    }
    return 0;
}