class DoublyLinkedListTest{
    public static void main(String args[]){
        DoublyLinkedList<Integer> x = new DoublyLinkedList<Integer>();
        for(int i = 0; i < 10000; i++){
            x.add(i);
        }
        for(int i = 0; i < x.size(); i++){
            System.out.println(x.getAt(i));
        }
    }
}