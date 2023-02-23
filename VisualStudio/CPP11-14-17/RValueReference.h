#pragma once
void testRValueReference();
int testMoveConstructor();
int testMoveAssignmentOperator();

class Useless
{
private:
    int n; // number of elements
    char* pc; // pointer to data
    static int ct; // number of objects
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless& f); // regular copy constructor
    Useless(Useless&& f); // move constructor
    ~Useless();
    Useless operator+(const Useless& f)const;
    Useless& operator=(const Useless& f); // copy assignment
    Useless& operator=(Useless&& f); // move assignment
    void ShowData() const;
};

