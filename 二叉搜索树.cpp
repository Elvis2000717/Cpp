#include <iostream>
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
	BSTNode() :data(T()), left(nullptr), right(nullptr)
	{}
	BSTNode(T d, BSTNode<T> *left = nullptr, BSTNode<T> *right = nullptr)
		:data(d), left(left), right(right)
	{}
	~BSTNode()
	{}
private:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
};

template<class T>
class BSTree
{
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
	T& Max(BSTNode<T> *t)const
	{
		assert(t != nullptr);
		while (t->right != nullptr)
			t = t->right;
		return t->data;
	}
	T& Min(BSTNode<T> *t)const
	{
		assert(t != nullptr);
		while (t->left != nullptr)
			t = t->left;
		return t->data;
	}

	BSTNode<T>* Search(BSTNode<T> *t, const T &key)const
	{
		if (t == nullptr || t->data == key)
			return t;
		if (key < t->data)
			return Search(t->left, key);
		else
			return Search(t->right, key);
	}

	bool Insert(BSTNode<T> *&t, const T &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<T>(x);
			return true;
		}
		if (x < t->data)
			return Insert(t->left, x);
		else if (x > t->data)
			return Insert(t->right, x);
		return false;
	}

	bool Remove(BSTNode<T> *&t, const T &x)
	{
		if (t == nullptr)
			return false;
		if (x < t->data)
			Remove(t->left, x);
		else if (x > t->data)
			Remove(t->right, x);
		else
		{
			BSTNode<T> *q;
			if (t->left == nullptr && t->right == nullptr)
			{
				delete t;
				t = nullptr;
			}
			else if (t->left != nullptr && t->right == nullptr)
			{
				q = t;
				t = t->left;
				delete q;
			}
			else if (t->right != nullptr && t->left == nullptr)
			{
				q = t;
				t = t->right;
				delete q;
			}
			else
			{
				q = t->left;
				while (q->right != nullptr)
					q = q->right;
				t->data = q->data;
				Remove(t->left, q->data);
			}
			return true;
		}
	}

	void Sort(BSTNode<T> *t)const
	{
		if (t != nullptr)
		{
			Sort(t->left);
			cout << t->data << ' ';
			Sort(t->right);
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