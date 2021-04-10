#include <iostream>
using namespace std;

namespace N
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N1
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

using N::b;
using namespace N;
using namespace N1;

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	printf("%d\n", c);
	return 0;
}