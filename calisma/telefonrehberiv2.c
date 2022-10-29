#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dugum
{
    int sira;
    char isim[40];
    char soyisim[40];
    int telefon[10];
    char mail[40];
    struct dugum * once;
    struct dugum * sonra;

}rehber;

rehber * bas = NULL;
rehber * gecici = NULL;
rehber * gecici2 = NULL;
rehber * sonra = NULL;

rehber KisiEkle(int sira, char isim[40], char soyisim[40], int telefon[10], char mail[40]);
void kisileriGoruntule();

int main()
{
    int secim;
    printf("______Telefon Rehberi______ ");
    while (secim != 4)
    {
        printf("\n \n 1 - Kisi ekle \n 2 - Kisileri Sirala \n 3 - Kisileri isimlerine gore ara \n 4 - Kisileri soyisimlerine gore ara \n 5 - Kisileri Goruntule \n 6 - Programi Kapar\n Secim : ");
        scanf("%d", &secim);

        switch (secim)
        {
            case 1:
                /* Kisileri rehbere ekleyecek blok */
                int a;
                int b[40];
                char c[40], d[40], e[40];

                printf("Eklenecek kisinin bilgilerini giriniz:\n ");
                printf("Eklenecek kisinin sirasi: ");
                scanf("%d", &a);
                printf("\n");
                printf("Eklenecek kisinin adi: ");
                scanf("%s", &c);
                printf("\n");
                printf("Eklenecek kisinin soyadi: ");
                scanf("%s", &d);
                printf("\n");
                printf("Eklenecek kisinin telefon numarasi: ");
                scanf("%a", &b);
                printf("\n");
                printf("Eklenecek kisinin mail adresi: ");
                scanf("%s", &e);
                printf("\n");
                
                KisiEkle(a, c, d, b, e);
                break;
            case 2:
                /* Kisileri isimlerine gore bulacak blok */

                break;
            case 3:
                /* Kisileri soyisimlerine gore bulacak blok */
                break;   
            case 4:
                /* Kisileri silecek blok */
                break;                              
            case 5:
                /* Rehberi ekranda gorunteleyecek blok */
                kisileriGoruntule();
                
                break;
            case 6:
                /*Programi kaptan block*/
                exit;

                break;
            default:
                printf("Lutfen Gecerli Bir Islem Girin!");
                break;
        }
    }
    return 0;
}

rehber KisiEkle(int sira, char isim[40], char soyisim[40], int telefon[], char mail[40])
{
    system("cls");

    rehber *yenikisi = (rehber *)malloc(sizeof(rehber));

    yenikisi -> sira = sira;
    yenikisi -> isim[40] = isim[40];
    yenikisi -> soyisim[40] = soyisim[40];
    yenikisi -> telefon[10] = telefon[10];
    yenikisi -> mail[40] = mail[40];

    yenikisi -> sonra = bas;

    if (bas == NULL)
    {
        bas = yenikisi;
        bas -> sonra = bas;
        bas -> once =  bas;
    }
    else
    {
        if (bas -> sonra == bas)
        {
            bas -> sonra = yenikisi;
            bas -> once = yenikisi;
            yenikisi -> sonra = bas;
            yenikisi -> once = bas;
        }
        else
        {
            gecici = bas;
            while (gecici -> sonra != bas)
            {
                gecici = gecici -> sonra;
            }
            
            gecici -> sonra = yenikisi;
            yenikisi -> once = gecici;
            yenikisi -> sonra = bas;
            bas -> once = yenikisi;
        }
        
        
    }
}

void kisileriGoruntule()
{
    system("cls");

    if (bas == NULL)
    {
        printf("Rehber bos\n");
    }
    else
    {
        gecici = bas;
        while (gecici -> sonra != sonra)
        {
            printf("\n sira: %d\n ad: %s\n soyad: %s\n telefon numarasi: %d\n mail adresi %s\n",gecici -> sira, gecici -> isim, gecici -> soyisim, gecici -> telefon, gecici -> mail);
            gecici = gecici -> sonra;
            break;
        }
            printf("\n sira: %d\n ad: %s\n soyad: %s\n telefon numarasi: %d\n mail adresi %s\n",gecici -> sira, gecici -> isim, gecici -> soyisim, gecici -> telefon, gecici -> mail);
    }
}

void isimeGoreAra(rehber * (int sira), char isim[40])
{
    system("cls");
    rehber * gecici = (int sira);
    
    while ((int sira) != NULL)
    {
        if (gecici == sira)
        {
            printf("\n sira: %d\n ad: %s\n soyad: %s\n telefon numarasi: %d\n mail adresi %s\n",gecici -> sira, gecici -> isim, gecici -> soyisim, gecici -> telefon, gecici -> mail);
        }
        gecici = gecici -> sonra;
        
    }
    printf("Aranan ad: %s bulunamadi.\n",gecici -> isim);
}