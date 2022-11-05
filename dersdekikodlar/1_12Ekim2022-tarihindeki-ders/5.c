#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *adres;
};
typedef struct dugum bliste;

bliste *dugumolustur(int);
void dugumyazdir();
bliste *dugum1 = NULL;
int main(){
	dugum1 = dugumolustur(10);
	bliste *dugum2 = dugumolustur(20);
	bliste *dugum3 = dugumolustur(30);
	dugum1 -> adres = dugum2;
	dugum2 -> adres = dugum3;
	dugumyazdir();
	return 0;
}
bliste *dugumolustur(int veri){
	bliste *yenidugum = (bliste*)malloc(sizeof(bliste));
	yenidugum -> veri = veri;
	yenidugum -> adres = NULL;
	return yenidugum;
}
void dugumyazdir(){
	bliste *temp = dugum1;
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> adres;
	}
}

