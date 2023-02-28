#include<iostream>
using namespace std;
class Array {
private:
	int* item;
	int size;
	int length;
public:
	Array(int arraySize) {
		size = arraySize;
		length = 0;
	}
	//function fill array
	void Fill(int arrayFill) {
		item = new int[size];
		if (arrayFill > size) {
			cout << "arry fill must't exceed arry size" << endl;
		}
		else {
			for (int i = 0; i < arrayFill; i++) {
				cout << "Enter the value of element " << i + 1 << " : ";
				cin >> item[i];
				length++;
			}
		}
	}
	//function dispaly arry 
	void Display() {
		cout << "Array Elememts are : \n";
		for (int i = 0; i < length; i++) {
			cout << item[i] << "\t";
		}
		cout << "\n";
	}
	//fuction get length
	void GetLength() {
		cout << "The Array Lenght is: " << length << endl;
	}
	//function get size
	void GetSize() {
		cout << "The Array Size is: " << size << endl;
	}
	//Search function 
	int Search(int element) {
		int  index = -1;
		for (int i = 0; i < length; i++) {
			if (element == item[i]) {
				index = i;
				break;
			}
		}
		return index;
	}
	//append fuction 
	void Append(int element) {
		if (length < size) {
			item[length] = element;
			length++;
		}
		else
			cout << "The array is full!" << endl;
	}
	//insert fuction 
	void Insert(int element, int index) {
		if (index < size) {
			for (int i = length; i > index; i--) {
				item[i] = item[i - 1];
			}
			item[index] = element;
			length++;
		}
		else
			cout << "arry is full you can't insert any element \n";
	}
	//delete function 
	void	Delete(int index) {
		if (index < size) {
			for (int i = index; i < length - 1; i++) {
				item[i] = item[i + 1];
			}
			length--;
		}
		else
			cout << "Array out of lenght\n";
	}
	//Enlarge function
	void Enlarge(int newSize) {
		if (size >= newSize) {
			cout << "the size must be greater than old size\n";
		}
		else {
			int* old = item;
			item = new int[newSize];
			for (int i = 0; i < length; i++) {
				item[i] = old[i];
			}
			size = newSize;
			delete[]old;
		}
	}
};
int main() {
	int arrSize;
	int fillCount;
	int x;
	int y;
	cout << "Please Enter Array Size \n";
	cin >> arrSize;
	Array arr(arrSize);
	cout << "Enter how many Element you want to Enter it\n";
	cin >> fillCount;
	arr.Fill(fillCount);
	arr.Display();
	arr.GetLength();
	arr.GetSize();
	cout << "Enter the value you want to search it in the array\n";
	cin >> x;
	if (arr.Search(x) != -1) {
		cout << x << " Found at position " << arr.Search(x) << endl;
	}
	else {
		cout << x << " not found at the array" << endl;
	}
	cout << "Please Enter Element You want to append it in the array \n";
	cin >> y;
	arr.Append(y);
	arr.Display();
	cout << "Enter the element you want to insert it\n";
	cin >> x;
	cout << "Enter the index you want to put in it\n";
	cin >> y;
	arr.Insert(x, y);
	arr.Display();
	cout << "Enter index of element you want to delete \n";
	cin >> x;
	arr.Delete(x);
	arr.Display();
	cout << "Enter the Size you want to put it\n";
	cin >> x;
	arr.Enlarge(x);
	arr.GetSize();

}