#include <ncurses.h>
#include <unistd.h>

#include <menu.h>
#include <string.h>
#include <stdlib.h>
#define ENTER 10


void LogoEngi(int delay);	//tampilin logo engi...
void LoadData();			//load game data... username, dkk
int  ChooseMenu();			//tampilin menu -> pilih menu
void NewGame();				//input nama -> game: data nama
void LoadGame();			//game: data nama -> main
void StartGame();			//game: data nama -> main
void ShowCredit();

char *concat(const char *s1, const char *s2);

//global variabel
char *ListUserName[] = {"keka", "fio", "wanul", "dandi", "al"};
char *UserName = "Guest";

///////////////////////////////////////////////////////////////////////////////

int main()
{
	LogoEngi(2);
	LoadData();
	
	int pilihan;
	while((pilihan = ChooseMenu()) != -999){
		LogoEngi(0);
		switch(pilihan){
	        case 1	:{	NewGame();
						break;}
						
			case 2	:{	LoadGame();
						break;}
						
			case 3	:{	StartGame();
						break;}
		};
		// ngeupdate UserName
	}; 
	
	LogoEngi(1);
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void LogoEngi(int delay) {
	initscr();
	noecho();
	curs_set(FALSE);

	//posisi agar outputnya centered
	int S = COLS/2 - 58;

	mvprintw(5 , S,"                                                                                                                    ");
	mvprintw(6 , S,"!|!|!|!|  !|      !|    !|!|!|  !|!|!|      !|    !|  !|!|!|  !|!|!|!|!|    !|!|!|  !|    !|  !|!|!|!|  !|      !|  ");
	mvprintw(7 , S,"!|        !|!|    !|  !|          !|        !|  !|      !|        !|      !|        !|    !|  !|        !|!|    !|  ");
	mvprintw(8 , S,"!|!|!|    !|  !|  !|  !|  !|!|    !|        !|!|        !|        !|      !|        !|!|!|!|  !|!|!|    !|  !|  !|  ");
	mvprintw(9 , S,"!|        !|    !|!|  !|    !|    !|        !|  !|      !|        !|      !|        !|    !|  !|        !|    !|!|  ");
	mvprintw(10, S,"!|!|!|!|  !|      !|    !|!|!|  !|!|!|      !|    !|  !|!|!|      !|        !|!|!|  !|    !|  !|!|!|!|  !|      !|  ");
	mvprintw(11, S,"                                                                                                                    ");
	mvprintw(12, S,"                                                                                                                    ");
	mvprintw(13, S,"                                                                                                      ");
	mvprintw(14, S,"    	  !|!|!|!|  !|      !|  !|!|!|      !|!|    !|      !|    !|!|!|  !|!|!|    !|!|    !|      !|  !|  ");
	mvprintw(15, S,"    	  !|          !|  !|    !|    !|  !|    !|  !|!|    !|  !|          !|    !|    !|  !|!|    !|  !|  ");
	mvprintw(16, S,"    	  !|!|!|        !|      !|!|!|    !|!|!|!|  !|  !|  !|    !|!|      !|    !|    !|  !|  !|  !|  !|  ");
	mvprintw(17, S,"    	  !|          !|  !|    !|        !|    !|  !|    !|!|        !|    !|    !|    !|  !|    !|!|      ");
	mvprintw(18, S,"    	  !|!|!|!|  !|      !|  !|        !|    !|  !|      !|  !|!|!|    !|!|!|    !|!|    !|      !|  !|  ");
                                                                                                                                                                                                                                                                         
	refresh();
	sleep(delay);
	endwin();
}

char *concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void LoadData(){
	//baca dari sebuah file username yang sudah ada
	//simpan ke global variabel
}

int ChooseMenu(){
    WINDOW *my_menu_win;
	ITEM **my_items;
	MENU *my_menu;
	
	char *choices[] = {	"New Game", "Load Game", "Start Game", "Exit"};
	int n_choices   = 4;
	int c;				
    int i;
	
	/* Initialisasi curses */
	initscr();
    cbreak();
    noecho();
	
	keypad(stdscr, TRUE);

	/* Create items */
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; i++)
                my_items[i] = new_item(choices[i], "");

	/* Crate menu */
		my_menu = new_menu((ITEM **)my_items);

	/* Create the window to be associated with the menu*/
		int S =  COLS/2 - 20;
        my_menu_win = newwin(8, 30, 20, S);
        
        char *lalala = concat("PILIHAN MENU, ", UserName);
        
      	mvprintw(21, S+8, lalala);
        keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 0, 0, 3, 9));
		set_menu_format(my_menu, 4, 1);
			
	/* Print a border around the main window and print a title */
    	box(my_menu_win, 0, 0);
		mvwhline(my_menu_win, 2, 0, ACS_HLINE, 30);
        
	/* Post the menu */
		post_menu(my_menu);
		wrefresh(my_menu_win);
		refresh();

	/* Moving the menu */
	while((c = wgetch(my_menu_win)) != ENTER){
		switch(c){
	        case KEY_DOWN:	menu_driver(my_menu, REQ_DOWN_ITEM);
							break;
			case KEY_UP:	menu_driver(my_menu, REQ_UP_ITEM);
							break;}
           	wrefresh(my_menu_win);
	};	
	
	/* Dapatkan menu yang user pilih, compare string*/
	int result;
	if 		(item_name(current_item(my_menu)) == "New Game")
		result = 1;
	else if (item_name(current_item(my_menu)) == "Load Game")
		result = 2;
	else if (item_name(current_item(my_menu)) == "Start Game")
		result = 3;
	else if (item_name(current_item(my_menu)) == "Exit")
		result = -999;

	/* Unpost and free all the memory taken up */
        unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	clear();
	endwin();
	return result;
}

#include <assert.h>
#include <form.h>


void NewGame(){
	//baca input nama user
	//cek apakah nama exist di global variabel
	//jika tidak, tambahkan ke global variabel
	
	//next next level: jika ada, warn user progress gamenya bakal dioverwrite
	
}
void LoadGame(){
	//cetak global var
	//ubah UserName
	//mungkin progress nol
}
void StartGame(){
	//cetak global var
	//main dengan username UserName
}
void ShowCredit(){
	//pass
}


