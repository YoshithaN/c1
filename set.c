#include <stdio.h>

int main() {
    int set1[] = {1, 2, 3, 4};
    int set2[] = {3, 4, 5};
    int intersection[10];  
    int index = 0;

    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);

    for (int i = 0; i < size1; i++) {
        int value = set1[i];  

        for (int j = 0; j < size2; j++) {
            if (set2[j] == value) {
                intersection[index] = value;
                index++;
                break;             }
        }
    }

    printf("Intersection: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");

    return 0;
}
