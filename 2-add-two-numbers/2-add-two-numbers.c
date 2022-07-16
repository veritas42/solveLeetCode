/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* answer = malloc(sizeof(struct ListNode));
    struct ListNode* lastOfAnswer = answer;
    int sum = l1->val + l2->val;  
    int carry = sum / 10;
    answer->val = sum % 10;

    while ((l1->next != NULL) || (l2->next != NULL) || carry)
    {
        sum = 0;
        if (l1->next != NULL) {
            l1 = l1->next;
            sum += l1->val;
        }
        if (l2->next != NULL) {
            l2 = l2->next;
            sum += l2->val;
        }
        sum += carry;
        lastOfAnswer->next = malloc(sizeof(struct ListNode));
        lastOfAnswer = lastOfAnswer->next;
        carry = sum / 10;
        lastOfAnswer->val = sum % 10;
    }
    lastOfAnswer->next = NULL;
    return answer;
}
