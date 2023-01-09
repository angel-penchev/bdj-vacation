//
// Created by tsb on 12/29/2022.
//

#include "SkipListNode.h"

#include <utility>

SkipListNode::SkipListNode(std::string value, SkipListNode *next, SkipListNode *fastNext)
        : value(std::move(value)), next(next), fastNext(fastNext) {}

const std::string &SkipListNode::getValue() const {
    return value;
}

void SkipListNode::setValue(const std::string &value) {
    SkipListNode::value = value;
}

SkipListNode *SkipListNode::getNext() const {
    return next;
}

void SkipListNode::setNext(SkipListNode *next) {
    SkipListNode::next = next;
}

SkipListNode *SkipListNode::getFastNext() const {
    return fastNext;
}

void SkipListNode::setFastNext(SkipListNode *fastNext) {
    SkipListNode::fastNext = fastNext;
}
