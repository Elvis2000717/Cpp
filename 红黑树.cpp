#include <iostream>
#include <vector>

using namespace std;

typedef enum{RED = 0, BLACK = 1}Color_Type;

template <class Type>
class RBTree;

template<class Type>
class RBNode
{
	friend class RBTree<Type>;
public:
	RBNode(Type d) :data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr), color(RED)
	{}
	~RBNode()
	{}
private:
	Type data;
	RBNode *leftChild;
	RBNode *rightChild;
	RBNode *parent;
	Color_Type color;
};

template <class Type>
class RBTree
{
public:
	RBTree() :root(Nil), Nil(_Buynode())
	{
		Nil->leftChild = Nil->rightChild = Nil->parent = nullptr;
		Nil->color = BLACK;
	}
	
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &x)
	{
		return Remove(root, x);
	}

protected:
	bool Insert(RBNode<Type> *&t, const Type &x);
	bool Remove(RBNode<Type> *&t, const Type &x);
	RBNode<Type>* _Buynode(const Type &x = Type())
	{
		RBNode<Type> *s = new RBNode<Type>(x);
		s->leftChild = s->rightChild = s->parent = Nil;
		return s;
	}
protected:
	void Insert_Fixup(RBNode<Type> *&t, RBNode<Type> *x);
	void Remove_Fixup(RBNode<Type> *&t, RBNode<Type> *key);
protected:
	void RotateRight(RBNode<Type> *&t, RBNode<Type> *x)
	{
		RBNode<Type> *y = x->leftChild;
		x->leftChild = y->rightChild;
		if (y->rightChild != Nil)
			y->rightChild->parent = x;

		y->rightChild = x;
		if (x == t)
			t = y;
		else if (x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		y->parent = x->parent;
		x->parent = y;
	}
	
	void RotateLeft(RBNode<Type> *&t, RBNode<Type> *x)
	{
		RBNode<Type> *y = x->rightChild;
		x->rightChild = y->leftChild;
		if (y->leftChild != Nil)//如果y存在左子树，则把y的左子树和x连接
			y->leftChild->parent = x;

		y->leftChild = x;
		if (x == t)
			t = y;
		else if (x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		y->parent = x->parent;
		x->parent = y;
	}

private:
	RBNode<Type> *Nil;
	RBNode<Type> *root;
};

template <class Type>
bool RBTree<Type>::Insert(RBNode<Type> *&t, const Type &x)
{
	RBNode<Type> *pr = Nil;//父节点指针
	RBNode <Type> *p = t;//当前节点指针
	while (p != Nil)
	{
		if (x == p->data)//如果已经存在则不能插入
			return false;
		pr = p;//保存父节点
		if (x < p->data)
			p = p->leftChild;//向左子树中找
		else
			p = p->rightChild;//向右子树中找
	}

	p = _Buynode(x);//购买节点

	if (pr == Nil)//如果父节点也是空的，那么t是根节点
		t = p;//将购买的节点给根节点
	else
	{
		if (x < pr->data)
			pr->leftChild = p;
		else
			pr->rightChild = p;
		p->parent = pr;
	}

	Insert_Fixup(t, p);//调整平衡 t是根节点 p是插入的节点
	return true;
}

template <class Type>
void RBTree<Type>::Insert_Fixup(RBNode<Type> *&t, RBNode<Type> *x)
{
	while (x->parent->color == RED)
	{
		RBNode<Type> *s;
		if (x->parent == x->parent->parent->leftChild)
		{
			//父节点是左分支

			s = x->parent->parent->rightChild;// s是父节点的兄弟节点
			if (s->color == RED)//父节点的兄弟节点是红的
			{
				//状况三
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else//父节点的兄弟节点是黑的
			{
				if (x == x->parent->rightChild)//x是右节点
				{
					//状况二
					x = x->parent;
					RotateLeft(t, x);//左旋转
				}
				//状况一
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RotateRight(t, x->parent->parent);
			}
		}
		else
		{
			//父节点是右分支
			s = x->parent->parent->leftChild;//父节点的兄弟节点
			if (s->color == RED)
			{
				//状况三
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else//兄弟节点是黑的
			{
				if (x == x->parent->leftChild)
				{
					//状况二
					x = x->parent;
					RotateRight(t, x);
				}
				//状况一
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				RotateLeft(t, x->parent->parent);
			}
		}
	}
	t->color = BLACK;
}

template<class Type>
bool RBTree<Type>::Remove(RBNode<Type> *&t, const Type &key)
{
	RBNode<Type> *p = t;
	RBNode<Type> *q;
	//p找到目标元素key的节点   或者  p为Nil没找到
	while (p != Nil)
	{
		if (key == p->data)
			break;
		if (key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}

	//排除了p为Nil的情况
	if (p == Nil)
		return false;

	//p找到目标元素key的节点
	//要删除节点的左子树和右子树都有节点
	if (p->leftChild != Nil && p->rightChild != Nil)
	{
		q = p->leftChild;
		while (q->rightChild != Nil)
			q = q->rightChild;

		p->data = q->data;
		p = q;
	}

	if (p->leftChild != Nil)
		q = p->leftChild;
	else
		q = p->rightChild;

	//从上向下连接
	if (p == p->parent->leftChild)
		p->parent->leftChild = q;
	else
		p->parent->rightChild = q;

	//连接前驱节点
	q->parent = p->parent;

	//调整平衡
	if (p->color == BLACK)
		Remove_Fixup(t, q);

	//删除节点
	delete p;
	return true;
}

template<class Type>
void RBTree<Type>::Remove_Fixup(RBNode<Type> *&t, RBNode<Type> *x)
{
	RBNode<Type> *w;//兄弟节点
	while (x != t && x->color == BLACK)
	{
		if (x == x->parent->leftChild)
		{
			//删除节点在左分支
			w = x->parent->rightChild;

			//情形四
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RotateLeft(t, x->parent);
				w = x->parent->rightChild;
			}
			//情形三
			if (w->leftChild == Nil && w->rightChild == Nil)
			{
				x->parent->color = BLACK;
				w->color = RED;
				x = x->parent;
			}
			else
			{
				//情形二
				if (w->leftChild != Nil)
				{
					w->color = RED;
					w->leftChild->color = BLACK;
					w = w->leftChild;
					RotateRight(t, w->parent);
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->rightChild->color = BLACK;
				RotateLeft(t, x->parent);
				x = t;
			}
		}
		else
		{
			//删除的节点在右分支
			w = x->parent->leftChild;

			//情形四
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RotateRight(t, x->parent);
				w = x->parent->leftChild;
			}

			//情形三
			if (w->leftChild == Nil && w->rightChild == Nil)
			{
				w->color = RED;
				x->parent->color = BLACK;
				x = x->parent;
			}
			else
			{
				//情形二
				if (w->rightChild != Nil)
				{
					w->color = RED;
					w->rightChild->color = BLACK;
					w = w->rightChild;
					RotateLeft(t, w->parent);
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->leftChild->color = BLACK;
				RotateRight(t, x->parent);
				x = t;
			}
		}
	}
	x->color;
}

void main()
{
	vector<int> iv = { 10, 7, 8, 15, 5, 6, 11, 13, 12 };
	RBTree<int> rb;

	for (const auto &e : iv)
		rb.Insert(e);

	rb.Remove(5);
	rb.Remove(7);
	rb.Remove(6);

	return;
}