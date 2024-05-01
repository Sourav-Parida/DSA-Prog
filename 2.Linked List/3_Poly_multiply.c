#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to insert a term into a polynomial
void insertTerm_22051243(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    // Multiply each term of poly1 with each term of poly2
    for (struct Node* term1 = poly1; term1 != NULL; term1 = term1->next) {
        for (struct Node* term2 = poly2; term2 != NULL; term2 = term2->next) {
            int new_coeff = term1->coeff * term2->coeff;
            int new_exp = term1->exp + term2->exp;
            insertTerm_22051243(&result, new_coeff, new_exp);
        }
    }

    return result;
}

// Function to display a polynomial
void Avi_displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
    } else {
        struct Node* current = poly;
        while (current != NULL) {
            printf("%d", current->coeff);
            if (current->exp > 0) {
                printf("x^%d", current->exp);
            }
            if (current->next != NULL) {
                printf(" + ");
            }
            current = current->next;
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Input for the first polynomial
    printf("Enter the first polynomial terms (coeff exp, enter 0 0 to end):\n");
    while (1) {
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        insertTerm_22051243(&poly1, coeff, exp);
    }

    // Input for the second polynomial
    printf("Enter the second polynomial terms (coeff exp, enter 0 0 to end):\n");
    while (1) {
        int coeff, exp;
        scanf("%d%d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        insertTerm_22051243(&poly2, coeff, exp);
    }

    // Multiply the two polynomials
    result = multiplyPolynomials(poly1, poly2);

    // Display the input and result polynomials
    printf("First Polynomial: ");
    Avi_displayPolynomial(poly1);
    printf("Second Polynomial: ");
    Avi_displayPolynomial(poly2);
    printf("Result Polynomial: ");
    Avi_displayPolynomial(result);

    // Free memory
    while (poly1 != NULL) {
        struct Node* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        struct Node* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (result != NULL) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}