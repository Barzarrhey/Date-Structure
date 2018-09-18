//
//  demo.c
//  DateStructure
//  https://github.com/Barzarrhey
//  Created by Barzarrhey on 2018/9/18.
//  Copyright © 2018年 Barzarrhey. All rights reserved.

#include "sequenceList.h"

void vi(ElemType (*elem))
{
    *elem = *elem * 3 + 2;
}

int main()
{
    printf("*****************************************************\n"
           "    顺序表及其基本操作的测试程序                          \n"
           "        编号     操作                                 \n"
           "         1      构造一个空的顺序线性表                   \n"
           "         2      销毁顺序线性表                          \n"
           "         3      将L重置为空表                           \n"
           "         4      判断L是否为空表                          \n"
           "         5      返回L中数据元素个数                       \n"
           "         6      返回L中第i个数据元素的值                   \n"
           "         7      查找L中与给定元素e相等的元素并返回其位置      \n"
           "         8      返回给定元素e的前驱                       \n"
           "         9      返回给定元素e的后继                       \n"
           "         10     在L中第i个位置之前插入新的数据元素e          \n"
           "         11     给线性表自动赋值(1~10)                    \n"
           "         12     删除L的第i个数据元素，并返回其值             \n"
           "         13     依次对L的每个数据元素调用函数vi()            \n"
           "         14     打印线性表                                \n"
           "         0      退出                                     \n");
    int key = -1;
    int listLength = -1;
    int listEmptyFlag = -1;
    int i;
    Status getElemFlag = -1;
    int locateElemFlag = -1;
    ElemType e;
    Status priorElemFlag = -1;
    ElemType cur_e;
    ElemType pre_e;
    Status nextElemFlag = -1;
    ElemType next_e;
    Status listInsertFlag = -1;
    Status listDeleteFlag = -1;
    SqList L;
    while(key)
    {
        printf("请输入指令编号，按回车确认：\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                InitList(&L);
                printf("顺序线性表初始化成功！\n");
                break;
            case 2:
                DestroyList(&L);
                printf("顺序线性表销毁成功！\n");
                break;
            case 3:
                ClearList(&L);
                printf("将L重置为空表成功！\n");
                break;
            case 4:
                listEmptyFlag = ListEmpty(L);
                if(listEmptyFlag == TRUE)
                    printf("L是一个空表或不存在\n");
                else
                    printf("L不是一个空表\n");
                break;
            case 5:
                listLength = ListLength(L);
                printf("L的长度为：%d\n",listLength);
                break;
            case 6:
                printf("请输入你想查找的元素的位置：\n");
                scanf("%d",&i);
                getElemFlag = GetElem(L,i,&e);
                if(getElemFlag == ERROR)
                    printf("顺序线性表L不存在或为空表！\n");
                else
                    printf("L中第i个数据元素的值为：%d\n",e);
                break;
            case 7:
                printf("请输入你想查找的元素的值：\n");
                scanf("%d",&e);
                locateElemFlag = LocateElem(L,e,compare);
                if(locateElemFlag == 0)
                    printf("该元素不存在\n");
                else
                    printf("该元素的位置是：%d\n",locateElemFlag);
                break;
            case 8:
                printf("请输入你想查找的元素的值：(返回其前驱)\n");
                scanf("%d",&cur_e);
                priorElemFlag = PriorElem(L,cur_e,&pre_e);
                if(priorElemFlag == INFEASIBLE)
                    printf("操作失败！\n");
                else
                    printf("%d 的前驱是：%d\n",cur_e,pre_e);
                break;
            case 9:
                printf("请输入你想查找的元素的值：(返回其后继)\n");
                scanf("%d",&cur_e);
                nextElemFlag = NextElem(L,cur_e,&next_e);
                if(nextElemFlag == INFEASIBLE)
                    printf("操作失败！\n");
                else
                    printf("%d 的后继是：%d\n",cur_e,next_e);
                break;
            case 10:
                printf("请输入你想插入的元素位置及元素：\n");
                scanf("%d",&i);
                scanf("%d",&e);
                listInsertFlag = ListInsert(&L,i,e);
                if(listInsertFlag == ERROR)
                    printf("i值不合法\n");
                else
                    printf("插入成功！\n");
                break;
            case 11:
                // 添加10个数字给线性表list
                for (int i = 0; i < 10; i++)
                {
                    ListInsert(&L, i+1, i+1);
                }
                break;
            case 12:
                printf("请输入要删除的数据元素的位置：\n");
                scanf("%d",&i);
                listDeleteFlag = ListDelete(&L,i,&e);
                if(listDeleteFlag == ERROR)
                    printf("i值不合法\n");
                else
                    printf("删除成功！删除的元素是位于第%d的%d\n",i,e);
                break;
            case 13:
                ListTraverse(L,vi);
                break;
            case 14:
                PrintList(L);
                break;
            default:
                printf("无效的指令，请重新输入。\n");
        }
    }
    return 0;
}

/* *************************************
 控制台测试结果：
 *****************************************************
 顺序表及其基本操作的测试程序
 编号     操作
 1      构造一个空的顺序线性表
 2      销毁顺序线性表
 3      将L重置为空表
 4      判断L是否为空表
 5      返回L中数据元素个数
 6      返回L中第i个数据元素的值
 7      查找L中与给定元素e相等的元素并返回其位置
 8      返回给定元素e的前驱
 9      返回给定元素e的后继
 10     在L中第i个位置之前插入新的数据元素e
 11     给线性表自动赋值(1~10)
 12     删除L的第i个数据元素，并返回其值
 13     依次对L的每个数据元素调用函数vi()
 14     打印线性表
 0      退出
 请输入指令编号，按回车确认：
 1
 顺序线性表初始化成功！
 请输入指令编号，按回车确认：
 4
 L是一个空表或不存在
 请输入指令编号，按回车确认：
 5
 L的长度为：0
 请输入指令编号，按回车确认：
 11
 请输入指令编号，按回车确认：
 4
 L不是一个空表
 请输入指令编号，按回车确认：
 5
 L的长度为：10
 请输入指令编号，按回车确认：
 14
 1,2,3,4,5,6,7,8,9,
 请输入指令编号，按回车确认：
 6
 请输入你想查找的元素的位置：
 5
 L中第i个数据元素的值为：5
 请输入指令编号，按回车确认：
 7
 请输入你想查找的元素的值：
 6
 该元素的位置是：6
 请输入指令编号，按回车确认：
 8
 请输入你想查找的元素的值：(返回其前驱)
 5
 5 的前驱是：4
 请输入指令编号，按回车确认：
 9
 请输入你想查找的元素的值：(返回其后继)
 6
 6 的后继是：7
 请输入指令编号，按回车确认：
 10
 请输入你想插入的元素位置及元素：
 2
 1
 插入成功！
 请输入指令编号，按回车确认：
 14
 1,1,2,3,4,5,6,7,8,9,
 请输入指令编号，按回车确认：
 12
 请输入要删除的数据元素的位置：
 2
 删除成功！删除的元素是位于第2的1
 请输入指令编号，按回车确认：
 14
 1,2,3,4,5,6,7,8,9,
 请输入指令编号，按回车确认：
 13
 
 请输入指令编号，按回车确认：
 14
 5,8,11,14,17,20,23,26,29,
 请输入指令编号，按回车确认：
 3
 将L重置为空表成功！
 请输入指令编号，按回车确认：
 4
 L是一个空表或不存在
 请输入指令编号，按回车确认：
 5
 L的长度为：0
 请输入指令编号，按回车确认：
 14
 
 请输入指令编号，按回车确认：
 2
 顺序线性表销毁成功！
 请输入指令编号，按回车确认：
 0
 无效的指令，请重新输入。
 Program ended with exit code: 0
 *****************************************/
 
