public class QueueArray<T> implements Iterable<T> {
    private T arr[] = new T[1000];
    int top = 0;
    int bot = 0;
    public QueueArray(){}
    public QueueArray(T elem){
        enqueue(elem);
    }
    public int size(){
        int diff = bot - top;
        if ((diff) < 0){
            return diff+1000;
        }
        else{
            return diff;
        }
    }
    public boolean isEmpty(){
        return bot==top;
    }
    public T peek(){
        if (isEmpty()){
            throw new RuntimeException("Queue Empty");
        }
        return arr[top];
    }
    public void enqueue(T elem){
        arr[bot] = elem;
        bot = (bot+1)%1000;
    }
    public T dequeue(){
        if (isEmpty()){
            throw new RuntimeException("Queue Empty");
        }
        retval = arr[top];
        arr[top] = null;
        top = (top+1)%1000;
        return retval;
    }
    @Override public java.util.Iterator<T> iterator(){
        return java.util.Arrays.asList(arr).iterator();
    }
}