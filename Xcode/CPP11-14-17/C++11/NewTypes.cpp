//
//  NewTypes.cpp
//  CPP11-14-17
//
//  Created by Fei Qiu on 2022/11/3.
//

#include "NewTypes.hpp"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

template<typename T>
void printTypeValue(const string& name, const T& v) {
    cout << name << " = " << v << endl;
}

template<typename T, size_t N>
void printArrayTypeValue(const string& name, const T(&v)[N]) {
    cout << name << " = ";
    for (int i = 0; i < N; ++i) {
        cout << v[i];
    }
    cout << endl;
}

void testNewTypes() {
    cout << "--------test case: C++11 new types--------" << endl;
    char16_t ch1 = u'q'; // basic character in 16-bit form
    char32_t ch2 = U'\U0000222B'; // universal character name in 32-bit form

    wchar_t title[] = L"Chief Astrogator"; // w_char string
    char16_t name[] = u"Felonia Ripova"; // char_16 string
    char32_t car[] = U"Humber Super Snipe"; // char_32 string

    printTypeValue("ch1", ch1);
    printTypeValue("ch2", ch2);
    printArrayTypeValue("title", title);
    printArrayTypeValue("name", name);
    printArrayTypeValue("car", car);

    cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';

    cout << R"+*("(Who wouldn't?)", she whispered.)+*" << endl;
    cout << "--------test case: C++11 new types ended.--------" << endl << endl;
}
