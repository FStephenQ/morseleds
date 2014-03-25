#include <stdio.h>
#include <stdlib.h>
#define dot "setleds -L +num < /dev/tty1; sleep 1s; setleds -L -num < /dev/tty1"
#define dash "setleds -L +num < /dev/tty1; sleep 2s; setleds -L -num < /dev/tty1"
#define pause "setleds -L -num < /dev/tty1; sleep 3s"

#define ERR1 "Cannot open file\n"
#define ERR2 "Leds must be run as superuser\n"


void processchar(char hold);
	

int main(int argc, char* argv[]){
	if(geteuid() != 0){
		printf(ERR2);
		exit(2);
	}
	FILE *input = stdin;
	if(argv[1] != '-'){
		input = fopen(argv[1], "r");
		if(input == 0){
			printf(ERR1);
			exit(1);
		}
	}
	int hold = fgetc(input);
	while(hold != EOF){
	//	printf("%c\n", hold); debug line
		if( hold > 90 ){
			hold -= 32;
		}
		if(hold == 32){
			system(pause);
		}
		else{
			processchar((char)hold);	
		}
		hold = fgetc(input);
	}
	fclose(input);
	exit(0);
}

void processchar(char hold){
switch(hold){
	case 'V': system(dot);
	case 'U': system(dot);
	case 'A': system(dot);
	case 'T':system(dash);
		 break;
	
	case 'L': system(dot);
	case 'D':system(dash);
	case 'I': system(dot);
		  system(dot);
		  break;
	
	case 'C':system(dash);
	case 'R':system(dot);
	case 'N': system(dash); 
	case 'E':system(dot);
		 break;
	
	case 'Y': system(dash);
	case 'W': system(dot);
	case 'M': system(dash);
		  system(dash);
		  break;
	
	case 'B': system(dash);
	case 'S': system(dot);
		  system(dot);
		  system(dot);
		  break;

	case 'P': system(dot);
	case 'G': system(dash);
		  system(dash);
		  system(dot);
		  break;

	case '2':system(dot);
	case 'J':system(dot);
	case 'O':system(dash);
		 system(dash);
		 system(dash);
		 break;

	case 'Q': system(dash);
	case 'K': system(dash);
		  system(dot);
		  system(dash);
		  break;
	
	case 'F': system(dot);
		  system(dot);
		  system(dash);
		  system(dot);
		  break;
	
	case 'H': system(dot);
		  system(dot);
		  system(dot);
		  system(dot);
		  break;

	case 'X': system(dash);
		  system(dot);
		  system(dot);
		  system(dash);
		  break;
	
	case 'Z': system(dash);
		  system(dash);
		  system(dot);
		  system(dot);
		  break;
	
	default:system(pause);
		break;
}
system(pause);
}
