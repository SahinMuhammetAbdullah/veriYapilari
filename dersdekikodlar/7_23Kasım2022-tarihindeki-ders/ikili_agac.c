#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sol;
	struct dugum *sag;
};
typedef struct dugum agac;
agac *kok = NULL;

agac *dugumolustur(int);
void preorder(agac*);
void postorder(agac*);
void inorder(agac*);

int main() {
	kok = dugumolustur(10);
	agac *dugum_b = dugumolustur(20);
	agac *dugum_c = dugumolustur(30);
	agac *dugum_d = dugumolustur(40);
	agac *dugum_e = dugumolustur(50);
	agac *dugum_f = dugumolustur(60);
	agac *dugum_g = dugumolustur(70);
	kok -> sol = dugum_b;
	kok -> sag = dugum_c;
	dugum_b -> sol = dugum_d;
	dugum_b -> sag = dugum_e;
	dugum_c -> sol = dugum_f;
	dugum_c -> sag = dugum_g;
	printf("\nPreorder gosterim:\n");
	preorder(kok);
	printf("\nInorder gosterim:\n");
	inorder(kok);
	printf("\nPostorder gosterim:\n");
	postorder(kok);
	return 0;	
}
agac *dugumolustur(int gelen) {
    agac *yenidugum = (agac*)malloc(sizeof(agac));
    yenidugum -> veri = gelen;
    yenidugum -> sol = NULL;
    yenidugum -> sag = NULL;
    return yenidugum;
}
void preorder(agac *baslangic) {
	if(baslangic == NULL)
		return;
	printf("%d ", baslangic -> veri);
	preorder(baslangic -> sol);
	preorder(baslangic -> sag);
}
void postorder(agac *baslangic) {
	if(baslangic == NULL)
		return;
	postorder(baslangic -> sol);
	postorder(baslangic -> sag);
	printf("%d ", baslangic -> veri);
}
void inorder(agac *baslangic) {
	if(baslangic == NULL)
		return;
	inorder(baslangic -> sol);
	printf("%d ", baslangic -> veri);
	inorder(baslangic -> sag);
}
