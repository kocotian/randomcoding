/*
 * merge sort in c99
 * creator: kocotian
 *
 * see LICENSE file for details
 *
 * go to github.com/kocotian/randomcoding
 * for more random codes
 *
 */

#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 8
#define MIN 0
#define MAX 99

void
merge(char *mem, char l, char c, char r)
{
	char *umem = malloc(r - l + 1);
	char il = l, ir = c + 1, iter = 0;

	while(il <= c && ir <= r)
		if(mem[il] < mem[ir])
			umem[iter++] = mem[il++];
		else
			umem[iter++] = mem[ir++];

	while(il <= c)
		umem[iter++] = mem[il++];
	while(ir <= r)
		umem[iter++] = mem[ir++];

	iter = l - 1;
	while(++iter < r + 1)
		mem[iter] = umem[iter - l];

	free(umem);
}

void
msort(char *mem, char l, char r)
{
	char c = (l + r) / 2;
	if(l >= r) return;

	msort(mem, l, c);
	msort(mem, c + 1, r);
	merge(mem, l, c, r);
}

void
main(void)
{
	srand(time(NULL));
	char *mem = malloc(ARRSIZE);
	char iter = -1;
	printf("array before msort:  ");
	while(++iter < ARRSIZE)
	{
		mem[iter] = rand() % MAX + MIN;
		printf(" %d",
				mem[iter]);
	}
	msort(mem, 0, ARRSIZE - 1);
	printf("\narray after msort:   ");
	iter = -1;
	while(++iter < ARRSIZE)
		printf(" %d",
				mem[iter]);
	printf("\n");
	free(mem);
}
