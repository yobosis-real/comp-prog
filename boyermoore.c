#include <stdio.h>
#include <string.h>

int boyermoore(char p[], char t[]) {
    int bctable[128], i, j, k;
    int n = strlen(t);
    int m = strlen(p);

    for (j = 0; j < 128; j++)
        bctable[j] = m;

    for (j = 0; j < m - 1; j++) {
        k = (int)p[j];
        bctable[k] = m - j - 1;
    }

    i = m - 1;

    while (i < n) {
        j = m - 1;
        while (j >= 0 && p[j] == t[i]) {
            i--;
            j--;
        }

        if (j == -1)
            return i + 1;

        i = i + bctable[(int)t[i]];
    }

    return 0;
}

int main() {
    char t[] = "welcometodsatmcollege";
    char p[] = "dsatm";
    int i;

    i = boyermoore(p, t);

    if (i)
        printf("Pattern is present in text at position %d\n", i + 1);
    else
        printf("Pattern is not present in text\n");

    return 0;
}