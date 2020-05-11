
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

       
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}


void merge(int arr[], int l, int m, int r)
{
     int i=l,j=m+1;
     int a[r-l+1];
     int k=0;
     while(i<=m && j<=r) {
         if(arr[i]<arr[j]) {
             a[k++]=arr[i++];
         }
         else a[k++] =arr[j++];
     }
     while(i<=m) a[k++] = arr[i++];
     while(j<=r) a[k++] = arr[j++];
     k=0;
     for(int q=l;q<=r;q++) arr[q]=a[k++];
}