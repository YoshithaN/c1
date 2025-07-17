#include <stdio.h>
void rotate(int arr[],int n,char dir,int count){
    count%=n;
    int temp[n];
if (dir =='l'){
    for(int i=0;i<n;i++){
        temp[i]=arr[(i+count)%n];
        
    }
}
else if(dir=='r'){
    for(int i=0;i<n;i++){
        temp[i]=arr[(i-count+n)%n];
    
    }
    
}
else{
    printf("invalid");
    
}
for(int i=0;i<n;i++){
    arr[i]=temp[i];
    
}}
int main()
{
    int n,count;
    printf("enter no of terms\n");
    scanf("%d",&n);
    int arr[n];
    printf("ente elements to array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    
    
    }
    char dir;
    printf("enter count\n");
    scanf("%d",&count);
    printf("enter direction\n");
    scanf(" %c",&dir);
    printf("orginal array is:");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);}
    
    rotate(arr,n,dir,count);
    printf("printing rotating array");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
    
}
    

