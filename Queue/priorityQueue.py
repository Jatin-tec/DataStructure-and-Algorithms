def hepify(Arr, length, root):
    minn = root
    left = root*2+1
    right = root*2+2


    if left<length and Arr[left]<Arr[minn]:
        print("here")
        print(Arr[minn], Arr[left])
        print(minn, left)
        minn=left
        print(minn, left)

    elif right<length and Arr[right]<Arr[minn]:
        print("there")
        print(Arr[minn], Arr[right])
        print(minn, root)
        minn=right
        print(minn, root)

    if minn != root:
        Arr[minn], Arr[root] = Arr[root], Arr[minn]  
        hepify(Arr, length, minn)

def innsert(Arr, value):
    size = len(Arr)+1

    Arr.append(value)

    for i in range((size//2)-1, -1, -1):
        hepify(Arr, size, i)

def delete(Arr, value):
    pass

if __name__ == '__main__':
    queue = []
    innsert(queue, 3)
    innsert(queue, 2)
    innsert(queue, 1)
    print(queue)
    # innsert(queue, 1)