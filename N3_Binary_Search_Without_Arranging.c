#include<stdio.h>

int main(){
	
	int size, k, startindex=0, lastindex, m;
	int a[100];
	printf("Enter the size of the Array (Less than 100): ");
	scanf("%d", &size);
	printf("Enter the Elements of Array: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
		}
		
	printf("Enter the Element you want to Search: ");
	scanf("%d", &k);
	
	lastindex=size-1;
	
	
	while(startindex<=lastindex){
	   m=(startindex+lastindex)/2;
	   if(k==a[m]){
		   printf("Element %d is present at the index position %d", k, m);
		   break;
		   }
		
	   else if(k<a[m]){
		   lastindex=m-1;
		   }
	   
	   else if(k>a[m]){
		   startindex=m+1;
    	   }
    	
    	if(startindex>lastindex){
			printf("Element %d isnt present in the array", k);
			break;
			}	
	}
	

}
