def isBalanced(s):
    stack = []
    table = {
        ")" : "(",
        "]" : "[",
        "}" : "{",
    }
    for c in s:
        if not stack:
            stack.append(c)
        elif c not in table:
            stack.append(c)
        elif table[c] == stack[-1]:         // stack[-1]: get the last element in list
            stack.pop()
        else:
            stack.append(c)
    if stack:
        return "NO"
    else:
        return "YES"
