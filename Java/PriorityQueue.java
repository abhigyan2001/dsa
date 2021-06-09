import java.util.*;
class PriorityQueue<T extends Comparable<T>> {
    private int heapSize = 0;
    private int heapCapacity = 0;
    private List<T> heap = null;
    private Map <T, TreeSet<Integer>>map = new HashMap<>();

    public PriorityQueue(){
        this(1);
    }
    public PriorityQueue(int sz){
        heap = new ArrayList<>(sz);
    }
    public PriorityQueue(T[] elems){
        heapSize = heapCapacity = elems.length;
        heap = new ArrayList<T>(heapCapacity);

        for(int i=0; i<heapSize;i++){
            mapAdd(elems[i],i);
            heap.add(elems[i]);
        }
        for(int i=Math.max(0,(heapSize/2)-1); i>=0; i--){
            sink(i);
        }
    }
}