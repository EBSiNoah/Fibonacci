# -*- coding: utf-8 -*-
"""
Created on Sat Nov 26 14:04:50 2022

@Author: skm
@Filename .py
"""

def calMat(mA, mB):
    f=[ [ 0, 0 ], [ 0, 0 ] ]
    
    f[0][0] = mA[0][0] * mB[0][0] + mA[0][1] * mB[1][0]
    f[0][1] = mA[0][0] * mB[0][1] + mA[0][1] * mB[1][1]
    f[1][0] = mA[1][0] * mB[0][0] + mA[1][1] * mB[1][0]
    f[1][1] = mA[1][0] * mB[0][1] + mA[1][1] * mB[1][1]
    
    return f

def calMatNomalize(mA, mB):
    rowA=0
    colA=0
    rowB=0
    colB=0
    

def pybonacci(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[]
    fn[1]=[[1,1],[1,0]]
    result=[[1,1],[1,0]]
    M=N
    while(M > 1):
        if(M % 2):
            restore.insert(0,M % 2)
        M -= M % 2
        M = M // 2
        restore.insert(0,M)
    restore.append(N)
    print(restore)
    print(fn)
    for i in range(1,len(restore)):
        
        fn[restore[i]]=calMat(fn[restore[i]//2],fn[restore[i]//2])
        

    print(fn)

    return result[0][0]

def pybonacci01(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[]
    k=1
    fn[1]=[[1,1],[1,0]]
    M=N
    while(M > 1):
        if(M % 2):
            restore.insert(0,M % 2)
        M -= M % 2
        M = M // 2
        restore.insert(0,M)

    for i in range(len(restore)):
        fn[k + restore[i]]=calMat(fn[k],fn[restore[i]])
        k+=restore[i]

    print(fn)
    return fn[N][0][1]

def pybonacci02(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[]
    k=1
    fn[0]=[[1,0],[0,1]]
    fn[1]=[[1,1],[1,0]]
    M=N
    while(M > 1):
        restore.insert(0,M % 2)
        M -= M % 2
        M = M // 2
        restore.insert(0,M)

    for i in range(len(restore)):
        fn[k + restore[i]]=calMat(fn[k],fn[restore[i]])
        k+=restore[i]

    print(fn)
    return fn[N][0][1]

def pybonacci03(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[N]
    fn[0]=[[1,0],[0,1]]
    fn[1]=[[1,1],[1,0]]
    M=N
    while(M > 2):
#        restore.insert(0,M % 2)
        M -= M % 2
        M = M // 2
        restore.insert(0,M)

    for k in restore:
        fn[k]=calMat(fn[k//2],fn[k//2])

    print(restore, fn)
    return fn[N][0][1]

def pybonacci0301(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[N]
    fn[0]=[[1,0],[0,1]]
    fn[1]=[[1,1],[1,0]]
    M=N
    while(M > 2):
#        restore.insert(0,M % 2)
        M -= M % 2
        M = M // 2
        restore.insert(0,M)

    restore.remove(1)
    print(restore)
    for k in restore:
        fn[k]=calMat(fn[k//2],fn[k//2])
        if(k%2):
            fn[k]=calMat(fn[k],fn[1])
#        print(fn[k],k)

    print(restore, fn)
    return fn[N][0][1]

def pybonacci0302(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[N]
    fn[0]=[[1,0],[0,1]]
    fn[1]=[[1,1],[1,0]]
    M=N
    while(M//2 > 1):
#        restore.insert(0,M % 2)
        M -= M % 2
        M = M // 2
        restore.insert(0,M)

    #restore.remove(1)
    print(restore)
    for k in restore:
        fn[k]=calMat(fn[k//2],fn[k//2])
        if(k%2):
            fn[k]=calMat(fn[k],fn[1])
#        print(fn[k],k)

    print(restore, fn)
    return fn[N][0][1]

def pybonacci0303(N):
    fn=[ [ [0 for i in range(2)] for j in range(2) ] for l in range(N+1) ]
    restore=[N]
    fn[0]=[[1,0],[0,1]]
    fn[1]=[[1,1],[1,0]]
    M=N
    while(M//2 > 1):
        M -= M % 2
        M = M // 2
        restore.insert(0,M)

    for k in restore:
        fn[k]=calMat(fn[k//2],fn[k//2])
        fn[k]=calMat(fn[k],fn[k%2])

    print(restore, fn)
    return fn[N][0][1]

def pybo_test():
    output=pybonacci(8)
    print(output)

def pybo_test01():
    output=pybonacci01(31)
    print(output)

def pybo_test02():
    output=pybonacci0303(31)
    print(output)

def main():
    pybo_test02()
    
if(__name__=="__main__"):
    main()