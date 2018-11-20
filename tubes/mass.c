#include <ncurses.h>


void BoxUserName();
void BoxMoney();
void BoxLife();
void BoxTime();
void BoxWaitingCust();
void BoxOrder();
void BoxFoodStack();
void BoxHand();
void BoxMap();

int main() {
	BoxUserName("keka.vigi");
	BoxMoney(321212);
	BoxLife(3);
	BoxTime();
	BoxWaitingCust();
	BoxOrder();
	BoxFoodStack();
	BoxHand();
	BoxMap();
	
	sleep(10);
	endwin();
    return 0;

}

void BoxUserName(char *name){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(3, 2+10, 0, 0);
    box(win, 0 , 0);
    mvprintw(1,1,name);
	wrefresh(win);
}

void BoxMoney(int money){
	WINDOW *win;
	
	char str[12];
	sprintf(str, "%d", money);
	
    initscr();
    refresh();
 
    win = newwin(3, 2+15, 0, 12);
    box(win, 0 , 0);
    mvprintw(1,13, "MONEY:");
    mvprintw(1,19, str);
	wrefresh(win);
}

void BoxLife(int left){
	WINDOW *win;

	char str[12];
	sprintf(str, "%d", left);
    initscr();
    refresh();
 
    win = newwin(3, 2+10, 0, 29);
    box(win, 0 , 0);
    mvprintw(1,30, "LIFE:");
    mvprintw(1,30+5, str);
	wrefresh(win);
}

void BoxTime(){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(3, 2+10, 0, 53);
    box(win, 0 , 0);
	wrefresh(win);
}

void BoxWaitingCust(){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(10, 2+10, 3, 0);
    box(win, 0 , 0);
	wrefresh(win);
}

void BoxOrder(){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(10, 2+10, 13, 0);
    box(win, 0 , 0);
	wrefresh(win);
}

void BoxFoodStack(){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(10, 2+10, 3, 49);
    box(win, 0 , 0);
	wrefresh(win);
}

void BoxHand(){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(10, 2+10, 13, 49);
    box(win, 0 , 0);
	wrefresh(win);
}

void BoxMap(){
	WINDOW *win;
 
    initscr();
    refresh();
 
    win = newwin(20, 2+34, 3, 12);
    box(win, 0 , 0);
	wrefresh(win);
}

