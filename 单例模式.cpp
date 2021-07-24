////请设计一个类，只能在堆上创建对象
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateOject()
//	{
//		return new HeapOnly;
//	}
//
//private:
//	HeapOnly(){}
//
//	//1.方法一
//	HeapOnly(const HeapOnly&);
//
//	//2.方法二
//	//C++11
//	HeapOnly(const HeapOnly&) = delete;
//};
//
////设计一个类，只能在栈上创建对象
////方法一
//class StackOnly
//{
//public:
//	//将构造函数私有化，然后设计静态方法创建对象返回
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly(){}
//};
//
////方法二:屏蔽new
//class StackOnly
//{
//public:
//	StackOnly(){}
//private:
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};
//
////设计一个类，不能被拷贝
//class CopyBan
//{
//	//拷贝存在于 1.拷贝构造函数 2.赋值运算符
//	//禁止拷贝只需要把这两个函数放到private，只声明不定义即可
//private:
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//};
//
////c++扩展了delete的用法，delete除了释放new申请的资源外
//class CopyBan
//{
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator = (const CopyBan&) = delete;
//};
//
////请设计一个类，不能被继承
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
//class A final
//{
//
//};
//
////单例设计模式
////设计一个类，只能创建一个对象
////方法1 饥汉模式
////优点：简单
////缺点：可能导致进程启动慢，并且如果有多个单例类对象实例启动顺序不确定
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	//构造函数
//	Singleton(){};
//
//	//c++98 预防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	//C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton m_instance;
//};
//
//Singleton Singleton::m_instance;
//
////懒汉模式
////优点：第一次使用实例对象时，创建对象，进程启动无负载，多个单例实例启动顺序自由控制
////缺点：复杂
//#include <iostream>
//#include <mutex>//互斥锁
//#include <thread>//线程
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		if (nullptr == m_pInstance)
//		{
//			m_mtx.lock();
//			if (nullptr == m_pInstance)
//			{
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//
//	//实现一个内嵌垃圾回收类
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	static CGarbo Garbo;
//
//private:
//	//构造函数私有
//	Singleton(){};
//
//	//防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	//单例对象指针
//	static Singleton* m_pInstance;
//	//互斥锁
//	static mutex m_mtx;
//};
//
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//
//void func(int n)
//{
//	cout << Singleton::GetInstance() << endl;
//}
//
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//
//	t1.join();
//	t2.join();
//
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//}



#include <iostream>
using namespace std;
//
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateHeapOnly()
//	{
//		return new HeapOnly;
//	}
//private:
//	HeapOnly()
//	{}
//
//	HeapOnly(HeapOnly&);
//
//	HeapOnly(const HeapOnly&) = delete;
//};
//
//class StackOnly
//{
//public:
//	static StackOnly CreateStackOnly()
//	{
//		return StackOnly();
//	}
//
//private:
//	StackOnly()
//	{}
//};
//
//class StackOnly
//{
//public:
//	StackOnly()
//	{}
//private:
//	void* operator new(size_t size);
//	void operator delete(void *p);
//};
//
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//private:
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//};
//
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator=(const CopyBan&) = delete;
//};
//
//class NonInherit
//{
//public:
//	static NonInherit NonInheritCreate()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
//class NonInherit final
//{
//public:
//	NonInherit()
//	{}
//};

//单例模式
//class Singleton
//{
//public:
//	static Singleton* SingletonCreate()
//	{
//		return &m_simgleton;
//	}
//private:
//	Singleton()
//	{}
//
//	Singleton(const Singleton&)
//	{}
//
//	Singleton& operator=(const Singleton&)
//	{}
//
//	static Singleton m_simgleton;
//};
//
//Singleton Singleton::m_simgleton;
//
//int main()
//{
//
//	cout << Singleton::SingletonCreate() << endl;
//	cout << Singleton::SingletonCreate() << endl;
//
//
//	return 0;
//}

//懒汉模式
//#include <iostream>
//#include <thread>//thread
//#include <mutex>
//using namespace std;//
//
//class Singleton
//{
//public:
//	static Singleton* SingletonCreate()//static *
//	{
//		if (m_singleton == nullptr)//==
//		{
//			m_mutex.lock();
//			if (m_singleton == nullptr)//==
//			{
//				m_singleton = new Singleton();//new
//			}
//			m_mutex.unlock();
//		}
//		return m_singleton;
//	}
//
//	//内嵌的垃圾回收类
//	class CGarbo//Garbage collection
//	{
//	public:
//		~CGarbo()
//		{
//			if (Singleton::m_singleton)
//				delete Singleton::m_singleton;
//		}
//	};
//
//	static CGarbo Garbo;
//
//private:
//	Singleton()
//	{}
//
//	Singleton(Singleton const&)//const&
//	{}
//
//	Singleton& operator=(Singleton const&)//const&
//	{}
//private:
//	static Singleton* m_singleton;//*
//	static mutex m_mutex;
//};
//
//Singleton* Singleton::m_singleton = nullptr;//*
//mutex Singleton::m_mutex;
//
//void func(int n)
//{
//	cout << Singleton::SingletonCreate() << endl;
//}
//
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 20);
//
//	t1.join();
//	t2.join();
//
//	cout << Singleton::SingletonCreate() << endl;
//	cout << Singleton::SingletonCreate() << endl;
//
//	return 0;
//}

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class singleton
{
public:
	static singleton* singleton_create()
	{
		if (m_singleton == nullptr)
		{
			m_mutex.lock();
			if (m_singleton == nullptr)
			{
				m_singleton = new singleton();
			}
			m_mutex.unlock();
		}
		return m_singleton;
	}

	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (m_singleton)
			{
				delete singleton::m_singleton;
			}
		}
	};

	static CGarbo m_cgarbo;
private:
	singleton()
	{}

	singleton(const singleton&)
	{}

	singleton& operator=(const singleton&)
	{}
private:
	static singleton* m_singleton;
	static mutex m_mutex;
};

singleton* singleton::m_singleton = nullptr;
singleton::CGarbo m_cgarbo;
mutex singleton::m_mutex;

void func(int n)
{
	cout << singleton::singleton_create() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 20);

	t1.join();
	t2.join();

	cout << singleton::singleton_create() << endl;
	cout << singleton::singleton_create() << endl;

	return 0;
}