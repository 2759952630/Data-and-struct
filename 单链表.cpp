#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100  //线性表存储空间的初始分配量
#define OK 1    //成功标识
#define ERROR 0 //失败标识
#define TURE 1
#define FALSE 0
typedef int Status;	//Status是函数的类型，其值是函数结果状态代码，如OK等
typedef int ElemType;   //ElemType的类型根据实际情况而定，这里假定为int


/*线性表的单链表存储结构*/
//构造结点
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode,*LinkList;


/*构造一个带头结点的单链表
  单链表的初始化
算法步骤：（1）生成新节点作为头节点，用头指针L指向头结点
          （2）将头结点指针域置空
*/
Status InintList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    return OK;
}

/*
判断链表是否为空
空表：链表中无元素（头指针和头结点依然存在）
思路：判断头结点指针域是否为空
*/
Status ListEmpty(LinkList L) {//为空返回1，否则0
    if (L->next)//非空
    {
        return 0;
    }
    else {
        return 1;
    }
}

/*
销毁单链表
*/
Status DestroyList_L(LinkList& L) {
    LNode* p;
    while (L) {
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}
/*
清空单链表
*/
Status ClearList(LinkList& L) {
    LNode* p, * q;
    p = L->next;
    while (p) {//没到表尾
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;//头结点指针域为空
    return OK;
}

/*
求单链表的表长
从首元节点开始，依次计数所有节点
*/
int ListLength(LinkList L) {
    LinkList p;
    p = L->next;
    int i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return OK;
}

/*
获取单链表中第i个元素的值
1.从第一个节点（p=L->next）开始顺序扫描
2.定义j做计数器，初值为1
3.扫描到下一节点时j+1
4.j==i时，p指向的即为第i个元素
*/
Status GetElem(LinkList L, int i, ElemType& e) {
    LNode* p;
    p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

/*
按值查找，根据指定数据获取该元素所在的位置（地址）
从第一个节点起，依次和e比较
*/
LNode* LocateElem_1(LinkList L, ElemType e) {
    LNode* p;
    p = L->next;
    int i = 1;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

/*
按值查找，返回所在位置序号
*/
Status LocateElem_2(LinkList L, ElemType e) {
    LNode* p;
    p = L->next;
    int j=1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    if (p) return j;
    else return 0;
}


/**
 * 单链表插入操作
 * 初始条件：线性表L已存在
 * 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度增加1
 * 1.首先找到i-1位置处的节点的存储位置p
 * 2.生成新节点s
 * 3.s的指针域指向i位置，i-1位置处指针域指向s
*/
Status InsterList(LinkList& L, int i, ElemType e) {
    LNode* p,*s;
    p = L;
    int j = 0;
    while (p && j < i - 1) {//找到i-1处节点
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}


/**
 * 单链表删除操作
 * 初始条件：线性表L已存在
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
 * 首先找到a[i-1]的存储位置p，保存要删除的a[i]的值
 * 令p->next指向a[i+1]
 * 释放节点a[i]的空间
*/
Status DeleteList(LinkList L, int i, ElemType& e) {
    LNode* p, * q;
    int j = 0;
    p = L;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    q = p->next;
    p->next=q->next;
    e = q->data;
    delete q;
    return OK;

}




/*打印单链表表中的所有元素*/


int main()
{
    LinkList L;
   
}
