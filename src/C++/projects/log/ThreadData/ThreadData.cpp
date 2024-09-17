#include "ThreadData.hpp"

ThreadData::ThreadData(int id) {
    this->id = id;
    this->status200 = 0;
    for (int i = 0; i < 24; i++) {
        this->sumHour[i] = 0;
    }
}

ThreadData::~ThreadData() {
}

void ThreadData::addStatus200() {
    this->status200++;
}

int ThreadData::getStatus200() {
    return this->status200;
}

void ThreadData::addSumHour(int index) {
    this->sumHour[index]++;
}
void ThreadData::getSumHour(int rValue[24]) {
    for (int i = 0; i < 24; i++) {
        rValue[i] = this->sumHour[i];
    }
}

void ThreadData::setId(int id) {
    this->id = id;
}

int ThreadData::getId() {
    return this->id;
}

void ThreadData::setStr(std::string st) {
    this->str = st;
}

std::string ThreadData::getStr() {
    return this->str;
}