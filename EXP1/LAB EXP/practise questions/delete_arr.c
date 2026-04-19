/*
-shift arr to the left so we can overwrite the element tht needs to be deleted
-reduce arr size by one
*/
#include <stdio.h>
int main(){
    int i,n,x,pos;
    int arr[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",arr[i]);
    for(i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
        
    }
    }
}