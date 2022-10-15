#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

int COUNT = 1;

char** split_string(char* s, char d);
void print_char_array(char**);
char* strip(char*);

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text)
{
    char**** document = NULL;
    int paragraphs = 1, sentences = 0, words = 0;
    
    COUNT = 1;
    char** p = split_string(text, '\n');
    //printf("%i Paragraphs: \n", COUNT-1);
    //print_char_array(p);
    paragraphs = COUNT - 1;
    document = malloc(sizeof(char***)*paragraphs);
    for (int c=0; c<paragraphs; c++)
    {
        COUNT = 1;
        char** s = split_string(p[c], '.');
        //printf("%i Sentences in Paragraph %i: \n", COUNT-1, c+1);
        //print_char_array(s);
        sentences = COUNT - 1;
        document[c] = malloc(sizeof(char**)*sentences);
        for (int d=0; d<sentences; d++)
        {
            COUNT = 1;
            char** w = split_string(s[d], ' ');
            //printf("%i words in Sentence %i of Paragraph %i: \n",COUNT-1, d+1, c+1);
            //print_char_array(w);
            words = COUNT - 1;
            document[c][d] = malloc(sizeof(char*)*words);
            for (int e=0; e<words; e++)
            {
                document[c][d][e] = malloc(sizeof(char)*(strlen(w[e])+1));
                for (int f=0, z=strlen(w[e]); f<=z; f++)
                    document[c][d][e][f] = w[e][f];
                //printf("%s\n", document[c][d][e]);
                free(w[e]);
            }
        }
    }
    return document;
}

char** split_string(char* s, char d)
{
    if (!s || !d)
        return NULL;
    
    char* word = NULL;
    char** string = NULL;
    int k=0, l=strlen(s), counter = 0;

    for (int x=0; x<=l; x++)
    {
        if ((s[x] == d || s[x] == '\0') && word != NULL)
        {
            string = realloc(string, sizeof(char*)*(COUNT));
            if (string == NULL)
                return NULL;
            
            string[COUNT-1] = strip(word);
            word = NULL;
            k=0;
            COUNT++;
        }
        else
        {
            word = realloc(word, sizeof(char)*(k+2));
            if (word == NULL)
                return NULL;
            word[k] = s[x];
            word[k+1] = '\0';
            k++;
        }
    }
    free(s);
    return string;
}


void print_char_array(char** sp)
{
    for (int c=0; c<COUNT-1; c++)
        printf("Item %i: %s\n", c+1, sp[c]);
}



char* strip(char* word)
{
    if (word == NULL)
        return NULL;
    
    char* new_word = NULL;
    int start, end, c=2, l = strlen(word);

    for (start=0; start<l; start++)
    {
        if (word[start] != ' ')
            break;
    }

    for (end=l-1; end>=0; end--)
    {
        if (word[end] != ' ')
            break;
    }

    for (int d = start; d <= end; d++ )
    {
        new_word = realloc(new_word, sizeof(char)*c);
        new_word[c-2] = word[d];
        new_word[c-1] = '\0';
        c++;
    }

    free(word);
    return new_word;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}