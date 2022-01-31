#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
//#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

	constexpr size_t cache_length = 16384;
 	char cachebuffer[cache_length] = {0};
 	size_t howmany = 0;
 	while(std::cin) {
    	std::cin.read(cachebuffer, cache_length);
    	howmany += std::cin.gcount();
 	}

 	if (argc == 1) {
 		for (int i = 0; cachebuffer[i] != 0; i++) {
 			cout << cachebuffer[i];
 		}
 		return 0;
 	}

 	string arg = argv[1];
	int l = arg.length();

 	int s;
 	int k = 0;
 	bool check = false;

 	for (int i = 0; cachebuffer[i] != 0; i++) {
 		char c = cachebuffer[i];
 		
 		if (cachebuffer[i - 1] == 10) {
 			s = i;
 		}

 		if (c == arg[0] && k == 0) {
 			check = true;
 			k++;
 		} else if (check && c == arg[k]) {
 			k++;
 		} else {
 			check = false;
 			k = 0;
 		}

 		if (k == l) {
 			for (int j = s; cachebuffer[j] != 10; j++) {
 				cout << cachebuffer[j];
 				i = j;
 			}

 			cout << endl;
 		}
 	}

 	//cout << result << endl;

}
