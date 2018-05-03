#ifndef __LINEAR_H__
#define __LINEAR_H__

/*
ADT List{
    //构造一个空的线性表
    InitList(&L);
    //销毁线性表
    DestoryList(&L);
    //将L重置为空表
    ClearList(&L)
    //获得L的元素个数
    ListLength(L);
    //判断L是否为空，TRUE是空，FALSE是非空
    ListEmpty(L);
    //获取第i位置的元素
    GetElem(L, i, &e);
    //找到L中第一个和e比满足compare的元素
    LocateElem(L, e, compare());
    //找到cur_e之前的元素， pre_e返回
    PriorElem(L, cur_e, &pre_e);
    //找到cur_e后面的元素
    NextElem(L, cur_e, &next_e);
    //L的第i个元素之前插入e
    ListInsert(&L, i, e);
    //删除第i个位置的元素
    ListDelete(&L, i, &e);
    //对L的所有元素调用visit()
    ListTraverse(L, visit());
};
*/
#include <stdlib.h>
#include <iostream>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
template <typename ElemType>
struct SqList{
    ElemType* elem;
    int length;
    int listsize;
};

template<typename ElemType>
class linear_Sq{
public:
    int InitList_Sq();
    int DestoryList()
    {
        if(L.elem)
            free(L.elem);
        L.length = 0;
        L.listsize = 0;
        return 1;
    }
    int ClearList()
    {

    }
    int ListDelete(int i, ElemType& e)
    {
        int j;
        if(i < 1 || i > L.length)
            return 0;
        e = L.elem[i - 1];
        for(j = i - 1; j < L.length - 1; j++)
            L.elem[j] = L.elem[j + 1];
        L.length--;
        return 1;
    }

    int ListLength()
    {
        return L.length;
    }

    int ListEmpty()
    {
        return L.length == 0;
    }

    int GetElem(int i, ElemType& e)
    {
        if(i < 1 || i > L.length)
            return 0;
        e = L.elem[i - 1];
        return 1;
    }

    int PriorElem(ElemType cur, ElemType& pre)
    {
        int i;
        if(L.length <= 1)
            return 0;
        if(pre == L.elem[0])
            return 0;
        for(i = 1; i < L.length; i++)
        {
            if(L.elem[i] == cur)
            {
                pre = L.elem[i - 1];
                return 1;
            }
        }
        return 0;
    }

    int nextElem(ElemType cur, ElemType& next)
    {
        int i;
        if(L.length <= 1)
            return 0;
        if(next == L.elem[L.length - 1])
            return 0;
        for(i = 0; i < L.length - 1; i++)
        {
            if(L.elem[i] == cur)
            {
                next = L.elem[i + 1];
                return 1;
            }
        }
        return 0;
    }

    int ListInsert(int i, ElemType e)
    {
        int j;
        if(i < 1 || i > L.length + 1)
            return 0;
        if(L.length == L.listsize)
        {
            L.elem = (ElemType*)realloc(L.elem, (L.length + LISTINCREMENT) * sizeof(ElemType));
        }
        j = L.length - 1;
        while(j >= i - 1)
        {
            L.elem[j + 1] = L.elem[j];
            j--;
        }
        L.elem[i - 1] = e;
        L.length++;
        return 1;
    }

    int ListPrint()
    {
        using namespace std;
        cout << "ListSize = " << L.length <<endl;
        int i;
        for(i = 0; i < L.length; i++)
        {
            cout << "List[" << i << "]" << " = " << L.elem[i] << endl;
        }
    }

private:
    SqList<ElemType> L;
};

#endif