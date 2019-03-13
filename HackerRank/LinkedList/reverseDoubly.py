def reverse(head):
    # -----------------------------Regular Solution-----------------------------
    # temp = head
    # new_head = head
    # while temp:
    #     p = temp.prev
    #     temp.prev = temp.next
    #     temp.next = p
    #     new_head = temp
    #     temp = temp.next
    # return  new_head
    # ---------------------------- 一个好聪明的python解法------------------------
    if not head:
        return head
    head.prev, head.next = head.next, head.prev
    if not head.prev:
        return head
    return reverse(head.prev)
    
# In python you can switch variables in a single line like shown above, so the code goes through each node at a time reversing the connections until you hit the final node.
# The last node returned would be the final one encountered, which is now the first element.
