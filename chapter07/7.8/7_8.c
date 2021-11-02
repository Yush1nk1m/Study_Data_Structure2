#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

DListNode* current;

void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (p == current)
            printf("<- | #%s# | -> ", p->data);
        else
            printf("<- | %s | -> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode* before, element data)
{
    DListNode* newdata = (DListNode*)malloc(sizeof(DListNode));
    strcpy(newdata->data, data);
    newdata->llink = before;
    newdata->rlink = before->rlink;
    before->rlink->llink = newdata;
    before->rlink = newdata;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(void)
{
    char ch;
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");

    current = head->rlink;
    print_dlist(head);

    do {
        printf("\n명령어를 입력하시오(<, >, q) : ");
        ch = getchar();
        if (ch == '<') {
            current = current->llink;
            if (current == head)
                current = current->llink;
        }
        else if (ch == '>') {
            current = current->rlink;
            if (current == head)
                current = current->rlink;
        }
        print_dlist(head);
        getchar();  // get '\n'
    } while (ch != 'q');

    ddelete(head, head->rlink);
    ddelete(head, head->rlink);
    ddelete(head, head->rlink);
    free(head);
    return 0;
}