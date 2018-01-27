#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void show(char *name){
	printf("welcome %s i hope you enjoy this shit\n", name);
	printf("1_new game                                                _________ \n");
	printf("2_load game                                               |       | \n");
	printf("3_Exit this shit                                          |       | \n");
	printf("                                                          |       | \n");
	printf("                                                          O       | \n");
	printf("                                                        -(_)-     | \n");
	printf("                                                         / \\      |\n");
	printf("                                                                 /_\\ \n");
	printf("                                                                /___\\ \n");
	printf("                                                               /_____\\ \n");
	printf("                                          ____________________/_______\\_____ \n");
}
void hang(int sid){
	switch(sid){
		case 0:
			{
				printf("    _____\n");
				printf("         |\n");
				printf("         |\n");
				printf("         |\n");	
				printf("         |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n"); 
				break;
			}
		case 1:
			{
				printf("     _____\n");
				printf("    |    |\n");
				printf("    O    |\n");
				printf("         |\n");	
				printf("         |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n"); 
				break;
			}
		case 2:
			{
				printf("     _____\n");
				printf("    |    |\n");
				printf("    O    |\n");
				printf("    |    |\n");	
				printf("    |    |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n"); 
				break;	
			}
		case 3:
			{
				printf("     _____\n");
				printf("    |    |\n");
				printf("    O    |\n");
				printf("    |    |\n");	
				printf("    |    |\n");
				printf("   /     |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n"); 	
				break;
			}
		case 4:
			{
				printf("     _____\n");
				printf("    |    |\n");
				printf("    O    |\n");
				printf("    |    |\n");	
				printf("    |    |\n");
				printf("   / \\   |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n"); 
				break;
			}
		case 5:
			{
				printf("shit , he's dead!! \n Game Over !!\n");
				printf("     _____\n");
				printf("    |    |\n");
				printf("    O    |\n");
				printf("   _|_   |\n");	
				printf("    |    |\n");
				printf("   / \\   |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n"); 
				break;
			}
	}
}

void game_start(){
	int i;
	char topic_names[MAX][MAX] , choose_topic[MAX] , buff[1000];
	FILE *fpat ;
	FILE *fpct ;
	fpat = fopen("AVAILABLE_TOPICS.txt" , "r");
	if(fpat == NULL){
		printf("Cannot open the topcis file");
		return -1;
	}
	printf("These are opics of this game\n\n");
	for(i=0 ; i<=5 ; i++){
		fscanf(fpat , "%s" , &topic_names[i]);
		printf("%s\n" , topic_names[i]);
	}
	fclose(fpat);
	printf("Name of the chose field : \n"); scanf("%s" , &choose_topic);
	fpct = fopen(choose_topic , "r");
	if(fpct == NULL){
		printf("Cannot open the topcis file");
		return -1;
	}
	while(fgets(buff, 999 , fpct) != NULL)
	printf("%s" , buff);
}
int main(){
	int code=0;
	char player_name[50];
	printf("Name :"); gets(player_name);
	while(1){
		show(player_name);
		scanf("%d" , &code);
		if(code == 1){
			game_start();
			break;
		}
		if(code == 3){
			return -1;
		}
	}
}
