# Data Structure 연결 리스트(Linked List) - Array List (lxxjn0)

## [lxxjn0_ArrayList.h](lxxjn0_ArrayList.h)

```cpp {numberLines: true}
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
```

## [lxxjn0_ArrayList.cpp](lxxjn0_ArrayList.cpp)

```cpp {numberLines: true}
#include "lxxjn0_ArrayList.h"

#define ZERO 0

template <typename LData>
ArrayList<LData>::ArrayList() {
    this->numOfData = ZERO;  // List에 저장된 데이터의 수는 0
    this->curPosition = -1;  // 현재 List의 그 어떠한 위치도 가리키지 않음
}

template <typename LData>
void ArrayList<LData>::LInsert(LData data) {
    // 더 이상 저장할 공간이 없다면
    if (this->LCount() > LIST_LEN) {
        cout << "저장이 불가능합니다." << endl;
        return;
    }
    // 현재 데이터의 마지막 위치에 입력받은 data를 저장하고 데이터 저장 개수 1 증가
    this->arr[numOfData++] = data;
}

template <typename LData>
bool ArrayList<LData>::LFirst(LData* pdata) {
    // 저장된 데이터가 존재하지 않는다면
    if (this->numOfData == ZERO) {
        return false;
    }

    // List의 가장 첫번째 인덱스로 curPosition을 초기화
    this->curPosition = ZERO;
    *pdata = this->arr[this->curPosition];  // 첫번째 데이터의 값을 반환
    return true;
}

template <typename LData>
bool ArrayList<LData>::LNext(LData* pdata) {
    // List에 저장된 데이터의 개수 범위를 초과하는 경우
    if (this->curPosition >= this->numOfData - 1) {
        return false;
    }

    // curPostion을 1 증가시키고, 해당 위치의 데이터를 반환
    *pdata = this->arr[++(this->curPosition)];
    return true;
}

template <typename LData>
LData ArrayList<LData>::LRemove() {
    LData tmpLData = this->arr[this->curPosition];  // 삭제할 데이터를 임시 저장

    // 삭제할 위치 이후의 데이터들을 모두 한칸씩 앞으로 이동시킴
    for (int i = this->curPosition; i < this->numOfData - 1; i++) {
        this->arr[i] = this->arr[i + 1];
    }
    this->numOfData--;    // List 크기를 1 감소
    this->curPosition--;  // 참조할 위치를 1 감소(삭제한 다음 데이터를 가리킴)
    return tmpLData;      // 삭제한 데이터를 반환
}

template <typename LData>
int ArrayList<LData>::LCount() {
    return this->numOfData;  // List의 크기를 반환
}
```

## [lxxjn0_ArrayListMain.cpp](lxxjn0_ArrayListMain.cpp)

```cpp {numberLines: true}
#include "lxxjn0_ArrayList.h"
#include "lxxjn0_ArrayList.cpp"

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
