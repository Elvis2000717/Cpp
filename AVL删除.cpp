#include<iostream>
#include<vector>
#include<stack>
#include<assert.h>
using namespace std;

//AVL
template<class Type>
class AVLTree;

//节点类
template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode():data(Type()),leftChild(nullptr),rightChild(nullptr),bf(0)
	{}
	AVLNode(Type d):data(d),leftChild(nullptr),rightChild(nullptr),bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	AVLNode *leftChild;
	AVLNode *rightChild;
	int bf;  //平衡因子 0 -1 1  2 -2
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
	bool Remove(AVLNode<Type> *&t, const Type &key);
protected:
	void RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
	}
	void RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
	}
	void RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		AVLNode<Type> *subL = ptr->leftChild;
		ptr = subL->rightChild;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf
		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf;
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
	}
	void RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		AVLNode<Type> *subR = ptr->rightChild;
		ptr = subR->leftChild;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf
		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		ptr->bf = 0;
	}
private:
	AVLNode<Type> *root;
};

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
{
	//1 按照bst进行节点插入
	AVLNode<Type> *pr = nullptr;
	AVLNode<Type> *p = t;
	stack<AVLNode<Type>*> st;
	while(p != nullptr)
	{
		if(x == p->data)
			return false;

		pr = p;
		st.push(pr);

		if(x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}

	p = new AVLNode<Type>(x);
	if(pr == nullptr)
	{
		//插入根节点
		t = p;
		return true;
	}

	if(x < pr->data)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//2 调整平衡
	while(!st.empty())
	{
		pr = st.top();
		st.pop();
		//更新bf
		if(p == pr->leftChild)
			pr->bf--;
		else
			pr->bf++;

		if(pr->bf == 0) //不需要调整
			break;
		else if(pr->bf==1 || pr->bf==-1) //向上回溯
			p = pr;
		else
		{
			//不平衡
			if(pr->bf < 0)
			{
				if(p->bf < 0)   //    /
				{
					//cout<<"RotateR"<<endl;
					RotateR(pr);
				}
				else            //    <
				{
					//cout<<"RotateLR"<<endl;
					RotateLR(pr);
				}
			}
			else
			{
				if(p->bf > 0)    // \ 
				{
					//cout<<"RotateL"<<endl;
					RotateL(pr);
				}
				else             //  >
				{
					//cout<<"RotateRL"<<endl;
					RotateRL(pr);
				}
			}
			break;
		}
	}

	//重新链接节点
	if(st.empty())
		t = pr;
	else
	{
		AVLNode<Type> *q = st.top();
		if(pr->data < q->data)
			q->leftChild = pr;
		else
			q->rightChild = pr;
	}

	return true;
}

template<class Type>
bool AVLTree<Type>::Remove(AVLNode<Type> *&t, const Type &key)
{
	//1 按照bst删除节点
	AVLNode<Type> *pr = nullptr;
	AVLNode<Type> *p = t, *q;
	stack<AVLNode<Type>*> st;
	while(p != nullptr)
	{
		if(key == p->data)
			break;

		pr = p;
		st.push(pr);

		if(key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if(p == nullptr)
		return false;

	if(p->leftChild!=nullptr && p->rightChild!=nullptr)
	{
		pr = p;
		st.push(pr);
		q = p->leftChild;
		while(q->rightChild != nullptr)
		{
			pr = q;
			st.push(pr);
			q = q->rightChild;
		}

		p->data = q->data;
		p = q;
	}

	if(p->leftChild != nullptr)
		q = p->leftChild;
	else
		q = p->rightChild;

	//重新链接
	if(p->data < pr->data)
		pr->leftChild = q;
	else
		pr->rightChild = q;

	//用于判断是否为q->bf==0的跳出
	bool is_break_flag = false;

	//2 调整平衡
	while(!st.empty())
	{
		//回退
		pr = st.top();
		st.pop();

		if(p->data < pr->data)
			pr->bf++;
		else
			pr->bf--;

		if(pr->bf==1 || pr->bf==-1)
			break;
		else if(pr->bf==2 || pr->bf==-2)
		{
			//旋转调整

			//让q指向较高的子树
			if(pr->bf > 0)
				q = pr->rightChild;
			else 
				q = pr->leftChild;

			if(q->bf == 0)
			{
				if(pr->bf > 0)
				{
					RotateL(pr);
					pr->bf = -1;
					pr->leftChild->bf = 1;
				}
				else
				{
					RotateR(pr);
					pr->bf = 1;
					pr->rightChild->bf = -1;
				}
				is_break_flag = true;
			}
			else
			{
				if (pr->bf > 0)
				{
					if (q->bf > 0)
						RotateL(pr);
					else
						RotateRL(pr);
				}
				else
				{
					if (q->bf < 0)
						RotateR(pr);
					else
						RotateLR(pr);
				}
			}

			//重新链接节点
			if (st.empty())
				t = pr;
			else
			{
				q = st.top();
				if (pr->data < q->data)
					q->leftChild = pr;
				else
					q->rightChild = pr;
			}
			if(is_break_flag)
				break;
		}
	}

	//删除节点
	delete p;
	return true;
}

void main()
{
	vector<int > iv = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	AVLTree<int> avl;

	for(const auto &e : iv)
		avl.Insert(e);

	//
	//
	//avl.Remove(16);
	avl.Remove(26);
	avl.Remove(3);
	avl.Remove(9);


	return;
}
