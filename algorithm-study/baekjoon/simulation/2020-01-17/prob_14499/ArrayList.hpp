//
//  ArrayList.hpp
//  ArrayList
//
//  Created by 박민건 on 2020/01/12.
//  Copyright © 2020 박민건. All rights reserved.
//

#pragma once

#define LIST_LEN 5

typedef int LData;

typedef class __ArrayList{
private:
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
public:
    __ArrayList();
    void LInsert(LData data);
    bool LFirst(LData* pdata);
    bool LNext(LData* pdata);
    bool LIndex(int index,LData* pdata);
    LData LRemove();
    LData LIRemove(int index);
    int LCount();
}ArrayList;

typedef ArrayList List;
