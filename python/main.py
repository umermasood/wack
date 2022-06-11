#!/usr/bin/env python
import os
from sys import platform


def echo_banner():
    f = open('banner.txt')
    banner_ascii = f.read()
    print(banner_ascii)
    f.close()


def check_os_platform():
    if platform == 'linux' or platform == 'linux2':
        return 'linux'
    elif platform == 'darwin':
        return 'macos'
    elif platform == 'win32' or platform == 'win64':
        return 'windows'


def fetch_weather(location):
    print(f'Checking weather for {location}...')
    operating_system = check_os_platform()
    if operating_system == 'linux' or operating_system == 'macos':
        os.system(f'curl wttr.in/{location}')
    elif operating_system == 'windows':
        os.system(f'Invoke-RestMethod https://wttr.in/{location}')


def present_main_menu():
    while True:
        print('''1. Enter Location\n2. Exit Application\n''')
        while True:
            option = input('Please select an option : ')
            if option == '1':
                location = input('Enter location to check weather : ')
                fetch_weather(location)
                break

            elif option == '2':
                exit()

            else:
                print('Kindly choose from the available options; i.e. 1 or 2')


def main():
    echo_banner()
    present_main_menu()


if __name__ == "__main__":
    main()
