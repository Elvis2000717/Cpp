#include <iostream>
#include <stdlib.h>

using namespace std;

//int main()
//{
//	int i = 1;
//	cout << &i << endl;
//	cout << (char*)&i << endl;
//	cout << (*(char*)&i) << endl;
//
//	return 0;
//}

//#include <stdio.h>
//int check_sys()
//{
//	int i = 1;
//	return (*(char *)&i);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("Ð¡¶Ë\n");
//	}
//	else
//	{
//		printf("´ó¶Ë\n");
//	}
//	return 0;
//}

#include <stdio.h>
//void test(int arr[])//ok?

//void test(int arr[10])//ok?

//void test(int *arr)//ok?
//void test2(int *arr[20])//ok?

//void test2(int **arr)//ok?
//{}

int main()
{
	int *a = (int *)calloc(10, sizeof(int));
	int *b = (int *)malloc(10);
	int *c = (int *)realloc(b, 20);

	free(a);
	free(c);
}