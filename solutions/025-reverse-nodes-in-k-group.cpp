class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrevious = &dummy;

        while (true) {
            ListNode* kthNode = groupPrevious;
            for (int step = 0; step < k && kthNode; step++) kthNode = kthNode->next;
            if (!kthNode) break;

            ListNode* groupNext = kthNode->next;
            ListNode* previous = groupNext;
            ListNode* current = groupPrevious->next;

            while (current != groupNext) {
                ListNode* nextNode = current->next;
                current->next = previous;
                previous = current;
                current = nextNode;
            }

            ListNode* oldFirst = groupPrevious->next;
            groupPrevious->next = kthNode;
            groupPrevious = oldFirst;
        }

        return dummy.next;
    }
};