1. Fractional Knapsack Problem:
c
#include <stdio.h>
#include <stdlib.h>

struct item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct item *item1 = (struct item *)a;
    struct item *item2 = (struct item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    return ratio2 > ratio1 ? 1 : -1;
}

double fractionalKnapsack(int W, struct item arr[], int n) {
    qsort(arr, n, sizeof(struct item), compare);
    int i;
    double finalValue = 0.0;

    for (i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50; // Weight of knapsack
    struct item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum value we can obtain = %lf", fractionalKnapsack(W, arr, n));
    return 0;
}
