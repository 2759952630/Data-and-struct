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

//顺序表数据结构
typedef struct
{
    ElemType* elem;
    int length;
}SqList;

//构造一个空的线性表
Status InitList(SqList* L)
{
    L->elem = new ElemType(MAXSIZE);
    //C语言描述:L.->elme = (ElemType*)malloc(MAXSIZE*sizeof(ElemType);
    if (!L->elem) {
        return ERROR;
    }
    L->length = 0;
    return OK;
}

/*
插入操作
初始条件：顺序表L已存在
操作结果：在L中的第i个位置之前插入新的数据元素e，L的长度加1
*/
Status ListInsert(SqList* L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE) {
        return ERROR;//线性表已满
    }
    if (i<1 || i>L->length + 1) {
        return ERROR;//插入位置不在线性表范围内
    }
    if (i <= L->length) {//若插入位置不在表尾，若插入位置在表尾，则无需执行元素后移操作
        for (k = L->length - 1; k >= i - 1; k--) {
            L->elem[k + 1] = L->elem[k];//将i位置之后的元素向后移一个位置
        }
    }
    L->elem[i - 1] = e;//插入新元素e
    L->length++;//线性表长加一
    return OK;
}

/*
删除操作
初始条件：顺序表L已存在
操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
*/
Status ListDelete(SqList* L, int i, ElemType* e) {
    int k;
    if (L->length == 0) {
        return ERROR;//线性表为空
    }
    if (i<1 || i>L->length) {
        return ERROR;//删除位置不在线性表范围
    }
    *e = L->elem[i - 1];//返回其删除元素的值
    if (i <= L->length) {//若删除位置不在表尾
        for (k = i; k <= L->length; k++) {
            L->elem[k - 1] = L->elem[k];//将i位置之后的元素前移
        }
    }
    L->length--;//表长减一
    return OK;
}

/*查找操作---------顺序查找
操作结果：L中查找与给定值e相等的元素，若成功返回该元素在表中的序号，否则返回0
*/
Status LocateList1(SqList* L, ElemType e) {
    if (L->length == 0) {
        return ERROR;//线性表为空
    }
    int i, k = 0;
    for (i = 0; i < L->length; i++) {
        if (L->elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

/*查找操作--------二分查找*/
Status LocateList2(SqList* L, ElemType e) {
    if (L->length == 0) {
        return ERROR;//线性表为空
    }
    int low = 0, high = L->length - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (L->elem[mid] == e) {
            return mid + 1;
        }
        else if (L->elem[mid] < e) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

/*
获取元素操作
操作结果：用e返回L中第i个数据元素的值
*/
Status GetElem(SqList L, int i, ElemType* e) {
    if (L.length == 0 || i<1 || i>L.length) {
        return ERROR;//同上
    }
    *e = L.elem[i - 1];
    return OK;
}

//清空线性表
Status ClearList(SqList* L)
{
    L->length = 0;
    return OK;
}

//返回线性表的元素个数
Status ListLength(SqList* L) {
    return L->length;
}

//判断线性表是否为空
Status ListEmpty(SqList* L) {
    if (L->elem) {
        return TURE;
    }
    else return FALSE;
}

//打印线性表中的所有元素
void OutPut(SqList L) {
    printf("当前顺序表的长度:%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    printf("构造一个空的线性表L\n");
    InitList(&L);
    OutPut(L);  //打印结果
    printf("测试插入10个数\n");
    for (int i = 1; i <= 10; i++) {
        ListInsert(&L, i, i);
    }
    OutPut(L);  //打印结果
    printf("在第三位之前插入0\n");
    ListInsert(&L, 3, 0);
    OutPut(L);  //打印结果
    printf("删除第6位的数据\n");
    ElemType e;
    ListDelete(&L, 6, &e);
    printf("删除的数据为：%d\n", e);
    OutPut(L);  //打印结果
    printf("获取元素操作\n");
    GetElem(L, 5, &e);
    printf("得到第5个元素：%d\n", e);
    cout << LocateList1(&L, 6) << endl;
    //cout << LocateList2(&L, 5) << endl;
}