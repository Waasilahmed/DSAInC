#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int *mtrx, int *pro, int p) {
    int *size = (int *)malloc(p * p * sizeof(int));
    
    int r = 0;
    while (r < p) {
        int c = 0;
        while (c < p) {
            size[r * p + c] = 0;
            int i = 0;
            do {
                size[r * p + c] += (mtrx[r * p + i] * pro[i * p + c]);
                i++;
            } while (i < p);
            c++;
        }
        r++;
    }

    int *calc = malloc(p * p * sizeof(int));

    int e = 0;
    while (e < p * p) {
        calc[e] = size[e];
        e++;
    }


    free(size);

    int f = 0;
    while (f < p * p) {
        pro[f] = calc[f];
        f++;
    }


    free(calc);
}

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");

    int p = 0; int s = 0; int expo = 0;

    fscanf(file, "%d", &p);


    int *pro = (int *)malloc(p * p * sizeof(int));


    int *mtrx = (int *)malloc(p * p * sizeof(int));
    


    int r = 0;
    while (r < p) {
        int c = 0; 
        while (c < p) {
            fscanf(file, "%d", &s);
            mtrx[r * p + c] = s;
            pro[r * p + c] = s;
            c++;
        }
        r++;
    }





    fscanf(file, "%d", &expo);

    for (int i = 0; i < expo - 1; i++) {
        multiplyMatrices(mtrx, pro, p);
    }

    int z = 0;


    while (z < p) {
        int c = 0;
        while (c < p) {
            printf("%d", pro[z * p + c]);
            if (c != p - 1) printf(" ");
            c++;
        }
        printf("\n");
        z++;
    }



    free(mtrx);
    free(pro);

    return 0;
}

