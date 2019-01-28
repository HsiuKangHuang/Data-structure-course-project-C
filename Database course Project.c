#include<stdio.h>
typedef struct{
        short int row;
        short int col;
        short int dir;
}element;
element stack[100];

int main(){

    int i,j,row,col,dir,next_row,next_col,found=0;
    int mark[100][100];
    int maze[100][100];
    int coin=0;
    int top=1;//top init at 1 because stack[0] is full;top means the next enpty.
    int n,e_x,e_y,e_i,e_j;
    element position;
    element stack[1000];    

    scanf("%d%d%d%d%d",&n,&e_x,&e_y,&e_i,&e_j);
    mark[e_x][e_y]=1;
    stack[0].row=e_x;stack[0].col=e_y;stack[0].dir=1; //dir1234  

    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
          scanf("%d",&maze[i][j]);
       }
    }    
    printf("start position:row=%d,col=%d\n",e_x,e_y);
    while(top>0&&found==0){
         top=top-1;
         position=stack[top];
         row=position.row;col=position.col;dir=position.dir;
         while(dir<5&&found==0){
              //move in dir
              if(dir==1){
              next_row=row-1;next_col=col;
              }
              else if(dir==2){
              next_row=row;next_col=col+1;
              }
              else if(dir==3){
              next_row=row+1;next_col=col;
              }
              else{
              next_row=row;next_col=col-1;
              }
//              printf("next_row=%d,next_col=%d ",next_row,next_col); //

              if(next_row==e_i&&next_col==e_j){
              found=1;
              printf("end position:row=%d,col=%d\n",next_row,next_col);
              }
              else if(maze[next_row][next_col]==0&&mark[next_row][next_col]==0){
              mark[next_row][next_col]=1;
              printf("The position now:row=%d,col=%d\n",next_row,next_col);  //
              position.row=row;position.col=col;position.dir=++dir;
              stack[top++]=position;
              row=next_row;col=next_col;dir=1;   
              }
              else if(maze[next_row][next_col]==2&&mark[next_row][next_col]==0){
              mark[next_row][next_col]=1;              
              printf("The position now:row=%d,col=%d\n",next_row,next_col);  //
              position.row=row;position.col=col;position.dir=++dir;
              stack[top++]=position;
              row=next_row;col=next_col;dir=1;
              coin++;   
              }
              else{ 
              dir=dir+1;
              }
           
         }
    }
    printf("%d ",coin);
    return 0;
}
