#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct subdir
{
	char sbDirName[10],parentDirName[10],fname[10][10];
	int fcnt;
};
struct
{
	char dname[10],fname[10][10],parentDir[10];
	struct subdir *SubDirectory[10];
	int fcnt,subcnt;
}dir[10];

int main()
{
	int i,ch,dcnt,k;
	char f[30], d[30],sbd[30],master[15];
	dcnt=0;
	printf("Welcome to Tree structured Directory.\n");
	printf("Enter the name of the Master Directory:\t");
	scanf("%s",master);
	printf("\n");
	while(1)
	{
	printf("1.Create Directory\t2.Create Sub Directory\t3.Create File\n4.Delete File\t5.Delete file in Sub Directory");
		printf("\t6.Display Directories\n7.Display Sub Directory\t8.Search File\t9.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		       case 1:
				{
					printf("\nEnter name of directory: ");
					scanf("%s", dir[dcnt].dname);
					strcpy(dir[dcnt].parentDir,master);
					dir[dcnt].fcnt=0;
					dcnt++;
					printf("Directory created");
					printf("\n\n");
				}
				break;
	
			case 2:
				{
			       printf("\nEnter Directory into which Sub Directory is to be created: ");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
				if(strcmp(d,dir[i].dname)==0)
				{
				struct subdir *sd =(struct subdir*)malloc(sizeof(struct subdir));
						strcpy(sd->parentDirName,dir[i].dname);
						printf("Enter name of newly Sub Directory: ");
						scanf("%s",sd->sbDirName);
						dir[i].SubDirectory[dir[i].subcnt] = sd;
						dir[i].subcnt++;
						printf("SubDirectory created");
						printf("\n\n");
						break;
				}
					if(i==dcnt)
						printf("\nNo Such Directory exist");
						printf("\n\n");
				}break;

			case 3:
				{
					printf("\nEnter name of the Directory : ");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
				  if(strcmp(d,dir[i].dname)==0)
				      {
					if(dir[i].subcnt>0)
					{
				        printf("Whether to place the file in any Sub Directory(y/n): ");
							char c;
						scanf(" %c",&c);
						if(c=='y')
						{
						printf("Enter name of Sub Directory: ");
							scanf("%s",sbd);  						                                      for(int j=0;j<dir[i].subcnt;j++)
						{
				           	if(strcmp(sbd,dir[i].SubDirectory[j]->sbDirName)==0)
						{
						printf("Enter name of the file: ");				            	scanf("%s",dir[i].SubDirectory[j]->fname[dir[i].SubDirectory[j]->fcnt]);
										
							dir[i].SubDirectory[j]->fcnt++;
							printf("File created in Sub Directory");
								printf("\n\n");
								goto break1;
									}
									if(j == dir[i].subcnt) 										printf("No such Sub Directory");
								}
							}
							else 
							{
								printf("OK then ");
								goto n_cr;
							}
						}
							n_cr:
								printf("Enter name of the file: ");
								scanf("%s",dir[i].fname[dir[i].fcnt]);
								dir[i].fcnt++;
								printf("File created in Directory");
								printf("\n\n");
						break;
					}
					if(i==dcnt)
					printf("Directory %s not found\n",d);
				}
				break1:break;

			case 4:
				{
					printf("\nEnter name of the Directory: ");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
					{
						if(strcmp(d,dir[i].dname)==0)
						{
							printf("Enter name of the file: ");
							scanf("%s",f);
							for(k=0;k<dir[i].fcnt;k++)
							{
								if(strcmp(f, dir[i].fname[k])==0)
								{
									printf("File %s is deleted ",f);
									dir[i].fcnt--;
									strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
									printf("\n\n");
									goto jmp;
								}
							}
							printf("File %s not found",f);
							printf("\n");
							goto jmp;
						}
					}
					printf("Directory %s not found",d);
					printf("\n");
				}jmp : break;

	
			case 5:
				{
					printf("\nEnter name of the Directory: ");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)	
					{
					if(strcmp(d,dir[i].dname)==0)
					{
					printf("Enter name of Sub Directory: ");
						scanf("%s",sbd);										for(int j=0;j<dir[i].subcnt;j++)
					{
					if(strcmp(sbd,dir[i].SubDirectory[j]->sbDirName)==0)
							{
							printf("Enter name of the file: ");
							scanf("%s",f);										for(k=0;k<dir[i].SubDirectory[j]->fcnt;k++)
							{
					if(strcmp(f, dir[i].SubDirectory[j]->fname[k])==0)
						{														printf("File %s is deleted ",f);
							printf("\n\n");
																				dir[i].SubDirectory[j]->fcnt--;
																			strcpy(dir[i].SubDirectory[j]->fname[k],
												dir[i].SubDirectory[j]->fname[dir[i].SubDirectory[j]->fcnt]);
											goto jmp2;
										}
									}
									printf("File %s not found",f);
									printf("\n");
									goto jmp2;	
							}
							printf("Sub Directory %s Not found",sbd);
								printf("\n\n");
								goto jmp2;
							}
						}
					}
					printf("Directory %s not found",d);
					printf("\n\n"); 
				}

				jmp2: break;

			case 6:
				{
					if(dcnt==0)
					printf("\nNo Directory found");
					else
					{
						printf("\nDirectory\t\t\tSub Directories\t\tFiles");
						for(i=0;i<dcnt;i++)
						{
							printf("\n%s\t\t\t",dir[i].dname);
								for(int j=0;j<dir[i].subcnt;j++)
						printf("\t%s",dir[i].SubDirectory[j]->sbDirName);

						    	for(int j=0;j<dir[i].fcnt;j++)										printf("\t\t%s",dir[i].fname[j]);
						}
					}
					printf("\n\n");
				}
				break;
	
			case 7:
				{
					for(i=0;i<dcnt;i++)
					{
						printf("\n%s\n",dir[i].dname);
						printf("Sub Directories\t\tParent Directory\t\tFiles\n");
						for(int j=0;j<dir[i].subcnt;j++)
						{
							printf("%s\t\t\t%s\t\t\t",dir[i].SubDirectory[j]->sbDirName,dir[i].SubDirectory[j]->parentDirName);
							for(int k=0; k<dir[i].SubDirectory[j]->fcnt; k++)
								{printf("%s",dir[i].SubDirectory[j]->fname[k]);}
						}
						printf("\n");
					}
					printf("\n\n");
				}break;

			case 8:
				{
					printf("\nEnter name of the Directory: ");
					scanf("%s",d);
					for(i=0;i<dcnt;i++)
					{
						if(strcmp(d,dir[i].dname)==0)
						{
							printf("\nEnter name of Subdirectory:(Enter n if file not in Sub Directory): ");
							scanf("%s",sbd);
							if(strcmp(sbd,"n") ==0) goto no_sb_dir;
							else
							{
							for(int j=0;j<dir[i].subcnt;j++)
					if(strcmp(sbd,dir[i].SubDirectory[j]->sbDirName) == 0)
							{
							printf("Enter the name of the file: \t");
										scanf("%s",f);
						for(k=0; k<dir[i].SubDirectory[j]->fcnt ;k++)							{
					if(strcmp(f, dir[i].SubDirectory[j]->fname[k])==0)
						{
						printf("File %s/%s/%s/%s found ",master,dir[i].dname,dir[i].SubDirectory[j]->sbDirName,f);
												printf("\n\n\n");
										goto jmp3;
											}
										}									printf("File %s not found",f);
								printf("\n\n");
							goto jmp3;
									}
							}
						no_sb_dir:
							printf("Enter the name of the file: ");
							scanf("%s",f);
					for(k=0;k<dir[i].fcnt;k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)								{
					printf("File %s/%s/%s found ",master,dir[i].dname,f);
									printf("\n\n\n");
									goto jmp3;
								}
							}
							printf("File %s not found",f);
							printf("\n\n");
							goto jmp3;
					}
					printf("Directory %s not found",d);
					printf("\n\n");
				}
				jmp3: break;
		default: exit(0);
			}
		}
	}
	return 0;
}