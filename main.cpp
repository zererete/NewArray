#include "CArray.h"
#include <iostream>
using namespace std;

int main()
{
	CArray<char*> arr(5);
	arr.fill(5, "world");

	arr[1] = "hello";
	arr[2] = "mister";
	arr[3] = "smith";

	cout << arr[1] << endl;

	CArray<char*> arr2(1);

	arr2 = arr;

	for (int i = 0; i < arr.size(); ++i)
		cout << "arr " << arr[i] << endl;
	cout << endl;
	for (int i = 0; i < arr2.size(); ++i)
		cout << "arr2 " << arr2[i] << endl;
	cout << endl;

	arr2[0] = "qwe1";
	arr2[1] = "qwe2";
	arr2[2] = "qwe3";
	arr2[3] = "qwe4";
	arr2[4] = "qwe5";

	for (int i = 0; i < arr.size(); ++i)
		cout << "arr " << arr[i] << endl;
	cout << endl;
	for (int i = 0; i < arr2.size(); ++i)
		cout << "arr2 " << arr2[i] << endl;
	cout << endl;

	arr.clear();
	return 0;
}