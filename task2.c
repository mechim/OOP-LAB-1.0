#include <stdio.h>

int main(){
    int n;
    printf("how big will the star be?\n > ");
    scanf("%d", &n);

    int star[n][n];

    //zeroing the array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            star[i][j] = 0;
        }
    }
    //making the tip
    int row = 0;
    star[0][n/2] = 1;
    row++;
   

    //getting to the spread
    int k = 0, c = 0;
    for (int i = 1; i < n/2-1; i++){
        for (int j = n/2-k; j <=n/2+k; j++){
            star[i][j] = 1;
        }
        c++;
        if (n > 15){
            if (c == 2){
                k++;
                c = 0;
            }
        } else k++;
        
        row++;
    }
    //making the spread
    for (int j = 0; j < n; j++){
        star[n/2-1][j] = 1;
    }
    row++;

    //making the lower wings
    int otstup = 0, kolvo = 1;
    for (int i = n-1; i > 0; i--){
        if(kolvo + otstup > n/2) break;
        for (int j = otstup; j < n-otstup; j++){
            
            if (j <= otstup+kolvo-1|| j >(n-1)-kolvo-otstup) {
                star[i][j] = 1;
            } else {
                star[i][j] = 0;
            }
        }
        otstup++;
        kolvo++;
        row++;
    }

    //final touch
    k = n/2 - 1;
    for (int i = n/2; i <= row; i++){
        for (int j = n/2-k; j <= n/2+k; j++){
            star[i][j] = 1;
        }
        k--;
    }
    //printing the star
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (star[i][j] == 1) printf("#"); 
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;

}