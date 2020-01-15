# Data Structure 연결 리스트(Linked List) - Double Linked List (lxxjn0)

## [lxxjn0_DoubleLinkedList.h](lxxjn0_DoubleLinkedList.h)

```cpp {numberLines: true}
#pragma once

#include <iostream>

using namespace std;

template <typename LData>
class Node {
   private:
    LData data;
    Node<LData>* next;  // 오른쪽 node를 가리키는 포인터 변수
    Node<LData>* prev;  // 왼쪽 node를 가리키는 포인터 변수

   public:
    LData GetData();
    Node<LData>* GetNext();
    Node<LData>* GetPrev();
    void SetData(LData data);
    void SetNext(Node<LData>* next);
    void SetPrev(Node<LData>* prev);
};

// 동적 할당을 기반으로 구현한 List인 Linked List
template <typename LData>
class DoubleLinkedList {
   private:
    Node<LData>* head;
    Node<LData>* cur;
    int numOfData;

   public:
    DoubleLinkedList();         // 생성자(초기화 진행)
    void LInsert(LData data, bool isInsertFront = false);   // 데이터 저장
    bool LFirst(LData* pdata);  // 첫번째 데이터 참조
    bool LNext(LData* pdata);   // 두번째 이후 데이터 참조
    bool LPrev(LData* pdata);   // 이전 데이터 참조
    LData LRemove();            // 참조한 데이터 삭제
    int LCount();               // 저장된 데이터의 수 반환
};

// DoubleLinkedList 클래스의 별명을 List로 설정(using은 typedef의 c++ 11 버전)
template <typename LData>
using List = DoubleLinkedList<LData>;
```

## [lxxjn0_DoubleLinkedList.cpp](lxxjn0_DoubleLinkedList.cpp)

```cpp {numberLines: true}
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
```

## [lxxjn0_DoubleLinkedListMain.cpp](lxxjn0_DoubleLinkedListMain.cpp)

```cpp {numberLines: true}
#include "lxxjn0_DoubleLinkedList.h"
#include "lxxjn0_DoubleLinkedList.cpp"

template <typename LData>
bool compare(LData d1, LData d2) {
    return d1 < d2;
}

// 저장된 데이터의 개수 출력
void PrintCurrentListSize(int size) {
    cout << "current data num: " << size << endl;
}

// 저장된 데이터 조회 및 출력
template <typename LData>
void PrintListElements(List<LData>& list, LData& data) {
    int nodeNum = list.LCount();

    if (list.LFirst(&data)) {
        cout << data << " ";

        for (int i = 0; i < nodeNum - 1; i++) {
            if (list.LNext(&data)) {
                cout << data << " ";
            }
        }

        for (int i = 0; i < nodeNum - 1; i++) {
            if (list.LPrev(&data)) {
                cout << data << " ";
            }
        }
    }
    cout << endl
         << endl;
}

// 선택한 데이터를 찾아서 삭제
template <typename LData>
void RemoveListElement(List<LData>& list, LData& data, LData target) {
    int nodeNum = list.LCount();

    if (nodeNum != ZERO) {
        list.LFirst(&data);
        if (data == target) {
            list.LRemove();
        }

        for (int i = 0; i < nodeNum - 1; i++) {
            list.LNext(&data);
            if (data == target) {
                list.LRemove();
            }
        }
    }
}

int main() {
    // List 생성 및 초기화
    List<int> list;
    int data;

    // 8개 데이터 저장
    for (int i = 1; i <= 8; i++) {
        list.LInsert(i);
    }

    // 저장된 데이터의 개수 출력
    PrintCurrentListSize(list.LCount());

    // 저장된 데이터 조회 및 출력
    PrintListElements(list, data);

    // 숫자 22를 탐색하여 모두 삭제
    RemoveListElement(list, data, 2);

    // 삭제 후 남은 데이터의 개수 출력
    PrintCurrentListSize(list.LCount());

    // 저장된 데이터 조회 및 출력
    PrintListElements(list, data);
}
```
