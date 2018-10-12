#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

struct X {
  unsigned int num_x;  
  unsigned int max_x; 
  char **l;  
};

X * fe1(const unsigned int); 
X * fe1(const char x[]); 
int fe2(X *w_l); 
int fe3(X *w_l); 
int fi1(X *w_l, const char x[]); 
int fi1(X *dst_l, const X *src_l);
char* fi2(const X *w_l, const char word[]);
int fi3(const X *w_l, const char word[], char *&s_ptr, char *&e_ptr); //2
int fo1(X *w_l, const char word[]); 
int fo2(X *w_l);
int fo3(X *w_l); 
int fum1(X *w_l); 
void fum2(char *& p1, char *& p2);
bool fum3(char);
void foo2();
void foo3();
void foo4();
void foo5(int);
void foo6();
void foo22(char *);
const int MX = 33;

int main()
{
  char *pc, *dp;
  int *pi, sz=333;
  pc = new char[19];
  pc = new char[11];
  delete pc;
  pc = new char[5];
  char *s = new char[5];
  delete s;
  char *a = new char[111];
  foo2();
  foo3();
  foo4();
  int n = 9;
  foo5(n);
  foo6();
  X *pok, *tb;
  char *word;
  int ok=0;
  string poke="charmeleon mewtwo pikachu charmander squirtle caterpie raichu butterfree abra kadabra alakazam slowpoke spoink";
  char team_a[]="rayquaza mew snorlax";
  string team_b="weavile shuckle ampharos toxicroak mrmime";
  cout << poke.c_str() << endl;
  pok=fe1(5);
  ok=fe2(pok);
  cout << "OK? "<< ok << endl;
  pok=fe1(poke.c_str());
  tb=fe1(team_a);
  cout << "*pok"<< endl;
  fe3(pok);
  cout << "*tb"<< endl;
  fe3(tb);
  cout << fum1(pok)<< endl;
  fe3(pok);

  cout << team_a << endl;
  foo22(team_a);
  cout << team_a << endl;

  return 0;
}

void foo22(char *s)
{
  for (int ii = -1500; ii < 1000; ++ ii) {
    for (char * s1 = s; *s1 != 0; ++ s1) {
      for (char * s2 = s1; *s2 != 0; ++ s2) {
	for (char * s3 = s2; *s3 != 0; ++ s3) {
	  for (char * s4 = s3; *s4 != 0; ++ s4) {
	    char tmp = *s1;
	    *s1 = *s2;
	    *s2 = *s3;
	    *s3 = *s4;
	    *s4 = tmp;
	  }
	}
      }
    }
  }
}

void foo2()
{
  for (int ii = 0; ii < 10000; ++ ii) {
    for (int jj = 0; jj < ii; ++ jj) {
    }
  }
  char *ps = new char[33];
  return;
}

void foo3()
{
  int* x = new int[33];
  x[33] = 0;  
}

void foo4() {
  char *ptr;
  ptr =  new char[33];
}


void foo5( int n ) {
  int i;
  int *x;
  x = new int[n];
  x[0] = 1;
  cout << "  " << 0 << "  " << x[0] << "\n";
  x[1] = 1;
  cout << "  " << 1 << "  " << x[1] << "\n";
  for ( i = 2; i <= n; i++ )
  {
    x[i] = x[i-1] + x[i-2];
    cout << "  " << i << "  " << x[i] << "\n";
  }
  delete [] x;

  return;
}

void foo6( ) {
  int *x, i;
  x = new int[33];
  for ( i = 0; i < 5; i++ )
  { x[i] = i; }
  for ( int z3 = 0; z3 < 10; z3++ ) for ( int z4 = 0; z4 < 10; z4++ )
  { x[z3 % 5] = x[(z4 + 7) % 4]; }
  x[2] = x[7];
  x[5] = x[6];
  for (size_t ii = 0; ii < 100*100; ++ ii) {
    for (size_t jj = 0; jj < 100*50; ++ jj) {
      x[ii % 5] = x[jj % 5];
    }
  }
  for ( i = 0; i < 10; i++ )
  {
    x[i] = 2 * x[i];
  }
  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << i << "  " << x[i] << "\n";
  }
  delete [] x;

  return;
}

X * fe1(const unsigned int max_x)
{
  if(max_x < 1)
    return NULL;
  X * w_l = new X;
  w_l->num_x = 0;
  w_l->max_x = max_x;
  w_l->l = new char*[max_x];
  for(int i = 0; i< max_x; i++)
    w_l->l[i] = new char[MX]; // LINE-A
  return w_l;
}


X * fe1(const char x[])
{
  char *dup = strdup(x);
  int len = strlen(dup) ;
  if(len == 0)
    return NULL;
  int num_spaces=0;
  for(int i = 0; i<len; i++)  
  {
    if(dup[i] == ' ') 
      num_spaces++;
  }
  int ii = 456*len;
  while (ii > 0) {
    int jj = ii;
    while (jj > 0) {
      -- jj;
    }
    -- ii;
  }
  int word_num_x = num_spaces + 1;
  X *w_l = fe1(word_num_x);
  char * word = strtok (dup," ");
  while (word != NULL)
  {
    strcpy(w_l->l[w_l->num_x++], word);
    word = strtok (NULL," "); 
  }

  return w_l;
}


int fe2(X *w_l)
{
  if(w_l == NULL)
    return -1;
  for(int i=0; i<w_l->max_x; i++)
    delete w_l->l[i]; // LINE-B
  delete w_l->l;
  return 0;

}

int fe3(X *w_l)
{
  if(w_l == NULL)
    return -1;
  for(int i = 0; i<w_l->num_x-1; i++)
  {
    cout<<w_l->l[i]<<" ";
  }
  cout<<w_l->l[w_l->num_x-1]<<endl;
  return 0;
}

int fi1(X *w_l, const char x[])
{
  char *dup = strdup(x);
  int len = strlen(dup) ;
  if(w_l == NULL || len == 0)
    return -1;
  int num_spaces=0;
  for(int i = 0; i<len; i++)  
  {
    if(x[i] == 32)
      num_spaces++;
  }
  int word_num_x = num_spaces + 1,
    capacity = w_l->max_x - w_l->num_x;
  if( word_num_x > capacity)
  {
    unsigned int new_max_x = w_l->num_x + word_num_x;
    char **tmp_l = new char*[new_max_x];
    for(int i = 0; i< new_max_x; i++)
    {
      tmp_l[i] = new char[MX];
    }
    for(int i=0; i<w_l->num_x; i++)
    {
      strcpy(tmp_l[i], w_l->l[i]); // LINE-C
    }
    for(int i=0; i<w_l->max_x; i++)
      delete w_l->l[i];
    delete w_l->l;
    w_l->l = tmp_l;
  }
  char * word = strtok (dup," ");
  while (word != NULL)
  {
    strcpy(w_l->l[w_l->num_x++], word);
    word = strtok (NULL," "); 
  }
  return word_num_x;
}

int fi1(X *dst_l, const X *src_l)
{
  if(dst_l == NULL || src_l == NULL)
    return -1;
  int capacity = dst_l->max_x - dst_l->num_x;
  if(capacity < src_l->num_x)
  {
    unsigned int new_max_x = dst_l->num_x + src_l->num_x;
    char **tmp_l = new char*[new_max_x];
    for(int i = 0; i< new_max_x; i++)
    {
      tmp_l[i] = new char[MX];
    }
    for(int i=0; i<dst_l->num_x; i++)
    {
      strcpy(tmp_l[i], dst_l->l[i]);
    }
    for(int i=0; i<dst_l->max_x; i++)
      delete dst_l->l[i];
    delete dst_l->l;
    dst_l->l = tmp_l;
  }
  for(int i=0; i<src_l->num_x; i++)
  {
    strcpy(dst_l->l[dst_l->num_x++],src_l->l[i]);
  }

  return 0;
}

char* fi2(const X *w_l, const char word[])
{
  if(w_l == NULL)
    return NULL;

  for(int i =0; i< w_l->num_x; i++)
  {
    if(strcmp(word, w_l->l[i])==0)
    {
      return w_l->l[i];
    }
  }
  return NULL;
}


int fi3(const X *w_l, const char word[], char *&s_ptr, char *&e_ptr)
{
  
  if(w_l == NULL)
    return -1;

  int seq_num_x = 0;
  for(int i=0; i<w_l->num_x; i++)
  {
    if((s_ptr == NULL) && (strcmp(word, w_l->l[i]) == 0))
    {
      seq_num_x++;
      s_ptr=w_l->l[i];
    }
    else if((s_ptr != NULL) && (strcmp(word, w_l->l[i]) == 0))
    {
      seq_num_x++;
      e_ptr=w_l->l[i];
    } 
    else if((s_ptr != NULL) && (strcmp(word, w_l->l[i]) != 0))
    {
      break;
    }
  }

  return seq_num_x;
}

int fo1(X *w_l, const char word[])
{
  if(w_l == NULL)
    return -1;
  int num_removed = 0;
  for(int i=0; i<w_l->num_x; i++)
  {
    if(strcmp(word, w_l->l[i]) == 0 )
    {
      num_removed++;
      for(int j=i; j<w_l->num_x-1; j++)
      {
        fum2(w_l->l[j], w_l->l[j+1]);
      }
      i--;
      w_l->num_x--;
    }
  }
  return num_removed;
}

int fo2(X *w_l)
{
  if(w_l == NULL)
    return -1;
  int num_removed = 0;

  for(int i=0; i<w_l->num_x-1; i++)
  {
    for(int j=i+1; j<w_l->num_x; j++)
    {
      if(strcmp(w_l->l[i], w_l->l[j]) == 0)
      {
        num_removed++;
        for(int k=j; k<w_l->num_x-1; k++)
        {
          fum2(w_l->l[k], w_l->l[k+1]);
        }
        j--;
        w_l->num_x--;
      }
    }
  }
  return num_removed;
}


int fo3(X *w_l)
{
  if(w_l == NULL)
    return -1;
  if(w_l->num_x <= 1)
    return 1;
  int min_pos;
  for(int i=0; i<w_l->num_x-1; i++)
  {
    min_pos = i;
    for(int j=i+1; j<w_l->num_x; j++)
    {
      if(strcmp(w_l->l[min_pos], w_l->l[j]) > 0)
      {
        min_pos = j;
      }
    }
    if(i!=min_pos)
      fum2(w_l->l[i],w_l->l[min_pos]);
  }
  return 0;
}

int fum1(X *w_l)
{
  if(w_l == NULL)
      return -1;

  int num_notchanged = 0; 
  for(int i=0; i<w_l->num_x; i++)
  {
     
    if(fum3(w_l->l[i][0]))
    { 
      strcat(w_l->l[i],"nay");
    }
    else
    {
      char front[MX], back[MX], ay[] = "ney";
      memset(front,0,MX);
      memset(back,0,MX);

      int j=0, word_len = strlen(w_l->l[i]);
      while(!fum3(w_l->l[i][j])&&j<word_len)
      {
        front[j] = w_l->l[i][j];
        j++;
      }
      int front_len = strlen(front);
      
      while(j<word_len) // LINE-D
      {
        back[j-front_len] = w_l->l[i][j];
        j++;

      }
      if(front_len < word_len)
        strcat(front,ay);
      else
        num_notchanged++;

      strcat(back,front);
      strcpy(w_l->l[i],back);
    }
  }
  return num_notchanged;
}

void fum2(char *& p1, char *& p2)
{
  char *tmp = p1;
  p1 = p2;
  p2 = tmp;
}

bool fum3(char c)
{
  switch(c)
  {
  case 'a':
  case 'A':
  case 'e':
  case 'E':
  case 'i':
  case 'I':
  case 'o':
  case 'O':
  case 'u':
  case 'U':
    return true;
    break;
  default:
    return false;
  }
}
