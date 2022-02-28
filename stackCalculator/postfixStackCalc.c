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
        return '\0';
    }
}

char peek(struct charStack *s) {
    if (isEmpty(s)) {
        puts("No data");
        return '\0';
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

// 괄호가 씌워진 중위 연산자를 읽어 후위 연산자로 바꾸는 알고리즘
// 1. 피연산자는 그대로 출력한다.
// 2. 연산자는 스택에 푸시한다.
// 3. '('는 지나친다.
// 4. ')'를 만나면 스택에서 팝하여 출력한다.
void print_toPostfix(struct charStack *s, char *input) {
    // char *result_expression = calloc(MAX, sizeof(char));

    int i = 0;
    while (1) {
        if (input[i] == '\0') break;

        if (input[i] == '(') {
            i++;
        } else if (isOperand(input[i])) {
            printf("%c", input[i++]);
        } else if (isOperator(input[i])) {
            push(s, input[i++]);
        } else if (input[i] == ')') {
            printf("%c", pop(s));
            i++;
        }
    }
}

// 괄호가 없는 중위 표현식을 후위 표현식으로 변환
// => 연산자의 우선순위를 고려하여 변화해본다.
// 0 = (, 1 = +,-  2 = *,/

// 1. 피연산자를 만나면 출력
// 2. '('를 만나면 푸시한다.
// 3. 연산자를 만나면 스택의 최상위에 위치한 연산자와 비교하여 
//      최상위 연산자가 우선순위가 더 높을 시 -> 해당 탑스택을 팝하여 출력하고 
//      최상위 연산자가 우선순위가 같거나 더 낮을 시 -> 무시하고 진행한다.
//              -> 마무리로 항상 비교문 및 행동이 끝나면 만난 연산자를 푸시한다.
//                                                  => 결국 스택에는 최상위 연산자보다 높은 우선순위를 지닌 연산자는 존재하지 않게된다.
// 4. ')'를 만나면 최상위 스택에 '('가 올 때까지 스택을 팝하고 출력. '('는 팝만하고 출력하지 않는다.
// 5. 중위 표현식에 더 읽을 것이 없다면 종료.
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

char* toPostfix(struct charStack *s, char *infix) {
    char stackTop;
    char *postfix = (char*)calloc(MAX, sizeof(char));
    char *returner = postfix;
    int aaa = 0;
    while (1) {
        printf("%c : %s\n", *infix, returner);
        if (*infix == '\0') {
            while (!isEmpty(s)) {
                *postfix = pop(s);
                postfix++;
            }
            break;
        }

        // 피연산자 출력
        if (isOperand(*infix)) {
            do {
                *postfix = *infix;
                postfix++; infix++;
            } while (isOperand(*infix));
            *postfix++ = ' ';
        // '('를 만나면 푸시
        } else if (*infix == '(') {
            push(s, *infix++);
        
        // ')'를 만나면 '('를 만날때까지 팝하여 출력. '('는 팝하고 출력하지 않음
        } else if (*infix == ')') {
            do {
                *postfix++ = pop(s);
            } while (peek(s) != '(');

            pop(s);
            infix++;
        // 연산자라면
        } else if (isOperator(*infix)) {

            // 스택이 비어있지 않을 때
            if (!isEmpty(s)) {
                // 만약 스택 최상위 연산자가 내가 만난 연산자보다 우선순위가 높다면
                while (!isEmpty(s) && isHigherPriority(peek(s), *infix)) {
                    // 팝하여 출력
                    *postfix++ = pop(s);
                }
            }

            // 내가 만난 연산자 푸시
            push(s, *infix++);
        }
    }

    return returner;
}

// 후위 표현식으로 바뀐 식을 계산하는 함수
// 1. 표현식이 끝날때까지 읽는다.
// 2. 피연산자를 만나면 스택에 집어 넣는다.
// 3. 연산자를 만날 시 스택의 상단에서 2개를 팝해 연산을 하고 결과값을 스택에 푸시한다.

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

int calc_postFix (struct charStack *s, char *postfix) {
    int ch1, ch2;
    int result;

    int i;
    while (*postfix != '\0') {
        if (*postfix == ' ') {
            postfix++;
        } else if (isOperand(*postfix)) {
            i = 0;
            do {
                i = i*10 + *postfix++ - '0';
            } while (isOperand(*postfix));
            
            push(s, (char)i);
            continue;
        } else if (isOperator(*postfix)) {
            ch2 = (int)pop(s);
            ch1 = (int)pop(s);

            result = arithmetic_calc(ch1, ch2, *postfix);
            postfix++;
            push(s, (char)result);
        }
    }

    result = (int)pop(s);

    return result;
}

// 후위 표현식으로 바뀐 식을 스택을 읽어내 올바른 순서로 연산하는 알고리즘

int main(void) {
    int result;

    struct charStack * s = (struct charStack*)calloc(MAX, sizeof(char));
    init(s);

    char *infix_expression = (char*)calloc(MAX, sizeof(char));
    char *postfix_expression = NULL;

    printf("Enter expression: ");
    scanf("%s", infix_expression);

    // print_toPostfix(s, infix_expression);

    postfix_expression = toPostfix(s, infix_expression);
    printf("%s\n", postfix_expression);

    // result = calc_postFix(s, postfix_expression);

    // printf("result: %d\n", result);

    free(infix_expression);
    free(postfix_expression);
}

// 1+(2*(3+4/2)+6)/2
// 1+2*3-(4+2*3)+3