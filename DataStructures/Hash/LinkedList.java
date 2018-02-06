/**
 * 
 */
package data_structures;

import java.util.Iterator;
import java.util.NoSuchElementException;

import data_structures.LinkedList.IteratorHelper;
import data_structures.LinkedList.Node;

/**
 * The linked list for our hash will only implement the
 * methods in the HashListI interface, a reduced set of
 * methods compared to the linked list from Assignment 1.
 * 
 *
 */
public class LinkedList<E> implements HashListI<E> {
	class Node <E> {
		E data;
		Node <E> next;
		public Node (E obj){
			data = obj;
			next = null;
		}
	}
	class IteratorHelper implements Iterator <E>{
		Node <E> index;
		public IteratorHelper(){
			index = head;
		}
		public boolean hasNext(){
			return(index != null);
		}
		public E next (){
			if (!hasNext())
				throw new NoSuchElementException();

			E val = index.data;
			index = index.next;
			return val;

		}
	}
	private Node <E> head;
	private Node <E> tail;
	private int currentSize;
	public LinkedList(){
		head = null;
		tail = head;
		currentSize = 0;
	}

	@Override
	public void add(E obj) {

		Node <E> node = new Node <E> (obj);
		node.next = head;
		if (head == null)
			tail = node;

		head = node;

		currentSize++;
	}

	@Override
	public E remove(E obj) {
		Node<E> current = head, previous = null;
		while(current != null){
			if (((Comparable <E>)current.data).compareTo(obj) == 0){
				if(current == head){
					if(head == null)
						return null;

					E tmp = head.data;
					if(head == tail)
						head = tail = null;

					else
						head = head.next;

					currentSize --;
					return tmp;
				}
				if (current == tail){
					if(head == null)
						return null;

					if(head == tail)
						head = tail = null;

					previous.next = null;
					tail = previous;
					currentSize --;
					return current.data;
				}
				currentSize --;
				previous.next = current.next;
				return current.data;			
			}

			previous = current;
			current = current.next;
		}

		return null;
	}

	@Override
	public void makeEmpty() {
		tail = head = null;
		currentSize = 0;
	}

	@Override
	public boolean isEmpty() {

		return head == null;

	}

	@Override
	public int size() {

		return currentSize;	

	}

	@Override
	public boolean contains(E obj) {
		Node <E> current = head;
		while(current != null){
			if(((Comparable<E>)obj).compareTo(current.data) == 0)
				return true;

			current = current.next;
		}
		return false;
	}

	@Override
	public Iterator<E> iterator() {

		return new IteratorHelper();

	}


}

