#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
void Merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void MergeSort(vector<int> &arr, int left, int right)
{

    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int LinearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] == target)
            return i;
    }
    return -1;
}

int Binarysearch(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left - right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[mid] < target)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }
}

void PrintArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, target, result;
    vector<int> arr;

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Enter element of array [" << i << "]: ";
        cin >> arr[i];
    }
    cout << endl
         << "Array is: ";
    PrintArray(arr);

    do
    {
        cout << endl
             << "---Search and Sort Menu---" << endl;
        cout << "Press 1 for Selection Sort" << endl;
        cout << "Press 2 for Merge Sort" << endl;
        cout << "Press 3 for Linear Search" << endl;
        cout << "Press 4 for Binary Search" << endl;
        cout << "Press 5 for Display Array" << endl;
        cout << "press 0 for Exit!!" << endl;

        cout << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        cout<<endl<<"Array is: ";
        PrintArray(arr); 

            SelectionSort(arr); 
            cout<<"Selection Sort: ";
            PrintArray(arr); 
            break;
        case 2:
            cout << endl
                 << "Array is: ";
            PrintArray(arr);

            MergeSort(arr, 0, arr.size() - 1);
            cout << "Merge Sort: ";
            PrintArray(arr);
            break;
        case 3:
        cout<<"Array is: ";
        PrintArray(arr); 

        if(arr.size() != 0) 
        {
            cout<<"Enter the target value to search: ";
            cin>>target; 
            result = LinearSearch(arr, target); 
        }
        else
        {
            cout<<"Array is Empty."<<endl; 
            break;
        }

        if (result != -1) {
            cout << "Element found at index: " << result << endl;
        } 
        else 
        {
            cout << "Element not found." << endl;
        }
        break;

        case 4:
        SelectionSort(arr); 
        cout << "Sorted array: ";
    PrintArray(arr); 
        if(arr.size() != 0) 
        {

            cout << "Enter the target value to search: ";
            cin >> target;
            result = Binarysearch(arr, target); 
        }
        else
        {
            cout<<"Array is Empty."<<endl; 
            break;
        }

        if (result != -1) {
            cout << "Element found at index: " << result << endl;
        } 
        else 
        {
            cout << "Element not found." << endl;
        }
        break;

        case 5:
            PrintArray(arr);
            break;
        case 0:
            cout << "Exiting Program";

            return 0;

        default:
            cout << "Invalid choice!!";
        }
    } while (choice != 0);
    return 0;
}