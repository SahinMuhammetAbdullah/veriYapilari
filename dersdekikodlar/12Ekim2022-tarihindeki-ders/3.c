#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *adres;
};
typedef struct dugum bliste;

int main(){
	bliste *dugum1;
	dugum1 = (bliste*)malloc(sizeof(bliste));
	dugum1 -> veri = 9;
	dugum1 -> adres = NULL;
	printf("%p\n", dugum1);
	printf("%d\n", dugum1 -> veri);
	printf("%p\n", dugum1 -> adres);
	return 0;
}
