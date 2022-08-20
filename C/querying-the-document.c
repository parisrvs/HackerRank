#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char** split_string(char* string, char c, int* size);

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];

}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];

}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];

}

char**** get_document(char* text) {
    int count_of_paragraphs, count_of_sentences, count_of_words;
    char** sentences = NULL, **words = NULL;

    char** paragraphs = split_string(text, '\n', &count_of_paragraphs);
    char**** document = (char****) malloc(sizeof(char***)*count_of_paragraphs);
    
    for (int c = 0; c < count_of_paragraphs; c++) {
        sentences = split_string(paragraphs[c], '.', &count_of_sentences);
        document[c] = (char***) malloc(sizeof(char**)*count_of_sentences);
        for (int d = 0; d < count_of_sentences; d++) {
            words = split_string(sentences[d], ' ', &count_of_words);
            document[c][d] = (char**) malloc(sizeof(char*)*count_of_words);
            for (int e = 0; e < count_of_words; e++) {
                int l = strlen(words[e]);
                document[c][d][e] = (char*) malloc(sizeof(char)*(l+1));
                for (int f = 0; f <=l; f++)
                    document[c][d][e][f] = words[e][f];
                free(words[e]);
            }
        }
    }
    return document;
}

char** split_string(char* string, char c, int* size) {
    int l = 2, l_string = strlen(string), count = 0;

    char** strings = NULL;

    for (int x = 0; x < l_string; x++)
    {   
        if (string[x] == c) {
            while(string[x+1] && string[x+1] == c)
                x++;
            if (string[x+1] && x < l_string) {
                count++;
                strings = (char**) realloc(strings, sizeof(char*)*count);
                strings[count-1] = NULL;
                l = 2;
            } else {
                break;
            }

        } else {
            if (!count) {
                strings = (char**) malloc(sizeof(char*)*(count+1));
                strings[count] = NULL;
                count++;
            }
            strings[count-1] = (char*) realloc(strings[count-1], sizeof(char)*l);
            strings[count-1][l-2] = string[x];
            strings[count-1][l-1] = '\0';
            l++;
        }
    }

    *size = count;
    return strings;
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