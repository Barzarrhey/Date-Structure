//
//  sequenceList.h
//  DateStructure
//
//  Created by Barzarrhey on 2018/9/18.
//  Copyright © 2018年 Barzarrhey. All rights reserved.
//  https://github.com/Barzarrhey

#ifndef sequenceList_h
#define sequenceList_h

#include <stdio.h>
#include <stdlib.h>

// 线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LIST_INCREMENT 2 /* 线性表存储空间的分配增量 */
#define OVERFLOW    0
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  0

typedef int ElemType; // ElemType 类型根据实际情况而定，这里假设为 int
typedef int Status; // 类型名定义用status代替int

typedef struct
{
    ElemType *elem; /* 存储空间基址 */
    int length; /* 当前长度 */
    int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
}SqList;

/* 操作结果：构造一个空的顺序线性表L */
void InitList(SqList *L);

/* 初始条件：顺序线性表L已存在。
 * 操作结果：销毁顺序线性表L */
void DestroyList(SqList *L);

/* 初始条件：顺序线性表L已存在。
 * 操作结果：将L重置为空表 */
void ClearList(SqList *L);

/* 初始条件：顺序线性表L已存在。
 * 操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L);

/* 初始条件：顺序线性表L已存在。
 * 操作结果：返回L中数据元素个数 */
int ListLength(SqList L);

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)。
 * 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(SqList L,int i,ElemType *e);

/* 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
 * 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。 */
int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType));

/* 初始条件：顺序线性表L已存在
 * 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义 */
Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e);

/* 初始条件：顺序线性表L已存在
 * 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义 */
Status NextElem(SqList L,ElemType cur_e,ElemType *next_e);

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1
 * 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L,int i,ElemType e);

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L,int i,ElemType *e);

/* 初始条件：顺序线性表L已存在
 * 操作结果：依次对L的每个数据元素调用函数vi(),vi()的形参加'&'，表明可通过调用vi()改变元素的值 */
void ListTraverse(SqList L,void(*vi)(ElemType*));

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：打印线性表*/
void PrintList(SqList L);

/* 判断两个元素是否相等 */
Status compare(ElemType m,ElemType n);

#endif /* sequenceList_h */
