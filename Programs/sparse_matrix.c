#include<stdio.h>

int main(void){
    int r,c, count=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);
    int matrix[r][c];
    
    printf("Enter elements into the matrix: \n");
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (matrix[i][j] == 0){
                count++;
            }
        }
    }

    if (count > ((r*c)/2)){
        int s = 0;
        int sparse[count][3];
        printf("It is a Sparse Matrix\n");

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (matrix[i][j] != 0){
                    sparse[s][0] = i;
                    sparse[s][1] = j;
                    sparse[s][2] = matrix[i][j];
                    s++;
                }
            }
        }

        printf("3-tuple representation of this sparse matrix: \n");
        for (int i=0; i<s; i++){
            for (int j=0; j<3; j++){
                printf("%3d ", sparse[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("It's not a Sparse Matrix\n");
    }
    
    return 0;
}