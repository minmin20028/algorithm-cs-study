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