#include "words.hpp"
#include <cstring>
#include <iostream>


using namespace std;

Words *
newListFromSize(unsigned int max_words)
{
  if (max_words >  0) {
    Words *w = new Words();
    w->list = new char*[max_words];
    w->num_words = 0;
    w->max_words = max_words;
    return w;

  } else {
     return nullptr;
  }
  

  /*


if (max_words < 0) {
  Words* w = new Words();
  w->max_words = max_words;
  w->num_words = 0;
  char** temp = new char*[max_words];
  w->list = temp;
  delete temp;
  return w;
  } else {
    return nullptr;
  }
*/
}

Words *
newListFromString(const char *words)
{
  if (words) {
    Words *w = new Words();
  
  char* temp = new char[strlen(words) + 1];
  strcpy(temp, words);
  int count = 1;
  int len = strlen(temp);
  for (int i = 0; i < len; i++) {
    if (temp[i] == ' ') {
      count ++;
      temp[i] = '\0';
    }
  }
 
  w->list = new char*[count];
  w->num_words = count;
  w->max_words = count;
  

  char* start = temp;
  for (int i = 0; i < count; i++) {
    w->list[i] = new char [strlen(start) + 1];
    strcpy(w->list[i], start);
    start = start + strlen(start) + 1;
  }
  //  delete temp;
  return w;

} else {
  return nullptr;
}
}

int
deleteList(Words *p_w)
{
  if (p_w) {
    
    for (int i = 0; i < p_w->num_words; i++) {
      delete p_w->list[i];
    }

    delete p_w->list;
    delete &(p_w->max_words);
    delete &(p_w->num_words);
    delete p_w;
    return 0;
  } else {
    return -1;
  }
}

int
printList(Words *p_w)
{
  if (p_w) {
    for (int i = 0; i < p_w->num_words; i++) {
      std::cout << p_w->list[i] << " ";
    }
    std::cout << std::endl;
    return 0;  
  } else { 
    return -1;
  }
}

int
appendListFromString(Words *p_w, const char *words)
{
  if (p_w && strlen(words) > 0 ) {

    
 char* temp = new char[strlen(words) + 1];
  strcpy(temp, words);
  int word_count;
  word_count = 1;
  int len = strlen(temp);
  for (int i = 0; i < len; i++) {
    if (temp[i] == ' ') {
      word_count += 1;
      temp[i] = '\0';
    }
  }
  
    if (p_w->num_words + word_count > p_w->max_words) {
	char** nextList = new char*[p_w->num_words + word_count];
        for (int i = 0; i < p_w->num_words; i++) {
	   nextList[i] = new char[strlen(p_w->list[i]) + 1];
	   strcpy(nextList[i],p_w->list[i]);
	} 
        
        char* start = temp;
	for (int i = 0; i < word_count; i++) {
	  nextList[p_w->num_words + i] = new char [strlen(start) + 1];
	  strcpy(nextList[p_w->num_words + i], start);
	  start += strlen(start) + 1;
	}
	for (int i = 0; i < p_w->num_words; i++) {
	  delete p_w->list[i];
  	}
	delete p_w->list;
	p_w->list = nextList;
	p_w->num_words += word_count;
	p_w->max_words = p_w->num_words;
delete nextList;
        
    } else {
  	char* start = temp;
      	for (int i = 0; i < word_count; i++) {
	  p_w->list[p_w->num_words + i] = new char [strlen(start) + 1];
 	  strcpy(p_w->list[p_w->num_words + i], start);
	  start += strlen(start);
	}
 	p_w->num_words = p_w->num_words + word_count;

    }
  

    delete temp;
    return word_count;
  } else { 
    return -1;
  }
}

int
appendListFromList(Words *dst, const Words *src)
{
  if (dst || src) {
    if (src->num_words + dst->num_words <= dst->max_words) {
	for (int i = 0; i < src->num_words; i++) {
	  dst->list[dst->num_words + i] = new char[strlen(src->list[i]) + 1];
	  strcpy(dst->list[dst->num_words + i], src->list[i]);
    	}
 	dst->num_words += src->num_words;
    } else {
      int count = src->num_words + dst-> num_words;
      char** temp = new char*[count];
      for (int i = 0; i < count; i++) {
	if (i < dst->num_words) {
	  temp[i] = new char[strlen(dst->list[i]) + 1];
	  strcpy(temp[i], dst->list[i]);
	} else {
	  temp[i] = new char[strlen(src->list[i - dst->num_words]) + 1];
	  strcpy(temp[i], src->list[i - dst->num_words]);
	}
      }
      for (int i = 0; i < dst->num_words; i++) {
	delete dst->list[i];
      }
    dst->list = temp;
      delete temp;
      dst->num_words = count;
      dst->max_words = count;	
    }
    return 0;
  } else {
    return -1;
  }
}

const char *
findWord(const Words *p_w, const char *word)
{
  if (p_w) {
    for (int i = 0; i < p_w->num_words; i++) {
      if (strcmp(word, p_w->list[i]) == 0) {
	return p_w->list[i];
      }
    }
    return nullptr;
  } else {
    return nullptr;
  }
}

int
removeWord(Words *p_w, const char *word)
{
  if (p_w) {
    int num_rem = 0;
    for (int i = 0; i < p_w->num_words; i++) {
      if (strcmp(word, p_w->list[i]) == 0) {  
         num_rem++;
      }
    }
    if (num_rem == 0) {
      return 0;
    } else {
      char** temp = new char*[p_w->max_words];
      int cur = 0;
      for (int i = 0; i < p_w->num_words; i++) {
        if (strcmp(p_w->list[i], word) == 0) {
	  continue;
        } else {
	  temp[cur] = new char[strlen(p_w->list[i]) + 1];
          strcpy(temp[cur], p_w->list[i]);
	  cur++;
	}
      }
      for (int i = 0; i < p_w->num_words; i++) {
	delete p_w->list[i];
      }
      p_w->list = temp;
      delete temp;
      p_w->num_words -= num_rem;
      return num_rem;    
    }
  } else {
    return -1;
  }
}
