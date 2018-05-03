#include "linear.h"

template<typename ElemType> int linear_Sq<ElemType>::InitList_Sq()
{
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem)
        exit(1);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}


int main()
{
    using namespace std;
    linear_Sq<int> sq;
    int a = 0;
    sq.InitList_Sq();
    for(int i = 0; i < 3000; i++)
    {
        sq.ListInsert(1, 5);
    }

    cout << sq.ListLength() << endl;
   /*
    sq.ListInsert(1, 6);
    sq.ListPrint();
    sq.PriorElem(5, a);

    sq.ListPrint();
    */
    return 1;
}