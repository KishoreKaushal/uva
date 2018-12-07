#include <iostream>
#include <list>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

int main()
{
    std::list<int> list1 = { 5,9,0,1,3 };
    std::list<int> list2 = { 8,7,2,6,4 };

    list1.sort();
    list2.sort();
    std::cout << "list1:  " << list1 << "\n";
    std::cout << "list2:  " << list2 << "\n";
    list1.merge(list2);
    std::cout << "merged: " << list1 << "\n";
}

/*************OUTPUT*****************/
/* list1:   0 1 3 5 9               */
/* list2:   2 4 6 7 8               */
/* merged:  0 1 2 3 4 5 6 7 8 9     */
/************************************/
