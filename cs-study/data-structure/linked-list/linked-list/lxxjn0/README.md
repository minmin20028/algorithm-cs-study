# Data Structure 연결 리스트(Linked List) - Linked List (lxxjn0)

## [lxxjn0_LinkedList.h](lxxjn0_LinkedList.h)

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

// 동적 할당을 기반으로 구현한 List인 Linked List
template <typename LData>
class LinkedList {
   private:
    Node<LData>* head;
    Node<LData>* cur;
    Node<LData>* before;
    int numOfData;
    bool (*comp)(LData d1, LData d2);

    void FInsert(LData data);
    void SInsert(LData data);

   public:
    LinkedList();               // 생성자(초기화 진행)
    void LInsert(LData data);   // 데이터 저장
    bool LFirst(LData* pdata);  // 첫번째 데이터 참조
    bool LNext(LData* pdata);   // 두번째 이후 데이터 참조
    LData LRemove();            // 참조한 데이터 삭제
    int LCount();               // 저장된 데이터의 수 반환
    void SetSortRule(bool (*comp)(LData d1, LData d2));
};

// LinkedList 클래스의 별명을 List로 설정(using은 typedef의 c++ 11 버전)
template <typename LData>
using List = LinkedList<LData>;
```

## [lxxjn0_LinkedList.cpp](lxxjn0_LinkedList.cpp)

```cpp {numberLines: true}
#include "lxxjn0_LinkedList.h"

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
LinkedList<LData>::LinkedList() {
    this->head = new Node<LData>;  // dummy node의 생성
    this->head->SetNext(NULL);
    this->comp = NULL;
    this->numOfData = ZERO;
}

// 정렬 기준이 마련되지 않아 head에 node를 삽입하는 함수
template <typename LData>
void LinkedList<LData>::FInsert(LData data) {
    Node<LData>* newNode = new Node<LData>;  // 새 node 생성
    newNode->SetData(data);                  // 새 node에 데이터 저장

    newNode->SetNext(this->head->GetNext());  // 새 node가 다른 node를 가리키게 함
    this->head->SetNext(newNode);             // dummy node가 새 node를 가리키게 함

    this->numOfData++;  // 저장된 node의 수를 하나 증가
}

template <typename LData>
void LinkedList<LData>::SInsert(LData data) {
    Node<LData>* newNode = new Node<LData>;  // 새 node 생성
    Node<LData>* prev = this->head;          // prev 는 dummy node를 가리킴
    newNode->SetData(data);                  // 새 node에 데이터 저장

    // 새 node가 들어갈 위치를 찾기 위한 반복문
    while ((prev->GetNext() != NULL) && (this->comp(data, prev->GetNext()->GetData()) != true)) {
        prev = prev->GetNext();  // 다음 node로 이동
    }

    newNode->SetNext(prev->GetNext());  // 새 node의 뒤를 연결
    prev->SetNext(newNode);             // 새 node의 앞을 연결

    this->numOfData++;  // 저장된 node의 수를 하나 증가
}

template <typename LData>
void LinkedList<LData>::LInsert(LData data) {
    if (this->comp == NULL) {  // 정렬 기준이 마련되지 않은 경우
        FInsert(data);         // head에 node를 추가
    } else {                   // 정렬 기준이 마련된 경우
        SInsert(data);         // 정렬 기준에 의거하여 node를 추가
    }
}

// dummy node 바로 뒤에 위치하는 첫 번째 node의 데이터 반환
template <typename LData>
bool LinkedList<LData>::LFirst(LData* pdata) {
    if (this->head->GetNext() == NULL) {  // dummy node가 NULL을 가리킨다면
        return false;                     // node가 존재하지 않음
    }

    this->before = this->head;            // before은 dummy node를 가리키게 함
    this->cur = this->before->GetNext();  // cur은 첫 번째 node를 가리키게 함

    *pdata = this->cur->GetData();  // 첫 번째 node의 데이터 반환
    return true;
}

template <typename LData>
bool LinkedList<LData>::LNext(LData* pdata) {
    if (this->cur->GetNext() == NULL) {  // 첫 번째 node가 NULL을 가리킨다면
        return false;                    // node가 더 이상 존재하지 않는다
    }

    this->before = this->cur;          // cur이 가리키던 것을 before가 가리킴
    this->cur = this->cur->GetNext();  // cur은 그 다음 node를 가리킴

    *pdata = this->cur->GetData();  // cur이 가리키는 node의 데이터를 반환
    return true;
}

template <typename LData>
LData LinkedList<LData>::LRemove() {
    Node<LData>* rpos = this->cur;  // 삭제 대상의 주소 값을 rpos에 저장
    LData rdata = rpos->GetData();  // 삭제 대상의 데이터를 rdata에 저장

    this->before->SetNext(this->cur->GetNext());  // 삭제 대상을 List에서 제거
    this->cur = this->before;                     // cur이 가리키는 위치를 재조정

    free(rpos);         // List에서 제거된 node 소멸
    this->numOfData--;  // 저장된 node의 수 하나 감소
    return rdata;       // 제거된 node의 데이터 반환
}

template <typename LData>
int LinkedList<LData>::LCount() {
    return this->numOfData;
}

template <typename LData>
void LinkedList<LData>::SetSortRule(bool (*comp)(LData d1, LData d2)) {
    this->comp = comp;
}
```

## [lxxjn0_LinkedListMain.cpp](lxxjn0_LinkedListMain.cpp)

```cpp {numberLines: true}
#include "lxxjn0_LinkedList.h"
#include "lxxjn0_LinkedList.cpp"

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
    // 첫번째 데이터 조회
    if (list.LFirst(&data)) {
        cout << data << " ";

        // 두번째 이후 데이터 조회
        while (list.LNext(&data)) {
            cout << data << " ";
        }
    }
    cout << endl
         << endl;
}

// 선택한 데이터를 찾아서 삭제
template <typename LData>
void RemoveListElement(List<LData>& list, LData& data, LData target) {
    // target에 해당하는 데이터를 찾아서 삭제
    if (list.LFirst(&data)) {
        if (data == target) {
            list.LRemove();
        }

        while (list.LNext(&data)) {
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

    // List의 정렬 기준 등록
    list.SetSortRule(compare);

    // 5개 데이터 저장
    list.LInsert(11);
    list.LInsert(22);
    list.LInsert(33);
    list.LInsert(11);
    list.LInsert(22);

    // 저장된 데이터의 개수 출력
    PrintCurrentListSize(list.LCount());

    // 저장된 데이터 조회 및 출력
    PrintListElements(list, data);

    // 숫자 22를 탐색하여 모두 삭제
    RemoveListElement(list, data, 22);

    // 삭제 후 남은 데이터의 개수 출력
    PrintCurrentListSize(list.LCount());

    // 저장된 데이터 조회 및 출력
    PrintListElements(list, data);
}
```
