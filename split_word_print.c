/*
 * Name: split_word_print.c
 * 
 * 作用: 用于字幕显示，行长为N，不要将长度 < N 的单词显示到两行，
 * 
 * Date: 2016.3.15
 *
 * Auther: Spaceman007
 */

#include <stdio.h>
#include <string.h>

// 打印Str的前n个字符
void print_n_chars(char *Str, int n)
{
	int i = 0;
	
	for (i = 0; i < n; ++i)
	{
		printf("%c", *(Str + i));
	}
}

// 给定Str, 返回接下来单词的长度。word为下个单词起始位置。忽略空格。
int len_of_next(char *Str, char **word)
{
	char *p = Str;

	while (*p == ' ') ++p;
	*word = p;

	if (p == NULL) {
		return 0;
	}

	for (; *p != ' ' && *p != '\0'; ++p);

	return p - *word;
}

// N: 行长
void print_words(char *Str, int N)
{
	char *p  = Str;
	char *word = p;
	int M = N;
	int len = 0;
	int word_len = len_of_next(p, &word);

	while (word_len > 0) 
	{
		// 换行的两种情况: 
		// 1.当单词长度 < N 并且比剩余长度长时
		// 2. 剩余长度为0
		if ( (word_len <= N && word_len > M) || 
				M == 0)
		{
			printf("\n");
			M = N;
		} 

		len = word_len > M ? M : word_len;
		print_n_chars(word, len);
		p = word + len;
		M -= len;

		if (M > 0) {
			printf(" ");
			M--;
		}

		word_len = len_of_next(p, &word);
	}
}

int main(void)
{
	// "incompatible pointer types initializing char  with an expression of type      char  Wincom";
	char words[280];
	printf("input: ");
	scanf("%[^\n]", words);

	print_words(words, 17);

	return 0;
}
