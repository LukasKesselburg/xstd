#include "List.hpp"
#include "List.cpp"
#include "ArrayList.hpp"
#include "ArrayList.cpp"
#include "LinkedList.hpp"
#include "LinkedList.cpp"
#include "DoubleLinkedList.hpp"
#include "DoubleLinkedList.cpp"

#include <iostream>
using std::cout;
using std::endl;

template <template<typename> class ListType>
void test_ListType()
{
    List<int> *test = new ListType<int>();
    test->insert(0, 4);
    test->insert(1, 5);
    test->insert(2, 6);
    test->insert(0, 3);
    test->insert(0, 2);
    test->insert(0, 1);
    cout << *test << endl;

    List<int> *test2 = new ListType<int>();
    test2->insert(0, test->removeAt(0));
    test2->insert(0, test->removeAt(1));
    test2->insert(0, test->removeAt(2));
    cout << *test << endl;
    cout << *test2 << endl;

    (*test)[0] = 10;
    (*test)[2] = 8;
    cout << *test << endl;

    List<int> *test3 = new ListType<int>(*test);
    cout << *test3 << endl;

    List<int> *test4 = new ListType<int>{7, 8, 9};
    cout << *test4 << endl;

    List<int> *test5 = new ListType<int>{};
    cout << *test5 << endl;

    // List<int>* test5 = new ListType<int>{20}; // initializer_list
    // List<int>* test6 = new ListType<int>(20); // Capacity: 20

    // cout << *test->capacity() << endl;
    // cout << *test4->capacity() << endl;
    // cout << *test5->capacity() << endl;
    // cout << *test6->capacity() << endl;

    List<char> *test_char = new ListType<char>();
    test_char->insert(0, 'o');
    test_char->insert(0, 'l');
    test_char->insert(0, 'l');
    test_char->insert(0, 'a');
    test_char->insert(0, 'H');
    cout << *test_char << endl;
    test_char->removeAt(4);
    char x = 'a';
    test_char->remove(x);
    cout << *test_char << endl;
}

int main()
{
    cout << endl << "ArrayList" << endl;
    test_ListType<ArrayList>();

    cout << endl << "LinkedList" << endl;
    test_ListType<LinkedList>();

    cout << endl << "DoubleLinkedList" << endl;
    test_ListType<DoubleLinkedList>();

    cout << "Done" << endl;

    return 0;
}

// cout << sizeof(int{0}) << endl;
// cout << sizeof((unsigned int){0}) << endl;
// cout << sizeof(long{0}) << endl;
// cout << sizeof((unsigned long){0}) << endl;
// cout << sizeof((long long){0}) << endl;
// cout << sizeof((unsigned long long){0}) << endl;
// cout << sizeof(float{0}) << endl;
// cout << sizeof(double{0}) << endl;
// cout << sizeof((long double){0}) << endl;