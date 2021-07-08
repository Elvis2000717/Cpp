//�����һ���ֻ࣬���ڶ��ϴ�������
class HeapOnly
{
public:
	static HeapOnly* CreateOject()
	{
		return new HeapOnly;
	}

private:
	HeapOnly(){}

	//1.����һ
	HeapOnly(const HeapOnly&);

	//2.������
	//C++11
	HeapOnly(const HeapOnly&) = delete;
};

//���һ���ֻ࣬����ջ�ϴ�������
//����һ
class StackOnly
{
public:
	//�����캯��˽�л���Ȼ����ƾ�̬�����������󷵻�
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly(){}
};

//������:����new
class StackOnly
{
public:
	StackOnly(){}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

//���һ���࣬���ܱ�����
class CopyBan
{
	//���������� 1.�������캯�� 2.��ֵ�����
	//��ֹ����ֻ��Ҫ�������������ŵ�private��ֻ���������弴��
private:
	CopyBan(const CopyBan&);
	CopyBan& operator=(const CopyBan&);
};

//c++��չ��delete���÷���delete�����ͷ�new�������Դ��
class CopyBan
{
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator = (const CopyBan&) = delete;
};

//�����һ���࣬���ܱ��̳�
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

class A final
{

};

//�������ģʽ
//���һ���ֻ࣬�ܴ���һ������
//����1 ����ģʽ
//�ŵ㣺��
//ȱ�㣺���ܵ��½�������������������ж�����������ʵ������˳��ȷ��
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//���캯��
	Singleton(){};

	//c++98 Ԥ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//C++11
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton m_instance;
};

Singleton Singleton::m_instance;

//����ģʽ
//�ŵ㣺��һ��ʹ��ʵ������ʱ���������󣬽��������޸��أ��������ʵ������˳�����ɿ���
//ȱ�㣺����
#include <iostream>
#include <mutex>//������
#include <thread>//�߳�
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();
			if (nullptr == m_pInstance)
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}

	//ʵ��һ����Ƕ����������
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

	static CGarbo Garbo;

private:
	//���캯��˽��
	Singleton(){};

	//������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//��������ָ��
	static Singleton* m_pInstance;
	//������
	static mutex m_mtx;
};

Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}