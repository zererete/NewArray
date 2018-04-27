#include "CArray.h"
#include <iostream>
using namespace std;

int main()
{
	CArray<string> arr;

	arr.push_back("asd");
	arr.push_front("qwe");
	
	for (int i = 0; i < arr.size(); ++i)
		cout << "arr " << arr[i].data() << endl;
	cout << arr.empty() << endl;


	arr.clear();
	arr.push_back("1");
	arr.push_front("2");

	for (int i = 0; i < arr.size(); ++i)
		cout << "arr " << arr[i].data() << endl;
	cout << arr.empty() << endl;
	//CArray<string> arr(5);
	//arr.fill(5, "world");

	//arr[1] = "hello";
	//arr[2] = "mister";
	//arr[3] = "smith";

	//cout << arr[1].data() << endl;

	//CArray<string> arr2(10);
	//arr2.insert(5, "ins");
	//for (int i = 0; i < arr2.size(); ++i)
	//	cout << "arr2 " << arr2[i].data() << endl;
	//cout << endl;
	//arr2 = arr;

	//for (int i = 0; i < arr.size(); ++i)
	//	cout << "arr " << arr[i].data() << endl;
	//cout << endl;
	//for (int i = 0; i < arr2.size(); ++i)
	//	cout << "arr2 " << arr2[i].data() << endl;
	//cout << endl;

	//arr2.insert(0,"qwe1");
	//arr2[1] = "qwe2";
	//arr2[2] = "qwe3";
	//arr2[3] = "qwe4";
	//arr2[4] = "qwe5";
	//arr2.insert(0, "insert");

	//for (int i = 0; i < arr.size(); ++i)
	//	cout << "arr " << arr[i].data() << endl;
	//cout << endl;
	//for (int i = 0; i < arr2.size(); ++i)
	//	cout << "arr2 " << arr2[i].data() << endl;
	//cout << endl;

	//arr.clear();
	return 0;
}