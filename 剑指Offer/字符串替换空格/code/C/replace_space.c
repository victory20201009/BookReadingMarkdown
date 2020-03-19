#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_space_count(char* str) {
	int cnt = 0, i = 0;
	while (str[i]) {
		if (str[i++] == ' ')++cnt;
	}
	return cnt;
}

char* replace_space(char* str) {
	int len = 0;
	if (str == NULL || (len = strlen(str)) == 0) {
		return NULL;
	}
	int newlen = len + get_space_count(str) * 2;
	char* res = (char*)malloc(newlen + 1);
	if (res != NULL) {
		res[newlen] = 0;
		int i = newlen - 1, j = len - 1;
		while (j > -1) {
			if (str[j] == ' ') {
				res[i] = '0';
				res[i - 1] = '2';
				res[i - 2] = '%';
				i -= 3;
			}
			else {
				res[i] = str[j];
				--i;
			}
			--j;
		}
		return res;
	}
	else {
		return NULL;
	}
}

int main() {
	char str1[] = "hello world";
	puts(replace_space(str1));
	char str3[] = "  ";
	puts(replace_space(str3));
}