#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct ListNode {   // Node type
    element data;
    struct ListNode* link;
} ListNode;

// Error Handling Function
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  // (1)
    p->data = value;                                    // (2)
    p->link = head;     // copying head pointer's value // (3)
    head = p;           // change head pointer          // (4)
    return head;        // return changed head pointer  // (5)
}

ListNode* insert_next(ListNode** head, element value)
{
    if (*head == NULL) {
        ListNode* new = (ListNode*)calloc(1, sizeof(ListNode));
        new->data = value;
        *head = new;
        return *head;
    }
    else {
        ListNode* p = (*head);
        while (p->link != NULL)
            p = p->link;
        ListNode* new = (ListNode*)calloc(1, sizeof(ListNode));
        new->data = value;
        p->link = new;
        return *head;
    }
}

// insert new node after pre node
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));  // (1)
    p->data = value;                                    // (2)
    p->link = pre->link;                                // (3)
    pre->link = p;                                      // (4)
    return head;                                        // (5)
}

ListNode* delete_first(ListNode* head)
{
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;         // (1)
    head = removed->link;   // (2)
    free(removed);          // (3)
    return head;            // (4)
}

// delete pre-linked node
ListNode* delete(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;        // (1)
    pre->link = removed->link;  // (2)
    free(removed);              // (3)
    return head;                // (4)
}

int count_list(ListNode* head)
{
    int count = 0;
    for (ListNode* p = head; p != NULL; p = p->link)
        count++;
    return count;
}

int sum_list(ListNode* head)
{
    int total = 0;
    for (ListNode* p = head; p != NULL; p = p->link)
        total += p->data;
    return total;
}

int search_count(ListNode* head, element value)
{
    int count = 0;
    for (ListNode* p = head; p != NULL; p = p->link) {
        if (p->data == value) count++;
    }
    return count;
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    puts("NULL");
}

int main(void) {
    ListNode* head = NULL;
    int n;
    element tmp;
    do {
        printf("노드의 개수 : "); scanf("%d", &n);
    } while (n <= 0);
    
    for (int i = 0; i < n; i++) {
        printf("노드 #%d 데이터 : ", i + 1);
        scanf("%d", &tmp);
        head = insert_next(&head, tmp);
    }
    
    element value;
    printf("탐색할 값을 입력하시오 : "); scanf("%d", &value);
    printf("%d는 연결 리스트에서 %d번 나타납니다.\n", value, search_count(head, value));

    return 0;
}