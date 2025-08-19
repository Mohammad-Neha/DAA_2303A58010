#include <stdio.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) {
    int m[50][50];
    int i,L;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
        
    for ( L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
             int k;
            for (k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter orders of matrices:\n");
    int i;
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
	int minCost = matrixChainOrder(p, n );
    printf("Least number of multiplications is %d\n", minCost);

    return 0;
}
