#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    void setName(string name);
    void setBuilt(bool built);
    void setBuiltYear(int builtYear);
    void setWeight(int weight);
    string getName() const;
    bool getBuilt() const;
    int getBuiltYear() const;
    int getWeight() const;

private:
    string _name;
    bool   _built;
    int    _builtYear;
    int    _weight;

};

#endif // COMPUTER_H
