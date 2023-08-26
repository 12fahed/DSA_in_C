//Linear Search
#include<stdio.h>

int main(){
	
	int size, k, index, flag=0;
	int a[100];
	printf("Enter the size of the Array (Less than 100): ");
	scanf("%d", &size);
	printf("Enter the Elements of Array: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &a[i]);
		}
		
	printf("Enter the Element you want to Search: ");
	scanf("%d", &k);
	
	for(int i=0; i<size; i++){
		if(k==a[i]){
			index=i;
			flag=1;
			break;
			}
		}
	
	
	if(flag==1){
		printf("Element %d was found at the Index %d", k, index);
		}
		
    else{
		printf("Element %d isnt Present in the array", k);
		}
}
