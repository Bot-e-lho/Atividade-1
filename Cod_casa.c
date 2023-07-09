#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);

int main()
{
	char licensePlate[] = "1s3 456";
    char* words[] = {"looks", "pest", "stew", "show"};
    //char licensePlate[] = "s31 AY2";
    //char* words[] = {"say","ally","angry","shy"};
    int wordsSize = sizeof(words) / sizeof(words[0]);

    char* Shortest = shortestCompletingWord(licensePlate, words, wordsSize);
    printf("\nMenor palavra: %s\n", Shortest);

    free( Shortest );
	return (0);
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize){
    char* Temp = (char*)malloc(sizeof(char) * (strlen(licensePlate) + 1));
    int c = 0;
    int a = 0;
    int j = 0;
    char* Short_Word = NULL;

    while ( licensePlate[a] != '\0' ) {
            if( isalpha( licensePlate[a] ) ) {
                Temp[c] = licensePlate[a];
                c++; 
            }
            a++;
            Temp[c] = '\0';
        }

    for ( int i = 0; i < c; i++ ) {
        Temp[i] = tolower( Temp[i] );
        }

    for ( int i = 0; i < wordsSize; i++ ) {
        int Flag = 1;
        
        int Cont_Word[26] = {};
        for ( j = 0; words[i][j] != '\0'; j++ ) {
            int Aux = words[i][j] - 'a';
            Cont_Word[Aux]++;
        }
        
        int Cont_Temp[26] = {}; 
        for ( j = 0; Temp[j] != '\0'; j++ ) {
            int Aux = Temp[j] - 'a';
            Cont_Temp[Aux]++;
        }

        for ( j = 0; j < 26; j++ ) {
            if ( Cont_Temp[j] > Cont_Word[j] ) {
                Flag = 0;
                break;
            }
        }
        if ( Flag ) {
            if ( Short_Word == NULL || strlen( words[i] ) < strlen( Short_Word ) ) {
                if ( Short_Word != NULL) {
				    free( Short_Word );
                }   
                Short_Word = (char*)malloc(sizeof(char) * (j + 1));
                strcpy( Short_Word, words[i] );
            } 
		}
    }

    free( Temp );
    return Short_Word;
}