/*
	Çift yönlü bağlı liste örnek programı.
	Program klavyeden girilen tam sayı değerleri bağlı liste olarak kaydeder.
	Her sayısal değerden sonra bağlı liste ekrana yazdırılır. Kalvyeden
	0 değeri girildiğinde program sonlanır. https://notpast.com
*/

#include <stdio.h>
#include <stdlib.h>

//Çift yönlü bağlı liste düğümü.
typedef struct NODE{
	//Düğüme ait veri.
	//Farklı tipte değişkenler burada tanımlanabilir.	
	int x;
	//Bir sonraki düğümün adresi.
	struct NODE * next;
	//Bir önceki düğümün adresi.
	struct NODE * previous;
}NODE;


NODE * CreateNode(NODE * previous,int x){
	NODE * node;
	//Yeni düğüm için bellekten yer ayrılıyor.
	node=(NODE *)malloc(sizeof(NODE));
	if(node){
		//Yeni düğüme veri kaydediliyor.
		node->x=x; 
		//NULL anlamı sonrasında düğüm olmadığıdır.
		node->next=NULL;
		//Bir önceki düğümün adresi yeni oluşturulan 
		//düğümün bir önceki düğüm adresine kaydediliyor.
		if(previous){
			node->previous=previous;
			previous->next=node;
		}else{
			//root ise önceki düğümü yok.
			node->previous=NULL;
		}
	}
	return node;
}


//Çift yönlü bağlı listede düğüm silme fonksiyonu.
void RemoveNode(NODE *node){
	NODE *tmp;
	if(!node->previous){
		return;
	}

	//Bir önceki düğümün sonraki düğüm adresine 
	//silinecek düğümden sonraki düğümün adresi kaydediliyor.
	tmp=node->previous;
	tmp->next=node->next;

	//Düğüm siliniyor.
	free(node);
	return;
}

//Bağlı listyi sondan başlayarak ekrana yazdıran fonksiyon.
//last parametresi bağlı listenin son düğümü.
void PrintListLeft(NODE * last){
	NODE * tmp=last;
	while(tmp){
		printf("%d,",tmp->x);
		//Bir önceki düğüm tmp değişkenine aktarılıyor.
		tmp=tmp->previous;
	}
	return;
}


//Bağlı listyi baştan başlayarak ekrana yazdıran fonksiyon.
//root parametresi bağlı listenin ilk düğümğü.
void PrintListRight(NODE * root){
	NODE * tmp=root;
	while(tmp){
		printf("%d,",tmp->x);
		//Bir sonraki düğüm tmp değişkenine aktarılıyor.
		tmp=tmp->next;
	}
	return;
}



//Ana fonksiyon.
int main(void){
	NODE * tmp=NULL;
	NODE * last=NULL;
	NODE * root=NULL;
	int x=0;

	//İlk düğüm oluşturuluyor.
	root=CreateNode(NULL,0);
	last=root;

	do{
		printf("\nx:");
		//Klavyeden yeni düğüm için tam sayı bir değer okunuyor.
		scanf("%d",&x);
		//Okunan değerle yenir düğüm oluşturuluyor.
		tmp=CreateNode(last,x);
		if(tmp){
			//Oluşturulan düğümün adresi bir önceki düğüme kaydediliyor.
			last->next=tmp;
			last=last->next;
		}
		//Bağlı listeyi sondan başlayarak ekrana yazdırılıyor.
		PrintListLeft(last);
	}while(x!=0);

	return 0;
}
