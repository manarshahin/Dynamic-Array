#include <iostream>
using namespace std;
template<class T>
class DynamicArray
{
private:
	T* Arr = new T[Capacity];//make a static array in the heap
	int Length = 0;
	int Capacity = 0;
public:
	/*defalut constractor and destractor*/
	DynamicArray() {}
	~DynamicArray() {}
	/*return the size of the array*//*complexity==O(1)*/
	int length()
	{
		return Length;
	}
	/*return the size of array in the memory *//*complexity==O(1)*/
	int capacity() {
		return Capacity;
	}
	/*check if the array is empty or not*//*complexity==O(1)*/
	bool isEmpty()
	{
		return (Length == NULL);
	}
	/*return the first element*//*complexity==O(1)*/
	T front()
	{
		return Arr[0];
	}
	/*return the last element*//*complexity==O(1)*/
	T back()
	{
		return Arr[Length - 1];
	}
	/*return the element in index *//*complexity==O(1)*/
	T getValue(int index)
	{
		if (index < Length)
			return Arr[index];
		return 0;
	}
	/*remove the last elelment*//*complexity==O(1)*/
	T pop_back()
	{
		return Arr[--Length];
	}
	/*insert the elements in the array*//*complexity==O(1)*/
	void push_back(int element)
	{
		if (Length == Capacity) {
			resize(Capacity + 1);
		}
		Arr[Length] = element;
		Length++;
	}
	/*insert in the indexs*//*complexity==O(n)*/
	void insert(int index, int element)
	{
		if (index <= Length)
		{
			if (Length == Capacity)
			{
				resize(Capacity + 1);
			}
			for (int i = Length - 1; i >= index; i--)
			{
				// shift all element right  
			   // from given index 
				Arr[i + 1] = Arr[i];
			}
			// insert data at given index 
			Arr[index] = element;
			Length++;
		}
	}
	/*make an update in the elements *//*complexity==O(1)*/
	void update(int index, int element)
	{
		if (index <= Length)
			Arr[index] = element;
	}
	/*make the length==capscity*//*complexity==O(n)*/
    void shrink()
	{
		int* temp=NULL;
        if (Length > 0) { 
  
            // temp is a count size array 
            // and store array elements 
            temp = new int[Length]; 
            for (int i = 0; i < Length; i++) { 
  
                // copy all array value into temp 
                temp[i] = Arr[i]; 
            } 
             Capacity = Length; 
            // count size array temp initialize  
            // into variable array again 
            Arr = temp; 
        } 
	}
	/*complexity == O(n)*/
	void resize(int size)
	{    if (size == Length)
				return;
		 if (size <= 0)
				return;
		int* temp = new int[size];
		int min = (size > Length) ? Length : size;
		for (int i = 0; i < min; i++)
			temp[i] = Arr[i];
		delete[]Arr;
		Arr = temp;
		temp = NULL;
		Capacity = size;
	}
	/*make a comparision between two array if it is equlas others or not *//*complexity==O(n)*/
	bool equals(DynamicArray array)
	{
		for (int x = 0;x < Length;x++)
		{
			if (Arr[x] != array.Arr[x])
				return false;
		}
		return true;
	}
	/*copy the all elements*//*complexity==O(n)*/
	T *copy() 
	{
		int* temp = new int[Length];
		for (int i = 0;i < Length;i++)
			temp[i] = Arr[i];
		return temp;
	}
	/*reverse the elements in the array*//*complexity==O(n)*/
	void reverse()
	{
        for (int i = 0;i < Length / 2;i++)
		{
			int temp = Arr[i];
			Arr[i] = Arr[((Length - 1) - i)];//Arr[i] = Arr[Length - 1];
			Arr[((Length - 1) - i)] = temp;//Arr[Length - 1] = temp;
		}
	}
	/*check is the element is fine in the array or not*//*complexity==O(n)*/
    bool contains(int element)
{
	for (int i = 0;i < Length;i++)
	{
		if (Arr[i] == element)
			return true;
	}
	return false;
}
	/*search about an element in the array and return it is index*//*complexity==O(n)*/
    int linearSearch(int element)
    {
		for (int i = 0;i < Length;i++)
		if (Arr[i] == element)
				return i;
		return -1;
    }
	/*print the elements in the array*//*complexity==O(n)*/
    void print() {
	for (int i = 0;i < Length;i++)
		cout << Arr[i] << endl;
}
	/*the element that is biger than it is nuibghers*//*complexity==O(n)*/
    int findPeak()
	{
		
		for (int i=1;i<Length-1;i++) 
		{
			if (Arr[i] > Arr[i - 1] && Arr[i] > Arr[i + 1])
				return i;
		}
	}
	/*remove an element in particular index*//*complexity==O(n)*/
    void erase(int index)
 {
	if (Length > 0)
	{
		for (int i = index; i < Length - 1; i++)
		{
			// shift all element of right
			// side from given index in left
			Arr[i] = Arr[i + 1];
		}
		Arr[Length - 1] = 0;
		Length--;
	}
	/*//Another code to implement this function
	int* arr = new int[Length-1];
	for (int i = 0, x = 0;i < Length;i++)
	{
		if (i == index)
			continue;
		arr[x++] = Arr[i];
	}
		Length--;
		Capacity--;
		Arr = arr;*/
}
	/*remove the elements in the array*//*complexity==O(1)*/
    void clear()
	{
		Length = 0;
	}
};
