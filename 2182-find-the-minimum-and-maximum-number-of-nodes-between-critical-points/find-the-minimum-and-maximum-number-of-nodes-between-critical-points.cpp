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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prevNum = head->val;
        head = head->next;
        vector<int> v;
        int mini = INT_MAX;
        int i=1;
        while(head != nullptr && head->next != nullptr) {
            if((prevNum < head->val && head->next->val < head->val) || (prevNum > head->val && head->next->val > head->val)) {
                if(!v.empty() && i - v.back() < mini) mini = i - v.back() ;
                v.push_back(i);            
            }
            prevNum = head->val;
            head = head->next;
            i++;
        }
        int s = v.size();
        if(s <= 1) return {-1, -1};
        return {mini, v[s-1] - v[0]};
    }
};