/*
Find sum of all array elements using recursion
*/

#include <stdio.h>
int sum(int a[],int n){
    if (n==0){
        return 0;}
    else{
        return (a[n-1],sum(a,n-1));    
    }
}
int main(){
    int n, a[100];
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
