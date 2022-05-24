/**
 * @file expr.c
 * @author aubrey nicoll <aubrey.nicoll@gmail.com>
 * @brief my version of expr, which evaluates reverse polish notation
 * @version 0.1
 * @date 2022-05-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 128

int main(int argc, char *argv[]) {
  double stack[STACK_SIZE];
  size_t stack_ptr = 0;
  double operand1, operand2;

  for (size_t i = 1; i < argc; i++) {
    if (isdigit(argv[i][0])) {
      stack[stack_ptr++] = atof(argv[i]);
    } else {
      char op = argv[i][0];
      operand2 = stack[--stack_ptr];
      operand1 = stack[--stack_ptr];
      switch (op) {
        case '+':
          operand1 += operand2;
          break;
        case '-':
          operand1 -= operand2;
          break;
        case '*':
          operand1 *= operand2;
          break;
        case '/':
          if (!operand2) {
            fprintf(stderr, "Div by 0 is undefined\n");
            exit(1);
          }
          operand1 /= operand2;
          break;
        default:
          fprintf(stderr, "Unknown operator: %c\n", op);
          exit(1);
      }
      stack[stack_ptr++] = operand1;
    }
  }
  printf("%f\n", operand1);
}
