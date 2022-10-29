#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int veri;
    struct node *sonraki;
}node;

int main() {
    int secim,sayi,eleman_sayisi=0;
    int i,j,gecici,swap;
   
   
    node *root = (node*)malloc(sizeof(node));
    node *temp = root;
    temp->sonraki=NULL;
   
   
    printf("______BAGLI LISTE______ ");
   
    while(secim!=4){
        printf("\n \n 1 - Eleman Ekle \n 2 - Listele \n 3 - Sirala \n 4 - Cikis\n Secim : ");
        scanf("%d",&secim);
    switch(secim){
        case 1:
            printf("\n Sayi girin: ");
            scanf("%d",&sayi);
            if(temp->sonraki==NULL) {
                temp->veri=sayi;
                temp->sonraki=(node*)malloc(sizeof(node));
                temp=temp->sonraki;
                temp->sonraki=NULL;
                eleman_sayisi++;
            }
            else printf("Ooops!");
                       
            break;
        case 2:
            temp=root;
            printf("\n Listeleniyor");
            while(temp->sonraki!=NULL){
                printf("-> %d ",temp->veri);
                temp=temp->sonraki;
            }
            break;
        case 3:
            //Bubble Sort
            for (i=0;i<eleman_sayisi;i++){
                temp=root;
                while(temp->sonraki!=NULL){
                    if(temp->veri > temp->sonraki->veri){
                        swap=temp->sonraki->veri;
                        temp->sonraki->veri=temp->veri;
                        temp->veri=swap;
                    }
                    temp=temp->sonraki;
                }
           
            }
           printf("\n Sayilar Siralandi, Gormek icin Listeleyin..");
            break;
        case 4:
            break;
        default:
            printf("Lutfen Gecerli Bir Islem Girin!");
            break;
                 
        }
   
    }

   
      return 0;
}
