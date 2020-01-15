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