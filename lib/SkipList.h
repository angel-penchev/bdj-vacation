//
// Created by tsb on 12/29/2022.
//

#ifndef BDJ_VACATION_SKIPLIST_H
#define BDJ_VACATION_SKIPLIST_H


#include <cstddef>
#include <vector>
#include <map>
#include "SkipListNode.h"

class SkipList {
    std::size_t nodesCount;
    SkipListNode *first;
    SkipListNode *last;

public:
    explicit SkipList(std::vector<std::string> cities = {}, std::map<std::string, std::string> directConnections = {});

    size_t getNodesCount() const;

    void setNodesCount(size_t nodesCount);

    SkipListNode *getFirst() const;

    void setFirst(SkipListNode *first);

    SkipListNode *getLast() const;

    void setLast(SkipListNode *last);
};

#endif //BDJ_VACATION_SKIPLIST_H
