Data Structures Easy to Advanced Course

Data Structure 1: Arrays

2 types of arrays:

1: Static Arrays
2: Dynamic Arrays

### What are Static arrays:

It is a fixed length container containing n elements indexable from the range [0, n-1]

Q. What is meant by being indexable?
A. This means that each slot/index in the array can be referenced with a number

Furthermore static arrays are contiguous chunks of memory.


Where are they used?

1. Storing and accessing sequential Data
2. Temporarily storing objects
3. Used by IO routines as buffers
4. Lookpu tables and inverse lookup tables
5. Can be used to return multiple values from a function
6. Used in dynamic programming to cache answers to subproblems (e.g. Knapsack problem and Coin Change problem)

Complexity:

            Static Array    Dynamic Array
Access:     O(1)            O(1)
Search:     O(n)            O(n) 
(potentially need to travel the entire array in case the element does not exist)
Insertion:  N/A             O(n)
Appending:  N/A             O(1)
(It is always added to the end of the array)
Deletion:   N/A             O(n)

44  12  -5  17  6   0   3   9   100
0   1   2   3   4   5   6   7   8

Generally array indexing is 0 based meaning that the first element is found in position zero.

Worst of all is Quantum computing, as it tries to please Mathematicians, Physicists and Computer Scientists all at the same time

Now see Source Code

### Data Structure 2: Linked Lists

A linked list is a sequential list of nodes that hold data which point to other nodes also containing data
The last node has a null reference.

Where are they used?

1. Used in many lists, stacks and queues implementations.
2. Great for creating circular lists
3. Can easily model real world objects such as trains
4. Used in separate chaining which is present certain Hashtable implementations to deal with hashing collisions
5. Often used in the implementation of adjacency lists for graphs.

Terminology:

Head: The first node in a linked list
Tail: The last node in a linked list
Pointer: Reference to another node
Node: An object containing data and pointers

Singly vs Doubly Linked Lists:

Singly linked lists only hold a reference to the next node. 
In the implementation, you always maintain a reference to the 
head to the linked list and a reference to the tail node for 
quick additions or removals.

With a doubly linked list each node holds a reference to the next
and the previous node. In the implementation you always maintain a reference
to the head and tail of the double linked list to do quick additions or removals
from both ends of the list.

Pros and Cons of Singly and Doubly Linked Lists

        |Pros                    |Cons
Singly  |Uses less memory        |Cannot easily access previous element
Linked  |Simpler implementation  |
        |                        |
Doubly  |Can be traversed        |Takes 2x memory
Linked  |backwards               |

Implementation Details

Inserting in Singly Linked Lists:

Given Task: Insert 11 where the 3rd node is.

Head        Tail
5   23  7   13

First, create a new pointer which points to the head.

Then, traverse to the 2nd node.

Then, add a new node with value 11 that points to the node containing 7.
And then, point the node containing 23 towards 11.

That's it.

Inserting in Doubly Linked Lists:

Create a pointer and advance it to just before the insertion position.

Then create a new node which points forward to the node after the insertion position,
and change the next node's backwards pointer to point back to the newly created node.

Next, change the forward pointer of the previous node to point to the newly created node,
and set the backwards pointer of the newly created node to point back to the previous node.

Again, that's it

Removing from a Singly Linked List:

7 0 4 9 15
(let's say we want to remove 9 from it)

We use 2 pointers now:
Trav1 and Trav2 are used. 
Trav1 points to the node before the node we wish to remove, and Trav2 points to the next node.

Once we advance them to the right position, another pointer (temp) is created 
to the node we wish to remove so that we can deallocate its memory later on.

Now, we set the pointer of node 4 (Trav1) to point to Trav2, 
and we can now deallocate the temp node that we wish to delete. Important in C/C++.

Removing in a Double Linked List:

We now only need a single traversing pointer now.

We move this pointer to the position that we wish to remove. 

Now, set the previous node's forward pointer to the next node, 
and the next node's backward pointer to the previous node,
and then deallocate the original pointer.

Complexity Analysis of Linked Lists:


                 Singly Linked   Doubly Linked
Search           O(n)            O(n)
Insert at Head   O(1)            O(1)
Insert at Tail   O(1)            O(1)
Remove at Head   O(1)            O(1)
Remove at Tail   O(n)            O(1)           
Remove in Middle O(1)            O(n)

In Singly linked, Remove at Tail is O(n) since we need to seek to 
the end of the list and find out the new tail's value

This doesn't happen in Double Linked lists since we can remove a tail node
in the same way as removing a head node.

Similarly, the Remove in Middle could be the last but one element, 
and we would need to seek to the end in that case.

Now see Source Code

### Data Structure 3: Stack 












-> A Note on Recursive vs Iterative Algorithms:

Recursive Algorithms work better when the languages have tail call optimization, 
i.e. the language optimizes the code to avoid taking up extra memory.
Python doesn't implement Tail call optimization, but Swift (for iOS) does.