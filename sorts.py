def heapify(arr, i):
    if(i < 0):
        return
    left = 2*i + 1
    right = 2*i + 2
    if(right < len(arr) and arr[right] < arr[i]):
        arr[i], arr[right] = arr[right], arr[i]
    if(left < len(arr) and arr[left] < arr[i]):
        arr[i], arr[left] = arr[left], arr[i]


def heapsort(arr, size, new_arr):
    for i in range((size//2)-1, -1, -1):
        heapify(arr, i)
    if(size > 0):
        data = arr.pop(0)
        new_arr.append(data)
        size = size-1
        heapsort(arr, size, new_arr)
    else:
        return


def bubblesort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if(arr[j] < arr[i]):
                arr[i], arr[j] = arr[j], arr[i]


def insertionsort(arr):
    temp_storer = len(arr)-1
    for i in range(1, len(arr)):
        j = i
        val = arr[i]
        while(j >= 0):
            if(val < arr[j]):
                arr[j+1] = arr[j]
                temp_storer = j
            j = j-1
        if(temp_storer != len(arr)-1):
            arr[temp_storer] = val


def selectionsort(arr):
    for i in range(len(arr)):
        mini = i
        for j in range(i, len(arr)):
            if(arr[mini] > arr[j]):
                mini = j
        arr[i], arr[mini] = arr[mini], arr[i]


def partition(arr, i, j):
    pivot = (j+i)//2
    while(j > i):
        if(arr[i] > arr[pivot] and arr[j] < arr[pivot]):
            arr[i], arr[j] = arr[j], arr[i]
            i = i+1
            j = j-1
        elif(arr[i] > arr[pivot] and arr[j] >= arr[pivot]):
            j = j-1
        elif(arr[i] <= arr[pivot] and arr[j] < arr[pivot]):
            i = i+1
        else:
            i = i+1
            j = j-1
    arr[pivot], arr[j] = arr[j], arr[pivot]
    return j


def quicksort(arr, i, j):
    if(j > i):
        end = partition(arr, i, j)
        quicksort(arr, i, end-1)
        quicksort(arr, end+1, j)


def merge(arr, start, mid, end):
    i = start
    k = start
    j = mid+1
    b = [0]*(end+1)
    while(i <= mid and j <= end):
        if(arr[i] < arr[j]):
            b[k] = arr[i]
            i = i+1
            k = k+1
        else:
            b[k] = arr[j]
            j = j+1
            k = k+1
    for q in range(i, mid+1):
        b[k] = arr[q]
        k = k+1
    for qq in range(j, end+1):
        b[k] = arr[qq]
        k = k+1
    for kk in range(start, end+1):
        arr[kk] = b[kk]


def mergesort(arr, low, high):
    if(low < high):
        mid = (low+high)//2
        mergesort(arr, low, mid)
        mergesort(arr, mid+1, high)
        merge(arr, low, mid, high)


arr = list(map(int, input("Enter array : ").split()))
print(f"Original array is : {arr}")
print("\nChoose what type of sorting technique to use: ")
print("1.Bubble Sort")
print("2.Insertion Sort")
print("3.Selection Sort")
print("4.Heap Sort")
print("5.Quick Sort")
print("6.Merge Sort")
ch = int(input("\nEnter Choice: "))
if(ch == 1):
    bubblesort(arr)
elif(ch == 2):
    insertionsort(arr)
elif(ch == 3):
    selectionsort(arr)
elif(ch == 4):
    new_arr = []
    heapsort(arr, len(arr), new_arr)
    arr = new_arr
elif(ch == 5):
    quicksort(arr, 0, len(arr)-1)
elif(ch == 6):
    mergesort(arr, 0, len(arr)-1)
print(f"Sorted array is: {arr}")
