#include "Lambda.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long Size = 390000L;
const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int testLambda()
{
    using std::cout;
    std::vector<int> numbers(Size1);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);

    // using function pointers
    cout << "Sample size = " << Size1 << '\n';
    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";
    // increase number of numbers
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size2 << '\n';

    // using a functor
    class f_mod
    {
    private:
        int dv;
    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) { return x % dv == 0; }
    };
    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << "\n\n";
    // increase number of numbers again
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size3 << '\n';

    // using lambdas
    count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    return 0;
}

int testLambda2() {
    using std::cout;
    std::vector<int> numbers(Size);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size << '\n';
    // using lambdas
    int count3 = std::count_if(numbers.begin(), numbers.end(),
        [](int x) {return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&count13](int x) {count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    // using a single lambda
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
        [&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    return 0;
}
