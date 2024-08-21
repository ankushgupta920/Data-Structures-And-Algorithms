// Bubble sort:
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[100] , size, i, j, temp;
//     cout<<"Enter the size of array: "<<endl;
//     cin>>size;
//     cout<<"Enter the array elements: "<<endl;

//     for(i = 0; i < size; i++)
//     {
//         cin>>arr[i];
//     }

//     for(i = size; i > 0; i--)
//     {
//         for(j = 0; j < i-1; j++)
//         {
//             if(arr[j]  > arr[j+1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }

//     cout<<"Sorted Result: "<<endl;
//     for(i = 0; i<size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }   


// selection sort:
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[100] , size, i, j, temp;
//     cout<<"Enter the size of array: "<<endl;
//     cin>>size;
//     cout<<"Enter the array elements: "<<endl;

//     for(i = 0; i < size; i++)
//     {
//         cin>>arr[i];
//     }

//     for(i = 0; i<size-1; i++)
//     {
//         for(j = i+1; j<size; j++)
//         {
//             if(arr[j] < arr[i])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }

//     cout<<"Sorted Result: "<<endl;
//     for(i = 0; i<size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }   


// insertion sort:
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[100] , size, i, j, temp;
//     cout<<"Enter the size of array: "<<endl;
//     cin>>size;
//     cout<<"Enter the array elements: "<<endl;

//     for(i = 0; i < size; i++)
//     {
//         cin>>arr[i];
//     }

//     for(i = 1; i < size; i++)
//     {
//         for(j = i; j >= 1; j--)
//         {
//             if(arr[j-1] > arr[j])
//             {
//                 temp = arr[j-1];
//                 arr[j-1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

//     cout<<"Sorted Result: "<<endl;
//     for(i = 0; i<size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }  



// Quick sort:
// #include<iostream>
// using namespace std;
// int parition(int arr[] , int start , int end)
// {
//     int pivot = arr[start];

//     int cnt = 0, i, j;
//     for(i = start+1; i<=end; i++)
//     {
//         if(arr[i] <= pivot)
//         {
//             cnt++;
//         }
//     }

//     // from this above loop we get the right place for the partition

//     int pivotIndex = start + cnt;

//     swap(arr[pivotIndex] , arr[start]);

//     // left(<a) and right(>a)

//     i =  start , j = end;

//     while(i < pivotIndex && j > pivotIndex)
//     {
//         // if already the elements are smaller then pivot
//         while(arr[i] <= pivot)
//         {
//             i++;
//         }

//         // if already the elements are bigger then pivot
//         while(arr[j] > pivot)
//         {
//             j--;
//         }

//         if(i < pivotIndex && j > pivotIndex)
//         {
//             swap(arr[i] , arr[j]);
//             i++;
//             j--;
//         }
//     }
//     return pivotIndex;
// }
// void quicksort(int arr[] , int start , int end)
// {
//     // base case
//     if(start >= end)
//     {
//         return;
//     }

//     // partition:
//     int p;
//     p = parition(arr,start,end);

//     // left part sort:
//     quicksort(arr,start,p-1);

//     // right part sort
//     quicksort(arr,p+1,end);
// }
// int main(){
//     int arr[100] , size, i, j, temp;
//     cout<<"Enter the size of array: "<<endl;
//     cin>>size;
//     cout<<"Enter the array elements: "<<endl;

//     for(i = 0; i < size; i++)
//     {
//         cin>>arr[i];
//     }

//     quicksort(arr,0,size-1);

//     cout<<"Sorted Result: "<<endl;
//     for(i = 0; i<size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// return 0;
// }  


// Merge sort:
#include<iostream>
using namespace std;
void merge(int *arr , int start , int end)
{
    int mid = (start + end) / 2;

    // creating two sperate arrays:
    int len1 = mid - start+1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];


    // copying the values from the main array to the sperate arrays:
    int mainArrayindex = start;
    for(int i = 0; i<len1; i++)
    {
        first[i] = arr[mainArrayindex];
        mainArrayindex++;
    }

    mainArrayindex = mid + 1;
    for(int i = 0; i<len2; i++)
    {
        second[i] = arr[mainArrayindex];
        mainArrayindex++;
    }

    // merge both the arrays:
    int index1 = 0;
    int index2 = 0;
    mainArrayindex = start;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            arr[mainArrayindex++] = first[index1++];
        }
        else
        {
            arr[mainArrayindex++] = second[index2++];
        }
    }

    while(index1 < len1)
    {
        arr[mainArrayindex++] = first[index1++];
    }

    while(index2 < len2)
    {
        arr[mainArrayindex++] = second[index2++];
    }
}
void mergesort(int *arr , int start , int end)
{
    // base case
    if(start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    // left part sort:
    mergesort(arr , start , mid);

    // right part sort:
    mergesort(arr , mid+1 , end);

    // dono ko merge kar do
    merge(arr , start , end);
}
int main(){
    int arr[100] , size, i, j, temp;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    cout<<"Enter the array elements: "<<endl;

    for(i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    mergesort(arr,0,size-1);

    cout<<"Sorted Result: "<<endl;
    for(i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
} 