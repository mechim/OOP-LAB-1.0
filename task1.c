#include <stdio.h>

int main(){
    int n;

    printf("how big will the triangle be?\n > ");
    scanf("%d",&n);

    for (int k = 1; k <= n; k++){
        for (int i = 0; i<n-k; i++){
        printf(" ");
        }

        for (int j = 0; j<k; j++){
            printf("#");
        }
        printf("\n");
    
    }

}