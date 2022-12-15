// avl agaci
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

// avl agaci dugumu olusturan fonksiyon
typedef struct Dugum {
    int veri;
    struct Dugum *sol;
    struct Dugum *sag;
    int yukseklik;
}avlAgac;

avlAgac *kok = NULL;

int yukseklik(avlAgac *N);
int enFazla(int a, int b);
avlAgac *yeniDugum(int veri);
avlAgac *sagaDondur(avlAgac *y);
avlAgac *solaDondur(avlAgac *x);
int dengeAl(avlAgac *N);
avlAgac *ekleme(avlAgac *dugum, int veri);
void preOrder(avlAgac *kok);
avlAgac *arama(int aranan);

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

// agacin yuksekligini olusturan bir fonksiyon
int yukseklik(avlAgac *N) {
    if (N == NULL)
        return 0;
    return N->yukseklik;    
}

// en fazla iki tam sayi olusturan fonksiyon
int enFazla(int a, int b) {
    return (a > b) ? a : b;
}

// verilen veri ile yeni bir dugum olusturan fonksiyon
avlAgac *yeniDugum(int veri) {
    avlAgac *dugum = (avlAgac *)malloc(sizeof(avlAgac));
    
    dugum->veri = veri;
    dugum->sag = NULL;
    dugum->sol = NULL;
    dugum->yukseklik = 1; // yeni bir dugume baslangicta yaprak ekler
    return(dugum);
}

// y ile köklenmiş alt ağacı sağa döndürmek için bir fonksiyon
avlAgac *sagaDondur(avlAgac *y) {
    avlAgac *x = y->sol;
    avlAgac *gecici = x->sag;

    // rotasyonu olusturur
    x->sag = y;
    y->sol = gecici;

    // yukseklikleri gunceller
    y->yukseklik = enFazla(yukseklik(y->sol), yukseklik(y->sag) + 1);
    x->yukseklik = enFazla(yukseklik(x->sol), yukseklik(x->sag) + 1);

    // yeni koku dondurur
    return x;
}

// x ile köklenmiş alt ağacı sola döndürmek için bir fonksiyon
avlAgac *solaDondur(avlAgac *x) {
    avlAgac *y = x->sag;
    avlAgac *gecici = y->sol;

    // rotasyonu olusturur
    y->sol = x;
    x->sag = gecici;

    // yukseklikleri gunceller
    x->yukseklik = enFazla(yukseklik(x->sol), yukseklik(x->sag)) + 1;
    y->yukseklik = enFazla(yukseklik(y->sol), yukseklik(y->sag)) + 1;

    // yeni koku dondurur
    return y;
}

// N dugumunun denge faktorunu alan fonksiyon
int dengeAl(avlAgac *N) {
    if (N == NULL)
        return 0;
    return yukseklik(N->sol) - yukseklik(N->sag);    
}

// koklu alt agaca bir veri eklemek icin ozyinilemeli fonksiyon
// dugum ile ve alt agacin yeni kokunu dondurur
avlAgac *ekleme(avlAgac *dugum, int veri) {
    // 1. Normal BST yerlestirme islemini gerçekleştirir
    if (dugum == NULL)
        return (yeniDugum(veri));

    if (veri < dugum->veri)
        dugum->sol = ekleme(dugum->sol, veri);
    else if (veri > dugum->veri)
        dugum->sag = ekleme(dugum->sag, veri);
    else// BST'de eşit anahtarlara izin verilmez
        return dugum;

    // 2. Bu ata düğümün yüksekliğini günceller
    dugum->yukseklik = 1 + enFazla(yukseklik(dugum->sol), yukseklik(dugum->sag));

    // 3. Bu dugumun dengesiz olup olmadigini kontrol etmek icin bu ata dugumun denge faktorunu alir
    int denge = dengeAl(dugum);

    // eger bu düğüm dengesizleşirse, o zaman 4 durum var bunlari kontrol eder

    // sol sol durumu
    if (denge > 1 && veri < dugum->sol->veri)
        return sagaDondur(dugum);


    // sag sag durumu
    if (denge < -1 && veri > dugum->sag->veri)
        return solaDondur(dugum);

    // sol sag durumu
    if (denge > 1 && veri > dugum->sol->veri) {
        dugum->sol = solaDondur(dugum->sol);
        return sagaDondur(dugum);
    }

    // sag sol durumu
    if (denge < -1 && veri < dugum->sag->veri) {
        dugum->sag = sagaDondur(dugum->sag);
        return solaDondur(dugum);
    }

    // degistirilmis dugum isaretcisini dondurur
    return dugum;
}

// agacin preorder gecisini yazdirmak icin fir fonksiyon
// fonksiyon ayrica her dugumun yuksekliginide de yazdirir

void preOrder(avlAgac *kok) {
    if (kok != NULL) {
        printf("%d ", kok->veri);
        preOrder(kok->sol);
        preOrder(kok->sag);
    }
}

avlAgac *arama(int aranan) {
    avlAgac *gecici;
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