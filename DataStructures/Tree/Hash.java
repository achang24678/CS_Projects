package data_structures;

import java.util.Iterator;

/**
 * The Hash data structure has O(1) time complexity (best case) for add, remove, and find
 * for an object in the data structure. The methods in the Hash data structure are defined
 * by the HashI interface. The Hash consists of an array of Linked Lists,
 * the Linked Lists are defined by the HashListI interface.
 * 
 *
 * @param <K> The key for entries in the hash
 * @param <V> The value for entries in the hash
 */

public class Hash<K, V> implements HashI<K, V> {

	class HashElement<K,V> implements Comparable<HashElement<K,V>>{

		K key;
		V value;

		public HashElement(K key, V value){
			this.key = key;
			this.value = value;
		}
		public int compareTo(HashElement<K,V> h){
			return ((Comparable<K>) h.key).compareTo(this.key);
		}
	}

	HashListI<HashElement<K,V>>[] hash_array;
	int tableSize, numElements;
	double maxLoadFactor;

	public Hash(int tableSize){
		this.tableSize = tableSize;
		maxLoadFactor = 0.75;
		numElements = 0;
		hash_array = (LinkedList<HashElement<K,V>>[]) new LinkedList[tableSize];

		for(int i = 0; i < tableSize; i++)
			hash_array[i] = new LinkedList <HashElement<K,V>>();

	}
	class IteratorHelper<T> implements Iterator<T>{

		T[]keys;
		int position;
		public IteratorHelper(){

			keys = (T[]) new Object[numElements];
			int p = 0;
			for(int i = 0; i < tableSize; i++){
				LinkedList <HashElement<K,V>> list = (LinkedList<Hash<K, V>.HashElement<K, V>>) hash_array[i];

				for(HashElement<K,V> h : list){
					keys[p++] = (T)h.key;
				}
				position = 0;
			}
		}

		public boolean hasNext(){
			return position < keys.length;
		}
		public T next(){
			if (!hasNext())
				return null;
			return keys[position ++];
		}
	}


	@Override
	public boolean add(K key, V value) {

		if(loadFactor() > maxLoadFactor)
			resize(tableSize * 2);

		HashElement<K,V> he = new HashElement (key,value);

		int hashVal = key.hashCode() & 0x7FFFFFFF % tableSize;
		hash_array[hashVal].add(he);
		numElements ++; 

		return true;
	}

	@Override
	public boolean remove(K key) {
		int hashVal = key.hashCode() & 0x7FFFFFFF % tableSize;
		for(HashElement<K,V> he: hash_array[hashVal]){
			if(((Comparable<K>) key).compareTo(he.key) == 0)
				hash_array[hashVal].remove(he);
			numElements --;
			return true;
		}
		return false;
	}

	@Override
	public boolean changeValue(K key, V value) {
		int hashVal = key.hashCode() & 0x7FFFFFFF % tableSize;
		for(HashElement<K,V> he: hash_array[hashVal]){
			if(((Comparable<K>) key).compareTo(he.key) == 0)
				he.value = value;
			return true;
		}
		return false;
	}

	@Override
	public boolean contains(K key) {

		int hashVal = key.hashCode() & 0x7FFFFFFF % tableSize;
		for(HashElement<K,V> he: hash_array[hashVal]){
			if(((Comparable<K>) key).compareTo(he.key) == 0)
				return true;
		}
		return false;
	}

	@Override
	public V getValue(K key) {

		int hashVal = key.hashCode() & 0x7FFFFFFF % tableSize;

		for(HashElement<K,V> he: hash_array[hashVal]){
			if(((Comparable<K>) key).compareTo(he.key) == 0)
				return he.value;
		}
		return null;
	}

	@Override
	public int size() {

		return numElements;
	}

	@Override
	public boolean isEmpty() {

		return (numElements == 0);
	}

	@Override
	public void makeEmpty() {
		tableSize = 0;
		numElements = 0;
	}

	@Override
	public double loadFactor() {

		return (numElements/tableSize);
	}

	@Override
	public double getMaxLoadFactor() {

		return maxLoadFactor;

	}

	@Override
	public void setMaxLoadFActor(double loadfactor) {

		maxLoadFactor = loadfactor;
	}

	@Override
	public void resize(int newSize) {

		LinkedList<HashElement<K,V>>[] new_array = (LinkedList<HashElement<K,V>>[]) new LinkedList[newSize];

		for(int i = 0; i < newSize; i++)
			new_array[i] = new LinkedList <HashElement<K,V>>();

		for(K key: this){

			V val = getValue(key);
			HashElement<K,V> he = new HashElement<K,V>(key,val);
			int hashVal = (key.hashCode() & 0x7FFFFFFF) % newSize;
			new_array[hashVal].add(he);
		}
		hash_array = new_array;
		tableSize = newSize;

	}



	@Override
	public Iterator<K> iterator() {

		return new IteratorHelper();

	}

}
