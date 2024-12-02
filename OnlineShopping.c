#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
    char name[10];
    int tok;
};

int main() {
    int n, k, ni;
    scanf("%d", &n);

    int av[n], cl[n];
    for (int i = 0; i < n; i++) scanf("%d", &av[i]);
    for (int i = 0; i < n; i++) scanf("%d", &cl[i]);

    scanf("%d", &k);
    scanf("%d", &ni);

    struct item items[ni];
    for (int i = 0; i < ni; i++) {
        scanf("%s", items[i].name);
        scanf(":%d", &items[i].tok);
    }

    int max = 0, maxpos = -1;
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int l = 0; l < k; l++) {
            sum += (cl[i + l] ? 0 : av[i + l]);
        }
        if (sum > max) {
            max = sum;
            maxpos = i;
        }
    }

    if (maxpos != -1) {
        for (int i = maxpos; i < maxpos + k; i++) {
            cl[i] = 1;
        }
    }

    int finalsum = 0;
    for (int i = 0; i < n; i++) {
        finalsum += (cl[i] ? av[i] : 0);
    }

    int min = 1000, minpos = -1;
    for (int i = 0; i < ni; i++) {
        int diff = finalsum - items[i].tok;
        if (diff >= 0 && diff < min) {
            min = diff;
            minpos = i;
        }
    }

    if (minpos != -1) {
        printf("%d:%s\n", items[minpos].tok, items[minpos].name);
    } else {
        printf("No suitable item found\n");
    }

    return 0;
}
