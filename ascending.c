//arranging three numbers in ascending order
#include<stdio.h>

int main(){
  int a,b,c;
  printf("Enter three numbers: ");
  scanf("%d %d %d", &a,&b,&c);
  if(a<b&&a<c){
    if(b<c){
      printf("Ascending order is: %d %d %d \n", a,b,c);
    }
    else{
      printf("Ascending order is: %d %d %d \n", a,c,b);
    }
  }
   if(b<a&&b<c){
    if(a<c){
      printf("Ascending order is: %d %d %d \n", b,a,c);
    }
    else{
      printf("Ascending order is: %d %d %d \n", b,c,a);
    }
  }
  if(c<a&&c<b){
    if(a<b){
      printf("Ascending order is: %d %d %d \n", c,a,b);
    }
    else{
      printf("Ascending order is: %d %d %d \n", c,b,a);
    }
  }
  return 0;
}