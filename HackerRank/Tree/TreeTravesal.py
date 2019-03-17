
# pre order
def preOrder(root):
    #Write your code here
    if root:
        print(str(root.info) + " ",end = "") // need to print in the same line
        preOrder(root.left)
        preOrder(root.right)
