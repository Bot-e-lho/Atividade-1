#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);

int main()
{
	char licensePlate[] = "1s3 456";
    char* words[] = {"looks", "pest", "stew", "show"};
    char licensePlate[] = "s31 AY2";
    char* words[] = {"say","ally","angry","shy"};

    int wordsSize = sizeof(words) / sizeof(words[0]);

    char* Shortest = shortestCompletingWord(licensePlate, words, wordsSize);
    printf("\nMenor palavra: %s\n", Shortest);

    free( Shortest );
	return (0);
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
char* temp = (char*)malloc(sizeof(char) * sizeof(licensePlate));
int c = 0;
int a = 0;
        while(licensePlate[a] != '\0'){
            if(isalpha(licensePlate[a]) == 1){
                temp[c] = licensePlate[a];



                c++;
                a++;
            }
        }
        for(int i = 0; i < c; i++){
            temp[c] = tolower(temp[c]);
        }
    







    
char* aux = malloc(sizeof(char) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        int j = 0;
        while(words[i][j] != '\0'){
              for(int t = 0; t < c; t++){
                  if(words[i][j] == temp[t]){
                     strcpy(aux[i], words[i]);
                        }
                  j++;
                }
            }
        }
free(temp);
return aux;
}
 
    
    
