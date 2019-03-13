# simple Fibonacchi solution will return session time out. O(n^2)
def stepPerms(n):
    if n==0 or n==1 or n==2:
        return n
    elif n==3:
        return 4
    else:
        return stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3)
# ---------------------O(N) Solution----------------------------
    f1, f2, f3 = 1, 2, 4
    for i in range(n-1):
        f1, f2, f3 = f2, f3, f1 + f2 + f3
    return f1
