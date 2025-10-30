#include <stdio.h>

void descending(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int n,k;
    printf("Enter no of events participated : ");
    scanf("%d",&n);
    int arr[n];
    printf("enetr points for activities\n");
    for(int i=0;i<n;i++){
        printf("Activity %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("enter max no to be participated : ");
    scanf("%d",&k);
    
    descending(arr,n);
    int sum=0;
    for(int i=0;i<k && i<n;i++){
        sum+=arr[i];
    }
    printf("max points :%d",sum);
    return 0;
}