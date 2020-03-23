## 两遍遍历
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //两遍遍历
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        vector<ListNode*> ans={head};
        ListNode* p = head;
        while (p->next != NULL)
        {
            ans.push_back(p->next);
            p = p->next;
        }
        return ans[ans.size() / 2];
    }
};
```
## 快慢指针
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //快慢指针
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
```