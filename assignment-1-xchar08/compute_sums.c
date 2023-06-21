#include <stdio.h>
#include "monster_utils.h"

int main(){
    int n, a, b, c = 0;
    printf("Enter three integers: ");
    scanf("%d %d %d", &n,&a,&b);
    for(int i = 0; i < n; i++){
        if(i%a==0 || i%b==0){
            c+=i;
        }
    }   
    printf("%d",c);
    return 0;
}