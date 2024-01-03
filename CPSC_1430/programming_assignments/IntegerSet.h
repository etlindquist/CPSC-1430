#include <string>
using namespace std;

class IntegerSet{
    public:
    IntegerSet();
    IntegerSet(int[], int);
    int* unionOfSets(IntegerSet*);
    int* intersectionOfSets(IntegerSet*);
    int insertElement();
    void deleteElement(int);
    void printSet();
    bool isEqualTo(IntegerSet*);
    void emptySet();
    void inputSet();
    int* getSet();

    private:
    bool validEntry(string);
    int* a;
};