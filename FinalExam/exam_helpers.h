#ifndef EXAM_HELPERS_H
#define EXAM_HELPERS_H

#include <iostream>

// TODON'T(student): add anything you want graded to this file (we won't look at it)
// TODON'T(student): submit this file (we won't look at it)

#define DEBUG(X) std::cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " := " << X << std::endl;

#define INFO(X) std::cout << #X << " := " << X << std::endl;

#endif  // EXAM_HELPERS_H