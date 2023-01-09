//
// Created by tsb on 12/29/2022.
//
#include <string>

#ifndef BDJ_VACATION_SKIPLISTNODE_H
#define BDJ_VACATION_SKIPLISTNODE_H


class SkipListNode {
    std::string value;
    SkipListNode *next;
    SkipListNode *fastNext;

public:
    SkipListNode(std::string value, SkipListNode *next = nullptr, SkipListNode *fastNext = nullptr);

    const std::string &getValue() const;

    void setValue(const std::string &value);

    SkipListNode *getNext() const;

    void setNext(SkipListNode *next);

    SkipListNode *getFastNext() const;

    void setFastNext(SkipListNode *fastNext);
};


#endif //BDJ_VACATION_SKIPLISTNODE_H
