#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string data[5] = {
        "first name",
        "last name",
        "nick name",
        "phone number",
        "darkest secret"
    };

    string input;
    cout << "Please enter the information:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << setfill(' ') << setw(15);
        cout << data[i] << " > ";
        cin >> input;
    }
}




