#include <iostream>

namespace dsa {

template <typename T>
class DoublyLinkedList;

template <typename T>
class DoublyLinkedList{
private:
    class Node {
        public:
            T data;
            Node* prev;
            Node* next;
            Node() : prev(nullptr), next(nullptr){}
            Node(T d, Node* p, Node* n) : data(d), prev(p), next(n){}
    };
    int len = 0;
    Node* head;
    Node* tail;
    T remove(Node* node){
        if(node->prev==nullptr){
            return removeFirst();
        }
        if(node->next==nullptr){
            return removeLast();
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        T data = node->data;

        delete node;
        node = node->prev = node->next = nullptr;
        len--;
        return data;
    }
public:
    virtual ~DoublyLinkedList() {
        clear();
    }
    DoublyLinkedList() : head(nullptr), tail(nullptr),len(0){}
    DoublyLinkedList(T (&arr)[N]) : head(nullptr), tail(nullptr), len(N){
        for(int i = 0; i < N; i++){
            add(arr[i]);
        }
    }
    void clear(){
        Node* trav = head;
        do{
            Node* next = trav->next;
            delete trav;
            trav = next;
        }while(trav!=nullptr);
        delete head;
        delete tail;
        delete trav;
        head = tail = trav = nullptr;
        len = 0;
    }
    int size(){
        return len;
    }
    bool isEmpty(){
        return len==0;
    }
    void add(const T &elem){
        addLast(elem);
    }
    void addLast(const T &elem){
        if(isEmpty()){
            head = tail = new Node(elem, nullptr, nullptr);
        }
        else{
            tail->next = new Node(elem, tail, nullptr);
            tail = tail->next;
        }
        len++;
    }
    void addFirst(const T &elem){
        if (isEmpty()){
            head = tail = new Node(elem, nullptr, nullptr);
        }
        else {
            head->prev = new Node(elem, nullptr, nullptr);
            head = head->prev;
        }
        size++;
    }
    void addAt(int index, const T &data){
        if (index < 0){
            throw ("Illegal Index");
        }
        if (index ==0){
            addFirst(data);
            return;
        }
        if (index==len){
            addLast(data);
            return;
        }
        Node* trav = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        Node* newnode = new Node(data, trav, trav->next);
        trav->next->prev = newnode;
        trav->next = newnode;
        len++;
    }
    T peekFirst(){
        if(isEmpty()){
            throw std::runtime_error("Empty List");
        }
        return head->data;
    }
    T peekLast(){
        if(isEmpty()){
            throw std::runtime_error("Empty List");
        }
        return tail->data;
    }
    T removeFirst(){
        if (isEmpty()){
            throw std::runtime_error("Empty List");
        }
        T data = head->data;
        head = head->next;
        len--;
        if(isEmpty()){
            delete tail;
            tail = nullptr;
        }
        else{
            delete head->prev;
            head->prev = nullptr;
        }
        return data;
    }
    T removeLast(){
        if (isEmpty()){
            throw std::runtime_error("Empty List");
        }
        T data = tail->data;
        tail = tail->prev;
        len--;
        if(isEmpty()){
            delete head;
            head = nullptr;
        }
        else{
            delete tail->next;
            tail->next = nullptr;
        }
        return data;
    }
    bool remove(const T &obj){
        Node* trav = head;
        for(trav = head; trav != nullptr; trav = trav->next){
            if(trav->data == obj){
                remove(trav);
                return true;
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
    int indexOf(const T &obj){
        Node* trav = head;
        int index = 0;
        for(; trav != nullptr; trav = trav->next,index++){
            if(trav->data == obj){
                return index;
            }
        }
        return -1;
    }
    bool contains(const T &obj){
        return indexOf(obj)!=-1;
    }
    void reverse(){
        Node* curr = head;
        Node* pre = nullptr, nex = nullptr;
        while(curr != nullptr){
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }
        head = pre;
    }
};
int main(){
    return 0;
}

} // closing the namespace