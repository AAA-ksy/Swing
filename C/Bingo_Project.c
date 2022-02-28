#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int pnum,i,j;
char pname[3][10];
char *bingo1,*bingo2,*bingo3;  //빙고판 3개 만들 포인터
char answer1,answer2,answer3; //알파벳 입력받을 변수
int k=1,n;		//빙고 검사할 때 반복에 쓰일 변수
int check=0;	//빙고개수 변수
int result;		//함수의 반환값을 받을 변수


int check_bingo(char *bingo);
	
int main()
{
	bingo1=(char*)malloc(sizeof(char)*25);
	bingo2=(char*)malloc(sizeof(char)*25);
	bingo3=(char*)malloc(sizeof(char)*25);	//빙고판 만드는데 필요한 메모리 할당

	printf("인원 수를 입력하십시오(2~3명) : ");
	scanf("%d",&pnum);		//인원수 입력

	for(i=0;i<pnum;i++)
	{
		printf("사용자 이름을 입력하세요 : ");
		scanf("%s",&pname[i]);
	}				//사용자 이름 순서대로 입력
	system("cls");	//화면 모두 지움

	for(i=0;i<25;i++)		//1차원 배열의 요소
	{	
		
		bingo1[i]=rand()%25+65;	//1차원 배열 요소 순서대로 난수 저장

		for(j=0;j<i;j++)
		{
			if(bingo1[i]==bingo1[j])	//전 요소들과 같은지 비교
		{
			i--;		//	같다면 그 요소의 난수를 다시 배정받음
			break;
		}
		}
	}

	for(i=0;i<25;i++)		//위와 같은 방식으로 bingo2판 배열
	{
		
		bingo2[i]=rand()%25+65;

		for(j=0;j<i;j++)
		{
			if(bingo2[i]==bingo2[j])
		{
			i--;
			break;
		}
		}
	}

	for(i=0;i<25;i++)		//같은 방식으로 bingo3판 배열
	{
		
		bingo3[i]=rand()%25+65;

		for(j=0;j<i;j++)
		{
			if(bingo3[i]==bingo3[j])
		{
			i--;
			break;
		}
		}
	}

	if(pnum==2)		//인원수가 2명이라면 2명의 이름을 상단에 출력
	{
			printf("  [%s]     [%s]\n",pname[0],pname[1]);
			
	}

	if(pnum==3)		//인원수가 3명이라면 3명의 이름을 상단에 출력
	{
		printf("   [%s]  [%s]  [%s]\n",pname[0],pname[1],pname[2]);
	}
	for(i=0;i<5;i++)	
	{
		j=i*5;
		printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
		if (pnum==2)
            printf(" | %c %c %c %c %c", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
		if (pnum==3){
			printf(" | %c %c %c %c %c", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
			printf(" | %c %c %c %c %c", bingo3[j], bingo3[j+1], bingo3[j+2], bingo3[j+3], bingo3[j+4]);
		}
		printf("\n");
	}
			while(1)
			{
				if(pnum==2)		//인원수가 2명일 때
				{	for(n=1;;n++)		//n을 이용해서 반복문 사용
					{	check=0;
						if(k==2*n-1)		//입력 턴을 위한 변수 k 지정. 홀수일 때만 입력가능
						{
							fflush(stdin);		//버퍼지움
							printf("%s님, 알파벳을 입력하세요 : ",pname[0]);
							scanf("%c",&answer1);
							for(i=0;i<25;i++)
							{
								if(bingo1[i]==answer1)		//배열 내에 입력받은 값과 동일한 값이 있는지 검사
								{
									bingo1[i]='#';		//있다면 그 값을 샵으로 변경
									break;
								}
							}
							printf("  [%s]     [%s]\n",pname[0],pname[1]);	//바뀐 빙고판 출력
						for(i=0;i<5;i++)
						{
							j=i*5;
							printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
							printf(" | %c %c %c %c %c\n", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
		
						}
						k+=1;  //턴을 위해 k에 1을 더함
						
						result=check_bingo(&bingo1[0]);	//빙고 개수를 result에 저장
					
					switch(result)
						{
						case 1:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[0],result);
							break;
						case 2:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[0],result);
							break;
						case 3:
							printf("%s님이 이겼습니다.\n",pname[0]);
							exit(0);
						}
			}
							
							

						if(k==2*n)   //k가 짝수일 때만 입력가능. 턴 변환되어 두번째 사용자의 빙고판 변경
						{
							fflush(stdin);
							printf("%s님, 알파벳을 입력하세요. : ",pname[1]);
							scanf("%c",&answer2);
							for(i=0;i<25;i++)
							{
								if(bingo2[i]==answer2)
								{
									bingo2[i]='#';
									break;
								}
							}
							printf("  [%s]     [%s]\n",pname[0],pname[1]);
					for(i=0;i<5;i++)
				{
					j=i*5;
					printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
					printf(" | %c %c %c %c %c\n", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
				}
							k+=1;
							check=0;
							result=check_bingo(&bingo2[0]);	//빙고 개수를 result에 저장
					
					switch(result)
						{
						case 1:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[1],result);
							break;
						case 2:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[1],result);
							break;
						case 3:
							printf("%s님이 이겼습니다.\n",pname[1]);
							exit(0);
						}
							
						}
				}
			}
				
				
			if(pnum==3)
			{
				for(n=1;;n++)
					{
						if(k==3*n-2)
						{
							fflush(stdin);		
							printf("%s님 알파벳을 입력하세요 : ",pname[0]);
							scanf("%c",&answer1);
							for(i=0;i<25;i++)
							{
								if(bingo1[i]==answer1)
								{
									bingo1[i]='#';
									break;
								}
							}
							printf("   [%s]  [%s]  [%s]\n",pname[0],pname[1],pname[2]);
					for(i=0;i<5;i++)
				{
					j=i*5;
					printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
					printf(" | %c %c %c %c %c", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
			printf(" | %c %c %c %c %c\n", bingo3[j], bingo3[j+1], bingo3[j+2], bingo3[j+3], bingo3[j+4]);
				}
							k+=1;
							check=0;
							result=check_bingo(&bingo1[0]);	//빙고 개수를 result에 저장
					
					switch(result)
						{
						case 1:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[0],result);
							break;
						case 2:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[0],result);
							break;
						case 3:
							printf("%s님이 이겼습니다.\n",pname[0]);
							exit(0);
						}
							
						}

						if(k==3*n-1)
						{
							fflush(stdin);
							printf("%s님 알파벳을 입력하세요 : ",pname[1]);
							scanf("%c",&answer2);
							for(i=0;i<25;i++)
							{
								if(bingo2[i]==answer2)
								{
									bingo2[i]='#';
									break;
								}
							}
							printf("   [%s]  [%s]  [%s]\n",pname[0],pname[1],pname[2]);
					for(i=0;i<5;i++)
				{
					j=i*5;
					printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
					printf(" | %c %c %c %c %c", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
			printf(" | %c %c %c %c %c\n", bingo3[j], bingo3[j+1], bingo3[j+2], bingo3[j+3], bingo3[j+4]);
				}
							k+=1;
							check=0;
							result=check_bingo(&bingo2[0]);	//빙고 개수를 result에 저장
					
					switch(result)
						{
						case 1:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[1],result);
							break;
						case 2:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[1],result);
							break;
						case 3:
							printf("%s님이 이겼습니다.\n",pname[1]);
							exit(0);
						}
							
						}

						if(k==3*n)
						{
							fflush(stdin);
							printf("%s님 알파벳을 입력하세요 : ",pname[2]);
							scanf("%c",&answer3);
							for(i=0;i<25;i++)
							{
								if(bingo3[i]==answer3)
								{
									bingo3[i]='#';
									break;
								}
							}
							printf("   [%s]  [%s]  [%s]\n",pname[0],pname[1],pname[2]);
					for(i=0;i<5;i++)
				{
					j=i*5;
					printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
					printf(" | %c %c %c %c %c", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
			printf(" | %c %c %c %c %c\n", bingo3[j], bingo3[j+1], bingo3[j+2], bingo3[j+3], bingo3[j+4]);
						}
					k+=1;
					check=0;
							result=check_bingo(&bingo3[0]);	//빙고 개수를 result에 저장
					
					switch(result)
						{
						case 1:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[2],result);
							break;
						case 2:
							printf("%s님이 %d줄 빙고했습니다.\n",pname[2],result);
							break;
						case 3:
							printf("%s님이 이겼습니다.\n",pname[2]);
							exit(0);
						}
					
				}
			}
				
			}
	}
}

int check_bingo(char *bingo)
{
						for(i=0;i<5;i++)
							{
								if(bingo[i]==35 && bingo[i+5]==35&&bingo[i+10]==35&&bingo[i+15]==35&&bingo[i+20]==35)   //빙고 세로줄 체크
								check+=1;
							}

						for(i=0;i<21;i+=5)
							{
								if(bingo[i]==35&&bingo[i+1]==35&&bingo[i+2]==35&&bingo[i+3]==35&&bingo[i+4]==35)		//빙고 가로줄 체크
								check+=1;
							}

						for(i=0;i<5;i+=4)
							{
								if(i==0)
								{	
									if(bingo[i]==35&&bingo[i+6]==35&&bingo[i+12]==35&&bingo[i+18]==35&&bingo[i+24]==35)	//왼쪽에서 오른쪽 대각선 체크
									check+=1;
								
								}
								if(i==4)
								{
									if(bingo[i]==35&&bingo[i*2]==35&&bingo[i*3]==35&&bingo[i*4]==35&&bingo[i*5]==35)		//오른쪽에서 왼쪽 대각선 체크
									check+=1;
									
						
								}
							}
						return check;
}

