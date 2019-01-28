#include<stdio.h>

int main(){
     
    int s,i,j,k;
    int set,interger,num,end;
    int mat[100][100];
    int row_stack[100],col_stack[100],mark[100][100];
    int ring,begin,p;

    scanf("%d",&set);
    for(s=1;s<=set;s++){
        scanf("%d",&interger);
        for(i=0;i<interger;i++){
           for(j=0;j<interger;j++){
               scanf("%d",&num);
               mat[i][j]=num;              
           }
        }
       
     begin=-1;
     for(i=0;i<interger;i++){
        for(j=0;j<interger;j++){
           if(mat[i][j]==1){
             begin=i;
             break;
           }
        }

        if(begin!=-1)
        break;
     }

     ring=0; 
     p=-1;
     for(i=0;i<100;i++){      // initialize mark
        for(j=0;j<100;j++){
           mark[i][j]=0;
        }
     }
  
  
     
     i=begin; // begin at beginning row
     while(ring==0){
       for(j=0;j<interger;j++){
          if(mat[i][j]==1){

            for(k=0;k<p;k++){
                
              if(row_stack[k]==i && col_stack[k]==j){  //走到走過的地方
                 ring=1;
                 break;   
              }          
            }
 
            if(ring==1){
            break;
            }
             
            p++;
            row_stack[p]=i;
            col_stack[p]=j;

            
            mark[i][j]=1; //走過變1
            i=j; //從指定排開始找
            j=-1; //歸零  
          }
          else if(mat[i][j]==0){
            if(j==interger-1){
              if(p==-1){
                ring=-1;
                break;
              }
              
              i=row_stack[p];
              j=col_stack[p];
              p--;

              if(j==interger-1&&p!=0){
                 i=row_stack[p];
                 j=col_stack[p];
                 p--;
              }
              else if(j==interger-1&&p==0){
                     ring=-1;
                     break;
              }
            }
          }
       } 
     }
   
    if(ring==1&&s==set)
    printf("Yes");
    else if(ring==-1&&s==set)
    printf("No");
    else if(ring==1&&s!=set)
    printf("Yes\n");
    else
    printf("No\n"); 
    scanf("%d",&end);
    }
  
  return 0;  
}
