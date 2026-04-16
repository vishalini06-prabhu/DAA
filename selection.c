#include<stdio.h>
int main(){
   int n,i,j,temp,min;
   printf("Enter number of elements:\n");
   scanf("%d",&n);
   int a[n];
   printf("Enter array elements:\n");
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   for(i=0;i<n-1;i++){
      min=i;
      for(j=i;j<n;j++){
         if(a[j]<a[min]){
            min=j;
         }
      }
      if(min!=i){
         a[i]=a[i]+a[min];
         a[min]=a[i]-a[min];
         a[i]=a[i]-a[min];
      }
   }
   printf("Sorted Array: ");
   for(i=0;i<n;i++){
      printf("%d ",a[i]);
   }
   return 0;
}
