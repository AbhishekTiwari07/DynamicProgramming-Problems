def minPartition(a,n,s1,s2):
    if n==1:
        return min((abs((s1+a[0])-s2)),(abs(s1-(s2+a[0]))))
    else:
        return min(minPartition(a,n-1,s1+a[n-1],s2),minPartition(a,n-1,s1,s2+a[n-1]))

arr = [5,1,6]
s1=s2=0
print(minPartition(arr,len(arr),s1,s2))