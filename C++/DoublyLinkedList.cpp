#include <iostream>
using namespace std;
template <typename T>
class DoublyLinkedList{
private:
    int len = 0;
    class Node {
        public:
            T data;
            Node *prev;
            Node *next;
            Node(T d, Node *p, Node *n) : data(d), prev(p), next(n){}
    };
    Node *head;
    Node *tail;
    T remove(Node<T> node){
        if(node->prev==NULL){
            return removeFirst();
        }
        if(node->next==null){
            return removeLast();
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        T data = node->data;

        node->data = NULL;
        node = node->prev = node->next = NULL;
        --size;
        return data;
    }
public:
    DoublyLinkedList() : head(NULL), tail(NULL),len(0){}
    DoublyLinkedList(T (&arr)[N]) : head(NULL), tail(NULL),len(N){
        for(int i = 0; i < N; i++){
            add(arr[i]);
        }
    }
    void clear(){
        Node *trav = head;
        while(trav!=NULL){
            trav->prev = NULL;
            trav->next = NULL;
            trav->data = NULL;
            trav = next;
        }
        head = tail = trav = NULL;
        len = 0;
    }
    int size(){
        return len;
    }
    bool isEmpty(){
        return len==0;
    }
    void add(T elem){
        addLast(elem);
    }
    void addLast(T elem){
        if(isEmpty()){
            head = tail = new Node(elem, NULL, NULL);
        }
        else{
            tail->next = new Node(elem, tail, NULL);
            tail = tail->next;
        }
    }
    void addFirst(T elem){
        if (isEmpty()){
            head = tail = new Node(elem, NULL, NULL);
        }
        else {
            head.prev = new Node(elem, NULL, NULL);
            head = head.prev;
        }
        size++;
    }
    T peekFirst(){
        if(isEmpty()){
            throw runtime_error("Empty List");
        }
        return head->data;
    }
    T peekLast(){
        if(isEmpty()){
            throw runtime_error("Empty List");
        }
        return tail->data;
    }
    T removeFirst(){
        if (isEmpty()){
            throw runtime_error("Empty List");
        }
        T data = head->data;
        head = head->next;
        --size;
        if(IsEmpty()) tail = NULL;
        else head->prev = NULL;
        return data;
    }
    T removeLast(){
        if (isEmpty()){
            throw runtime_error("Empty List");
        }
        T data = tail->data;
        tail = tail->next;
        --size;
        if(IsEmpty()) tail = NULL;
        else head->prev = NULL;
        return data;
    }
    bool remove(T obj){
        Node* trav = head;
        if(obj == NULL){
            for(trav = head; trav != null; trav = trav->next){
                if(trav->data == null){
                    remove(trav);
                    return true;
                }
            }
        }
        else {
            for(trav = head; trav != null; trav = trav.next){
                if(obj.equals(trav.data)){
                    remove(trav);
                    return true;
                }
            }
        }
        return false;
    }
    T get(int index){
        Node* trav = head;
        for(int i = 0; i < index; i++){
            trav = trav.next;
        }
        return trav.data;
    }
    int indexOf(T obj){
        Node* trav = head;
        int index = 0;
        if(obj == NULL){
            for(trav = head; trav != NULL; trav = trav->next,index++){
                if(trav->data == null){
                    return index;
                }
            }
        }
        else {
            for(trav = head; trav != null; trav = trav->next,index++){
                if(obj == (trav->data)){
                    return index;
                }
            }
        }
        return -1;
    }
    bool contains(T obj){
        return indexOf(obj)!=-1;
    }
};
int main(){
    return 0;
}