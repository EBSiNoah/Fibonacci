# -*- coding: utf-8 -*-
"""
Created on Sat Nov 26 14:04:50 2022

@Author: skm
@Filename .py
"""
import copy

def calMat(mA, mB):
    f=[ [ 0, 0 ], [ 0, 0 ] ]
    
    f[0][0] = mA[0][0] * mB[0][0] + mA[0][1] * mB[1][0]
    f[0][1] = mA[0][0] * mB[0][1] + mA[0][1] * mB[1][1]
    f[1][0] = mA[1][0] * mB[0][0] + mA[1][1] * mB[1][0]
    f[1][1] = mA[1][0] * mB[0][1] + mA[1][1] * mB[1][1]
    
    return f

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

def pybo_test():
    output=pybonacci(8)
    print(output)

def main():
    pybo_test()
    
if(__name__=="__main__"):
    main()