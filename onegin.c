#include <stdio.h>
#include <string.h>
#define BUFSIZE 1000
char** ReadText(FILE* f, int* nstrings, size_t* maxsize)
    {
    char** text;
    int i = 0;
    *maxsize = 0;
    while (!feof(f))
        {
       // char str;
        char str[BUFSIZE];
        fgets(str, BUFSIZE, f);
        printf("%s\n", str);
        text[0] = str;
       // printf("good %s\n", str);

//        if ((*maxsize) < strlen(str))
    //        {
      //      *maxsize = strlen(str);
       //     }  
        }
  //  *nstrings = i;
    char** ii;
    return ii;
    }

//int compare(const void * x1, const void * x2)
//    {
//    s1 = *(char*)x1;
//    s2 = *(char*)x2;
//    wh 
//    }

int main()
    {
    printf("jjd");
    FILE *myfile;
    myfile = fopen("EO.txt", "r");
    int* nstr;
    size_t* maxsize;
    char** txt =  ReadText( myfile, nstr, maxsize);     
//    qsort(txt, *nstr, maxsize, strcmp);
    int i;
  //  for (i = 0; i < *nstr; i++) 
    //    printf(*txt[i]);   
    fclose(myfile);    
    }
