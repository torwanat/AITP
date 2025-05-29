#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	
	file.open()
	string s;
	int found = 0;
	int lineNum = 0;
	string searched = "Tadeusz";
	if(file){
		while(getline(file,s)){
			linenum++;
			for(int i = 0; i < s.lenght(); i++){
				for(int j = 0; j <= searched.lenght(); j++){
					if(j == searched.lenght()){
						found++;
						break;
					}
				if(s[i] != searched[j]) break;
				i++;
				}
			}
		}
	}
}
