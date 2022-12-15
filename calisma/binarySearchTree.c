// iki arama agaci(bst) kodu
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Dugum {
    int veri;
    struct Dugum *sol;
    struct Dugum *sag;
}bst;

bst *kok = NULL;

bst *yeniDugum(int veri);
void inOrder(bst *kok);
bst *ekleme(bst *dugum, int veri);
bst *arama(int aranan);

int main() {
    clock_t startTime, endTime;
	startTime = clock();

    int A[30000];
    for (int i = 0; i < 30000; i++) {
        A[i] = i + 1;
    }
    for (int i = 0; i < 30000; i++) {
        kok = ekleme(kok, A[i]);
    }
    arama(1000);
    arama(10080);
    arama(1236);
    arama(54321);
    arama(56785);
    arama(10001);
    arama(128567);

    endTime = clock();
	printf("\n%f",((float)(endTime-startTime)/CLOCKS_PER_SEC));
    return 0;
}

// yeni bst dugumu olusturan fonksiyon
bst *yeniDugum(int veri) {
    
    bst *gecici = (bst *)malloc(sizeof(bst));
    
    gecici->veri = veri;
    gecici->sol = NULL;
    gecici->sag = NULL;

    return gecici;
}

// bst sirali gecisini yapan fonksiyon
void inOrder(bst *kok) {
    if (kok != NULL) {
        inOrder(kok->sol);
        printf(" %d ", kok->veri);
        inOrder(kok->sag);
    }
}

// ekleme yapan bir fonksiyon
// verilen veri ile yeni bir dugum
bst *ekleme(bst *dugum, int veri) {
    // agac bossa yeni dugum dondurur
    if (dugum == NULL)
        return yeniDugum(veri);
    
    // bos degilse ekleme yapmaya devam ettirir
    if (veri < dugum->veri)
        dugum->sol = ekleme(dugum->sol, veri);
    else if (veri > dugum->veri)
        dugum->sag = ekleme(dugum->sag, veri);

    // dugum isaretcisini dondurur
    return dugum;
}

bst *arama(int aranan) {
    bst *gecici;
    gecici = kok;

    while (gecici->veri != aranan) {
        if (gecici != NULL) {
            if (aranan < gecici->veri)
                gecici = gecici->sol;
            else if (aranan > gecici->veri)
                gecici = gecici->sag;
        }
        
        if (gecici == NULL) {
            printf("\n aradiginiz %d bulunmuyor", aranan);
            return NULL;
        }
    }

    printf("\n aradiginiz %d bulunuyor", gecici->veri);
    
    return gecici;
}