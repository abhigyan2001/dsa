from linked_list import *
class Queue:
    lst = LinkedList()
    def __init__(self,elem=None):
        if elem:
            self.offer(elem)
    def __len__(self):
        return len(self.lst)
    def isempty(self):
        return len(self.lst)==0
    def offer(self,elem):
        self.lst.addlast(elem)
    def poll(self):
        return self.lst.removefirst()
    def peek(self,index=0):
        return self.lst[index]
    def __getitem__(self,index):
        return self.peek(index)
    def __iter__(self):
        return self
    def __next__(self):
        return self.lst.__next__()
    def __repr__(self):
        return repr(self.lst)