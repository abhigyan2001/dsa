class Array:
    _arr = []
    _len = 0
    _capacity = 0

    def __init__(self,capacity=16):
        if capacity < 0:
            raise ValueError(f"Illegal Capacity: {capacity}")
        self._capacity = capacity
        self._arr = [0]*capacity
        
    def size(self):
        return self._len
    def isEmpty(self):
        return self.size()==0
    def get(self,index):
        return self._arr[index]
    def set(self,index,value):
        self._arr[index]=value
    def clear(self):
        self._arr = [0]*self._capacity
        self._len = 0
    def add(self,value):
        if self._len+1 > self._capacity:
            if self._capacity == 0:
                self._capacity = 1
            else:
                self._capacity *= 2
        newarr = [0]*self._capacity
        for i in range(self._len):
            newarr[i] = self._arr[i]
        newarr[self._len+1]=value
        self._len+=1
        self._arr = newarr
