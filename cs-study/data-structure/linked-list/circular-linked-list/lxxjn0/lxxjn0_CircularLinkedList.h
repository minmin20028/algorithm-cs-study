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