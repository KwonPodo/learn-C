#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

struct charStack {
    int max;
    int num;
    char *stk;
};

void init(struct charStack *s) {
    if ((s->stk = calloc(MAX, sizeof(char))) == NULL) {
        s->max = 0;
    }

    s->max = MAX;
    s->num = 0;
}

int isEmpty(struct charStack *s) {
    return s->num <=  0;
}

int isFull(struct charStack *s) {
    return s->num >= s->max;
}

void terminate(struct charStack *s) {
    if (s->stk != NULL) {
        free(s->stk);
    }

    s->max = 0;
    s->num = 0;
}

void push(struct charStack *s, char data) {
    if (!isFull(s)) {
        s->stk[s->num++] = data;
    } else {
        printf("Push Failed\n");
    }
}

char pop(struct charStack *s) {
    if (!isEmpty(s)) {
        return s->stk[--(s->num)];
    } else {
        return -1;
    }
}

int peek(struct charStack *s) {
    if (isEmpty(s)) {
        puts("No data");
        return -1;
    } else {
        return s->stk[s->num - 1];
    }
}

void clearStack(struct charStack *s) {
    s->num = 0;
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    } else return 0;
}

int isOperand(char ch) {
    if (ch > 47 && ch < 58) {
        return 1;
    } else {
        return 0;
    }
}

int arithmetic_calc (int ch1, int ch2, char operator) {
    int result;

    switch (operator)
    {
    case '+':
        result = ch1 + ch2;
        break;
    
    case '-':
        result = ch1 - ch2;
        break;
    
    case '*':
        result = ch1 * ch2;
        break;
    
    case '/':
        result = ch1 / ch2;
        break;
    
    default:
        break;
    }

    return result;
}

int givePriority(char ch) {
    if (ch == '(') {
        return 0;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }

    return -1;
}

int isHigherPriority (char ch1, char ch2) {
    int prior_ch1, prior_ch2;
    prior_ch1 = givePriority(ch1); prior_ch2 = givePriority(ch2);

    return prior_ch1 > prior_ch2;
}

/**
 * 피연산자 스택, 연산자 스택 두 개로 구현한다.
 * 
 * 현재 보고 있는 연산자의 우선순위 > 스택탑일 때 => 지금 보고 있는 것 푸시
 * 현재 보고 있는 연산자의 우선순위 <= 스택탑일 때 => (를 만나거나 스택이 빌때까지 뽑아서 계산한뒤 푸시
 *              => 저장해놓은 연산자들보다 우선순위가 같거나 낮은 연산자가 나왔다는 것은, 그냥 계산하고 넘어가도 된다는 뜻이다.
 * 
 * 중위 -> 후위 과정에서 우선순위가 동일하거나 낮을 때 모두 계산하고 넘어간다.
 * '('의 경우 일단 푸시한뒤, ')'를 만나면 '('가 나올때까지 계산한뒤 피연산자 스택에 푸시한다.
 */

int infixCalc(struct charStack *operand, struct charStack *operator, char *infix) {
    int i;
    int ch1, ch2, result = 0;
    char *search = infix;


    while (*search != '\0') {
        i = 0;
        if (*search == '(') {
            push(operator, *search++);
            continue;
        } else if (isOperand(*search)) {
            do {
                i = i*10 + *search++ - '0';
            } while (isOperand(*search));

            push(operand, i);
            continue;
        } else if (isOperator(*search)) {
            if (isEmpty(operator)) {
                push(operator, *search++);
            } else {
                // 지금 보고 있는 토큰의 우선순위가 스택탑보다 높을 때 푸시
                    if (isHigherPriority(*search, peek(operator))) {
                        push(operator, *search++);
                    } else {
                        //지금 보고 있는 토큰의 우선순위가 스택탑보다 낮거나 같을때 팝해서 연산
                        do {
                            ch2 = (int)pop(operand);
                            ch1 = (int)pop(operand);

                            result = arithmetic_calc(ch1, ch2, pop(operator));
                            push(operand, result);
                        } while (!isEmpty(operator) && peek(operator) != '(');

                        push(operator, *search++);
                        continue;
                    }
            }
        } else if (*search == ')') {
            do {
                ch2 = (int)pop(operand);
                ch1 = (int)pop(operand);

                result = arithmetic_calc(ch1, ch2, pop(operator));
                push(operand, result);
            } while (peek(operator) != '(');

            pop(operator);
            search++;
            continue;
        }
    }

    while (!isEmpty(operator)) {
        ch2 = (int)pop(operand);
        ch1 = (int)pop(operand);

        result = arithmetic_calc(ch1, ch2, pop(operator));
        push(operand, result);
    }

    result = pop(operand);

    return result;
}

int main(void) {
    int result;

    struct charStack * operand = (struct charStack*)calloc(MAX, sizeof(char));
    struct charStack * operator = (struct charStack*)calloc(MAX, sizeof(char));
    init(operand);
    init(operator);

    char *infix_expression = (char*)calloc(MAX, sizeof(char));

    printf("Enter expression: ");
    scanf("%s", infix_expression);

    result = infixCalc(operand, operator, infix_expression);

    printf("result: %d\n", result);

    free(infix_expression);
}

// 1+(2*(3+4/2)+6)/2