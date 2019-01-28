#include<stdio.h>

int main(){

    int num,path,initial,save;
    int cur[100],nex[100];
    int power[100];
    int current_stack[100],path_stack[100];
    int i,pow,m1,m2,current,yes,p,w,f,back;
    scanf("%d%d%d%d",&num,&path,&initial,&save);
    
    for(i=0;i<num;i++){
       scanf("%d",&pow);
       power[i]=pow;
    }    
    for(i=0;i<path;i++){
       scanf("%d%d",&m1,&m2);
       cur[i]=m1;
       nex[i]=m2;       
    }

    current=0; //現在要挑戰的關卡current
    yes=0;  //yes 代表是否成功拯救
    p=0;    // path 紀錄
    w=1;    // win times begins at 1
    f=0;    // fail times
   
      while(yes==0){

           for(i=0;i<path;i++){
               if(cur[i]==current){
                 if(initial>power[nex[i]]){
                   initial=initial+power[nex[i]];
                   path_stack[p]=i;
                   current_stack[p]=current;
                   p++;
                   w++;
                   current=nex[i];
                   i=-1;
                   if(initial>save){
                   yes=1;
                   break;
                   }
                 }
                 else
                 f++;
               }
               if(i==path-1){   //路死了
               current=current_stack[--p];  //current變回上一層
               i=path_stack[p];  // i從上次找完的下一個開始
               }         
           }
           
      
      }
     printf("%d %d %d",f,w,initial);

return 0;
   
}

      
 
