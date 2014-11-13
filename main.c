/**
 * @file main.c
 * @brief Start point for the program
 *
 * @author Brooks Kindle
 * @date Nov. 12th, 2014
 */

#include <stdio.h>
#include <ncurses.h>

int main(void) {
	char ch = 0,
		 *devname = "/dev/tty2";
	FILE *dev = NULL;

	dev = fopen(devname, "w");
	if(!dev) { //unable to open terminal
		fprintf(stderr, "Unable to open %s..quitting\n", devname);
	}
	////////////////
	//init ncurses//
	////////////////
	initscr();
	raw();
	noecho(); //prevent echoing user input

	printw("Welcome to BTSEND...");
	printw("Press Ctrl-C to exit\n");
	
	ch = getch();
	while(ch != '\3') { //loop until Ctrl-C entered
		fprintf(dev, "%c", ch); //send user input
		printw("%c", ch);
		refresh(); //refresh screen so characters display
		ch = getch(); //get user input
	}//end while

	printw("Thank you for using btsend.\n");
	printw("Press <any> key to continue.\n");
	refresh();
	getch();
	endwin();
	return 0;
}//end main
