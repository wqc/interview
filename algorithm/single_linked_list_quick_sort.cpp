/*************************************************************************
	> File Name: algorithm/single_linked_list_quick_sort.cpp
	> Author: sigh1988
	> Mail: sigh1988@qq.com
	> Created Time: Tue Apr 17 13:41:24 2018
 ************************************************************************/
struct Node {
    int key;
    Node* next;
    Node(int nKey, Node* pNext)
        : key(nKey)
        , next(pNext)
    {}
};

Node* GetPartion(Node* pBegin, Node* pEnd) {
    int key = pBegin->key;
    Node* p = pBegin;
    Node* q = p->next;
    while(q != pEnd) {
        if(q->key < key){
            p = p->next;
            swap(p->key,q->key);
        }
        q = q->next;
    }
    swap(p->key,pBegin->key);
    return p;
}

void QuickSort(Node* pBeign, Node* pEnd) {
    if (pBeign != pEnd && pBegin->next != pEnd) {
        Node* partion = GetPartion(pBeign,pEnd);
        QuickSort(pBeign,partion);
        QuickSort(partion->next,pEnd);
    }
}
