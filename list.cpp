#include <iostream>
using namespace std;

namespace my_list
{
	template<class _Ty>
	class list
	{
	public:
		//类型的萃取
		typedef size_t        size_type;
		typedef _Ty           value_type;
		typedef _Ty*          pointer_type;
		typedef _Ty&          reference_type;
		typedef const _Ty*    const_pointer_type;
		typedef const _Ty&    const_reference_type;

	public:
		struct _Node;
		typedef struct _Node* _Nodeptr;
		struct _Node
		{
			_Nodeptr _Next;
			_Nodeptr _Prev;
			_Ty      _Value;
		};

	public:
		struct _Acc
		{
			typedef _Node* & _Nodepref;
			typedef _Ty&     _Vref;
			static _Nodepref _Next(_Nodeptr _P)
			{
				return _P->_Next;
			}
			static _Nodepref _Prev(_Nodeptr _P)
			{
				return _P->_Prev;
			}
			static _Vref _Value(_Nodeptr _P)
			{
				return _P->_Value;
			}
		};

	public:
		//迭代器
		class iterator
		{
		public:
			iterator()
			{}
			iterator(_Nodeptr _P) :_Ptr(_P)
			{}

		public:
			bool operator!=(const iterator &_it)
			{
				return _Ptr != _it._Ptr;
			}
			bool operator==(const iterator &_it)
			{
				return !(*this != _it);
			}
			_Ty& operator*()
			{
				return _Acc::_Value(_Ptr);
			}
			iterator& operator++()
			{
				_Ptr = _Acc::_Next(_Ptr);
				return *this;
			}
			iterator operator++(int)
			{
				iterator tmp(_Ptr);
				++*this;
				return tmp;
			}
			iterator& operator--()
			{
				_Ptr = _Acc::_Prev(_Ptr);
				return *this;
			}
			iterator operator--(int)
			{
				iterator tmp(_Ptr);
				--*this;
				return tmp;
			}
			_Nodeptr _Mynode()
			{
				return _Ptr;
			}

		private:
			_Nodeptr _Ptr;
		};
	
	public:
		explicit list() :_Head(_Buynode()), _Size(0)
		{}
		list(size_type _N, const _Ty& _V = _Ty())
			:_Head(_Buynode()), _Size(0)
		{
			insert(begin(), _N, _V);
		}

		~list()
		{
			erase(begin(), end());
			_Freenode(_Head);
			_Head = 0;
			_Size = 0;
		}

	public:
		iterator begin()
		{
			return iterator(_Acc::_Next(_Head));
		}
		iterator end()
		{
			return iterator(_Head);
		}

	public:
		/*void push_back(const _Ty& _X)
		{
			_Nodeptr _S = _Buynode(_Head, _Acc::_Prev(_Head));
			_Acc::_Value(_S) = _X;
			//_S->prev->next = _S;
			_Acc::_Next(_Acc::_Prev(_S)) = _S;

			//_S->next->prev = _S;
			_Acc::_Prev(_Acc::_Next(_S)) = _S;

			_Size++;
		}*/
		void push_back(const _Ty& _X)
		{
			insert(end(), _X);
		}
		void push_front(const _Ty& _X)
		{
			insert(begin(), _X);
		}
		
		bool empty()const
		{
			return _Size == 0;
		}
		size_type size()const
		{
			return _Size;
		}
		_Ty& front()
		{
			return *begin();
		}
		const _Ty& front()const
		{
			return *begin();
		}
		_Ty& back()
		{
			return *--end();
		}

		public:
			iterator insert(iterator _P, const _Ty& _X = _Ty())
			{
				_Nodeptr _S = _P._Mynode();
				//_Nodeptr _S = (_Node*)malloc(sizeof(_Node));
				_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
				_S = _Acc::_Prev(_S);
				_Acc::_Next(_Acc::_Prev(_S)) = _S;
				_Acc::_Value(_S) = _X;

				_Size++;
				return iterator(_S);
			}
			void insert(iterator _P, size_type _M, const _Ty& _X)
			{
				for (; 0 < _M; --_M)
					insert(_P, _X);
			}
			void insert(iterator _P, const _Ty *_F, const _Ty *_L)
			{
				for (; _F != _L; ++_F)
					insert(_P, *_F);
			}
			/*void insert(iterator _P, _It _F, _It _L)
			{
				for (; _F != _L; ++_F)
					insert(_P, *_F);
			}*/

			iterator erase(iterator _P)
			{
				_Nodeptr _S = (_P++)._Mynode();
				_Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
				_Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);
				_Freenode(_S);
				--_Size;
				return (_P);
			}
			iterator erase(iterator _F, iterator _L)
			{
				while (_F != _L)
					erase(_F++);
				return (_F);
			}

			void _Freenode(_Nodeptr _S)
			{
				free(_S);
			}
			void clear()
			{
				erase(begin(), end());
			}

	protected:
		_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
		{
			_Nodeptr _S = (_Node*)malloc(sizeof(_Node));
			//_S->_Next = _Narg != 0 ? _Narg : _S;
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;

			//_S->_Prev = _Parg != 0 ? _Parg : _S;
			_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
			return _S;
		}

	private:
		_Nodeptr _Head;
		size_type _Size;
	};
};

int main()
{
	/*my_list::list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);

	my_list::list<int>::iterator pos = mylist.begin();
	mylist.insert(pos, 10);
	mylist.push_back(20);
	mylist.push_front(30);*/

	my_list::list<int> mylist(10, 5);

	mylist.erase(mylist.begin());
	mylist.erase(--mylist.end());
	//mylist.clear();
	my_list::list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		cout << *it << "-->";
		++it;
	}
	cout << "Over." << endl;

	cout << "front: " << mylist.front() << endl;
	cout << "back: " << mylist.back() << endl;

	return 0;
}