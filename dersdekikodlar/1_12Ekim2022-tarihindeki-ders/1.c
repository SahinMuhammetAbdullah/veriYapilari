#include <stdio.h>

void eleman_sil(int [], int, int);

int main(){
	
	int dizi[] = {10, 55, 33, 6, 50};
	int N = sizeof(dizi) / sizeof(int);
	int i;

	for(i = 0; i < N; i++){
		printf("%d %d\n", i, dizi[i]);
	}

	eleman_sil(dizi, 0, N);

	for(i = 0; i < N; i++){
		printf("%d %d\n", i, dizi[i]);
	}

	return 0;
}

void eleman_sil(int dizi[], int k, int N){
	
	int i;
	
	for(i = k; i < N - 1; i++){
		dizi[i] = dizi[i + 1];
	}
}
