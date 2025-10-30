#include <stdio.h>

 void printarray(int arr[],int l,int h){
     for(int i=l;i<h;i++){
         printf("%d ",arr[i]);   
        }
        
 }
 
 void readarray(int arr[],int n){
     printf("Enter elements to Array\n");
     for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
         
     }
 }
 
 void swap(int * a,int *b){
     int temp=*a;
     *a=*b;
     *b=temp;
 }
 
 int partition(int arr[],int l,int h){
     int pivot=arr[l];
     int i=l;
     int j=h;
     while(i < j)
     {
     do{
         i++;
     }while(i<=h && arr[i]<=pivot);
     do{
         j--;
     }while(j>=l && arr[j]>pivot);
     
     if(i<j){
         swap(&arr[i],&arr[j]);
     }
         
     }
     
     swap(&arr[l],&arr[j]);
     return j;
     
     
 }
 
 void quicksort(int arr[],int l,int h){
     if(l<h){
         int index=partition(arr,l,h+1);
         printarray(arr,l,index);
         printf("\t*%d\t",arr[index]);
         printarray(arr,index+1,h+1);
         printf("\n");
         
         quicksort(arr,l,index-1);
         quicksort(arr,index+1,h);
     }
 }
 
 int main(){
     int n;
     printf("Enter no of elements in the array: ");
     scanf("%d",&n);
     int arr[n];
     readarray(arr,n);
     printf("\nOrginal Array: ");
     printarray(arr,0,n);
     printf("\n");
     quicksort(arr,0,n-1);
     printf("Sorted array :");
     printarray(arr,0,n);
 }