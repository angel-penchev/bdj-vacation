//
// Created by tsb on 12/29/2022.
//

#include "SkipList.h"

SkipList::SkipList(std::vector<std::string> cities, std::map<std::string, std::string> directConnections) {
    this->nodesCount = cities.size();

    this->first = new SkipListNode(cities[0]);
    SkipListNode *current = this->first;

    for (size_t i = 1; i < cities.size(); i++) {
        current->setNext(new SkipListNode(cities[i]));
        current = current->getNext();
    }
    this->last = current;

    current = this->first;
    while (current != nullptr) {
        if (directConnections.find(current->getValue()) != directConnections.end()) {
            std::string directNeighbour = directConnections[current->getValue()];
            SkipListNode *fastNeighbour = this->first;
            while (fastNeighbour->getValue() != directNeighbour) {
                fastNeighbour = fastNeighbour->getNext();
            }
            current->setFastNext(fastNeighbour);
        }
        current = current->getNext();
    }
}

size_t SkipList::getNodesCount() const {
    return nodesCount;
}

void SkipList::setNodesCount(size_t nodesCount) {
    SkipList::nodesCount = nodesCount;
}

SkipListNode *SkipList::getFirst() const {
    return first;
}

void SkipList::setFirst(SkipListNode *first) {
    SkipList::first = first;
}

SkipListNode *SkipList::getLast() const {
    return last;
}

void SkipList::setLast(SkipListNode *last) {
    SkipList::last = last;
}

//SkipList::SkipList(const SkipList &other) {
//}