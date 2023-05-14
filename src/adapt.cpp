#include "adapt.h"

int BinarySearch::Do(std::vector<int> &v, int tag) {
    int index = -1;
    int l = 0, r = v.size() - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (v[mid] < tag) {
            l = mid + 1;
        } else if (v[mid] > tag) {
            r = mid - 1;
        } else {
            index = mid;
            break;
        }
    }
    return index;
}
