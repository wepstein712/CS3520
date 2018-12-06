#include "cstringlib.hpp"

namespace str {
  
  size_t strlen(const char *str) {
    size_t n = 0;
    while (*str != '\0') {
	    n++;
    }
    return n;
  }
  
  char *strncpy(char *destination, const char *source, size_t num) {
    bool check =  false;
  
    for (auto i = 0; i < num; i++) {
        if (source[i] == '\0') { check = true; }
	if (check) { destination[i] = '\0';}
 	destination[i] = source[i];
    }
    return destination;
  }

  char *strncat(char *destination, const char *source, size_t num) {
    if (strlen(destination) + num > (sizeof(*destination))) {
	char* temp = new char[sizeof(*destination) + (int)(num) + 1];
	for (int i = 0; i < sizeof(*temp); i++) {
	  	if (i < strlen(*destination)) {
			temp[i] = destination[i];
		} else {
			temp[i] = source[i - strlen(*destination)];
		}
		if (i + 1 == sizeof(*temp)) {
			 temp[i] = '\0'; 
		}
	}
	delete destination;
	return temp;
    } else {
        int len = strlen(destination);
	for (int i = 0; i < num; i++) {
		destination[len + i] = source[i];
	} 
	return destination;
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
	t = false;    
	for (int i = 0; i < strlen(delimiters); i++) {
		if (str[start] == delimiters[i]) { 
			t = true;
			break; 
		}
	}
	start++;
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

