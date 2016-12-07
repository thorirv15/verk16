#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    void setName(string name);
    void setType(string type);
    void setBuiltYear(int builtYear);
    void setOriginalOrDeveloped(string OriginalOrDeveloped);
    string getName() const;
    string getType() const;
    int getBuiltYear() const;
    string getOriginalOrDeveloped() const;

private:
    string _name;
    string _type;
    int    _builtYear;
    string _originalOrDeveloped;

};

#endif // COMPUTER_H
