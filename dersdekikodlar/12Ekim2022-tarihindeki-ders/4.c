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
	dugum1 -> adres = (bliste*)malloc(sizeof(bliste));
	dugum1 -> adres -> veri = 20;
	dugum1 -> adres -> adres = NULL;
	dugum1 -> adres -> adres = (bliste*)malloc(sizeof(bliste));
	dugum1 -> adres -> adres -> veri = 55;
	dugum1 -> adres -> adres -> adres = NULL;
	bliste *temp = dugum1;
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> adres;
	}
	return 0;
}
