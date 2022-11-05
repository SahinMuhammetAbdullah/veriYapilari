#include <stdio.h>

void eleman_ekle(int [], int, int, int);

int main()
{

	int dizi[] = {1, 2, 3, 4, 5};
	int N = sizeof(dizi) / sizeof(int);
	int i;

	for(i = 0; i < N; i++)
	{
		printf("%d %d\n", i, dizi[i]);
	}

	eleman_ekle(dizi, 2, 100, N);

	for(i = 0; i < N; i++)
	{
		printf("%d %d\n", i, dizi[i]);
	}

	return 0;
}

void eleman_ekle(int dizi[], int k, int eleman, int N)
{
	
	int i;

	for(i = N - 2; i >= k; i--){
		dizi[i + 1] = dizi[i];
	}
	dizi[k] = eleman;
}
