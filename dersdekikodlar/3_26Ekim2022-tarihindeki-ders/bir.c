#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum dairesel_ty_bliste;
dairesel_ty_bliste *bas = NULL;
int main(){
	dairesel_ty_bliste *dugum1;
	dugum1 = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
	bas = dugum1;
	dugum1 -> veri = 9;
	dugum1 -> sonraki = bas;
	dairesel_ty_bliste *dugum2;
	dugum2 = (dairesel_ty_bliste*)malloc(sizeof(dairesel_ty_bliste));
	dugum1 -> sonraki = dugum2;
	dugum2 -> veri = 21;
	dugum2 -> sonraki = bas;
	printf("%p\n", bas);
	printf("%d\n", dugum1 -> veri);
	printf("%p\n", dugum1 -> sonraki);
	printf("%p\n", dugum2);
	printf("%d\n", dugum2 -> veri);
	printf("%p\n", dugum2 -> sonraki);
	return 0;
}
