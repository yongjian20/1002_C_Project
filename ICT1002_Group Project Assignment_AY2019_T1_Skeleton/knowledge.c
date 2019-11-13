/*
 * ICT1002 (C Language) Group Project, AY19 Trimester 1.
 *
 * This file implements the chatbot's knowledge base.
 *
 * knowledge_get() retrieves the response to a question.
 * knowledge_put() inserts a new response to a question.
 * knowledge_read() reads the knowledge base from a file.
 * knowledge_reset() erases all of the knowledge.
 * kowledge_write() saves the knowledge base in a file.
 *
 * You may add helper functions as necessary.
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chat1002.h"

/*
 * Get the response to a question.
 *
 * Input:
 *   intent   - the question word
 *   entity   - the entity
 *   response - a buffer to receive the response
 *   n        - the maximum number of characters to write to the response buffer
 *
 * Returns:
 *   KB_OK, if a response was found for the intent and entity (the response is copied to the response buffer)
 *   KB_NOTFOUND, if no response could be found
 *   KB_INVALID, if 'intent' is not a recognised question word
 */
int knowledge_get(const char *intent, const char *entity, char *response, int n) {
	
	/* to be implemented */
	
	return KB_NOTFOUND;
	
}


/*
 * Insert a new response to a question. If a response already exists for the
 * given intent and entity, it will be overwritten. Otherwise, it will be added
 * to the knowledge base.
 *
 * Input:
 *   intent    - the question word
 *   entity    - the entity
 *   response  - the response for this question and entity
 *
 * Returns:
 *   KB_FOUND, if successful
 *   KB_NOMEM, if there was a memory allocation failure
 *   KB_INVALID, if the intent is not a valid question word
 */
int knowledge_put(const char *intent, const char *entity, const char *response) {
	
	/* to be implemented */
	
	return KB_INVALID;
	
}


/*
 * Read a knowledge base from a file.
 *
 * Input:
 *   f - the file
 *
 * Returns: the number of entity/response pairs successful read from the file
 * If the file fails to open it returns 0
 * It builds the knowledge base KNOWLEDGE_BASE that's stored in RAM
 */
int knowledge_read(FILE *f) {
	
	if (f == NULL) return 0;

	char *line = NULL;
	size_t len = 0;
	ssize_t n_char;
	int n_line = 0;
	while ((n_char = getline(&line, &len, f)) != -1) {
		strtok(line, "\n"); // Removing trailing \n
		// Extracting tokens
		strcpy(KNOWLEDGE_BASE[n_line].intent, 	strtok(line, ","));
		strcpy(KNOWLEDGE_BASE[n_line].entity, 	strtok(NULL, ","));
		strcpy(KNOWLEDGE_BASE[n_line].response,	strtok(NULL, ","));
		++n_line;
    }
	// Updates N_KNOWLEDGE
	N_KNOWLEDGE = n_line;
	return n_line;
	
}


/*
 * Reset the knowledge base, removing all know entitities from all intents.
 */
void knowledge_reset() {
	
	/* to be implemented */
	
}


/*
 * Write the knowledge base to a file.
 *
 * Input:
 *   f - the file
 */
void knowledge_write(FILE *f) {

	char* delimiter = ",";
	char* newline = "\n";

	int n_line;
	char* line = malloc(256);
	knowledge buffer;
	for (n_line = 0; n_line < N_KNOWLEDGE; ++n_line){
		buffer = KNOWLEDGE_BASE[n_line];

		// Create string
		strcpy(line, buffer.intent); 	strcat(line, delimiter);
		strcat(line, buffer.entity); 	strcat(line, delimiter);
		strcat(line, buffer.response); 	strcat(line, newline);

		// Writes string
		fputs(line, f);
	}
}