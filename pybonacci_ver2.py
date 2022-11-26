# -*- coding: utf-8 -*-
"""
Created on Sat Nov 26 14:04:50 2022

@Author: skm
@Filename .py
"""
import copy

def calMat(front, behind):
    result=[[]]
    row=[]
    a=front[0][0]
    b=front[0][1]
    c=front[1][0]
    d=front[1][1]
    e=behind[0][0]
    f=behind[0][1]
    g=behind[1][0]
    h=behind[1][1]
    row.append(a*e+b*g)
    row.append(a*f+b*h)
    result.append(copy.deepcopy(row))
    row.clear()
    row.append(c*e+d*g)
    row.append(c*f+d*h)
    result.append(copy.deepcopy(row))
    row.clear()
    
    return result

def pybonacci(idx):
    fn=[[1,1],[1,0]]
    restore=[]
    init=[]
    
    for i in range(idx):
        init.append(0)
    init[1]=1
    init[2]=1
    
    while(idx > 1):
        if(idx % 2):
            restore.insert(0,idx % 2)
        idx -= idx % 2
        idx = idx // 2
        restore.insert(0,idx)
    
    for i in range(len(restore)):
        


def pybo_test():
    output=pybonacci(31)

def main():
    pybo_test()
    
if(__name__=="__main__"):
    main()