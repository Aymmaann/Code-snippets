//Program to input array from the user and reverse it
#include<stdio.h>
int main(){
  int i,j,n,a[100];
  printf("Enter number of elements in array: ");
  scanf("%d", &n);
  
  printf("Input %d elements in the array: \n", n);
  for(i=1; i<=n; i++){
    printf("element - %d : ", i);
    scanf("%d",&a[i]);
  }
  
  printf("The elements in the array are: \n");
  for(i=0; i<n; i++){
    printf("%d ", a[i]);
  }

  printf("\nThe array in reverse is: \n");
  for(i=n-1; i>=0; i--){
    printf("%d ",a[i]);
  }
  printf("\n");
  
  return 0;
}