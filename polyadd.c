#include <stdio.h>

struct polynomial {
    int coeff;
    int exp;
};


int readPoly(struct polynomial p[]) {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the coefficients and exponents in descending order of exponents:\n");
    for (i = 0; i < n; i++) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &p[i].coeff);
        printf("Exponent: ");
        scanf("%d", &p[i].exp);
    }
    return n;
}


void printPoly(struct polynomial p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].coeff != 0) {
            printf("%dx^%d", p[i].coeff, p[i].exp);
            if (i < n - 1) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}


int addPoly(struct polynomial p1[], int n1, struct polynomial p2[], int n2, struct polynomial p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        } else if (p1[i].exp < p2[j].exp) {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        } else {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
    }

    
    while (i < n1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }

    
    while (j < n2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }
    return k;
}

int main() {
    
    struct polynomial poly1[10], poly2[10], poly3[10];
    int n1, n2, n3;

    printf("Enter the first polynomial:\n");
    n1 = readPoly(poly1);

    printf("\nEnter the second polynomial:\n");
    n2 = readPoly(poly2);

    printf("\nFirst polynomial is: ");
    printPoly(poly1, n1);

    printf("Second polynomial is: ");
    printPoly(poly2, n2);

    n3 = addPoly(poly1, n1, poly2, n2, poly3);

    printf("\nResultant polynomial is: ");
    printPoly(poly3, n3);

    return 0;
}