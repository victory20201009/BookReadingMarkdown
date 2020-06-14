#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
        int v;
        ListNode* nt;
};

/*
 * 生成链表
 */
ListNode* makeList(int *arr,int start,int end){
        if(arr==NULL||start>end) return NULL;
        ListNode *pHead = new ListNode();
        pHead->v = arr[start];
        ListNode* pNode=pHead;
        for(int i=start+1; i<=end; ++i) {
                pNode->nt = new ListNode();
                pNode = pNode->nt;
                pNode->v = arr[i];
                pNode->nt=NULL;
        }
        return pHead;
}

/*
 * 打印链表
 */
void printListTable(ListNode* pHead) {
        if(pHead==NULL) return;
        ListNode* pNode = pHead;
        printf("[");
        while(pNode) {
                printf("%d",pNode->v);
                if(pNode->nt) printf(",");
                else printf("]");
                pNode=pNode->nt;
        }
        putchar('\n');
}

/*
 * 向尾部添加元素
 */
void addToTail(ListNode** head,int v) {
        if(!head)
                return;
        ListNode* pNode = new ListNode();
        pNode->v=v;
        pNode->nt=NULL;
        if(!(*head))
                *head = pNode;
        else{
                ListNode *pTmp = *head;
                while(pTmp->nt) pTmp=pTmp->nt;
                pTmp->nt=pNode;
        }
}

/*
 * 释放链表空间
 */
void freeListTable(ListNode* pHead) {
        if(pHead) {
                printf("start to free the memory that listTable has occupied\n");
                ListNode* curPnode = pHead,*nextPnode=pHead->nt;
                while(curPnode) {
                        delete curPnode;
                        curPnode = nextPnode;
                        nextPnode = nextPnode->nt;
                }
        }
}

/*
 * 向尾部添加
 */
void testAddToTail(ListNode* pHead) {
        printf("test add ele to listTable\n");
        int i;
        while(scanf("%d", &i)!=EOF) {
                if(i) {
                        addToTail(&pHead,i);
                        printListTable(pHead);
                }else{
                        printf("exit testAddToTail\n");
                        return;
                }

        }
}

/*
 * 反向打印链表 使用栈
 */
void reverselyPrintListTable(ListNode* pHead){
        if(pHead) {
                stack<int> nodeStack;
                ListNode* pNode =pHead;
                while(pNode) {
                        nodeStack.push(pNode->v);
                        pNode=pNode->nt;
                }
                putchar('[');
                while(!nodeStack.empty()) {
                        printf("%d",nodeStack.top());
                        nodeStack.pop();
                        if(!nodeStack.empty()) putchar(',');
                        else putchar(']');
                }
                putchar('\n');
        }
}

void reverselyPrintListTable2_(ListNode* pHead){
        if(pHead) {
                reverselyPrintListTable2_(pHead->nt);
                if(!(pHead->nt)) putchar('[');
                else putchar(',');
                printf("%d",pHead->v);
        }
}

/*
 * 反向打印链表 使用递归
 */
void reverselyPrintListTable2(ListNode* pHead) {
        reverselyPrintListTable2_(pHead);
        if(pHead)
                putchar(']');
        putchar('\n');
}

/*
 * 删除第一个满足条件的
 */
void removeFirst(ListNode** head,int n){
        if(head&&*head) {
                ListNode* pDelete=NULL;
                if((*head)->v==n) {
                        pDelete=*head;
                        *head = pDelete->nt;
                }else{
                        ListNode* pTmp  = *head;
                        while(pTmp->nt&&pTmp->nt->v!=n) pTmp=pTmp->nt;
                        if(pTmp->nt) {
                                pDelete = pTmp->nt;
                                pTmp->nt=pTmp->nt->nt;
                        }
                }
                if(pDelete) {
                        delete pDelete;
                        pDelete=NULL;
                }
        }
}

/*
 * 根据指针删除一个元素 O(1)时间复杂度
 */
void removeElement(ListNode** head,ListNode* pDelete){
        if(pDelete) {
                /*实际被的删除结点*/
                ListNode* pAlternativeDelete = NULL;
                /*实际被删除的结点的上一个结点*/
                ListNode* pre=NULL;
                if(pDelete->nt) {
                        pAlternativeDelete = pDelete->nt;
                        pre = pDelete;
                }else{
                        pAlternativeDelete = pDelete;
                        if(head&&*head) {
                                if(*head==pDelete) {
                                        delete *head;
                                        *head=NULL;
                                        return;
                                }else{
                                        ListNode* tmp = *head;
                                        while(tmp&&tmp->nt!=pDelete) tmp=tmp->nt;
                                        if(tmp) {
                                                pre = tmp;
                                        }else{
                                                throw "to de delete element is not in the given ListTable";
                                        }

                                }
                        }else{
                                throw "ListTable head can not be NULL";
                        }
                }
                if(pAlternativeDelete&&pre) {
                        pre->v = pAlternativeDelete->v;
                        pre->nt = pAlternativeDelete->nt;
                        delete pAlternativeDelete;
                        pAlternativeDelete=NULL;
                }else{
                        throw "internal error";
                }
        }
}

int main(int argc, char const *argv[]) {
        int arr[] = {1,2,6,1,7,11,8,14};
        ListNode* listTable = makeList(arr,0,7);

        //printListTable(listTable);

        //testAddToTail(listTable);
        //reverselyPrintListTable(listTable);
        //reverselyPrintListTable2(listTable);
        /*
        removeFirst(&listTable,11);
        printListTable(listTable);
        removeFirst(&listTable,1);
        printListTable(listTable);
        */
        printListTable(listTable);
        removeElement(&listTable,listTable);
        printListTable(listTable);
        freeListTable(listTable);


        return 0;
}
