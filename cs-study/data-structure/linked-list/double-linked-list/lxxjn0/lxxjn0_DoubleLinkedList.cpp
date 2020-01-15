#include "lxxjn0_DoubleLinkedList.h"

#define ZERO 0

template <typename LData>
LData Node<LData>::GetData() {
    return this->data;
}

template <typename LData>
Node<LData>* Node<LData>::GetNext() {
    return this->next;
}

template <typename LData>
Node<LData>* Node<LData>::GetPrev() {
    return this->prev;
}

template <typename LData>
void Node<LData>::SetData(LData data) {
    this->data = data;
}

template <typename LData>
void Node<LData>::SetNext(Node<LData>* next) {
    this->next = next;
}

template <typename LData>
void Node<LData>::SetPrev(Node<LData>* prev) {
    this->prev = prev;
}

template <typename LData>
DoubleLinkedList<LData>::DoubleLinkedList() {
    this->head = NULL;
    this->numOfData = ZERO;
}

template <typename LData>
void DoubleLinkedList<LData>::LInsert(LData data, bool isInsertFront) {
    Node<LData>* newNode = new Node<LData>;
    newNode->SetData(data);

    newNode->SetNext(this->head);

    if (this->head == NULL) {
        this->head = newNode;
        newNode->SetNext(newNode);
        newNode->SetPrev(newNode);
    } else {
        newNode->SetNext(this->head);
        newNode->SetPrev(this->head->GetPrev());
        this->head->GetPrev()->SetNext(newNode);
        this->head->SetPrev(newNode);

        if (isInsertFront) {
            this->head = newNode;
        }
    }

    this->numOfData++;
}

template <typename LData>
bool DoubleLinkedList<LData>::LFirst(LData* pdata) {
    if (this->head == NULL) {
        return false;  // node가 존재하지 않음
    }

    this->cur = this->head;

    *pdata = this->cur->GetData();  // 첫 번째 node의 데이터 반환
    return true;
}

template <typename LData>
bool DoubleLinkedList<LData>::LNext(LData* pdata) {
    if (this->head == NULL) {
        return false;
    }

    this->cur = this->cur->GetNext();  // cur은 그 다음 node를 가리킴

    *pdata = this->cur->GetData();  // cur이 가리키는 node의 데이터를 반환
    return true;
}

template <typename LData>
bool DoubleLinkedList<LData>::LPrev(LData* pdata) {
    if (this->head == NULL) {
        return false;
    }

    this->cur = this->cur->GetPrev();

    *pdata = this->cur->GetData();
    return true;
}

template <typename LData>
LData DoubleLinkedList<LData>::LRemove() {
    Node<LData>* rpos = this->cur;  // 삭제 대상의 주소 값을 rpos에 저장
    LData rdata = rpos->GetData();  // 삭제 대상의 데이터를 rdata에 저장

    if (rpos == this->head) {
        if (this->head == this->head->GetNext()) {
            this->head = NULL;
        } else {
            this->head = this->head->GetPrev();
        }
    }

    this->cur->GetPrev()->SetNext(this->cur->GetNext());
    this->cur->GetNext()->SetPrev(this->cur->GetPrev());
    this->cur = this->cur->GetPrev();

    free(rpos);         // List에서 제거된 node 소멸
    this->numOfData--;  // 저장된 node의 수 하나 감소
    return rdata;       // 제거된 node의 데이터 반환
}

template <typename LData>
int DoubleLinkedList<LData>::LCount() {
    return this->numOfData;
}