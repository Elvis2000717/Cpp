#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

template<class Type>
class BSTree;

template<class Type>
class BSTNode
{
	friend class BSTree<Type>;
public:
	BSTNode():data(Type()),leftChild(nullptr),rightChild(nullptr)
	{}
	BSTNode(Type d, BSTNode<Type> *left=nullptr, BSTNode<Type> *right=nullptr)
		:data(d),leftChild(left),rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode *leftChild;
	BSTNode *rightChild;
};

template<class Type>
class BSTree
{
public:
	BSTree() : root(nullptr)
	{}
	BSTree(vector<Type> &v) :root(nullptr)
	{
		for(const auto &e : v)
			Insert(e);
	}
public:
	Type& Min()const;
	Type& Max()const
	{
		return Max(root);
	}
	BSTNode<Type>* Search(const Type &key)const
	{
		return Search(root, key);
	}
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &x)
	{
		return Remove(root, x);
	}
	void Sort()const
	{
		Sort(root);
	}
protected:
	Type& Max(BSTNode<Type> *t)const
	{
		assert(t != nullptr);
		while(t->rightChild != nullptr)
			t = t->rightChild;
		return t->data;
	}
	
	BSTNode<Type>* Search(BSTNode<Type> *t, const Type &key)const
	{
		if(t==nullptr || t->data==key)
			return t;
		if(key < t->data)
			return Search(t->leftChild, key);
		else
			return Search(t->rightChild, key);
	}
	bool Insert(BSTNode<Type> *&t, const Type &x)
	{
		if(t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}

		if(x < t->data)
			return Insert(t->leftChild, x);
		else if(x > t->data)
			return Insert(t->rightChild, x);

		return false;
	}
	bool Remove(BSTNode<Type> *&t, const Type &x)
	{
		if(t == nullptr)
			return false;
		if(x < t->data)
			Remove(t->leftChild, x);
		else if(x > t->data)
			Remove(t->rightChild, x);
		else
		{
			BSTNode<Type> *q;
			if(t->leftChild == nullptr && t->rightChild == nullptr)
			{
				delete t;
				t = nullptr;
			}
			else if(t->leftChild != nullptr && t->rightChild == nullptr)
			{
				q = t;
				t = t->leftChild;
				delete q;
			}
			else if(t->leftChild == nullptr && t->rightChild != nullptr)
			{
				q = t;
				t = t->rightChild;
				delete q;
			}
			else
			{
				q = t->leftChild;
				while(q->rightChild != nullptr)
					q = q->rightChild;
				t->data = q->data;
				Remove(t->leftChild, q->data);
			}
			return true;
		}
		/*
		assert(t != nullptr);
		BSTNode<Type> *p = Search(t, x);
		if(p == nullptr)
			return false;
		if(p->leftChild == nullptr && p->rightChild == nullptr)
		{
			delete p;
			p = nullptr;
		}
		else if(t->leftChild != nullptr && t->rightChild == nullptr)
		{
			t->data = t->leftChild->data;
			Remove(t->leftChild,t->leftChild->data);
		}
		else if(t->leftChild == nullptr && t->rightChild != nullptr)
		{
			t->data = t->rightChild->data;
			Remove(t->rightChild,r->rightChild->data);
		}
		else
		{
			auto p = t->rightChild;
			while(p->rightChild != nullptr)
				p = p->rightChild;
			
			t->data = p->data;
			Remove(p,p->data);
		}
		*/
	}
	void Sort(BSTNode<Type> *t)const
	{
		if(t != nullptr)
		{
			Sort(t->leftChild);
			cout<<t->data<<" ";
			Sort(t->rightChild);
		}
	}
private:
	BSTNode<Type> *root;
};

void main()
{
	vector<int> iv{ 10, 15,18,12,20,5, 9, 7, 3};
	BSTree<int> bst(iv);

	//cout<<"Max = "<<bst.Max()<<endl;
	//BSTNode<int > *p = bst.Search(180);
	//bst.Sort();
	bst.Remove(10);
	return;
}

/*
void main()
{
	vector<int> iv{ 10, 15,18,12,20,5, 9, 7, 3};
	BSTree<int> bst;
	for(const auto &e : iv)
		bst.Insert(e);
	return;
}

/*
class A
{
public:
	virtual void func1() //符号表
	{
		cout<<"aaaaaaaa"<<endl;
	}

	virtual void func2() //符号表
	{
		cout<<"bbbbbbbbbbbb"<<endl;
	}
private:
	int a;
};

class B : public A
{
public:
	void func1()
	{
		cout<<"CCCCCC"<<endl;
	}
private:
	int b;
};
int main(int argc, char* argv[])
{
	B d;
	memset(&d, 0, sizeof(d));

	A *pa = &d;
	pa->func1();
}

/*
class Base1
{ 
public: 
	int _b1;
};

class Base2 
{
public: 
	int _b2;
};

class Derive : public Base1, public Base2 
{
public: 
	int _d; 
};

int main()
{
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}

/*
class B 
{
public:
	B()
	{ 
		cout << "BBBBBBBBBBBBBBB"<< endl; 
	}
};
class C 
{
public:
	C()
	{ 
		cout <<"CCCCCCCCCCC" << endl; 
	}
};
class D : public C, virtual public B
{
public:
	D()
	{
		cout<<"DDDDDDDDDD"<<endl;
	}
};

int main() 
{
	D d;
	return 0;
}

/*
class A
{
public:
	A(char *s) 
	{ 
		cout << s << endl; 
	}
	~A(){}
};
class B : virtual public A
{
public:
	B(char *s1, char*s2):A(s2)
	{ 
		cout << s2 << endl; 
	}
};
class C :virtual public A
{
public:
	C(char *s1, char*s2):A(s2)
	{ 
		cout << s2 << endl; 
	}
};
class D : public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4) 
		:B(s1, s2), C(s1, s3),A("Hehe")
	{
		cout << s4 << endl;
	}
};

int main() 
{
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}

/*
class Base
{
public:
	Base()
	{

	}
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	virtual inline int fun() //inline 建议
	{
		return 0;
	}
private:
	int _b = 1;
};

class D : public Base
{
public:
	D()
	{
		cout<<"aaaaaaa"<<endl;
	}
public:
	virtual void Func1()
	{
		cout << "D::Func1()" << endl;
	}
private:
	int a = 0;
};

void main()
{
	Base b;
	D    d;
}

/*
void main()
{
	Base b1, b2;
	D d1;
	D d2;
}

/*
//抽象类
class A
{
public:
	virtual void Eat() = 0;  //接口 纯虚函数
	virtual void Foot() = 0;
	virtual void Sleep() = 0
	{
		cout<<"A::Sleep()"<<endl;
	}
};

class Dog : public A
{
public:
	void Eat()
	{
		cout<<"Dog::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Dog::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Dog::Sleep()"<<endl;
	}
};

class Pig : public A
{
public:
	void Eat()
	{
		cout<<"Pig::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Pig::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Pig::Sleep()"<<endl;
	}
};

class Bird : public A
{
public:
	void Eat()
	{
		cout<<"Bird::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Bird::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Bird::Sleep()"<<endl;
	}
	virtual void Fly()
	{
		cout<<"Bird::Fly()"<<endl;
	}
};

class TN : public Bird
{
public:
	void Eat()
	{
		cout<<"TN::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"TN::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"TN::Sleep()"<<endl;
	}
private:
	virtual void Fly()
	{}
};

void  main()
{
	Dog d;
	Bird b;
	b.Fly();

	TN tn;
	//tn.Fly();
}


/*
void main()
{
	A  a;
	A *pa = new Dog;
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

/*
class A
{
public:
	virtual void Eat()
	{
		cout<<"A::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"A::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"A::Sleep()"<<endl;
	}
};

class Dog : public A
{
public:
	void Eat()
	{
		cout<<"Dog::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Dog::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Dog::Sleep()"<<endl;
	}
};

class Pig : public A
{
public:
	void Eat()
	{
		cout<<"Pig::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Pig::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Pig::Sleep()"<<endl;
	}
};

void main()
{
	A  a;
	A *pa = new Dog;
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}
*/