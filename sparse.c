#include <stdio.h>

int m,n;
int count=0;

int main(){
    printf("enter rows and columns\n");
    scanf("%d%d",&m,&n);
    int matrix[m][n];
    
    printf("enter elements\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]!=0){
                count++;
            }
        }
    }
    printf("Original Matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                printf("%d\t",matrix[i][j]);
            
        }
        printf("\n");
    }
    printf("Sparse Matrix\n");
    struct tuple{
        int row;
        int col;
        int val;
    };
    struct tuple s[count+1];
    s[0].row=m;
    s[0].col=n;
    s[0].val=count;
    int c=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                s[c].row=i;
                s[c].col=j;
                s[c].val=matrix[i][j];
                c++;
            }
        }
        
    }
    for(int c=0;c<=count;c++){
        printf("%d\t%d\t%d\n",s[c].row,s[c].col,s[c].val);
    }
}