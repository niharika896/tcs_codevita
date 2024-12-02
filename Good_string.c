#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char good[100];
    char given[100];

    fgets(good, sizeof(good), stdin);
    fgets(given, sizeof(given), stdin);

    good[strcspn(good, "\n")] = '\0';
    given[strcspn(given, "\n")] = '\0';

    int ngo = strlen(good);
    int ngi = strlen(given);

    int dm = (3 * ngi) + 1;
    char arr[dm];

    memset(arr, '\0', sizeof(arr));

    arr[0] = given[0];
    arr[1] = good[0];

    for (int i = 0; i < ngi; i++) {
        int pos = given[i];
        int max = abs(good[0] - pos);
        int maxpos = 0;

        for (int j = 0; j < ngo; j++) {
            if (abs(good[j] - pos) < max) {
                max = abs(good[j] - pos);
                maxpos = j;
            }
        }

        if (i != 0) {
            arr[3 * i + 1] = arr[3 * i - 1];
        }
        arr[3 * i] = given[i];
        arr[3 * i + 2] = good[maxpos];
    }

    int sum = 0;
    for (int i = 0; i < ngi; i++) {
        sum += abs(arr[3 * i] - arr[3 * i + 2]);
    }

    printf("%s\n", arr);
    printf("%d\n", sum);

    return 0;
}
