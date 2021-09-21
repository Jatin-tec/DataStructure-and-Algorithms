def isBalanced(string):
    stack = []
    for element in string:
        if element == '(':
            stack.append(element)
        if element == ')':
            stack.pop() 
    
    if len(stack)>0:
        return 0
    else:    
        return 1


strrr= '(())'

print(isBalanced(strrr))