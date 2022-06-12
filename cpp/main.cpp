#include <iostream>
#include <string>

using namespace std;

int main() {
    string location; 
    cout << "Enter location to search weather : ";
    getline(cin, location);

    string request_url = "curl wttr.in/" + location;
    system(&request_url[0]);
}
