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