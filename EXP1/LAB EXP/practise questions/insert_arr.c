/*
-shift all elements one position to the right
-increase arr size by one
-take a variable pos and shift elements from there
*/
#include <stdio.h>
int main(){
    int i,n,x,pos;
    int arr[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    scanf("%d %d",&pos,&x);
    for(i=n;i>=pos;i--){
        arr[i]=arr[i-1];}
        arr[pos-1]=x;
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    }
    }
