#include <stdlib.h>
#include <stdio.h>
#define MAX 100


int lis( int* s, int N ) {
    int *act_best, i, j, max = 0;
    act_best = (int*) malloc ( sizeof( int ) * N );

    for (i = 0; i < N; i++ ){
        act_best[i] = 1;
    }

    for ( i = 1; i < N; i++ ) {
        for (j = 0; j < i; j++) {
            if (s[i] > s[j] && act_best[i] < act_best[j] + 1) {
                act_best[i] = act_best[j] + 1;
                max = act_best[i];
            }
        }
    }
    free( act_best );
    return max;
}

int lir(int s[], int n){
    int act_run = 0;
    int max_run = 0;
    int last = s[0]-1;
    int i;
    for(i = 0; i < n; i++) {
        /*printf("Aktuell: %d Letztes: %d ", s[i], last);*/
        if(last < s[i]) {
            act_run++;
        } else {
            if(act_run > max_run) {
                max_run = act_run;
                act_run = 1;
            }
        }
        /*printf(" Run: %d\n", act_run); */
        last = s[i];
    }
    if(act_run > max_run) {
        max_run = act_run;
    }

    return max_run;
}

int main() {
    int max_run, i;
    int s[MAX] = {9,5,2,3,4,3,1,6,4};
    int n = 9;
    max_run = lir(s, n);
    for(i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }


    printf("\nLIR Ergebnis: %d\n", max_run);

    printf("LIS Ergebnis: %d\n", lis( s, 9) );

    return 0;
}
