#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int pnum,i,j;
char pname[3][10];
char *bingo1,*bingo2,*bingo3;  //������ 3�� ���� ������
char answer1,answer2,answer3; //���ĺ� �Է¹��� ����
int k=1,n;		//���� �˻��� �� �ݺ��� ���� ����
int check=0;	//������ ����
int result;		//�Լ��� ��ȯ���� ���� ����


int check_bingo(char *bingo);
	
int main()
{
	bingo1=(char*)malloc(sizeof(char)*25);
	bingo2=(char*)malloc(sizeof(char)*25);
	bingo3=(char*)malloc(sizeof(char)*25);	//������ ����µ� �ʿ��� �޸� �Ҵ�

	printf("�ο� ���� �Է��Ͻʽÿ�(2~3��) : ");
	scanf("%d",&pnum);		//�ο��� �Է�

	for(i=0;i<pnum;i++)
	{
		printf("����� �̸��� �Է��ϼ��� : ");
		scanf("%s",&pname[i]);
	}				//����� �̸� ������� �Է�
	system("cls");	//ȭ�� ��� ����

	for(i=0;i<25;i++)		//1���� �迭�� ���
	{	
		
		bingo1[i]=rand()%25+65;	//1���� �迭 ��� ������� ���� ����

		for(j=0;j<i;j++)
		{
			if(bingo1[i]==bingo1[j])	//�� ��ҵ�� ������ ��
		{
			i--;		//	���ٸ� �� ����� ������ �ٽ� ��������
			break;
		}
		}
	}

	for(i=0;i<25;i++)		//���� ���� ������� bingo2�� �迭
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

	for(i=0;i<25;i++)		//���� ������� bingo3�� �迭
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

	if(pnum==2)		//�ο����� 2���̶�� 2���� �̸��� ��ܿ� ���
	{
			printf("  [%s]     [%s]\n",pname[0],pname[1]);
			
	}

	if(pnum==3)		//�ο����� 3���̶�� 3���� �̸��� ��ܿ� ���
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
				if(pnum==2)		//�ο����� 2���� ��
				{	for(n=1;;n++)		//n�� �̿��ؼ� �ݺ��� ���
					{	check=0;
						if(k==2*n-1)		//�Է� ���� ���� ���� k ����. Ȧ���� ���� �Է°���
						{
							fflush(stdin);		//��������
							printf("%s��, ���ĺ��� �Է��ϼ��� : ",pname[0]);
							scanf("%c",&answer1);
							for(i=0;i<25;i++)
							{
								if(bingo1[i]==answer1)		//�迭 ���� �Է¹��� ���� ������ ���� �ִ��� �˻�
								{
									bingo1[i]='#';		//�ִٸ� �� ���� ������ ����
									break;
								}
							}
							printf("  [%s]     [%s]\n",pname[0],pname[1]);	//�ٲ� ������ ���
						for(i=0;i<5;i++)
						{
							j=i*5;
							printf("%c %c %c %c %c", bingo1[j], bingo1[j+1], bingo1[j+2], bingo1[j+3], bingo1[j+4]);
							printf(" | %c %c %c %c %c\n", bingo2[j], bingo2[j+1], bingo2[j+2], bingo2[j+3], bingo2[j+4]);
		
						}
						k+=1;  //���� ���� k�� 1�� ����
						
						result=check_bingo(&bingo1[0]);	//���� ������ result�� ����
					
					switch(result)
						{
						case 1:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[0],result);
							break;
						case 2:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[0],result);
							break;
						case 3:
							printf("%s���� �̰���ϴ�.\n",pname[0]);
							exit(0);
						}
			}
							
							

						if(k==2*n)   //k�� ¦���� ���� �Է°���. �� ��ȯ�Ǿ� �ι�° ������� ������ ����
						{
							fflush(stdin);
							printf("%s��, ���ĺ��� �Է��ϼ���. : ",pname[1]);
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
							result=check_bingo(&bingo2[0]);	//���� ������ result�� ����
					
					switch(result)
						{
						case 1:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[1],result);
							break;
						case 2:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[1],result);
							break;
						case 3:
							printf("%s���� �̰���ϴ�.\n",pname[1]);
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
							printf("%s�� ���ĺ��� �Է��ϼ��� : ",pname[0]);
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
							result=check_bingo(&bingo1[0]);	//���� ������ result�� ����
					
					switch(result)
						{
						case 1:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[0],result);
							break;
						case 2:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[0],result);
							break;
						case 3:
							printf("%s���� �̰���ϴ�.\n",pname[0]);
							exit(0);
						}
							
						}

						if(k==3*n-1)
						{
							fflush(stdin);
							printf("%s�� ���ĺ��� �Է��ϼ��� : ",pname[1]);
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
							result=check_bingo(&bingo2[0]);	//���� ������ result�� ����
					
					switch(result)
						{
						case 1:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[1],result);
							break;
						case 2:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[1],result);
							break;
						case 3:
							printf("%s���� �̰���ϴ�.\n",pname[1]);
							exit(0);
						}
							
						}

						if(k==3*n)
						{
							fflush(stdin);
							printf("%s�� ���ĺ��� �Է��ϼ��� : ",pname[2]);
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
							result=check_bingo(&bingo3[0]);	//���� ������ result�� ����
					
					switch(result)
						{
						case 1:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[2],result);
							break;
						case 2:
							printf("%s���� %d�� �����߽��ϴ�.\n",pname[2],result);
							break;
						case 3:
							printf("%s���� �̰���ϴ�.\n",pname[2]);
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
								if(bingo[i]==35 && bingo[i+5]==35&&bingo[i+10]==35&&bingo[i+15]==35&&bingo[i+20]==35)   //���� ������ üũ
								check+=1;
							}

						for(i=0;i<21;i+=5)
							{
								if(bingo[i]==35&&bingo[i+1]==35&&bingo[i+2]==35&&bingo[i+3]==35&&bingo[i+4]==35)		//���� ������ üũ
								check+=1;
							}

						for(i=0;i<5;i+=4)
							{
								if(i==0)
								{	
									if(bingo[i]==35&&bingo[i+6]==35&&bingo[i+12]==35&&bingo[i+18]==35&&bingo[i+24]==35)	//���ʿ��� ������ �밢�� üũ
									check+=1;
								
								}
								if(i==4)
								{
									if(bingo[i]==35&&bingo[i*2]==35&&bingo[i*3]==35&&bingo[i*4]==35&&bingo[i*5]==35)		//�����ʿ��� ���� �밢�� üũ
									check+=1;
									
						
								}
							}
						return check;
}

