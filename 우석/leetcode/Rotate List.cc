/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* curHead;

    ListNode* rotateRight(ListNode* head, int k) {
        // if empty return null
        if(head == nullptr || head->next == nullptr) return head;

        // connect head and tail
        // make tail's next node is head
        ListNode* curHead = head;
        ListNode* curNode = head;
        int nodeCnt = 1;
        while(curNode->next){
            curNode = curNode->next;
            nodeCnt++;
        }
        // cur node = tail
        curNode->next = curHead;
        
        curNode = curHead;
        for(int i = 0; i<nodeCnt - k%nodeCnt -1 ; i++){
            curNode = curNode->next;
        }
        curHead = curNode->next;
        curNode->next = nullptr;

        return curHead;

    }
};