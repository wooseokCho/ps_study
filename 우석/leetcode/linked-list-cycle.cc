/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> nodeSet;        
        while(head != NULL) {
            if (nodeSet.contains(head)) {
                return true;
            }
            nodeSet.insert(head);
            head = head->next;
        }
        return false;
    }
};

// 개선후
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        do{
            if(fastPtr == NULL || fastPtr->next == NULL) return false;
            
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

        } while(slowPtr != fastPtr);

        return true;
    }
};