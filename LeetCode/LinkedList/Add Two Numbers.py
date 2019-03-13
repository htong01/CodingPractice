class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = n = ListNode(0)
        S = 0
        while l1 or l2 or S:
            if l1:
                S += l1.val
                l1 = l1.next
            if l2:
                S += l2.val
                l2 = l2.next
            n.next = ListNode(S%10)
            n = n.next
            S //= 10
        return root.next
