#include "List.hpp"
#include "List.cpp"
#include "ArrayList.hpp"
#include "ArrayList.cpp"

#include <iostream>
using std::cout;
using std::endl;

void test_ArrayList();

int main()
{
    test_ArrayList();

    cout << "Test" << endl;
    return 0;
}

void test_ArrayList()
{
    ArrayList<int> test;

    test.insert(0, 4);
    test.insert(1, 5);
    test.insert(2, 6);
    // test.insert(5, 7);
    test.insert(0, 3);
    test.insert(0, 2);
    test.insert(0, 1);

    ArrayList<int> test2;
    test2.insert(0, test.remove(0));
    test2.insert(0, test.remove(1));
    test2.insert(0, test.remove(2));
    cout << test << endl;
    cout << test2 << endl;
    cout << test.length() << endl;
    cout << test2.length() << endl;

    test[0] = 10;
    test[1] = 11;
    // test[3] = 11;
    test2[0] = 20;
    test2[1] = 21;
    cout << test << endl;
    cout << test2 << endl;

    ArrayList<int> test3(test);
    cout << test3 << endl;

    ArrayList<int> test4{7, 8, 9};
    cout << test4 << endl;

    ArrayList<char> test5(20);
    cout << test.capacity() << endl;
    cout << test4.capacity() << endl;
    cout << test5.capacity() << endl;
    cout << test5 << endl;

    ArrayList<char> test_char;
    test_char.insert(0, 'o');
    test_char.insert(0, 'l');
    test_char.insert(0, 'l');
    test_char.insert(0, 'a');
    test_char.insert(0, 'H');
    cout << test_char << endl;
    test_char.remove(4);
    cout << test_char << endl;
    char x = 'a';
    test_char.remove(x);
    cout << test_char << endl;
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