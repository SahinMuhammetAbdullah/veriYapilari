#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum yigin;
yigin *us = NULL;

void ekle(int);
void cikar();
void listele();
void tepe();
int bosmu();
int kapasite();

int main(){
	printf("Yigin bosmu: %d\n", bosmu());
    printf("Yiginin kapasitesi: %d\n", kapasite());
    tepe();
    ekle(1);
    printf("Yigin bosmu: %d\n", bosmu());
    tepe();
    ekle(2);
    ekle(3);
    ekle(4);
	ekle(5);
    printf("Yiginin kapasitesi: %d\n", kapasite());
    tepe();
    listele();
	cikar();
	listele();
	ekle(50);
	listele();
    tepe();
    ekle(55);
    ekle(45);
    ekle(35);
    ekle(25);
    ekle(15);
    ekle(65);
    cikar();
    listele();
    printf("Yigin bosmu: %d\n", bosmu());
    printf("Yiginin kapasitesi: %d\n", kapasite());
	return 0;
}
void ekle(int eleman){
	yigin *yeni;
	yeni = (yigin*)malloc(sizeof(yigin));
	yeni -> veri = eleman;
	if(us == NULL)
		yeni -> sonraki = NULL;
	else
		yeni -> sonraki = us;
	us = yeni;
}
void cikar(){
	if(us == NULL)
        printf("Yigin bos! Yigindan silinecek eleman yoktur\n");
    else{
        yigin *temp = us;
        printf("%d elemani yigindan cikartildi\n", temp -> veri);
        us = temp -> sonraki;
        free(temp);
    }
}
void listele(){
	yigin *temp = us;
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> sonraki;
	}
	printf("\n");
}
void tepe(){
    if(us == NULL)
        printf("Yigin bos!\n");
    else
        printf("Tepedeki eleman: %d\n", us -> veri);
}
int bosmu(){
    return us == NULL;
}
int kapasite(){
	yigin *temp = us;
	int sayac = 0;
	while(temp != NULL){
		temp = temp -> sonraki;
		sayac = sayac + 1;
	}
	return sayac;
}
