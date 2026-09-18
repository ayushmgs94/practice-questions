class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int index = 0; index < lists.size(); index += 2) {
                ListNode* second = (index + 1 < lists.size()) ? lists[index + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(lists[index], second));
            }
            lists = mergedLists;
        }

        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (first && second) {
            if (first->val <= second->val) {
                tail->next = first;
                first = first->next;
            } else {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }

        tail->next = first ? first : second;
        return dummy.next;
    }
};