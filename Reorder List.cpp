#include <iostream>
using namespace std;
/**

 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *tmpHead, *p1, *p2, *pre, *tmp1 , *tmp2;
        int count = 0;
        if(head==NULL || head->next==NULL)   return;
        ListNode *p = head;
        while(p!=NULL){
            count++;
            p = p->next;
        }
        if(count % 2 == 0){
            tmpHead = head->next;
            p1 = head;
            p2 = head->next;
        }else{
            tmpHead = head->next->next;
            p1 = head->next;
            p2 = tmpHead->next;
        }
        while( p2!=NULL ){
            p1->next = p2->next;
            if(p2->next != NULL)  p2->next = p2->next->next;
            else    p2->next = NULL;
            
            p1 = p1->next;
            p2 = p2->next;
        }
    p = head;
    cout<< count<<endl;
    while(p!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
        pre = tmpHead;
        p2 = tmpHead->next;
        pre->next = NULL;
        while( p2 != NULL){
            tmp1 = p2->next;
            p2->next = pre;
            pre = p2;
            p2 = tmp1;
        }
        p2 = pre;
        p1 = head;
        while(p1!=NULL && p2!=NULL){
            tmp1 = p1->next;
            p1->next = p2;
            tmp2 = p2->next;
            p2->next = tmp1;
            p1 = p2->next;
            p2 = tmp2;
        }
        if(p2!=NULL)   p1->next = p2;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
    s.reorderList(head);/*
    ListNode *p = head;
    while(p!=NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    */
    cout<<endl;
    return 0;
}

