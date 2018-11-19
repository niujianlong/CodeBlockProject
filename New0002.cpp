#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


template<typename T>
class Node {
private:
	T data;
	//int cNodeNum;
	vector<Node*> cNodeP;
public:
	Node(T data) :data(data) {};
	void addChildNode(Node* chNod);
	//{
	//cNodeP.push_back(chNod);
	//}
	vector<Node*> getCN(void)const { return cNodeP; }
	bool operator==(Node* a1) {
#if 0
		if (this->data == a1.data)
		{
			return true;
		}
		else
		{
			return false;
		}
#endif
		return this == a1; //指针实现就是为了实现这里，我想使用指针的相等来判定两个对象的相等而不是使用对象的的成员变量的值相等作为判断，因为用成员变量的值来判断其实是不完备的，假如两个对象的的data值都是g,但是它其实并不是我们需要的Node g
}
};

template<typename T>
void Node<T>::addChildNode(Node<T> * chNod)
{
	this->cNodeP.push_back(chNod);
}


/**
 * Return the length of the shortest path between root and target node.
 */
template<typename T>
int BFS(Node<T>* root, Node<T>* target) {
	queue<Node<T>*> myqueue;  // store all nodes which are waiting to be processed
	int step = 0;       // number of steps neeeded from root to current node
	// initialize
	//add root to myqueue;
	myqueue.push(root);
	// BFS
	while (!myqueue.empty()) {
		step = step + 1;
		// iterate the nodes which are already in the queue
		int size = myqueue.size();
		for (int i = 0; i < size; ++i) {
			Node<T>* cur = myqueue.front();//the first node in myqueue;
			//return step if cur is target;
			if (cur == target)
			{
				return step;
			}
			/*
			for (Node next : the neighbors of cur) {
				add next to myqueue;
			}*/
			//for(typename vector<Node<T>*>::iterator iter=cur.getCN().begin();iter!=cur.getCN().end();++iter)
			{
				//myqueue.push(iter);
			}
			for (int i = 0; i < cur->getCN().size(); i++)
			{
				myqueue.push(cur->getCN()[i]);
			}
			//remove the first node from myqueue;
			myqueue.pop();
		}
	}
	return -1;          // there is no path from root to target
}

int main(int argc, char * * argv)
{
	Node<string> a = Node<string>("a");
	Node<string> b = Node<string>("b");
	Node<string> c = Node<string>("c");
	Node<string> d = Node<string>("d");
	Node<string> e = Node<string>("e");
	Node<string> f = Node<string>("f");
	Node<string> g = Node<string>("g");
	a.addChildNode(&b);
	a.addChildNode(&c);
	a.addChildNode(&d);
	b.addChildNode(&e);
	c.addChildNode(&e);
	c.addChildNode(&f);
	d.addChildNode(&g);
	int step = BFS(&a, &g);
	cout << "step is " << step << endl;
	int i = 0;
	cin >> i;
}
