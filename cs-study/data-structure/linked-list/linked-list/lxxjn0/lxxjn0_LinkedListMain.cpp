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