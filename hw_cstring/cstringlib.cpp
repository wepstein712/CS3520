#include "cstringlib.hpp"

namespace str {
  
  size_t strlen(const char *str) {
    size_t n = 0;
    while (str[n] != '\0') {
	    n++;
    }
    return n;
  }
  
  char *strncpy(char *destination, const char *source, size_t num) {
    bool check =  false;
    //char* temp = new char[strlen(source)];
    size_t i;
    for (i = 0; i < num && source[i] != '\0'; i++) {
     destination[i] = source[i];
    }
    for (; i < num; i++) {
      destination[i] = '\0';
    }    
    return destination;
  }

  char *strncat(char *destination, const char *source, size_t num) {
    int len = strlen(destination) + (int)num;
    char* temp = new char[len + 1];
    for (auto i = 0; i <= len; i++) {
      if (i < strlen(destination)) {
	temp[i] = destination[i];
      } else {
	temp[i] = source[i - strlen(destination)];
      }
      if (i == len) {
	temp[i] = '\0';
      }
    }
    return nullptr;
  }

  int strcmp(const char *str1, const char *str2) {
    for (int i = 0; i < strlen(str1); i++) {
	if (str1[i] - str2[i] == 0) {
		 continue; 
	}
	else {
		return str1[i] - str2[i];
	}
    }
    return 0;
  }

  const char *strchr(const char *str, int character) {
   for (int i = 0; i <= strlen(str); i++) {
	if ( str[i] - character == 0) {
		 return &(str[i]);
	 }
    } 	
    return nullptr;
   }

  const char *strrchr(const char *str, int character) {
    for (int i = strlen(str); i >= 0; i--) {
	if (str[i] - character == 0) { 
		return &(str[i]);
	 }
    } 
    return nullptr;
   }

  const char *strstr(const char *str1, const char *str2) {
   for (int i = 0; i < strlen(str1); i++) {
	if (str1[i] == str2[0]) {
		bool t = true;
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i+j] != str2[j]) {
				t = false;
			 } else { break; }
		}
		if (t) { return &(str1[i]); }
		else {
			continue;
		}
	}
    }
    return nullptr;
  }

  size_t strspn(const char *str1, const char *str2) {
   int count = 0; 
    for (int i = 0; i < strlen(str1); i++) {
	bool t = false;
	for (int j = 0; j < strlen(str2); j++) {
		if (str1[i] == str2[j]) { t = true; break; }
	}
	if (t) { count++; }
    }
    return count;
 }

  size_t strcspn(const char *str1, const char *str2) {
   int count = 0;
    for (int i = 0; i < strlen(str1); i++) {
	bool t = false;
	for (int j = 0; j < strlen(str2); j++) {
		if (str1[i] == str2[j]) { t = true; break; }
	}
	if (t) { break; } else { count++; }
    }
    return count;
  }

  char *strtok(char * str, const char * delimiters) {
   if (!str) { return nullptr; }  
    bool t = false;
    int start = 0;
    do {
	if (t) { start++; }
	t = false;    
	for (int i = 0; i < strlen(delimiters); i++) {
		if (str[start] == delimiters[i]) { 
			t = true;
			break; 
		}
	}
	
    } while (t);
    char* sta = &(str[start]);
    for (int i = 0; i < strlen(sta); i++) {
	if (sta[i] == '\0') { break; }
	for (int j = 0; j < strlen(delimiters); j++) {
		if (sta[i] == delimiters[j]) {
			sta[i] = '\0';
			break;
		}
	}
    }
    return sta;
  }

}

