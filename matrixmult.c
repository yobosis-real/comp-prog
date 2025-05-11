#include <stdio.h>
#include <limits.h>

void MatrixChainOrder(int p[], int n) {
    int m[n][n];
    
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n-1]);
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};  // Example: A(40x20), B(20x30), C(30x10), D(10x30)
    int n = sizeof(arr)/sizeof(arr[0]);
    MatrixChainOrder(arr, n);
    return 0;
}
