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