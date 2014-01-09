/* basicsearch.cpp
 * 
 * linear serach and binary search
 */

#include <iostream>
#include <vector>
#include "../chapter2/myList.h"

template <typename ET>
long linearSearch(const std::vector<ET>& v, const ET& elem, bool& found, int& loc) {
    long count = 0;
    found = false;
    for (loc = 0; loc < v.size(); loc++) {
        count++;
        if (v[loc] == elem) {
            found = true;
            return count;
        }
    }
    return count;
}

template <typename ET>
long linearLinkedSearch(MyList<ET> const& list, ET const& elem, bool& found, int& loc) {
    long count = 0;
    found = false;
    for (loc = 0; loc < list.size(); loc++) {
        count++;
        if (list.getAt(loc) == elem) {
            found = true;
            return count;
        }
    }
    return count;
}

template <typename ET>
long binarySearch(const std::vector<ET>& v, const ET& elem, bool& found, int& loc) {
    long count = 0;
    found = false;
    int low = 0;
    int high = v.size() - 1;
    
    while (!found && low <= high) {
        loc = (high + low) / 2;
        count++;
        if (v[loc] == elem) 
            found = true;
        else if (v[loc] > elem) 
            high = loc - 1;
        else 
            low = loc + 1;
    }
    return count;
}

int main() {
    std::vector<int> vec;
    MyList<int> list;
    int elem = 874;
    bool found;
    int loc;
    long count;
    
    for (int i = 0; i < 1000; i++) {
        vec.push_back(i);
        list.pushBack(i);
    }

    count = binarySearch<int>(vec, elem, found, loc);
    std::cout << "binary search result: " << found << " location: " << loc << " count: " << count << std::endl;

    count = linearSearch<int>(vec, elem, found, loc);
    std::cout << "linear search result: " << found << " location: " << loc << " count: " << count << std::endl;

    count = linearLinkedSearch<int>(list, elem, found, loc);
    std::cout << "linear linked search result: " << found << " location: " << loc << " count: " << count << std::endl;

    return 0;
}

