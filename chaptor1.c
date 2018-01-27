#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 100
#define NUM_TRIES_ALLOWED 5
char new_file[MAX];
int count_of_correct_word=0;
int count_of_wrong_word=0;
int point[50];
int score=0;
int point_count=0;
struct guess_word{
	char word[30];
	struct guess_word *next;
};
struct person{
	char topic[MAX][MAX];
	int  max_score[MAX];
};
struct guess_word * create_node_word(char *word_file);
void add_end(struct guess_word *list, char *word_file);
struct person * create_node_person(char *player_name , int score , int field);
void main_menu(char *name);
void hang(int sid);
void insert_file();
int check_finish(char input);
int game(char *word_to_guess);
void game_menu_plus(char *player_name);
void one_player_backend(char *name , char topic[100] );
void two_person_game();
void game_menu(char *player_name);
void topic_menu(char *player_name);
void find_record(char *name);
int check_is(char *word , char *name);
int check_name(char *name);

int main(){
	int code=0;
	char player_name[50];
	printf("Name :"); gets(player_name);
	main_menu(player_name);
	while(1){
		scanf("%d" , &code);
//		system("cls");
		if(code == 1){
			game_menu(player_name);
			break;
		}
		if(code == 2){
			check_name(player_name);
		}
		if(code == 3){
			printf("Name the file that you want to create :");scanf("%s" , new_file);
			insert_file(new_file);
			system("cls");
			main_menu(player_name);
		}
		if(code == 4){
			return -1;
		}
	}
}
struct guess_word * create_node_word(char *word_file){
	struct guess_word *tt = (struct guess_word*)malloc(sizeof(struct guess_word));
	strcpy(tt->word,word_file);
	tt->next = NULL;
	return tt;
}
void  add_end(struct guess_word *list, char *word_file)
{
    struct guess_word *newnode=(struct guess_word *) malloc(sizeof(struct guess_word));
    struct guess_word *cur;
    for (cur=list ; cur->next!=NULL ; cur=cur->next);

    strcpy(newnode->word , word_file);
    cur->next=newnode;
    newnode->next=NULL;
}
//struct person * create_node_person(char *player_name , int score , int field){
//	 struct person* t = (struct person*)malloc(sizeof(struct person));
//	 strcpy(t->name,player_name);
//	 t->max_score[field] = score;
//	 t->next = NULL;
//}
void main_menu(char *name){
	printf("welcome %s i hope you enjoy this shit\n", name);
	printf("1_new game                                                _________ \n");
	printf("2_load game                                               |       | \n");
	printf("3_add a new file                                          |       | \n");
	printf("4_Exit this shit                                          |       | \n");
	printf("                                                         \\O/      | \n");
	printf("                                                         (_)      | \n");
	printf("                                                         / \\      |\n");
	printf("                                                                 /_\\ \n");
	printf("                                                                /___\\ \n");
	printf("                                                               /_____\\ \n");
	printf("                                          ____________________/_______\\_____ \n");
}
void hang(int sid){
	printf("%d\n\n" , score);
	switch(sid){
		case 0:
			{
				printf("    _____             correct word guessed :%d    wrong word guessed :%d\n" ,count_of_correct_word , count_of_wrong_word);
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
				printf("     _____            correct word guessed :%d    wrong word guessed :%d\n" ,count_of_correct_word , count_of_wrong_word);
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
				printf("     _____            correct word guessed :%d    wrong word guessed :%d\n" ,count_of_correct_word , count_of_wrong_word);
				printf("    |    |\n");
				printf("    O    |\n");
				printf("   (_)   |\n");
				printf("         |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n");
				break;
			}
		case 3:
			{
				printf("     _____            correct word guessed :%d    wrong word guessed :%d\n" ,count_of_correct_word , count_of_wrong_word);
				printf("    |    |\n");
				printf("    O    |\n");
				printf("   (_)   |\n");
				printf("   /     |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n");
				break;
			}
		case 4:
			{
				printf("     _____            correct word guessed :%d    wrong word guessed :%d\n" ,count_of_correct_word , count_of_wrong_word);
				printf("    |    |\n");
				printf("    O    |\n");
				printf("   (_)   |\n");
				printf("   / \\   |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n");
				break;
			}
		case 5:
			{
				printf("shit , he's dead!! \n Game Over !!\n");
				printf("     _____\n");
				printf("    |    |\n");
				printf("   \\O/   |\n");
				printf("   (_)   |\n");
				printf("   / \\   |\n");
				printf("         |\n");
				printf("        / \\ \n");
				printf("       /   \\ \n");
				break;
			}
	}
}
void insert_file(char *new_file){
	int num , i;
	char inword[MAX];
	FILE *nf;
	FILE *af;
	char dest[MAX] , src[MAX];
	strcpy( dest , new_file);
	strcpy( src , ".txt");
	strcat( dest , src);
	af = fopen("files\\AVAILABLE_TOPICS.txt" , "a");
	fprintf(af , "\n%s" , dest);
	fclose(af);
	strcpy( src , "files\\\\");
	strcat(src , dest);
	nf = fopen(src , "w");
	printf("how many word do you want to insert\n");
	scanf("%d" , &num);
	for(i=0 ; i<num ; i++){
		scanf("%s" , inword);
		fprintf(nf , "%s\ " , inword);
	}
	fclose(nf);
}
int check_finish(char input){
	if(input == 'Q'){ return 1;} /* player wants to leave the game*/
	else return 0;
}
int game(char *word_to_guess){
	point_count = 0;
	int num_letters      = 0, /* length of word char array */
       count             = 0,  /* for word char array       */
       tries             = 0,  /* total tries user has used */
       num_vis_chars     = 0,  /* # of visible characters   */
       correct_guesses   = 0,  /* # of correct guesses      */
       correct_flag      = 0,  /* was guess correct?        */
       repeat_flag       = 0;  /* was guess a repeat?       */
   char guess;
   /* array declarations */
   char incorrect_letters[255] = " ";
   /* get word */
   num_letters = strlen(word_to_guess);
   char visible_word[num_letters]; /* displays correct guesses */
   /* initialize visble_word */
   for( count = 0; count < num_letters; count++ )
      visible_word[count] = '-';
   visible_word[num_letters] = '\0';
   system("cls");
   hang( tries );
   while( tries < NUM_TRIES_ALLOWED )
   {
      printf( "WORD: %s\n", visible_word );
      printf( "Incorrect Guesses: %s\n", incorrect_letters );
      printf( "\nGuess a letter (and press 'Enter'): " );
      scanf( " %c", &guess );
	  if(check_finish(guess) == 1){
	  	return 0;
	  }
      /* match guess against previous guesses */
      for( count = 0; count < num_letters; count++ )
         if( guess == visible_word[count] || guess == incorrect_letters[count] )
         {
            repeat_flag  = 1;
            correct_flag = 1;
            break;
     	}
      if( repeat_flag == 0 )
         /* check for matches in string */
         for( count = 0; count < num_letters; count++ )
         {
            if( guess == word_to_guess[count] )
            {
               visible_word[count] = guess;
               correct_guesses++;

               if( correct_guesses == num_letters )
               {             		
               		system("COLOR 27");
               		count_of_correct_word++;
                	puts( "\n\nCONGRATULATIONS! You guessed the word!" );
                	printf( "WORD: %s\n\n", visible_word );
                	point[point_count] = num_letters*3 - tries; 
                	score = score + point[point_count];
                	point_count++;
                	Sleep(500); 
                	system("COLOR 07");
                	return -1;;
               }
               correct_flag = 1;
            }
         }

      if( correct_flag == 0 )
      {
         incorrect_letters[tries] = guess;
         tries++;
      }
      /* reset flags */
      repeat_flag  = 0;
      correct_flag = 0;
      system("cls");
      hang( tries );
   }
   system("COLOR 4F");
   count_of_wrong_word++;
   Sleep(1000);
   system("COLOR 07");
   printf( "WORD: %s\n\n", word_to_guess );
}
void game_menu_plus(char *player_name){
	system("cls");
	int i , code=0 , sid=0;
	char topic_names[MAX][MAX] , choose_topic[MAX] , buff[1000] , c;
	FILE *fpat ;
	printf("1_resume game\n2_quit to main menu\n3_quit the game\n");
	scanf("%d" , &sid);
	if(sid == 1){topic_menu(player_name);}
	if(sid == 2){
		system("cls");
		main_menu(player_name);
	}
	if(sid == 3){
		exit(0);
	}
}
void one_player_backend(char *name , char topic[100] ){
	char buff[100];
	char word_from_file[100];
	FILE *fpt;
	fpt = fopen( topic , "r" );
	if(fpt == NULL){
		printf("Cannot open the topic file");
		exit(0);
	}
	struct guess_word *head;
	//head = (struct guess_word *)malloc(sizeof(struct guess_word));
	fscanf(fpt,"%s",word_from_file);
	head=create_node_word(word_from_file);
	while(feof(fpt)==0){
		fscanf(fpt , "%s" , word_from_file);
		add_end(head,word_from_file);
	}
	struct guess_word *curent = head;
	printf("now game will begin so if you want to stop it enter Q \n");
	//clock_t  begin= clock() ;//process begins
	while(1){
		int sag = game(curent->word);
		if(sag==0){
			break;
		}
		if(curent->next == NULL){
			break;
		}
		curent=curent->next;
	}
	//clock_t end= clock ;//process ends
	//int timespent= end-begin/(CLOCKS_PER_SEC*10000000);
	//score = score/timespent;
//	printf("%d\n" , timespent);
//	printf("%d\n" , timespent);
	//Sleep("1000");
	FILE *fps;             /*file personal score*/
	char dest[MAX] , src[MAX];
	strcpy( dest , name);
	strcpy( src , ".txt");
	strcat( dest , src);
	strcpy( src , "names\\\\");
	strcat(src , dest);
	fps = fopen( src , "a+");
	fprintf(fps , "\n%s %d ", topic , score );
	fclose(fps);
	fclose(fpt);
	score = 0;
	point_count=0;
	game_menu_plus(name);
}
void two_person_game(){
	int num_letters      = 0, /* length of word char array */
       count             = 0,  /* for word char array       */
       tries             = 0,  /* total tries user has used */
       num_vis_chars     = 0,  /* # of visible characters   */
       correct_guesses   = 0,  /* # of correct guesses      */
       correct_flag      = 0,  /* was guess correct?        */
       repeat_flag       = 0;  /* was guess a repeat?       */
   char guess;
   /* array declarations */
   char word[255]              = " ";
   char hint[255]              = " ";
   char incorrect_letters[255] = " ";
   /* get word */
   puts( "Enter a word for player to guess." );
   scanf("%s" , word);
   puts( "Give the player a very short hint." );
   scanf("%s" , hint);
   num_letters = strlen( word );
   char visible_word[num_letters]; /* displays correct guesses */
   /* initialize visble_word */
   for( count = 0; count < num_letters; count++ )
      visible_word[count] = '-';
   visible_word[num_letters] = '\0';
   system("cls");
   printf( "HINT: %s\n\n", hint );
   hang( tries );
   while( tries < NUM_TRIES_ALLOWED )
   {
      printf( "WORD: %s\n", visible_word );
      printf( "Incorrect Guesses: %s\n", incorrect_letters );
      printf( "\nGuess a letter (and press 'Enter'): " );
      scanf( " %c", &guess );
      /* match guess against previous guesses */
      for( count = 0; count < num_letters; count++ )
         if( guess == visible_word[count] || guess == incorrect_letters[count] )
         {
            repeat_flag  = 1;
            correct_flag = 1;
            break;
     	}
      if( repeat_flag == 0 )
         /* check for matches in string */
         for( count = 0; count < num_letters; count++ )
         {
            if( guess == word[count] )
            {
               visible_word[count] = guess;
               correct_guesses++;
               if( correct_guesses == num_letters )
               {
                  puts( "\n\nCONGRATULATIONS! You guessed the word!" );
                  printf( "WORD: %s\n\n", visible_word );
                  exit( 0 );
               }
               correct_flag = 1;
            }
         }
      if( correct_flag == 0 )
      {
         incorrect_letters[tries] = guess;
         tries++;
      }
      /* reset flags */
      
      repeat_flag  = 0;
      correct_flag = 0;
      system("cls");
      puts( "\nHANGMAN" );
      printf( "HINT: %s\n\n", hint );
      hang( tries );
   }
   system("COLOR 4F");
   printf( "WORD: %s\n\n", word );
   Sleep("1000");
   system("COLOR 07");
   return -1;
}
void game_menu(char *player_name){
	system("cls");
	int sid=0;
	printf("How do you like to play?\n1_againts computer\n2_againts your friend\n");
	scanf("%d" , &sid);
	if(sid == 1){ topic_menu(player_name);}
	if(sid == 2){
		system("cls");
		two_person_game();
	}
}
void topic_menu(char *player_name){
	
	char choose_topic[MAX] , buff[1000] , c;
	FILE *fpat ;
	printf("which field you like to play in %s ? \n" , player_name);
		fpat = fopen("files\\AVAILABLE_TOPICS.txt" , "r");
		while((c = fgetc(fpat)) != EOF){
			printf("%c" , c);
		}
		//printf("(enetr < files\\\\ > befor the name of file)\n");
		scanf("%s" , buff);
		char dest[MAX] , src[MAX];
		strcpy( dest , buff);
		strcpy( src , ".txt");
		strcat( dest , src);
		strcpy( src , "files\\\\");
		strcat(src , dest);
		one_player_backend(player_name , src);
}
int check_name(char *name){
	
	char names[MAX];
	FILE *fpin;
	fpin = fopen("names\\names.txt" , "r");
	if(fpin == NULL){
		printf("Cannot open the names file");
		exit(0);
	}
	while(feof(fpin)==0){
		fscanf(fpin , "%s" , names);
		if(check_is(names , name) == 0){break ;}
		else{
			printf("you did not register befor\n");
			exit(0);
		}
	}
	find_record(name);
}
int check_is(char *word , char *name){
	int length_name = strlen(name);
	int length_word = strlen(word);
	printf("%s\n" , name);
	printf("%d\n" , length_name);
	printf("%s\n" , word);
	printf("%d\n" , length_word);
	if(length_name != length_word){
		return 0;
	}
	int i;
	for ( i = 0; i < length_name; i++){
		if ((word+i) != (name+i)) {
			return 0;
		}
	}
	return 1;
}
void find_record(char *name){
	int record ,i=0 ;
	char field[MAX];
	char dest[MAX] , src[MAX];
	strcpy( dest , name);
	strcpy( src , ".txt");
	strcat( dest , src);
	strcpy( src , "names\\\\");
	strcat(src , dest);
	FILE *pf;
	pf = fopen(src , "r");
	if(pf == NULL){
		printf("Cannot open the name file");
		exit(0);
	}
	while(feof(pf)==0){
		fscanf(pf , "%s %d\n" , field , &record);
		printf("%s : %d\n" , field , record);
	}
}
