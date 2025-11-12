#include "myops.h"

double calcualte(char* op, double a, double b) {
    printf("Calculating.....\n");

    if(!strcmp(op, "+")) {
        return myadd(a, b);
    }
    else if (!strcmp(op, "-")) {
        return mysub(a, b);
    }
    else if (!strcmp(op, "*")) {
        return mymul(a, b);
    }
    else if (!strcmp(op, "/")) {
        return mydiv(a, b);
    }
    else if (!strcmp(op, "%")) {
        return mymod(a, b);
    }
    else if (!strcmp(op, "^")) {
        return mypow(a, b);
    }
    else {
        printf("Unsupported operation: %s\n", op);
        return 0;
    }
}

int main(void) {

    double a, b;
    char op[3];

    printf("~~~ Welcome to my calculator ~~~\n\n");
    printf("Enter expression (e.g., 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result = %.2lf\n", calcualte(op, a, b));
    printf("~~~ Good bye. See you again ~~~\n\n");

    return 0;
}