#include <stdio.h>

struct sparse{
    int row;
    int col;
    int val;
};

int main(){
    int m,n,val1,val2;
    printf("enter total rows col of matrices\n");
    scanf("%d%d",&m,&n);
    printf("enter total nonzero elem in 1 and 2\n");
    scanf("%d%d",&val1,&val2);
    struct sparse m1[val1+1];
    struct sparse m2[val2+1];
    struct sparse sum[val1+val2+2];
    m1[0].row=m;
    m1[0].col=n;
    m1[0].val=val1;
    
    printf("enter data for m1\n");
    for(int i=1;i<=val1;i++){
        int r,c,va;
        scanf("%d%d%d",&r,&c,&va);
        m1[i].row=r;
        m1[i].col=c;
        m1[i].val=va;
    }
    m2[0].row=m;
    m2[0].col=n;
    m2[0].val=val2;
    printf("enter data for m2\n");
    for(int j=1;j<=val2;j++){
        int r,c,va;
        scanf("%d%d%d",&r,&c,&va);
        m2[j].row=r;
        m2[j].col=c;
        m2[j].val=va;
    }
    printf("sparse matrix1\n");
    printf("%d\t%d\t%d\n",m1[0].row,m1[0].col,m1[0].val);
    for(int i=1;i<=m1[0].val;i++){
        printf("%d\t%d\t%d\n",m1[i].row,m1[i].col,m1[i].val);
    }
    printf("sparse matrix2\n");
    printf("%d\t%d\t%d\n",m2[0].row,m2[0].col,m2[0].val);
    for(int i=1;i<=m2[0].val;i++){
        printf("%d\t%d\t%d\n",m2[i].row,m2[i].col,m2[i].val);
    }
    
    
    
    
    
    
    int i = 1, j = 1, k = 1;
    
    while(i <= m1[0].val && j <= m2[0].val){
        if(m1[i].row < m2[j].row){
            sum[k++] = m1[i++];
        }
        else if(m2[j].row < m1[i].row){
            sum[k++] = m2[j++];
        }
        else { // m1[i].row == m2[j].row
            if(m1[i].col < m2[j].col){
                sum[k++] = m1[i++];
            }
            else if(m2[j].col < m1[i].col){
                sum[k++] = m2[j++];
            }
            else { // m1[i].col == m2[j].col
                int sum_val = m1[i].val + m2[j].val;
                if(sum_val != 0){
                    sum[k].row = m1[i].row;
                    sum[k].col = m1[i].col;
                    sum[k].val = sum_val;
                    k++;
                }
                i++;
                j++;
            }
        }
    }
    
    while(i <= m1[0].val){
        sum[k++] = m1[i++];
    }
    
    while(j <= m2[0].val){
        sum[k++] = m2[j++];
    }
    
    sum[0].row = m1[0].row;
    sum[0].col = m1[0].col;
    sum[0].val = k-1;
    
    printf("\nSum of the two sparse matrices:\n");
    printf("%d\t%d\t%d\n", sum[0].row, sum[0].col, sum[0].val);
    for(i=1; i<=sum[0].val; i++){
        printf("%d\t%d\t%d\n", sum[i].row, sum[i].col, sum[i].val);
    }
    
    return 0;
}