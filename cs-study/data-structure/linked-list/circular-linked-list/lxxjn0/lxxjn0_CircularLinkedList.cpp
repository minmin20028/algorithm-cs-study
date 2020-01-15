#include "lxxjn0_CircularLinkedList.h"

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
void Node<LData>::SetData(LData data) {
    this->data = data;
}

template <typename LData>
void Node<LData>::SetNext(Node<LData>* next) {
    this->next = next;
}

template <typename LData>
CircularLinkedList<LData>::CircularLinkedList() {
    this->tail = NULL;
    this->cur = NULL;
    this->before = NULL;

    this->numOfData = ZERO;
}

// isInsertFront 옵션에 따라 head 또는 tail에 node를 삽입하는 함수
template <typename LData>
void CircularLinkedList<LData>::LInsert(LData data, bool isInsertFront) {
    Node<LData>* newNode = new Node<LData>;  // 새 node 생성
    newNode->SetData(data);                  // 새 node에 데이터 저장

    if (this->tail == NULL) {
        this->tail = newNode;       // tail이 새 node를 가리키게 함
        newNode->SetNext(newNode);  // 새 node가 자기 자신을 가리키게 함
    } else {
        newNode->SetNext(this->tail->GetNext());  // 새 node가 tail의 next를 가리키게 함
        this->tail->SetNext(newNode);             // tail에 새 node를 연결

        if (!isInsertFront) {
            this->tail = newNode;  // tail이 새 node를 가리키게 함
        }
    }

    this->numOfData++;  // 저장된 node의 수를 하나 증가
}

// dummy node 바로 뒤에 위치하는 첫 번째 node의 데이터 반환
template <typename LData>
bool CircularLinkedList<LData>::LFirst(LData* pdata) {
    if (this->tail == NULL) {  // tail이 NULL을 가리킨다면
        return false;          // node가 존재하지 않음
    }

    this->before = this->tail;          // before은 tail을 가리키게 함
    this->cur = this->tail->GetNext();  // cur은 head를 가리키게 함

    *pdata = this->cur->GetData();  // 첫 번째 node의 데이터 반환
    return true;
}

template <typename LData>
bool CircularLinkedList<LData>::LNext(LData* pdata) {
    if (this->tail == NULL) {  // 저장된 node가 없다면
        return false;
    }

    this->before = this->cur;          // cur이 가리키던 것을 before가 가리킴
    this->cur = this->cur->GetNext();  // cur은 그 다음 node를 가리킴

    *pdata = this->cur->GetData();  // cur이 가리키는 node의 데이터를 반환
    return true;
}

template <typename LData>
LData CircularLinkedList<LData>::LRemove() {
    Node<LData>* rpos = this->cur;  // 삭제 대상의 주소 값을 rpos에 저장
    LData rdata = rpos->GetData();  // 삭제 대상의 데이터를 rdata에 저장

    if (rpos == this->tail) {                       // 삭제 대상이 tail을 가리키는 경우
        if (this->tail == this->tail->GetNext()) {  // 마지막 한 개 남은 node였다면
            this->tail = NULL;
        } else {
            this->tail = this->before;
        }
    }

    this->before->SetNext(this->cur->GetNext());  // 삭제 대상을 List에서 제거
    this->cur = this->before;                     // cur이 가리키는 위치를 재조정

    free(rpos);         // List에서 제거된 node 소멸
    this->numOfData--;  // 저장된 node의 수 하나 감소
    return rdata;       // 제거된 node의 데이터 반환
}

template <typename LData>
int CircularLinkedList<LData>::LCount() {
    return this->numOfData;
}