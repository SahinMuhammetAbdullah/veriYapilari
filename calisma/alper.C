#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void traverse_and_display(struct Node* List){
    printf("[ ");
    while(List != NULL){
        printf("(%d) ", List->data);
        List = List->next;
    }
    printf("]\n");
}
void insert_node(struct Node** ref, int new_data)
{
    struct Node* temp_node = malloc(sizeof(struct Node*));

    struct Node *last = *ref;

    temp_node->data = new_data;

    temp_node->next = NULL;

    if(*ref == NULL){
        *ref = temp_node;
        return;
    }  

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp_node;
    return;
};
struct Node* del_first_node(struct Node *head){
    if(head == NULL) printf("list is empty");
    else{
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main(){
    int num_of_sending_datas, count = 1, taken_data;

    struct Node* head = NULL;
    struct Node* body = NULL;
    struct Node* end = NULL;
    struct Node* merged = NULL;

    head = malloc(sizeof(struct Node*));
    body = malloc(sizeof(struct Node*));
    end = malloc(sizeof(struct Node*));
    merged = malloc(sizeof(struct Node*));

    head = del_first_node(head);
    body = del_first_node(body);
    end = del_first_node(end);
    merged = del_first_node(merged);

    printf("3 Farklı Bağlı Liste Oluşturuldu.\n");
    printf("Bir listede kaç veri bulunsun: ");
    scanf("%d", &num_of_sending_datas);    
    printf("[Birinci Liste Üzerinde Düzenleme Yapıyorsunuz !]\n");
    
    while(num_of_sending_datas >= count){
        printf("%d. veriyi gönderin: ",count);
        scanf("%d", &taken_data);
        insert_node(&head,taken_data);
        count++;
    }
    count = 1;
    
    printf("\n[İkinci Liste Üzerinde Düzenleme Yapıyorsunuz !]\n");
    while(num_of_sending_datas >= count){
        printf("%d. Veriyi Gönderin: ", count);
        scanf("%d", &taken_data);
        insert_node(&body,taken_data);
        count++;
    }
    count = 1;
    
    printf("\n[Üçüncü Liste Üzerinde Düzenleme Yapıyorsunuz !]\n");
    while(num_of_sending_datas >= count){
    printf("%d. Veriyi Gönderin: ", count);
        scanf("%d", &taken_data);
        insert_node(&end,taken_data);
        count++;
    }
    

    printf("\n1.Liste : ");
    traverse_and_display(head);
    printf("\n2.Liste : ");
    traverse_and_display(body);
    printf("\n3.Liste : ");
    traverse_and_display(end);


    while(head != NULL){
        insert_node(&merged, head->data);
        head = head->next;
    }
    while(body != NULL){
        insert_node(&merged,body->data);
        body = body->next;
    }
    while(end != NULL){
        insert_node(&merged, end->data);
        end = end->next; 
    }
    
    printf("\nBirleştirilmiş: ");
    traverse_and_display(merged);
    printf("\n");

}