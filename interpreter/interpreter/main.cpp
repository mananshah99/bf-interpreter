#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ostream>
#include <assert.h>
#include <iostream>

using namespace std;

typedef struct op_stack {
	int max_capacity;
	int size;
	int *elements;
} op_stack;

op_stack* create_opstack(int MAX) {
	op_stack* t;
	t = (op_stack*)malloc(sizeof(op_stack));
	t -> size = 0;
	t -> max_capacity = MAX;
	t -> elements = (int*)malloc(sizeof(int)* MAX);
	return t;
}
void pop(op_stack* stk) {
	if (stk->size != 0) stk->size--;
}
int top(op_stack* stk)
{
	if (stk->size != 0) return stk->elements[stk->size - 1];
	exit(0);
}
void push(op_stack* stk, int element) {
	if (stk->size != stk->max_capacity) stk->elements[stk->size++] = element;
}

void exec(op_stack* orig_stk) {
	int a[3000] = { 0 };
	int* ptr = a;
	ptr += 1000;
	op_stack* lp = create_opstack(5000);
	
	while (orig_stk->size > 0) {
		char ch = (char)top(orig_stk);
		switch (ch) {
			case '>':
				++ptr;
				break;
			case '<':
				--ptr;
				break;
			case '+':
				++*ptr;
				break;
			case '-':
				--*ptr;
				break;
			case '.':
				putchar((char)*ptr);
				break;
			case ',':
				*ptr = getchar();
				break;
			case '[':
				if (*ptr > 0) {
					push(lp, orig_stk->size);
				}
				else {
					int c = 1;
					while (c > 0) {
						pop(orig_stk);
						if (top(orig_stk) == '[')
							c++;
						if (top(orig_stk) == ']')
							c--;
					}
				}
				break;
			case ']':
				if (*ptr > 0) {
					orig_stk->size = top(lp);
				}
				else {
					pop(lp);
				}
				break;
		}
		pop(orig_stk);
	}
}

int main(int argc, char* argv[])
{	
	op_stack *orig_stk = create_opstack(5000);
	FILE* fp = fopen("c:/users/manan/desktop/hello.bf" /*or argv[1]*/, "r");
	int ch = fgetc(fp);
	while (ch != EOF) {
		if (ch == '.' || ch == ',' || ch == '>' || ch == '<' || ch == '+' || ch == '-' || ch == '[' || ch == ']') push(orig_stk, ch);
		ch = fgetc(fp);
	}

	op_stack *n = create_opstack(5000);
	while (orig_stk->size > 0) {
		push(n, top(orig_stk));
		pop(orig_stk);
	}

	exec(n);
	//system("PAUSE");
}