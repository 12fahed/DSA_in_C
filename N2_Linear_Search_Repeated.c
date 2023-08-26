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
		
	printf("Entter the Element you want to Search: ");
	scanf("%d", &k);
	
	for(int i=0; i<size; i++){
		if(k==a[i]){
			index=i;
		    printf("Element %d was found at the Index %d\n", k, index);
		    flag=1;
			}
		}
		
	if(flag==0){
		printf("Element %d isnt present in the array", k);
		}
	
	
}
