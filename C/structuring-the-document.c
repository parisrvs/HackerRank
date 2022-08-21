#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};


typedef struct document document;
typedef struct paragraph paragraph;
typedef struct sentence sentence;
typedef struct word word;
char** split_string(char* string, char c, int* size);

struct document get_document(char* text) {
    document doc;
    char** paragraphs = split_string(text, '\n', &(doc.paragraph_count));
    char** sentences = NULL, **words = NULL;
    doc.data = (paragraph*) malloc(sizeof(paragraph)*(doc.paragraph_count));

    for (int c = 0; c < doc.paragraph_count; c++) {
        sentences = split_string(paragraphs[c], '.', &(doc.data[c].sentence_count));
        doc.data[c].data = (sentence*) malloc(sizeof(sentence)*(doc.data[c].sentence_count));
        for (int d = 0; d < (doc.data[c].sentence_count); d++) {
            words = split_string(sentences[d], ' ', &(doc.data[c].data[d].word_count));
            doc.data[c].data[d].data = (word*) malloc(sizeof (word)*(doc.data[c].data[d].word_count));
            for (int e = 0; e < doc.data[c].data[d].word_count; e++) {
                doc.data[c].data[d].data[e].data = words[e];
            }
        }
    }
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];

}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];

}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];

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


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}