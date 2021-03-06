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
#include <ctype.h>
#include <string.h>

#include <input.h>
#include <dictionary.h>

#include <hangman.h>

#define GAME_OVER 7 // max number of misses
#define PENALTY   2 // penalty for incorrect guess
#define ESC 27
#define ENTER 13

// state of hangman
typedef	struct state_s* state_t;

struct state_s
{
	char * help;
	char * password;
	char * secret;
	char * word;
	   int length;
	char * misses;
	   int missed;
	   int win;
};

void logicOfTheGame ( state_t state );

static void welcome( void )
{
	printf( "\n        **********************************          " );
	printf( "\n        *             HANGMAN            *          " );
	printf( "\n        **********************************          " );
	printf( "\n                                                    " );
	printf( "\n ( press ESC to exit or any other key to continue ) " );
}

static void win( void )
{
	printf( "\n        **********************************          " );
	printf( "\n        *             YOU WIN            *          " );
	printf( "\n        **********************************          " );
	printf( "\n                                                    " );
	printf("\n");
}

static void lose( void )
{
	printf( "\n        **********************************          " );
	printf( "\n        *             YOU LOSE           *          " );
	printf( "\n        **********************************          " );
	printf( "\n                                                    " );
	printf("\n");
}

void draw_hangman( state_t game )
{
	switch ( game->missed )
	{
		case 0 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/           " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		case 1 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		case 2 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |     (_)    " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		case 3 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |     (_)    " );
			printf( "\n |      |     " );
			printf( "\n |      |     " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		case 4 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |     (_)    " );
			printf( "\n |   >--|     " );
			printf( "\n |      |     " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		case 5 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |     (_)    " );
			printf( "\n |   >--|--<  " );
			printf( "\n |      |     " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		case 6 :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |     (_)    " );
			printf( "\n |   >--|--<  " );
			printf( "\n |      |     " );
			printf( "\n |     /      " );
			printf( "\n |   _/       " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
		
		default :
		{
			printf( "\n  ___________ " );
			printf( "\n |/     |     " );
			printf( "\n |     (_)    " );
			printf( "\n |   >--|--<  " );
			printf( "\n |      |     " );
			printf( "\n |     / \\    " );
			printf( "\n |   _/   \\_  " );
			printf( "\n |            " );
			printf( "\n |___         " );
		};
		break;
	}
}

void display( state_t game )
{
	system("clear");
	draw_hangman( game );
	printf( "\n                          " );
	printf( "\n     help: %s", game->help   );
	printf( "\n   secret: %s", game->secret );
	printf( "\n   misses: %s", game->misses );
}

// new game
state_t init( void )
{
	state_t game = ( state_t ) malloc ( sizeof( struct state_s ) );
	if( ( ESC != getch( ) ) ) {
		cut(random_word(dictionary), &game->secret, &game->help);
		game->length = strlen (game->secret);
		game->win = 0;
		game->password = malloc(game->length);
		strcpy(game->password, game->secret);
		for(int i = 0; i < game->length; i++) {
			if(isalpha(game->secret[i])) {
				game->secret[i] = '*';
			};
			game->password[i] = tolower(game->password[i]);
		};
		game->missed = 0;
		game->misses = malloc(GAME_OVER * 2 + 1);
		game->misses[game->length + 1] = '\0';
	} else {
		system( "clear");
		exit(1);
	}
	
	return game;
}

// update current game
void update( state_t game, char guess )
{
	int founded = 0;
	for (int i = 0; i < game->length; ++i)
	{
		if (game->password[i] == guess) {
			game->secret[i] = guess;
			founded = 1;
		}
	}
	if(!founded) {
		game->misses[2 * game->missed ]     = guess;
		game->misses[2 * game->missed + 1 ] = ' ';
		game->missed++;
	}
}

int play( void )
{
	system( "clear" );
	welcome( );
	state_t state = init();

	logicOfTheGame(state);

	return 0;
}

void logicOfTheGame ( state_t state ) {
	while (state->missed < GAME_OVER && state->win != 1) {
		display(state);
		update(state, (char)tolower(getch()));

		display(state);
		printf("\n   password:");
		
		char * pass = getstr(state->length);
		//se compara el estado acutal del secret y vemos si la palabra ingresada es correcta
		if(!strcmp(state->password, pass) || !strcmp(state->password, state->secret))  {
			state->win = 1;
		}
		printf( "\n" );
		flush();
	}

	if(state->win || state->missed < GAME_OVER) {
		win();
	} else {
		printf("	The word was: %s\n", state->password);
		lose();
	};
}