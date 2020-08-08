/* 
 * DOGSAY:
 *
 * The program generates an ASCII picture of a dog with a word of day
 * message. The program is inspired by the classic 'cowsay'; of which
 * you can some info on https://en.wikipedia.org/wiki/Cowsay
 * 
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

#include <dictionary.h>
#include <hangman.h>

// The dictionaries for this project where obtained from the
// OmegaWiki project <http://www.omegawiki.org/Special:Ow_downloads>

#define DEFAULT_DICTIONARY "data/def_eng.csv"

dictionary_t dictionary = NULL;

int main( int argc, char ** argv )
{
	char * dictionary_name;
	if(argc > 1) {
		if(argc == 2) {
			printf("usage: [-d filename]\n");
			exit(1);
		} else if(!strcmp( argv[1], "-d" ) ) {
			if(strcmp(argv[2], "data/def_spa.csv") && strcmp(argv[2], "data/def_short.csv")) {
				printf("INVALID DICTIONARY\n");
				exit(1);
			} else {
				dictionary_name = argv[2];
			}
		} else {
			printf("usage: [-d filename]\n");
			exit(1);
		}
	} else {
		dictionary_name = DEFAULT_DICTIONARY;
	}
	
	dictionary = load( dictionary_name );
	
	if ( dictionary == NULL )
	{
		printf( "error loading the dictionary\n" );
		return -1;
	}
	
	return play();
}
