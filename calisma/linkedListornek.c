/*
	Çift yönlü bağlı listeden eleman silen program.
	Program bir döngü ile oluşturumuş 10 düğümlü çift yönlü bağlı liste içinden 
	istenilen düğümü siler. Program döngüsü bütün düğümler silinene kadar
	devam eder. https://notpast.com
*/

#include <stdio.h>
#include <stdlib.h>3

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


//Tek yönlü bağlı listede düğüm silme fonksiyonu.
void RemoveNode(NODE *node){
	NODE *tmp;
	if(node->previous){
		//Bir önceki düğümün sonraki düğüm adresine 
		//silinecek düğümden sonraki düğümün adresi kaydediliyor.
		tmp=node->previous;
		tmp->next=node->next;
	}
	if(node->next){
		tmp=node->next;
		tmp->previous=node->previous;		
	}
	//Düğüm siliniyor.
	free(node);
	return;
}

//Bağlı listyi sondan başlayarak ekrana yazdıran fonksiyon.
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
	NODE * node=NULL;
	NODE * root=NULL;
	int x=0;
	int i=0;

	//İlk düğüm oluşturuluyor.
	root=CreateNode(NULL,0);
	node=root;

	//Bağlı listeye 10 düğüm ekleniyor.
	for(i=0;i<10;i++){
		tmp=CreateNode(node,i+1);
		node->next=tmp;	
		node=tmp;	
	}	

	//Bağlı liste yazdırılıyor.
	PrintListLeft(tmp);

	//Bütün düğümler silinene kadar döngü devam eder.
	do{
		printf("\nSilinecek dugum:");
		//Klavyeden silinecek düğüm değeri okunuyor.
		scanf("%d",&x);
		node=root;
		tmp=NULL;
		//Klavyeden okunan değer bağlı listede aranıyor.
		while(node){
			if(node->x==x){
				if(tmp==NULL){
					//Silinen düğüm ilk düğümse sonraki düğüm 
					//ilk düğüme kaydediliyor.					
					root=node->next;
				}
				//Düğüm siliniyor.				
				RemoveNode(node);
				break;
			}

			tmp=node;
			//Bir sonraki düğüme geçiliyor.
			node=node->next;
		}
		//Bağlı liste yazdırılıyor.
		PrintListRight(root);	
	}while(root);

	return 0;
}