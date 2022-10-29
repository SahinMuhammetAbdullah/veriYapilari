#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dugum
{
    char isim[40];
    char soyisim[40];
    char telefon[10];
    char mail[40];
    struct dugum * once;
    struct dugum * sonra;

};
typedef struct dugum rehber;

rehber *kisiEkle(char isim[40], char soyisim[40], char telefon[10], char mail[40]);
void listele(rehber *dayanak);

int main()
{
    int secim;
    printf("______Telefon Rehberi______ ");
    while (secim != 5)
    {
        printf("\n \n 1 - Rehberi Goruntule \n 2 - Kisileri Isinlerine Gore Ara \n 3 - Kisileri Soyisimlerine gore ara \n 4 - Kisileri Sil \n 5 - Programi Kapat\n Secim : ");
        scanf("%d", &secim);

        switch (secim)
        {
            case 1:
                /* Rehberi ekranda gorunteleyecek blok */
                rehber 
                    *kisi1, 
                    *kisi2, 
                    *kisi3, 
                    *kisi4
                ; 

                kisiEkle
                (
                    strcpy(kisi1->isim,"Muhammet Abdullah"), 
                    strcpy(kisi1->soyisim,"Sahin"), 
                    strcpy(kisi1->telefon,"5351040690"), 
                    strcpy(kisi1->mail,"apo690apo@gmail.com")
                );

                kisiEkle
                (
                    strcpy(kisi2->isim,"Salih"), 
                    strcpy(kisi2->soyisim,"Sahin"), 
                    strcpy(kisi2->telefon,"5352637898"), 
                    strcpy(kisi2->mail,"salihsahin@gmail.com")
                );

                kisiEkle
                (
                    strcpy(kisi3->isim,"Ahmet"), 
                    strcpy(kisi3->soyisim,"Kilic"), 
                    strcpy(kisi3->telefon,"5436678790"), 
                    strcpy(kisi3->mail,"ahmetkilic@gmail.com")
                );

                kisiEkle
                (
                    strcpy(kisi4->isim,"Muhammet"), 
                    strcpy(kisi4->soyisim,"Tamur"), 
                    strcpy(kisi4->telefon,"5321447690"), 
                    strcpy(kisi4->mail,"m.tamur@gmail.com")
                );

                kisi1 -> sonra = kisi2;
                kisi2 -> sonra = kisi3;
                kisi3 -> sonra = kisi4;
                kisi2 -> once = kisi1;
                kisi3 -> once = kisi2;
                kisi4 -> once = kisi3;
                
                listele(kisi1);                
                break;
            case 2:
                /* Kisileri isimlerine gore bulacak blok */
                break;
            case 3:
                /* Kisileri soyisimlerine gore bulacak blok */
                break;   
            case 4:
                /* Kisileri silecek blok */
                system("cls");
                int secilen;
                while (secilen != 3)
                {
                    printf("\n \n 1 - Bastan Sil \n 2 - Sondan Sil \n 3 - Sayfadan Cikis Yap \nSecim : ");
                    scanf("%d", &secilen);

                    switch (secilen)
                    {
                        case 1:
                            /* Bastan Sil blogu */
                            break;
                        case 2:
                            /* Sondan Sil blogu */
                            break;
                        case 3:
                            /* Sayfadan Cikis yap Blogu */
                            system("cls");
                            exit;

                            break;
                        default:
                            printf("Lutfen Gecerli Bir Islem Girin!");
                            break;
                    }
                }
                
                break;                              
            case 5:
                /*Programi kaptan block*/
                exit;

                break;
            default:
                system("cls");
                printf("Lutfen Gecerli Bir Islem Girin!");
                break;
        }
    }
    return 0;
}

rehber *kisiEkle(char isim[40], char soyisim[40], char telefon[10], char mail[40])
{
    rehber *yenikisi = (rehber *)malloc(sizeof(rehber));

    yenikisi -> isim[40] = isim[40];
    yenikisi -> soyisim[40] = soyisim[40];
    yenikisi -> telefon[10] = telefon[10];
    yenikisi -> mail[40] = mail[40];

    yenikisi -> sonra = NULL;
    yenikisi -> once = NULL;
    return yenikisi;
}

void listele(rehber *dayanak)
{
    rehber* gecici = dayanak;

    while (dayanak != NULL)
    {
        printf("\n ad: %s\n soyad: %s\n telefon numarasi: %s\n mail adresi %s\n",gecici -> isim[40], gecici -> soyisim[40], gecici -> telefon[10], gecici -> mail[40]);
        
        gecici = gecici -> sonra;
    }

    printf("\n ad: %s\n soyad: %s\n telefon numarasi: %s\n mail adresi %s\n",gecici -> isim[40], gecici -> soyisim[40], gecici -> telefon[10], gecici -> mail[40]);    
}

void ismeGoreAra(rehber *baslama_noktasi, char aranan[40])
{
	rehber *gecici = baslama_noktasi;

	while(gecici != NULL)
    {
		if(gecici -> isim[40] == aranan[40])
        {
			printf("aranan %s listede bulundu\n");

			return;
		}

		gecici = gecici -> sonra;
	}

	printf("aranan %s listede bulunamadi\n");
}