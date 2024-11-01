#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINES_PER_PAGE 25

// Struct to store word information
typedef struct {
    char *word;
    int line;
    int page;
} Word;

// Function to compare two words for sorting
int compare_words(const void *a, const void *b) {
    Word *word_a = (Word*) a;
    Word *word_b = (Word*) b;

    return strcmp(word_a->word, word_b->word);
}

int main() {

    FILE *file = fopen("TestFile.txt", "r");

    // Initialize variables for time measurement
    clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();

    char buffer[1024];
    Word words[1024];
    int num_words = 0;
    int line_number = 1;

    // Read file line by line and split into words
    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            words[num_words].word = strdup(token);
            words[num_words].line = line_number;
            num_words++;
            token = strtok(NULL, " \n");
        }
        line_number++;
    }

    // Sort the words in alphabetical order
    qsort(words, num_words, sizeof(Word), compare_words);

    // Print out the words and their page numbers
    int current_page = 1;
    int words_on_current_page = 0;
    printf("Word\tLine\tPage\n");
    for (int i = 0; i < num_words; i++) {
        if (words_on_current_page == LINES_PER_PAGE) {
            current_page++;
            words_on_current_page = 0;
        }

        printf("%s\t%d\t%d\n", words[i].word, words[i].line, current_page);
        words_on_current_page++;
    }

    fclose(file);

    // Print out the time taken by the program
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
