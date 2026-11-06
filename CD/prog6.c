prog6.y
code:

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char *val;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node *newNode(char *v, Node *l, Node *r)
{
    Node *n = malloc(sizeof(Node));
    n->val = strdup(v);
    n->left = l;
    n->right = r;
    return n;
}

void printTree(Node *n, int space)
{
    if (!n) return;

    if (n->right)
        printTree(n->right, space + 6);

    printf("\n");

    for (int i = 0; i < space; i++)
        printf(" ");

    printf("%s", n->val);

    if (n->left || n->right)
        printf("\n");

    if (n->left)
        printTree(n->left, space + 6);
}

void freeTree(Node *n)
{
    if (!n) return;

    freeTree(n->left);
    freeTree(n->right);
    free(n->val);
    free(n);
}

int yylex(void);
void yyerror(const char *s);
%}

%union {
    void *node;
}

%token <node> ID
%type <node> E T F

%start E

%%

E : E '+' T
    {
        $$ = newNode("+", (Node *)$1, (Node *)$3);
        root = (Node *)$$;
    }
  | T
    {
        $$ = $1;
        root = (Node *)$$;
    }
  ;

T : T '*' F
    {
        $$ = newNode("*", (Node *)$1, (Node *)$3);
    }
  | F
    {
        $$ = $1;
    }
  ;

F : ID
    {
        $$ = $1;
    }
  ;

%%

int yylex(void)
{
    int c;
    char s[100];
    int i = 0;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (isalpha(c)) {
        do {
            s[i++] = c;
            c = getchar();
        } while (isalnum(c) && i < 99);

        s[i] = '\0';

        if (c != EOF)
            ungetc(c, stdin);

        yylval.node = newNode(s, NULL, NULL);
        return ID;
    }

    if (c == '\n' || c == EOF)
        return 0;

    return c;
}

void yyerror(const char *s)
{
    printf("Syntax Error\n");
}

int main()
{
    printf("Enter expression: ");

    if (yyparse() == 0) {
        printf("\nParse Tree:\n\n");

        if (root &&
            root->left &&
            root->right &&
            root->right->left &&
            root->right->right) {

            printf("    %s\n", root->val);
            printf("   / \\\n");
            printf("  %s   %s\n",
                   root->left->val,
                   root->right->val);
            printf("      / \\\n");
            printf("     %s   %s\n",
                   root->right->left->val,
                   root->right->right->val);
        }
        else {
            printTree(root, 0);
            printf("\n");
        }
    }

    freeTree(root);
    return 0;
}

yacc -d prog6.y
gcc y.tab.c -o ast
./ast

Enter expression: a+b*c

Parse Tree:

    +
   / \
  a   *
      / \
     b   c
