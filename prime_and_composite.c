//Program to determine number is Prime or Composite number
#include <stdio.h>
int main(){
  int i,n,count=0;
  printf("Enter number: ");
  scanf("%d", &n);

  for(i=1;i<=n;i++){
    if(n%i==0){
      count+=1;
    }
  }
  if(count==2){
    printf("The number is Prime \n");
  }
  else{
    printf("The number is Composite \n");
  }
  return 0;
}