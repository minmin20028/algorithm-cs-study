# Data Structure 연결 리스트(Linked List) - Circular Linked List (lxxjn0)

## [lxxjn0_CircularLinkedList.h](lxxjn0_CircularLinkedList.h)

```cpp {numberLines: true}
#pragma once

#include <iostream>

using namespace std;

template <typename LData>
class Node {
   private:
    LData data;
    Node<LData>* next;

   public:
    LData GetData();
    Node<LData>* GetNext();
    void SetData(LData data);
    void SetNext(Node<LData>* next);
};

// List의 모든 node가 연결되어 있는 Circular Linked List
template <typename LData>
class CircularLinkedList {
   private:
    Node<LData>* tail;
    Node<LData>* cur;
    Node<LData>* before;
    int numOfData;

   public:
    CircularLinkedList();  // 생성자(초기화 진행)
    // 데이터 저장 (isInsertFront가 true일 경우 head에 node를 추가)// 데이터 저장 (isInsertFront가 true일 경우 head에 node를 추가)
    void LInsert(LData data, bool isInsertFront = false);
    bool LFirst(LData* pdata);  // 첫번째 데이터 참조
    bool LNext(LData* pdata);   // 두번째 이후 데이터 참조
    LData LRemove();            // 참조한 데이터 삭제
    int LCount();               // 저장된 데이터의 수 반환
};

// CircularLinkedList 클래스의 별명을 List로 설정(using은 typedef의 c++ 11 버전)
template <typename LData>
using List = CircularLinkedList<LData>;
```

## [lxxjn0_CircularLinkedList.cpp](lxxjn0_CircularLinkedList.cpp)

```cpp {numberLines: true}
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
```

## [lxxjn0_CircularLinkedListMain.cpp](lxxjn0_CircularLinkedListMain.cpp)

```cpp {numberLines: true}
#include "lxxjn0_CircularLinkedList.h"
#include "lxxjn0_CircularLinkedList.cpp"

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

    // 첫번째 데이터 조회
    if (list.LFirst(&data)) {
        cout << data << " ";

        for (int i = 0; i < nodeNum - 1; i++) {
            if (list.LNext(&data)) {
                cout << data << " ";
            }
        }
    }
}

// 선택한 데이터를 찾아서 삭제
template <typename LData>
void RemoveListElement(List<LData>& list, LData& data, LData target) {
    int nodeNum = list.LCount();

    if (nodeNum != 0) {
        list.LFirst(&data);
        if (data % 2 == 0) {
            list.LRemove();
        }

        for (int i = 0; i < nodeNum - 1; i++) {
            list.LNext(&data);
            if (data % 2 == 0) {
                list.LRemove();
            }
        }
    }
}

int main() {
    // List 생성 및 초기화
    List<int> list;
    int data;

    // 5개 데이터 저장
    list.LInsert(3);
    list.LInsert(4);
    list.LInsert(5);
    list.LInsert(2, true);
    list.LInsert(1, true);

    // 저장된 데이터의 개수 출력
    PrintCurrentListSize(list.LCount());

    // 저장된 데이터 조회 및 출력
    for (int i = 0; i < 3; i++) {
        PrintListElements(list, data);
    }

    cout << endl
         << endl;

    // 2의 배수를 탐색하여 모두 삭제
    RemoveListElement(list, data, 2);

    // 삭제 후 남은 데이터의 개수 출력
    PrintCurrentListSize(list.LCount());

    // 저장된 데이터 조회 및 출력
    PrintListElements(list, data);
}
```
