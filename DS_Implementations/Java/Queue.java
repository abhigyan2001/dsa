import java.util.LinkedList;
public class Queue<T> implements Iterable<T> {
    private LinkedList<T> list = new LinkedList<T>();
    public Queue(){}
    public Queue(T elem){
        enqueue(elem);
    }
    public int size(){
        return list.size();
    }
    public boolean isEmpty(){
        return list.isEmpty();
    }
    public T peek(){
        if(isEmpty()){
            throw new RuntimeException("Queue Empty");
        }
        return list.peekFirst();
    }
    public void enqueue(T elem){
        list.addLast(elem);
    }
    public T dequeue(){
        if(isEmpty()){
            throw new RuntimeException("Queue Empty");
        }
        return list.removeFirst();
    }
    @Override public java.util.Iterator<T> iterator(){
        return list.iterator();
    }
}