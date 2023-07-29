https://practice.geeksforgeeks.org/problems/heap-sort/1

https://youtu.be/NKJnHewiGdc?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA


class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
     int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[largest]<arr[left])
        largest = left;
    
     if(right<n && arr[largest]<arr[right])
        largest = right;
    
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
        
    }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n) {
      for(int i=n/2-1;i>=0;i--)
            heapify(arr,n,i);
        
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {   int size = n;
     buildHeap(arr,n);
           for(int i=n-1;i>=1;i--)
       {
           swap(arr[0],arr[i]);
           heapify(arr,i,0);
       }
    }
};