#pragma once

#include <iostream>
#define LIST_LEN 100

using namespace std;

// 배열을 기반으로 정의한 ArrayList 클래스
template <typename LData>
class ArrayList {
   private:
    LData arr[LIST_LEN];  // List의 저장소인 배열
    int numOfData;        // 저장된 데이터의 수
    int curPosition;      // 데이터 참조위치를 기록

   public:
    ArrayList();                // 생성자(초기화 진행)
    void LInsert(LData data);   // 데이터 저장
    bool LFirst(LData* pdata);  // 첫번째 데이터 참조
    bool LNext(LData* pdata);   // 두번째 이후 데이터 참조
    LData LRemove();            // 참조한 데이터 삭제
    int LCount();               // 저장된 데이터의 수 반환
};

// ArrayList 클래스의 별명을 List로 설정(using은 typedef의 c++ 11 버전)
template <typename LData>
using List = ArrayList<LData>;