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

void sonaekle(int);

void basaekle(int);

void arayaekle(bliste*, int);

int main(){
	dugum1 = dugumolustur(10);
	bliste *dugum2 = dugumolustur(20);
	bliste *dugum3 = dugumolustur(30);
	dugum1 -> adres = dugum2;
	dugum2 -> adres = dugum3;
	dugumyazdir();
	sonaekle(40);
	sonaekle(50);
	dugumyazdir();
	basaekle(100);
	dugumyazdir();
	arayaekle(dugum2, 200);
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

void sonaekle(int veri){
	bliste *eklenecek = dugumolustur(veri);
	if(dugum1 == NULL){
		dugum1 = eklenecek;
	}
	else{
		bliste *temp = dugum1;
		while(temp -> adres != NULL){
			temp = temp -> adres;
		}
		temp -> adres = eklenecek;
	}
}

void basaekle(int veri){
	bliste *eklenecek = dugumolustur(veri);
	if(dugum1 == NULL){
		dugum1 = eklenecek;
	}
	else{
		bliste *temp = dugum1;
		dugum1 = eklenecek;
		dugum1 -> adres = temp; 
	}
}

void arayaekle(bliste* yer, int veri){
	bliste *eklenecek = dugumolustur(veri);
	eklenecek -> adres = yer -> adres;
	yer -> adres = eklenecek;
}

