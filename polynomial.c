#include <stdio.h>

struct poly {
    int exp;
    int coe;
} p1[10], p2[10], p3[10];

void read(struct poly p[], int *t);
int add(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]);
void display(struct poly p[], int terms);

int main() {
    int t1 = 0, t2 = 0, t3;

    read(p1, &t1);
    printf("First polynomial\n");
    display(p1, t1);

    read(p2, &t2);
    printf("Second polynomial\n");
    display(p2, t2);

    t3 = add(p1, p2, t1, t2, p3);
    printf("\n\nResult polynomial\n");
    display(p3, t3);

    return 0;
}

void read(struct poly p[], int *t) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", t);

    printf("Enter the elements:\n");
    for (int i = 0; i < *t; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &p[i].coe);
        printf("Enter the exponent: ");
        scanf("%d", &p[i].exp);
    }
}

void display(struct poly p[], int terms) {
    for (int k = 0; k < terms; k++) {
        printf("%d(x^%d)", p[k].coe, p[k].exp);

        if (k < terms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int add(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].exp == p2[j].exp) {
            p3[k].coe = p1[i].coe + p2[j].coe;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        } else if (p1[i].exp > p2[j].exp) {
            p3[k].coe = p1[i].coe;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        } else {
            p3[k].coe = p2[j].coe;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
    }

    while (i < t1) {
        p3[k].coe = p1[i].coe;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }

    while (j < t2) {
        p3[k].coe = p2[j].coe;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }

    return k;
}
/*/*3. **Add Function (`int add(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[])`)**
   - Initialize indices `i`, `j`, and `k` to 0 to traverse `p1`, `p2`, and `p3` respectively.
   - Use a while loop to compare exponents of `p1` and `p2` until either of them is exhausted.
   - If the exponents are equal, add the coefficients and set the exponent in the result polynomial (`p3`).
   - If the exponent of `p1` is greater, copy the term from `p1` to `p3`.
   - If the exponent of `p2` is greater, copy the term from `p2` to `p3`.
   - After the while loop, copy the remaining terms from `p1` and `p2` to `p3` if any.
   - Return the total number of terms in the result polynomial.*/
*/
