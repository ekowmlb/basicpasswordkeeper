#include <stdio.h>
#include <stdlib.h>
int i;
typedef struct Website {
	char websitename[100];
	char username[256];
	char password[256];
	//char phint[70]; password hint
	char desciption[1024];

} website;
website *website_collection;
/* void readin(char s[],int maxlen) {
	int i = 0;
	char ch;
	int isDone = 0;
	while (!isDone) {
		ch = getchar();
	if (s[i] == EOF || s[i] == '\n') {

		isDone = 1;
	}
	if (i < maxlen-1) {
		s[i] = ch;

	}
	i += 1;


	}
	s[i] = '\0';


} */
int loadup(char *name) {
	FILE *f = fopen(name,"rb");
	int howmany;
	int endbit;
	if  (f == 0 ) {
		printf("Error.");
		return 0;
	}
	fseek(f,0,SEEK_END);
	endbit = ftell(f);
	howmany = endbit / sizeof(website);
	return howmany;

}
void addnewwebsite() {

	/* printf("Enter website name:");
	scanf("%s",website_collection[i].websitename);
	printf("\n Enter username:");
	scanf("%s",website_collection[i].username);
	printf("\n Enter password:");
	scanf("%s",website_collection[i].password);
	printf("\n Enter password hint (if any (leave blank for none)):");
	scanf("%s",website_collection[i].phint);
	printf("\n Enter desciption of what its for (leave blank for none):");
	scanf("%s",website_collection[i].desciption);
	FILE *fp = fopen("website","wb");
	i++;
	fwrite(website_collection,sizeof(website),i,fp);
						*/
	char filename[100];
	struct Website websiteins;
		printf("Enter website:");
		scanf("%s",websiteins.websitename);
		fflush(stdin);
		strcpy(filename,websiteins.websitename);
		printf("\n Enter username:");
		scanf("%s",websiteins.username);
		fflush(stdin);
		printf("\n Enter password:");
		scanf("%s",websiteins.password);
		// printf("\n Enter password hint (if any (leave blank for none)):");
		// scanf("%s",websiteins.password);
		fflush(stdin);
		printf("\n Enter desciption of what its for (leave blank for none):");
		scanf("%s",websiteins.desciption);
		fflush(stdin);
		FILE *fp = fopen(filename,"wb");
		fwrite(&websiteins,sizeof(websiteins),1,fp);
		printf("Thank You! Your file has been saved as: %s\n",filename);
		fclose(fp);


}
void removewebsite() {


}
void editwebsite() {
	struct Website read;
	char filename[100];
	// printf("You have %d websites stored\n",many);
	printf("What website are you looking for? ( same one as before )\n");
	fscanf(stdin,"%s",filename);
	FILE *fp = fopen(filename,"rb");
	fread(&read,sizeof(read),1,fp);
	printf("Website Name:%s\nUsername:%s\nPassword:%s\n",read.websitename,read.username,read.password);
	printf("Description:%s\n",read.desciption);

}
int main() {
	 website_collection = malloc(sizeof(website) * 1000);
	 short int d = 0;
	 whatever:;
	 d = 0;
	printf("\n");
	while (d != 4) {
	d = 0;
	fflush(stdin);
	puts("	---Password keeper---	");
	puts("1.Add New Website");
	puts("2.Remove a Website");
	puts("3.Edit/Look/Find a Website");
	puts("4.Quit");
	puts("Will Be Copyrighted.");
	scanf("%d",&d);
	switch (d) {
	case 1:
		addnewwebsite();
	break;
	case 2:
		removewebsite();
		break;
	case 3:
		editwebsite();
		break;
	case 4:
		return 0;
		break;
	default:
		puts("Invaild input.Try again");
		system("clear");
		goto whatever;
		break;

	}

	}
	return 0;
}
