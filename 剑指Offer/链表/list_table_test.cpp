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
                        if(!nodeStack.empty())putchar(',');
                        else putchar(']');
                }
                putchar('\n');
        }
}

int main(int argc, char const *argv[]) {
        int arr[] = {1,2,6,1,7,11,8,14};
        ListNode* listTable = makeList(arr,0,7);
        printListTable(listTable);
        //testAddToTail(listTable);
        reverselyPrintListTable(listTable);
        freeListTable(listTable);
        return 0;
}
