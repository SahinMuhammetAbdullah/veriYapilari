#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum
{
    char isim[40];
    char soyisim[40];
    char telefon[10];
    char mail[40];
    struct dugum * sonra;
    struct dugum * once;

};
typedef struct dugum rehber;

int main(int argc, char const *argv[])
{
    rehber *kisi1;
    strcpy(kisi1->isim,"abdullah"), 
    strcpy(kisi1->soyisim,"sahin");
    strcpy(kisi1->telefon,"5351040690");
    strcpy(kisi1->mail,"apo690apo@gmail.com");

    rehber *kisi2;
    strcpy(kisi2->isim,"salih");
    strcpy(kisi2->soyisim,"sah");
    strcpy(kisi2->telefon,"5352637898");
    strcpy(kisi2->mail,"salihsahin@gmail.com");             

    rehber *kisi3;
    strcpy(kisi3->isim,"Ahmet");
    strcpy(kisi3->soyisim,"kilic");
    strcpy(kisi3->telefon,"5436678790");
    strcpy(kisi3->mail,"ahmetkilic@gmail.com");             

    rehber *kisi4;
    strcpy(kisi4->isim,"muhammet"); 
    strcpy(kisi4->soyisim,"tamur");
    strcpy(kisi4->telefon,"5321447690");
    strcpy(kisi4->mail,"m.tamur@gmail.com");

    kisi1 -> sonra = kisi2;
    kisi2 -> sonra = kisi3;
    kisi3 -> sonra = kisi4;
    kisi2 -> once = kisi1;
    kisi3 -> once = kisi2;
    kisi4 -> once = kisi3;

    rehber * gecici = kisi1;

    while (gecici != NULL)
    {
        printf("\n ad: %s\n soyad: %s\n telefon numarasi: %s\n mail adresi %s\n",gecici -> isim[40], gecici -> soyisim[40], gecici -> telefon[10], gecici -> mail[40]);
        
        gecici = gecici -> sonra;
    }
    return 0;
}
