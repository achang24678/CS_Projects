package data_structures;

import java.util.Iterator;

public class Queue<E> {
	private ListI<E>List;
	public Queue(){
		List = new LinkedList<>();
	}
	public void enqueue(E obj){
		List.addLast(obj);
	}
	public E dequeue(){
		return List.removeFirst();
	}
	public int size(){
		return List.size();
	}
	public boolean isEmpty(){

		return List.isEmpty();
	}
	public boolean isFull(){

		return List.isFull();
	}

	public E peek() {

		return List.peekFirst();
	}
	public boolean contains(E obj) {

		return List.contains(obj);
	}
	public void makeEmpty() {
		List.makeEmpty();

	}
	public Iterator<E> iterator(){
		return List.iterator();
	}
}
