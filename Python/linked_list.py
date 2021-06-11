class Node:
    def __init__(self, data = None, prev = None, next = None):
        self.data = data
        self.next = next
        self.prev = prev
    def __str__(self):
        return str(self.data)
    def __repr__(self):
        return str(self.data)
class LinkedList:
    def __init__(self):
        self.size = 0
        self.head = None
        self.tail = None
        self.travIter = None
    def __len__(self):
        return self.size
    def clear(self):
        trav = self.head
        while trav:
            next = trav.next
            trav.prev = trav.next = None
            trav.data = None
            trav = next
        trav = self.head = self.tail = None
        self.size = 0
    def isempty(self):
        return self.size==0
    def add(self,elem):
        self.addlast(elem)
    def addfirst(self,elem):
        if self.isempty():
            self.head = self.tail = Node(elem,None,None)
        else:
            self.head.prev = Node(elem,None,self.head)
            self.head = self.head.prev
        self.size+=1
    def addlast(self,elem):
        if self.isempty():
            self.head = self.tail = Node(elem,None,None)
        else:
            self.tail.next = Node(elem,self.tail,None)
            self.tail = self.tail.next
        self.size+=1
    def peekfirst(self):
        return self.head.data
    def peeklast(self):
        return self.tail.data
    def removefirst(self):
        if self.isempty():
            raise Exception("Empty list")
        data = self.head.data
        self.head = self.head.next
        self.size-=1
        if self.size==0:
            self.tail = None
        self.head.prev = None
        return data
    def removelast(self):
        if self.isempty():
            raise Exception("Empty list")
        data = self.tail.data
        self.tail = self.tail.prev
        self.size-=1
        if self.size==0:
            self.head = None
        self.tail.next = None
        return data
    def __remove__(self,node):
        if node.prev == None:
            return self.removefirst()
        if node.next == None:
            return self.removelast()
        node.next.prev = node.prev
        node.prev.next = node.next
        data = node.data
        node = node.prev = node.next = None
        self.size-=1
        return data
    def removeAt(self,index):
        if index<0 or index>=self.size:
            raise ValueError()
        i = 0
        trav = self.head
        if(index < self.size//2):
            for i in range(index):
                trav = trav.next
        else:
            for i in range(index-1,-1,-1):
                trav = trav.prev
        return self.__remove__(trav)
    def remove(self,obj):
        trav = self.head
        while trav:
            if obj==trav.data:
                self.__remove__(trav)
                return True
            trav = trav.next
        return False
    def indexof(self,obj):
        trav = self.head
        counter = 0
        while trav:
            if obj==trav.data:
                return counter
            trav = trav.next
            counter+=1
        return -1
    def contains(self,obj):
        return self.indexof(obj)!=-1
    def __iter__(self):
        self.travIter = self.head
        return self
    def __next__(self):
        if self.travIter is None:
            raise StopIteration
        data = self.travIter.data
        self.travIter = self.travIter.next
        return data
    def __repr__(self):
        sb = "["
        for trav in self:
            sb+=str(trav)
            if trav is not None:
                sb+=","
        sb+="]"
        return str(sb)

