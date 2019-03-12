#define STACK_SIZE 100

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "../stack.h"

double stack [STACK_SIZE];
int sp = 0;

int push (double c) {
    if (sp < STACK_SIZE) {
        stack[sp++] = c;
        return 0;
    }

    else {
        return -1;
    }
}

double pop () {
    if (sp > 0){
        return stack[--sp];
    }
    else {
        return NAN;
    }
}

int isStackEmpty() {
    if (getStackSize() == 0){
        return 1;
    }
    else {
        return 0;
    }
}

int getStackSize(){
    return sp;
}

void emptyStack () {
    sp = 0;
}

int main (){

    double result;
    char c;
    double v1;
    double v2;
    int fail = 0;
    int flag = 0;
    int current = 0;
    int count = 1;

    c = getchar();

    while (c != EOF) {
        if (isdigit(c) > 0) {
            flag = 1;
            current = current * 10 + c - '0';
        }

        else if (flag == 1){
            fail = push(current);
            if (fail == -1){
                printf("Stack full when pushing (%d) at position %d\n", current, count);
                return -1;
            }
            else {
                fail = 0;
            }
            current = 0;
            flag = 0;
        }

        if (c == '+' || c == '-' || c == '*'|| c == '/' || c == 10 || c == 32 || c == 13 || c == 9) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                v2 = pop();
                v1 = pop();
                if (isnan(v2) == 1 || isnan(v1) == 1) {
                    printf("Input error at character %d (%c). Too few arguments on stack. \n", count, c);
                    return -1;
                } else {
                    double temp = 0;

                    if (c == '+') {
                        temp = v1 + v2;
                    }
                    else if (c == '-') {
                        temp = v1 - v2;
                    }
                    else if (c == '*') {
                        temp = v1 * v2;
                    }
                    else {
                        temp = v1 / v2;
                    }
                    fail = push(temp);
                    if (fail == -1) {
                        printf("Stack full when pushing (%.2f) at position %d\n", temp, count);
                        return -1;
                    } else {
                        fail = 0;
                    }
                }
            }
        }
        else if (isdigit(c) == 0) {
            printf("Unexpected symbol (%c) at position %d\n", c, count);
            return -1;
        }

            c = getchar();
            count++;
    }
    result = pop();

    if (isStackEmpty() == 0 || result == NAN){
        printf("There are too many values or too few operators in the expression \n");
    }
    else {
        printf("The result of the calculation is %.2f\n", result);
    }

}