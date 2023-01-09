//
// Created by tsb on 12/29/2022.
//

#ifndef BDJ_VACATION_SKIPLIST_H
#define BDJ_VACATION_SKIPLIST_H


#include <cstddef>
#include <vector>
#include <map>
#include <queue>
#include "SkipListNode.h"

class SkipList {
    std::size_t nodesCount{};
    SkipListNode *first{};
    SkipListNode *last{};

public:
    explicit SkipList(std::vector<std::string> cities = {}, std::map<std::string, std::string> directConnections = {});

    SkipList(const SkipList &other);

    SkipList & operator=(const SkipList &other);

    ~SkipList();

    static std::vector<std::string> findQuickest(const SkipListNode *treeNode, std::queue<std::string> mustVisit, std::vector<std::string> path = {});

    size_t getNodesCount() const;

    void setNodesCount(size_t nodesCount);

    SkipListNode *getFirst() const;

    void setFirst(SkipListNode *first);

    SkipListNode *getLast() const;

    void setLast(SkipListNode *last);

    void copy(const SkipList &other);

    void clear();
};

#endif //BDJ_VACATION_SKIPLIST_H
