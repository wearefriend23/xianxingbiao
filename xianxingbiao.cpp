#include <iostream>
using namespace std;

#define MAXSIZE 100   // 最大长度
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType* elem;  // 指向数据元素的基地址
    int length;      // 线性表的当前长度
} SqList;

// 构造一个空的顺序表L
Status InitList_Sq(SqList& L) {
    L.elem = new ElemType[MAXSIZE];  // 为顺序表分配空间
    if (!L.elem) exit(OVERFLOW);     // 存储分配失败
    L.length = 0;  // 空表长度为0
    return OK;
}

// 获取顺序表中指定位置的元素
Status GetElem(SqList L, int i, ElemType& e) {
    if (i < 1 || i > L.length) return ERROR;  // 判断i值是否合理，若不合理，返回ERROR
    e = L.elem[i - 1];  // 第i-1的单元存储着第i个数据
    return OK;
}

Status LocateELem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e) return i + 1;
    return 0;
}

Status ListInsert_Sq(SqList& L, int i, ElemType e) {
    if (i<1 || i>L.length + 1) return ERROR;      //i值不合法
    if (L.length == MAXSIZE) return ERROR; //当前存储空间已满
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j]; //插入位置及之后的元素后移
    L.elem[i - 1] = e;             //将新元素e放入第i个位置
    ++L.length;                //表长增1
    return OK;
}

Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
    if ((i < 1) || (i > L.length)) return ERROR;  //i值不合法
    e = L.elem[i - 1];                        //将欲删除的元素保留在e中
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];  //被删除元素之后的元素前移
    --L.length;                  //表长减1
    return OK;
}
int main() {
    SqList L;
    int i;
    ElemType e;

    if (InitList_Sq(L)) cout << "成功初始化顺序表！" << endl;
    L.length = 10;
    for (i = 0; i < L.length; i++) L.elem[i] = i + 1;
    cout << "当前顺序表的元素有：";
    for (i = 0; i < L.length; i++) cout << L.elem[i] << " ";
    cout << "\n请输入需要找的元素的位序：";
    cin >> i;
    if (GetElem(L, i, e)) cout << "位序为" << i << "的元素的值是：" << e << endl;
    else cout << "没有找到这个元素！" << endl;

    cout << "请输入要查找的元素:";
    cin >> e;
    cout << "你要查找的元素位于：" << LocateELem(L, e) << endl;

    cout << "请输入要插入的位置:";
    cin >> i;
    cout << "请输入要插入的元素:";
    cin >> e;
    if (ListInsert_Sq(L, i, e))
        cout << "插入成功\n";
    else
        cout << "插入失败\n";

    cout << "请输入要删除的位置:";
    cin >> i;
    if (ListInsert_Sq(L, i, e))
        cout << "删除成功\n";
    else
        cout << "删除失败\n";
    // 释放动态分配的内存，防止内存泄漏
    delete[] L.elem;
    return 0;
}
