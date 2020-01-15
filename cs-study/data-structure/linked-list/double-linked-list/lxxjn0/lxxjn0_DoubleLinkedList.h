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