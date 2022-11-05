#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int veri;
    struct dugum *onceki;
    struct dugum *sonraki;
};
typedef struct dugum dairesel_cy_bliste;

int main(){
    dairesel_cy_bliste *dugum1;
	dugum1 = 
	(dairesel_cy_bliste*)malloc(sizeof(dairesel_cy_bliste));
    dugum1 -> veri = 10;
    dairesel_cy_bliste *dugum2;
    dugum2 = 
	(dairesel_cy_bliste*)malloc(sizeof(dairesel_cy_bliste));
    dugum2 -> veri = 20;
    dairesel_cy_bliste *dugum3;
	dugum3 =
    (dairesel_cy_bliste*)malloc(sizeof(dairesel_cy_bliste));
    dugum3 -> veri = 30;
    dugum1 -> onceki = dugum3;
    dugum1 -> sonraki = dugum2;
    dugum2 -> onceki = dugum1;
    dugum2 -> sonraki = dugum3;
    dugum3 -> onceki = dugum2;
    dugum3 -> sonraki = dugum1;
    dairesel_cy_bliste *temp = dugum1;
	do{
		printf("%d ", temp -> veri);
		temp = temp -> sonraki;
	}while(temp != dugum1);
    return 0;
}
