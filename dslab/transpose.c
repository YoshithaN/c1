#include <stdio.h>

struct sparse{
    int row;
    int col;
    int val;
};

int main(){
    int r,c,val1,val2,row1,col1,v1,row2,col2,v2;
    printf("enetr total no of rows and col of matrix\t");
    scanf("%d%d",&r,&c);
    printf("enetr no of non zero elements in matrices\t");
    scanf("%d%d",&val1,&val2);
    struct sparse m1[val1+1];
    struct sparse m2[val2+1];
    struct sparse sum[val1+val2+2];
    struct sparse t[val1+1];
    m1[0].row=r;
    m1[0].col=c;
    m1[0].val=val1;
    printf("enetr elements to matrix1 \n");
    for(int i=1;i<=val1;i++){
        scanf("%d%d%d",&row1,&col1,&v1);
        m1[i].row=row1;
        m1[i].col=col1;
        m1[i].val=v1;
    }
    m2[0].row=r;
    m2[0].col=c;
    m2[0].val=val2;
    printf("enetr elements to matrix 2\n");
        for(int j=1;j<=val2;j++){
            scanf("%d%d%d",&row2,&col2,&v2);
            m2[j].row=row2;
            m2[j].col=col2;
            m2[j].val=v2;
        }
    printf("sparse matrix 1\n");
    printf("%d\t%d\t%d\n",m1[0].row,m1[0].col,m1[0].val);
    for(int i=1;i<=val1;i++){
        printf("%d\t%d\t%d\n",m1[i].row,m1[i].col,m1[i].val);
    }
    printf("sparse matrix 2\n");
    printf("%d\t%d\t%d\n",m2[0].row,m2[0].col,m2[0].val);
    for(int j=1;j<=val2;j++){
        printf("%d\t%d\t%d\n",m2[j].row,m2[j].col,m2[j].val);
    }
    
    int i=1,j=1,k=1;
    while(i<=m1[0].val && j<=m2[0].val){
        if (m1[i].row<m2[j].row){
        sum[k++]=m1[i++];}
        else if(m1[i].row >m2[j].row){
            sum[k++]=m2[j++];
        }
        else{
            if(m1[1].col < m2[j].col){
                sum[k++]=m1[i++];
            }
            else if(m1[i].col >m2[j].col){
                sum[k++]=m2[j++];
            }
            else{
                int sumval=m1[i].val+m2[j].val;
                if(sumval!=0){
                sum[j].val=sumval;
                sum[j].row=m1[i].row;
                sum[j].col=m1[i].col;
                k++;
                    
                }
            i++;
            j++;
            }
            
        }
    }
    while(i<=m1[0].val){
        sum[k++]=m1[i++];
        ;
    }
    while(j<=m2[0].val){
        sum[k++]=m2[j++];
        ;
    }
    
    sum[0].row=m1[0].row;
    sum[0].col=m1[0].col;
    sum[0].val=k-1;
    printf("sum of sparse matrix is\n");
    printf("%d\t%d\t%d\n",sum[0].row,sum[0].col,sum[0].val);
    for(int a=1;a<=sum[0].val;a++){
        printf("%d\t%d\t%d\n",sum[a].row,sum[a].col,sum[a].val);
    }
    
    int w=1;
    for(int c=0;c<m1[0].val;c++);
    {
        for(int i=1;i<=m1[0].val;i++){
            if(m1[i].col==c){
                t[w].row=m1[i].col;
                t[w].col=m1[i].row;
                t[w].val=m1[i].val;
                w++;
            }
            
        }
    }
    t[w].val=k-1;
    printf("%d\t%d\t%d\n",t[0].row,t[0].col,t[0].val);
    printf("transpose of matrix 1 is\n");
    for(int i=1;i<=t[i].val;i++){
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].val);
        
    }
    return 0;
    
    
}