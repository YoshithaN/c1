#include <stdio.h>
struct sparse{
    int row;
    int col;
    int val;
};
//struct sparse matrix[20];
int main(){
    int m,n,val;
    printf("enter total rows col and val\n");
    scanf("%d%d%d",&m,&n,&val);
    struct sparse matrix[val+1];
    struct sparse t[val+1];
    matrix[0].row=m;
    matrix[0].col=n;
    matrix[0].val=val;
    t[0].row=n;
    t[0].col=m;
    t[0].val=val;
    printf("enter data\n");
    for(int i=1;i<=val;i++){
        int m1,n1,val1;
        scanf("%d%d%d",&m1,&n1,&val1);
        matrix[i].row=m1;
        matrix[i].col=n1;
        matrix[i].val=val1;
    }
    int k=1;
    int c=0;
    while(c<matrix[0].col){
        for(int i=1;i<=matrix[0].val;i++){
            if(matrix[i].col==c){
                t[k].row=matrix[i].col;
                t[k].col=matrix[i].row;
                t[k].val=matrix[i].val;
                k++;
            }
        }
        c++;
    }
    printf("original matrix\n");
    printf("%d\t%d\t%d\n",matrix[0].row,matrix[0].col,matrix[0].val);
    for(int i=1;i<=matrix[0].val;i++){
        printf("%d\t%d\t%d\n",matrix[i].row,matrix[i].col,matrix[i].val);
    }
    printf("transpose\n");
    printf("%d\t%d\t%d\n",t[0].row,t[0].col,t[0].val);
    for(int i=1;i<=t[0].val;i++){
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].val);
    }
    return 0;
}