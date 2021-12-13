#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <queue>

using namespace std;

int** gen_m(int** M, int n)
{
	int i, j, z = 1;
	M = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		M[i] = (int*)malloc(n * sizeof(int));
	//srand(time(NULL));
	srand(12);
	for (i = 0; i < n; i++)
	{
		M[i][i] = 0;
		for (j = z; j < n; j++)
		{
			M[i][j] = rand() % 2;
			M[j][i] = M[i][j];
		}
		z++;
	}
	return M;
}


void print(int** M, int n)
{
	int i, j;

	printf("V matrice\n");
	for (i = 0; i < n; i++) printf(" x%d", i);
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%*d", 3, M[i][j]);
		}
	}
}

void ob_m_1(int** M, int n, int k, bool* m)
{
	queue <int> Q;
	int i, j = k;

	Q.push(k);
	m[k] = true;
	while (!Q.empty())
	{
		j = Q.front();
		printf("%*d", 3, j);
		Q.pop();
		for (i = 0; i < n; i++)
		{
			if (M[j][i] == 1 && m[i] == false)
			{
				m[i] = true;
				Q.push(i);
			}
		}
	}
}



void hod1(int** M, int n)
{
	int i;
	bool* m;
	
	m = (bool*)malloc(sizeof(bool) * n);
	for (i = 0; i < n; i++)
	{
		m[i] = false;
	}
	for (i = 0; i < n; i++)
	{
		if (m[i] == false)
		{
			printf("comp %d:", i);
			ob_m_1(M, n, i, m);
		}
	}
	free(m);
}

void main()
{
	
	int** M = NULL, n, i;

	printf("Vvedite razmer grafa:");
	scanf("%d", &n);
	M = gen_m(M, n);
	
	print(M, n);
	printf("\n\nResult obhoda v shir :");
	hod1(M, n);
	
	
	for (i = 0; i < n; i++)
	{
		free(M[i]);
	}
	free(M);

	_getch();
}