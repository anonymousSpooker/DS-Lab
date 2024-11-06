#include <stdio.h>
#define MAX 50

void heapify(int arr[], int n, int i){
        int root = i;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        
        if(leftChild < n && arr[leftChild] > arr[root])
                root = leftChild;
        if(rightChild < n && arr[rightChild] > arr[root])
                root = rightChild;
        if(root!=i){
                int temp = arr[i];
                arr[i] = arr[root];
                arr[root] = temp;
                heapify(arr,n,root);
        }
}

void heapSort(int arr[], int n){
        for(int i=n/2-1; i>=0; i--)
                heapify(arr,n,i);
        
        for(int i=n-1; i>0; i--){
                int temp = arr[i];
                arr[i] = arr[0];
                arr[0] = temp;
                // Heaping again for excluding the last element:
                heapify(arr,i,0);
        }
}

int main(){
     int arr[MAX],n;
     printf("Enter the size of the array: ");
     scanf("%d", &n);
     printf("Enter the array: ");
     for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
     heapSort(arr,n);
     printf("\nSorted Array: ");
     for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
     return 0;
}
