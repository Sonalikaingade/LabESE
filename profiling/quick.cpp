
#include <bits/stdc++.h>
using namespace std; 
void swap(int* a, int* b) 
{ 
 int t = *a; 
 *a = *b; 
 *b = t; 
}
 
int part (int arr[], int low, int high) 
{ 
 int pivot = arr[high];
 int i = (low - 1);
 for (int j = low; j <= high - 1; j++) 
 { 
 if (arr[j] < pivot) 
 { 
 i++; 
 swap(&arr[i], &arr[j]); 
 } 
 } 
 swap(&arr[i + 1], &arr[high]); 
 return (i + 1); 
} 
void quick(int arr[], int low, int high) 
{ 
 if (low < high) 
 { 
 int pi = part(arr, low, high); 
 
 quick(arr, low, pi - 1); 
 quick(arr, pi + 1, high); 
 } 
} 
 
void print(int arr[], int size) 
{ 
 int i; 
 for (i = 0; i < size; i++) 
 cout << arr[i] << " "; 
 cout << endl; 
 
} 
 
int main() 
{ 
 int arr[10000];
 int n = sizeof(arr) / sizeof(arr[0]);
 for (int i = 0; i<n; i++){
 arr[i] = i;
}
 
 quick(arr, 0, n - 1); 
 cout << "Sorted array: \n"; 
 print(arr, n); 
 return 0; 
}