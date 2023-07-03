#include <iostream>
#include <string>

#define cout std::cout
#define endl std::endl

class Sign
{
public:
    using string = std::string;

    explicit Sign(string message, int lineLength) : message(message), lineLength(lineLength){};

    int numberOfLines() { return message.length() / lineLength + (message.length() % lineLength == 0 ? 0 : 1); }

    string getLines()
    {
        string bufString = message;
        for (int i = 0; i < numberOfLines() - 1; i++)
            bufString.insert((i + 1) * lineLength + i, ";");
        return bufString;
    }
private:
    string message;
    int lineLength;
};

int main()
{
    cout << "TEST 1\n";
    Sign *sign1 = new Sign("AAABBB23", 3);
    cout << sign1->numberOfLines() << endl;
    cout << sign1->getLines() << endl;
    cout << sign1->getLines() << endl;

    cout << "\nTEST 2\n";
    Sign *sign2 = new Sign("ABCD", 10);
    cout << sign2->numberOfLines() << endl;
    cout << sign2->getLines() << endl;

    cout << "\nTEST 3\n";
    Sign *sign3 = new Sign("ABCDEF", 6);
    cout << sign3->numberOfLines() << endl;
    cout << sign3->getLines() << endl;

    cout << "\nTEST 4\n";
    Sign *sign4 = new Sign("", 4);
    cout << sign4->numberOfLines() << endl;
    cout << sign4->getLines() << endl;

    return 0;
}
