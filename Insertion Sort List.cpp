#include <iostream>
#include <vector>
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *virtual_head = new ListNode(0);
        ListNode *p,*pre,*cur, *next;
        if(head == NULL || head->next == NULL)  return head;
        virtual_head->next = head;
        p = head->next;
        next = p->next;
        head->next = NULL;
        
        while(p!=NULL){
            pre = virtual_head;
            cur = virtual_head->next;
            while(cur!=NULL && cur->val <= p->val){
                pre = pre->next;
                cur = cur->next;
            }
            pre->next = p;
            p->next = cur;
            p = next;
            if(p!=NULL) next = p->next;
        }
        return virtual_head->next;
    }
};

int main()
{
    Solution s;
    ListNode * head, *p;
    head = new ListNode(1);
    head->next = new ListNode(1);

    p = s.insertionSortList(head);

    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;


    return 0;
}
