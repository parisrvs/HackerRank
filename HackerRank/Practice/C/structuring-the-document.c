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


int COUNT = 0;
typedef struct word word;
typedef struct sentence sentence;
typedef struct paragraph paragraph;
typedef struct document document;

// this block of code frees the document. LINE 226.
// not required in HackerRank code.//not even allowed
void free_document(document);


char** split_string(char* s, char d)
{
    char** sa = NULL;
    char* string = NULL;

    int c=0, start, end;

    do
    {
        while(s[c] == d)
            c++;
        start = c;

        while(s[c] != d && s[c] != '\0')
            c++;
        end = c;

        int l = (end-start)+1, count = 0;
        if (l == 1)
            break;

        string = malloc(sizeof(char)*l);
        for (int e=start; e<end; e++)
        {
            string[count] = s[e];
            count++;
        }
        string[count] = '\0';
        COUNT++;
        sa = realloc(sa, sizeof(char*)*(COUNT+1));
        sa[COUNT-1] = string;
        sa[COUNT] = NULL;
        string = NULL;
    } while (1);

    free(s);
    return sa;
}


struct document get_document(char* text)
{
    int sentence_count, paragraph_count, word_count;
    document DOC;

    char** PARAGRAPHS = split_string(text, '\n');
    paragraph_count = COUNT;
    COUNT = 0;
    
    DOC.data = malloc(sizeof(paragraph)*paragraph_count);
    DOC.paragraph_count = paragraph_count;

    for (int c=0; c<paragraph_count; c++)
    {
        char** SENTENCES = split_string(PARAGRAPHS[c], '.');
        sentence_count = COUNT;
        COUNT = 0;
        
        ((DOC.data)[c]).data = malloc(sizeof(sentence)*sentence_count);
        ((DOC.data)[c]).sentence_count = sentence_count;

        for (int d=0; d<sentence_count; d++)
        {
            char** WORDS = split_string(SENTENCES[d], ' ');
            word_count = COUNT;
            COUNT = 0;

            ((((DOC.data)[c]).data)[d]).data = malloc(sizeof(word)*word_count);
            ((((DOC.data)[c]).data)[d]).word_count = word_count;

            for (int e=0; e<word_count; e++)
            {
                ((((((DOC.data)[c]).data)[d]).data)[e]).data = malloc(sizeof(char)*(strlen(WORDS[e])+1));
                for (int f=0, fl=strlen(WORDS[e]); f<=fl; f++)
                {
                    (((((((DOC.data)[c]).data)[d]).data)[e]).data)[f] = WORDS[e][f];
                }
                free(WORDS[e]);
            }
            free(WORDS);

        }
        free(SENTENCES);
    }
    free(PARAGRAPHS);
    return DOC;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n)
{
    return ((((((Doc.data)[n-1]).data)[m-1]).data)[k-1]);
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)
{
    return ((((Doc.data)[m-1]).data)[k-1]);
}

struct paragraph kth_paragraph(struct document Doc, int k)
{
    return ((Doc.data)[k-1]);
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
    free_document(Doc);
}

// this block of code frees the document.
// not required in HackerRank code.//not even allowed
void free_document(document d)
{
    int paragraphs = d.paragraph_count;
    for (int c=0; c<paragraphs; c++)
    {
        int sentences = ((d.data)[c]).sentence_count;
        for (int x=0; x<sentences; x++)
        {
            int words = ((((d.data)[c]).data)[x]).word_count;
            for (int e=0; e<words; e++)
            {
                free(((((((d.data)[c]).data)[x]).data)[e]).data);
            }

        free(((((d.data)[c]).data)[x]).data);
        }
        free(((d.data)[c]).data);
    }
    free(d.data);

}