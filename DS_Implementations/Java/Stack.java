public class Stack<T> implements Iterable<T>{
    DoublyLinkedList<T> l = new DoublyLinkedList<T>();
    public Stack(){
        //pass;
    }
    public Stack(T elem){
        push(elem);
    }
    public void push(T elem){
        if(elem == null){
            throw new RuntimeException("Null elements are not supported");
        }
        l.addFirst(elem);
    }
    public void pop(){
        if(l.isEmpty()){
            throw new java.util.EmptyStackException();
        }
        l.removeFirst();
    }
    public T peek(){
        if(l.isEmpty()){
            throw new java.util.EmptyStackException();
        }
        return l.peekFirst();
    }
    public int size(){
        return l.size();
    }
    public boolean isEmpty(){
        return size() == 0;
    }

    @Override public java.util.Iterator<T> iterator(){
        return l.iterator();
    }
}