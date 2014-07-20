#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct op_stack {
	int max_capacity;
	int size;
	int *elements;
} op_stack;

op_stack* create_opstack(int max) {
	op_stack* t;
	t = (op_stack*)malloc(sizeof(op_stack));
	t->size = 0;
	t->max_capacity = max;
	t->elements = (int*)malloc(sizeof(int)* max);
	return t;
}
void pop(op_stack* stk) {
	if (stk->size != 0) stk->size--;
}
int top(op_stack* stk) {
	if (stk->size != 0) return stk->elements[stk->size - 1];
	exit(0);  // FIXME: this is bad.  Bad bad bad bad bad.
}
void push(op_stack* stk, int element) {
	if (stk->size != stk->max_capacity) stk->elements[stk->size++] = element;
}

void exec(FILE* fp) {
	int a[3000] = { 0 };
	int* ptr = a;
	ptr += 1000;
	op_stack* lp = create_opstack(5000);
	
	while (!feof(fp)) {
		char ch = (char)fgetc(fp);
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
					push(lp, ftell(fp));
				}
				else {
					int c = 1;
					while (c > 0) {
						char topch = (char)fgetc(fp);
						if (topch == '[')
							c++;
						if (topch == ']')
							c--;
					}
				}
				break;
			case ']':
				if (*ptr > 0) {
					fseek(fp, top(lp), SEEK_SET);
				}
				else {
					pop(lp);
				}
				break;
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		fputs("error: missing a file to execute\n", stderr);
		return 1;
	}
	FILE* fp = fopen(argv[1], "r");
	if (!fp) {
		fputs("error: could not open file\n", stderr);
		return 1;
	}

	exec(fp);

	return 0;
}
