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
	bool operator==(Node& a1) const{ 
		if (this->data == a1.data)
		{
			return true;
		}
		else
		{
			return false;
		}
		
		//return &(this->data) == &(a1.data); 这里通过data的地址来重载==号是错误，他们的地址肯定是不一样的，因为int BFS(Node<T> root, Node<T> target) 这个声明本身就是值传递，也就是说你现在的a1仅仅是函数内部的对实参g的一个拷贝，所以地址肯定是不一样的，所以在重载==的时候一定要注意是值传递还是指针传递，所以其实最保险的做法是在重载==的实现的内部采用判断值是不是相等而不是判断地址是不是相等。。
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
int BFS(Node<T> root, Node<T> target) {
	queue<Node<T>> myqueue;  // store all nodes which are waiting to be processed
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
			Node<T> cur = myqueue.front();//the first node in myqueue;
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
			for (int i = 0; i < cur.getCN().size(); i++)
			{
				myqueue.push(*cur.getCN()[i]);
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
	int step = BFS(a, g);
	cout << "step is " << step << endl;
}
