package data_structures;

import java.util.Iterator;
import java.util.NoSuchElementException;


public class RedBlackTree<K, V> implements RedBlackI<K, V> {

	Node<K,V> root;
	int size;

	class Node<K,V>{
		K key;
		V value;
		Node<K,V> left, right, parent;
		boolean isLeftChild, black;

		public Node(K key, V value){
			this.key = key;
			this.value = value;
			left = right = parent = null;
			black = false;
			isLeftChild = false;
		}
	}

	class IteratorHelper implements Iterator<K>{

		Node<K,V> node;
		private IteratorHelper(Node<K,V> root){
			this.node = root;
			if(node == null)
				return;
			while(node.left != null)
				node = node.left;
		}

		public K next(){
			if(!hasNext())
				throw new NoSuchElementException();
			Node<K,V> gtr = node;
			if(node.right != null){
				node = node.right;
				while(node.left != null)
					node = node.left;
				return gtr.key;
			}
			while(true){
				if(node.parent == null){
					node = null;
					return gtr.key;
				}
				if(node == node.parent.left){
					node = node.parent;
					return gtr.key;
				}
				node = node.parent;
			}
		}

		public boolean hasNext(){
			return node != null;

		}
	}

	@Override
	public void add(K key, V value) {
		Node<K,V> node = new Node<K,V>(key,value);
		if(root == null){
			root = node;
			root.black = true;
			size++;
			return;
		}
		add(root, node);
		size++;
	}
	private void add(Node<K,V> parent, Node<K,V> newNode){
		if(((Comparable<K>)newNode.key).compareTo(parent.key) > 0){
			if(parent.right == null){
				parent.right = newNode; //parent points to newnode
				newNode.parent = parent; // newnode points back to parent
				newNode.isLeftChild = false;
				return;
			}
			add(parent.right, newNode);
		}
		if(parent.left ==null){
			parent.left = newNode;
			newNode.parent = parent;
			newNode.isLeftChild = true;
			return; 
		}
		add(parent.left, newNode);
		checkColor(newNode);
	}

	public void checkColor(Node<K,V> node){
		if(node == root)
			return;

		if(!node.black && !node.parent.black)
			correctTree(node);

		checkColor(node.parent); // prevent consecutive red nodes.
	}

	public void correctTree(Node<K,V> node){
		if(node.parent.isLeftChild){
			//aunt is node.parent.parent.right(grandparent's right child)
			if(node.parent.parent.right == null || node.parent.parent.right.black)
				rotate(node);
			if(node.parent.parent.right != null)
				node.parent.parent.right.black = true;//color flip set aunt to black

			node.parent.parent.black = false;//grandparent to red
			node.parent.black = true; //parent to black
			return;
		}
		//aunt is grandparent.left
		if(node.parent.parent.left == null || node.parent.parent.left.black)
			rotate(node);
		if(node.parent.parent.left != null)
			node.parent.parent.left.black = true;

		node.parent.parent.black = false;
		node.parent.black = true;
		return;
	}



	public void rotate(Node<K,V>node){
		if(node.isLeftChild){
			if(node.parent.isLeftChild){
				rightRotate(node.parent.parent);//parse in grandparent
				node.black = false; // set us to red
				node.parent.black = true; // set parent to black
				if(node.parent.right != null)
					node.parent.right.black = false; // set sibling to red
				return;
			}
			rightLeftRotate(node.parent.parent);
			node.black = true; 
			node.right.black = false;
			node.left.black = false;
			return;
		}
		if(!node.isLeftChild){
			if(!node.parent.isLeftChild){
				leftRotate(node.parent.parent);//parse in grandparent
				node.black = false; // set us to red
				node.parent.black = true; // set parent to black
				if(node.parent.right != null)
					node.parent.right.black = false; // set sibling to red
				return;
			}
			leftRightRotate(node.parent.parent);
			node.black = true;
			node.right.black = false;
			node.left.black = false;
			return;
		}
	}

	public void leftRotate(Node<K,V>node){
		Node<K,V> tmp = node.right;
		node.right = tmp.left;
		if(node.right != null){
			node.right.parent = node;
			node.right.isLeftChild = false;
		}
		if(node.parent == null){
			//we are the root node
			root = tmp; //root point to tmp
			tmp.parent = null;
		}
		else{
			tmp.parent = node.parent; //tmp points to grandparent node's parent
			if(node.isLeftChild){
				tmp.isLeftChild = true; //tmp becomes leftchild
				tmp.parent.left = tmp; // grandparent node's parent's left = tmp
			}
			else{
				tmp.isLeftChild = false; // else its at right
				tmp.parent.right = tmp; // grandparent node's parent's right = tmp
			}
			tmp.left = node; //gp to the tmp's left
			node.isLeftChild = true; // gp now is left child of tmp
			node.parent = tmp; // gp's parent pointer points back to tmp
		}
	}

	public void rightRotate(Node<K,V>node){
		Node<K,V> tmp = node.left;
		node.left = tmp.right;
		if(node.left != null){
			node.left.parent = node;
			node.left.isLeftChild = true;
		}
		if(node.parent == null){
			//we are the root node
			root = tmp; //root point to tmp
			tmp.parent = null;
		}
		else{
			tmp.parent = node.parent; //tmp points to grandparent node's parent
			if(node.isLeftChild){
				tmp.isLeftChild = true; //tmp becomes leftchild
				tmp.parent.left = tmp; // grandparent node's parent's left = tmp
			}
			else{
				tmp.isLeftChild = false; // else its at right
				tmp.parent.right = tmp; // grandparent node's parent's right = tmp
			}
			tmp.right = node; //gp to the tmp's right
			node.isLeftChild = false; // gp now is right child of tmp
			node.parent = tmp; // gp's parent pointer points back to tmp
		}
	}

	public void leftRightRotate(Node<K,V>node){
		leftRotate(node.left);
		rightRotate(node);
	}

	public void rightLeftRotate(Node<K,V>node){
		rightRotate(node.right);
		leftRotate(node);
	}

	public int blackNodes(Node<K,V>node){
		if(node == null)
			return 1;
		int rightBlackNodes = blackNodes(node.right);
		int leftBlackNodes = blackNodes(node.left);
		if(rightBlackNodes != leftBlackNodes)
			//throw an error
			// or fix the tree!
			if(node.black)
				leftBlackNodes++;
		return leftBlackNodes;

	}
	@Override
	public boolean contains(K key) {
		return contains(key, root);
	}

	private boolean contains(K key, Node<K,V>node){
		if(node == null)
			return false;
		if(((Comparable<K>)key).compareTo(node.key) == 0)
			return true;
		if(((Comparable<K>)key).compareTo(node.key) > 0)
			return contains(key, node.right);
		return contains(key, node.left);
	}

	@Override
	public V getValue(K key) {
		return getValue(key, root);
	}

	private V getValue(K key, Node<K,V>node){
		if(node == null)
			return null;
		if(((Comparable<K>)key).compareTo(node.key) == 0)
			return node.value;
		if(((Comparable<K>)key).compareTo(node.key) > 0)
			return getValue(key, node.right);
		return getValue(key, node.left);
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public boolean isEmpty() {
		return (size == 0);
	}

	@Override
	public int height() {
		if(root == null)
			return 0;
		return height(root)-1;
	}
	public int height(Node<K,V>node){
		if(node == null)
			return 0;
		int leftheight = height(node.left) +1;
		int rightheight = height(node.right)+1;
		if(leftheight > rightheight)
			return leftheight;
		return rightheight;
	}

	@Override
	public Iterator<K> iterator() {

		return IteratorHelper(root);
	}


	@Override
	public void print() {
		printInorder(root,0);
	}
	private void printInorder(Node<K,V> node, int depth){
		if (node == null) 
			return;

		printInorder(node.left, depth +1 );
		for(int a=0;a<depth;a++) 
			System.out.print(".");

		System.out.println(node.value);
		printInorder(node.right, depth +1);
	}

}
