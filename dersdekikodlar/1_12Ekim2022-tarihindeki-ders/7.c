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
void sondansil();
void bastansil();
int main(){
	dugum1 = dugumolustur(10);
	bliste *dugum2 = dugumolustur(20);
	bliste *dugum3 = dugumolustur(30);
	bliste *dugum4 = dugumolustur(40);
	bliste *dugum5 = dugumolustur(50);
	dugum1 -> adres = dugum2;
	dugum2 -> adres = dugum3;
	dugum3 -> adres = dugum4;
	dugum4 -> adres = dugum5;
	dugumyazdir();
	sondansil();
	dugumyazdir();
	bastansil();
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
	printf("\n");
}
void sondansil(){
	bliste *temp = dugum1;
	while(temp -> adres -> adres != NULL)
		temp = temp -> adres;
	free(temp -> adres);
	temp -> adres = NULL;
}
void bastansil(){
	if(dugum1 == NULL){
		printf("Listede silinecek eleman yoktur!");
	}
	else if(dugum1 -> adres == NULL){
		dugum1 = NULL;
	}
	else{
		bliste *ikinci = dugum1 -> adres;
		free(dugum1);
		dugum1 = ikinci;
	}
}
