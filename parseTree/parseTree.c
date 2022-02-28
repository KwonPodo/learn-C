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
    while (1) {
        // printf("%c : %s\n", *infix, returner);
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

struct node {
    char ch;
    struct node *left;
    struct node *right;
};

struct parseTree {
    struct node *root;
    int nodeCount;
};

struct node* createNode(char ch) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) return NULL;
    new->ch = ch;
    new->left = new->right = NULL;

    return new;
}

// 1 2 3*4 2 3*+3 +-+
// 1. 수식을 뒤에서부터 앞쪽으로 읽어나간다.
// 2. 수식에서 제일 마지막에 있는 토큰은 루트노드가 된다. => 후위표기식에서 가장 마지막에 있는 토큰은 항상 연산자이다.
// 3. 수식에서 읽어낸 토큰이 연산자인 경우에는 가지 노드가 되며, 이 토큰 다음에 따라오는 두 개의 토큰은 각각 오른쪽 자식 노드와 왼쪽 자식노드가된다.
//    단, 다음 토큰에도 연속해서 연산자인 경우에는 이 토큰으로부터 만들어지는 하위 트리가 완성된 이후에 읽어낸 토큰이 왼쪽 자식이 된다.
// 4. 수식에서 읽어낸 토큰이 숫자이면 이 노드는 잎노드이다.

void createParseTree(char *postfix, struct node **n) {
    int len = strlen(postfix);
    char token = postfix[len - 1];
    postfix[len - 1] = '\0';

    if (isOperator(token)) 
    {
        *n = createNode(token);
        createParseTree(postfix, &(*n)->right);
        createParseTree(postfix, &(*n)->left);
    }
    else if (isOperand(token))
    {
        *n = createNode(token);
    }
}

int evaluateParseTree(struct node *tree) {
    int left, right, result;
    left = right = result = 0;

    if (tree == NULL) return 0;
    
    if (isOperator(tree->ch)) 
    {
        switch (tree->ch)
        {
            left = evaluateParseTree(tree->left);
            right = evaluateParseTree(tree->right);
        case '+':
            result = left + right;
            break;
        
        case '-':
            result = left - right;
            break;
        
        case '*':
            result = left * right;
            break;
        
        case '/':
            result = left / right;
            break;
        
        default:
            break;
        }
    }
    else if (isOperand(tree->ch))
    {
        result = atoi(&tree->ch);
    }
    

    return result;
}

int main(void) {
    int result;

    struct charStack * s = (struct charStack*)calloc(MAX, sizeof(char));
    init(s);

    char *infix_expression = (char*)calloc(MAX, sizeof(char));
    char *postfix_expression = NULL;

    printf("Enter expression: ");
    scanf("%s", infix_expression);

    postfix_expression = toPostfix(s, infix_expression);
    printf("%s\n", postfix_expression);

    struct node *root = (struct node*)malloc(sizeof(struct node));

    createParseTree(postfix_expression, &root);

    result = evaluateParseTree(root);

    printf("result: %d\n", result);

    free(infix_expression);
    free(postfix_expression);
}

// 1+(2*(3+4/2)+6)/2
// 1+2*3-(4+2*3)+3