def reverse(arr,n,k):
    
    return arr[k:] + arr[:k]
    
tot = int(input())
for _ in range(tot):
    n,k = list(int(x) for x in input().split())
    arr = [int(i) for i in input().split()]
    res = reverse(arr,n,k)
    for x in res:
        print(x, end = ' ')
    print()
    

    
    
#######################################
##  Array rotation using reverse():  ##
#E#####################################

    
def reverse(arr, low, high):
    
    while low<high:
        arr[low], arr[high] = arr[high], arr[low]
        low += 1
        high -= 1
    
    return arr

def rotateArr(arr,d,n):

  reverse(arr, 0, d-1)
  reverse(arr,d,n-1)
  reverse(arr,0,n-1)

  return arr
    
