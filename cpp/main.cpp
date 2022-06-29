#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void echoBanner()
{
    ifstream f("banner.txt");

    if (f.is_open())
    {
        cout << f.rdbuf();
    }
}

void fetchWeather(string location)
{
    string request_url = "curl wttr.in/" + location;
    system(&request_url[0]);
}

void inputLocation()
{
    cout << "Enter location to check weather : ";

    string location = "";
    cin >> location;

    fetchWeather(location);
}

void presentMainMenu()
{
    while (true)
    {
        cout << "1. Enter Location\n2. Exit Application\n";
        while (true)
        {
            int option = 0;
            cout << "Please select an option : ";
            cin >> option;

            switch (option)
            {
            case 1:
            {
                inputLocation();
                break;
            }

            case 2:
                return;

            default:
            {
                cout << "Kindly choose from the available options; i.e. 1 or 2\n";
                break;
            }
            }
        }
    }

    string location;
    cout << "Enter location to search weather : ";
    getline(cin, location);
}

void fetch_weather(string location)
{
    cout << "Checking weather location for " << location << "...";
}

int main()
{
    echoBanner();
    presentMainMenu();
}
