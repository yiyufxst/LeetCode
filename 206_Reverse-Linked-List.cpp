#include <iostream>

using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        ListNode* result = NULL;
        ListNode* temp = NULL;
        
        while (head) {
            temp = head->next;
            head->next = result;
            result = head;
            head = temp;
        }
        return result;
    }
};
