#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

template<class T>
class BSTree;

template<class T>
class BSTNode
{
	friend class BSTree<T>;
public:
	BSTNode(const T& data = T()) : _left(nullptr), _right(nullptr), _data(data)
	{}
private:
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree() : root(nullptr)
	{}
	BSTree(vector<T> &v) : root(nullptr)
	{
		for (const auto &e : v)
			Insert(e);
	}

public:
	T& Min()const
	{
		return Min(root);
	}
	T& Max()const
	{
		return Max(root);
	}

	BSTNode<T>* Search(const T &key)const
	{
		return Search(root, key);
	}

	bool Insert(const T &x)
	{
		return Insert(root, x);
	}

	bool Remove(const T &x)
	{
		return Remove(root, x);
	}

	void Sort()const
	{
		Sort(root);
	}

protected:
	T& Min(BSTNode<T> *t)const
	{
		assert(t != nullptr);
		while (t->_left != nullptr)
			t = t->_left;
		return t->_data;
	}

	T& Max(BSTNode<T> *t)const
	{
		assert(t != nullptr);
		while (t->_right != nullptr)
			t = t->_right;
		return t->_data;
	}

	BSTNode<T>* Search(BSTNode<T> *t, const T &key)const
	{
		if (t == nullptr || t->_data == key)
			return t;
		if (key > t->_data)
			return Search(t->_right, key);
		else
			return Search(t->_left, key);
	}

	bool Insert(BSTNode<T> *&t, const T &x)const
	{
		if (t == nullptr)
		{
			t = new BSTNode<T>(x);
			return true;
		}
		if (x < t->_data)
			return Insert(t->_left, x);
		else if (x > t->_data)
			return Insert(t->_right, x);
		return false;
	}

	bool Remove(BSTNode<T> *&t, const T &x)
	{
		if (t == nullptr)
			return false;
		if (x < t->_data)
			return Remove(t->_left, x);
		else if (x > t->_data)
			return Remove(t->_right, x);
		else
		{
			BSTNode<T> *q;
			if (t->_left == nullptr && t->_right == nullptr)
			{
				delete t;
				t = nullptr;
			}
			else if (t->_left != nullptr && t->_right == nullptr)
			{
				q = t;
				t = t->_left;
				delete q;
			}
			else if (t->_right != nullptr && t->_right == nullptr)
			{
				q = t;
				t->_right;
				delete q;
			}
			else
			{
				q = t->_left;
				while (q->_right != nullptr)
					q = q->_right;
				t->_data = q->_data;
				Remove(t->_left, q->_data);
			}
			return true;
		}
	}

	void Sort(BSTNode<T> *t)const
	{
		if (t != nullptr)
		{
			Sort(t->_left);
			cout << t->_data << ' ';
			Sort(t->_right);
		}
	}

private:
	BSTNode<T> *root;
};

int main()
{
	vector<int> iv{ 10, 15, 18, 12, 20, 5, 9, 7, 3 };
	BSTree<int> bst(iv);
	bst.Sort();
	bst.Insert(13);
	bst.Remove(18);
	cout << endl;
	bst.Sort();
	cout << endl;

	cout << bst.Max() << endl;
	cout << bst.Min() << endl;
	cout << bst.Search(20) << endl;

	return 0;
}