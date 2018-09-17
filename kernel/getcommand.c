
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              readchar.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"


/*======================================================================*
                                 readacommand
 *======================================================================*/
void readacommand(char * pStr)
{
	char ch;
	accepton();
	echoon();
	while ( ( ch = getchar() ) != '\n' )
	{
		*pStr++ = ch;
	}
	*pStr = 0;
	echooff();
	acceptoff();
}

/*=====================================================================*
						readMainConsole

						in readchar.c
*======================================================================*/
void readMainConsole(char * pStr)
{
	char ch;
	accepton();
	echoon();
	int iefNum=0;
	char tempStr[256];
	int iPosoftemp=0;
	int i;
	int iOrderPosition=SumofConsoleOrder;
	memset(tempStr, '\0', 256);
	while ( ( ch = getchar() ) != '\n' )
	{
		if (ch!=33&&ch!=64)
		{
			//*pStr++=ch;
			tempStr[iPosoftemp++]=ch;
			if (ch!='\b')
			{
				iefNum++;
			}
			else
			{
				iefNum--;
			}

		}
		else
		{
			//up
			if (ch==33)
			{
				//�����ڶ���ʱ,�鵽����ʾ����������ʾλ���أ���
				//printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\")
				//���һ�У�����printf("[root@localhost root]#");printf("%s",ContentOfConsoleOrder[i]);
				if (SumofConsoleOrder!=0&&iOrderPosition!=-1)
				{//�ҵ�����ʾ
					iOrderPosition--;
					memset(tempStr,'\0',256);
					strcpy(tempStr,ContentOfConsoleOrder[iOrderPosition]);
					for (i=0;ContentOfConsoleOrder[iOrderPosition][i]!='\0';i++)
					{
					}
					iefNum=i;
					iPosoftemp=i;
					//printf("%s",tempStr);
					
				}
			}
			//down
			else if (ch==64)
			{
				if (iOrderPosition!=SumofConsoleOrder&&iOrderPosition!=SumofConsoleOrder-1&&iOrderPosition<16)
				{//���������߹�������
					iOrderPosition++;
					memset(tempStr,'\0',256);
					strcpy(tempStr,ContentOfConsoleOrder[iOrderPosition]);
					for (i=0;ContentOfConsoleOrder[iOrderPosition][i]!='\0';i++)
					{
					}
					iefNum=i;
					iPosoftemp=i;
					//printf("%s",tempStr);
					
				}
			}
		}
	}
	//���뿪ʱ����ָ���һ
	if (iPosoftemp<32)
	{
		strcpy(ContentOfConsoleOrder[SumofConsoleOrder++],tempStr);
	}
	else
	{
		memcpy(ContentOfConsoleOrder[SumofConsoleOrder++],tempStr,31);
		ContentOfConsoleOrder[SumofConsoleOrder-1][31] ='\0'; 
	}
	if (SumofConsoleOrder==16)
	{
		for (i =0;i<15;i++)
		{
			memset(ContentOfConsoleOrder[i],'\0',32);
			strcpy(ContentOfConsoleOrder[i],ContentOfConsoleOrder[i+1]);
		}
		memset(ContentOfConsoleOrder[i],'\0',32);
		SumofConsoleOrder--;
	}
	memset(pStr,'\0',256);
	strcpy(pStr,tempStr);
	//*pStr = 0;
	echooff();
	acceptoff();
}


/*======================================================================*
                                 getchar
 *======================================================================*/
char getchar()
{
	char ch;
	accepton();
	echoon();
	while ( !( ch = s_getchar() ) );
	echooff();
	acceptoff();
	return ch;
}

