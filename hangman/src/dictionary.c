/* 
 * Copyright (c) 2018 Valentin Cassano.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include <llist.h>

#include <dictionary.h>


struct word_s
{
	char * expression;
	char * definition;
};

struct dictionary_s
{
	 char * name;
	llist_t content;
	    int entries;
};


// assumption: line = "\" ... \", \" ... \"\n"
word_t line2word( char * line )
{
	word_t word = (word_t) malloc (sizeof(struct word_s));

	if(line) {
		word->expression = strtok(line, ",");
		word->definition = strtok(NULL, "\n");
	}

	return word;
}

// parse the buffer line by line converting the lines
// read into the words to be inserted in the dictionary
llist_t parse( char * buffer )
{
	llist_t content = make();
	char * nextLine;

	while(buffer) {
      	nextLine = strchr(buffer, '\n');
      	if(nextLine) *nextLine = '\0';      	
		add(content, line2word(buffer));
		buffer = nextLine ? (nextLine+1) : NULL;

	}

	return content;
}

dictionary_t load( char * file_name )
{
	int lengthOfFile= 0;
	char * buffer = 0;
	dictionary_t dictionary = NULL;

	dictionary = (dictionary_t) malloc (sizeof(struct dictionary_s));
	dictionary->name = file_name;
	FILE * dictionaryFile = fopen(file_name, "rt");

	if(dictionaryFile) {

		fseek(dictionaryFile, 0, SEEK_END);
		lengthOfFile = ftell(dictionaryFile);
		fseek(dictionaryFile, 0, SEEK_SET);
		buffer = malloc(lengthOfFile + 1);

		if(buffer) {
			fread(buffer, 1, lengthOfFile, dictionaryFile);
			buffer[lengthOfFile] = '\0';
		}
	}

	fclose(dictionaryFile);
	dictionary->content = parse(buffer);
	dictionary->entries = length(dictionary->content);
	free(buffer);
	srand( ( unsigned ) time (NULL)); 

	return dictionary;
}

word_t random_word( dictionary_t dictionary )
{
    return at( dictionary->content, rand( ) % dictionary->entries );
}

char * expression( word_t word )
{
	char * result = word->expression;
	result = word->expression + 1;
	result[strlen(result) - 1] = '\0';
	return result;
}

char * definition( word_t word )
{
	char * result = word->definition;
	result = word->definition + 1;
	result[strlen(result) - 1] = '\0';
	return result;
}

void cut (word_t word, char ** expre, char ** defin) {
	*expre = expression(word);
	*defin = definition(word);
}

void print_word( word_t word )
{
	printf( "  %s:", word->expression );
	printf( "\n  %s ", word->definition );
}
