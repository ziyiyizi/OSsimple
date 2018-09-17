
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              printf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include "type.h"
#include "const.h"
#include "string.h"

/******************************************************************************************
                        �ɱ������������ԭ�������漰�����ֽ�Ϊ������
===========================================================================================

i = 0x23;
j = 0x78;
char fmt[] = "%x%d";
printf(fmt, i, j);

        push    j
        push    i
        push    fmt
        call    printf
        add     esp, 3 * 4


                ��        HIGH        ��                        ��        HIGH        ��
                ��        ...         ��                        ��        ...         ��
                �ǩ���������������������                        �ǩ���������������������
                ��                    ��                 0x32010��        '\0'        ��
                �ǩ���������������������                        �ǩ���������������������
         0x3046C��        0x78        ��                 0x3200c��         d          ��
                �ǩ���������������������                        �ǩ���������������������
   arg = 0x30468��        0x23        ��                 0x32008��         %          ��
                �ǩ���������������������                        �ǩ���������������������
         0x30464��      0x32000 �������橤��������       0x32004��         x          ��
                �ǩ���������������������        ��              �ǩ���������������������
                ��                    ��        �������� 0x32000��         %          ��
                �ǩ���������������������                        �ǩ���������������������
                ��        ...         ��                        ��        ...         ��
                ��        LOW         ��                        ��        LOW         ��

ʵ���ϣ����� vsprintf �������������ģ�

        vsprintf(buf, 0x32000, 0x30468);

******************************************************************************************/

/*======================================================================*
                                 printf
 *======================================================================*/
int printf(const char *fmt, ...)
{
	int i;
	char buf[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);        /* 4 �ǲ��� fmt ��ռ��ջ�еĴ�С */
	i = vsprintf(buf, fmt, arg);
	write(buf, i);

	return i;
}

int printf_c(int color, const char *fmt, ...)
{
	int i;
	char buf[256];

	va_list arg = (va_list)((char*)(&fmt) + 4);        /* 4 �ǲ��� fmt ��ռ��ջ�еĴ�С */
	i = vsprintf(buf, fmt, arg);
	write_c(buf, i ,color);

	return i;
}

/*======================================================================*
                                 vsprintf
 *======================================================================*/
int vsprintf(char * buf, const char * fmt, va_list args)
{
	char * p;
	char tmp[256];
	va_list p_next_arg = args;
	for ( p = buf ; *fmt ; fmt++ )
	{
		if ( *fmt != '%' )
		{
			*p++ = *fmt;
			continue;
		}
		
		fmt++;
		
		switch (*fmt)
		{
		case 's':
			{
				strcpy(p, *(char **)(p_next_arg));
				int iStrLen = strlen(*(char **)(p_next_arg));
				p[iStrLen]=0;
				p += iStrLen;
				p_next_arg += 4;
				break;
			}
		case 'c':
			*p++ = *p_next_arg;
			p_next_arg += 4;
			break;
		case 'd':
			{
				_itoa(tmp, *((int *)p_next_arg));		
				int iStrLen = strlen(tmp);
				strcpy(p, tmp);
				p += iStrLen;
				p_next_arg += 4;
			}
			break;
		default:
			if (*fmt>='0'&&*fmt<='9')
			{
				//�Ȱ���ʾ���ٸ�̽�����
				int itotal=0;
				int itempnum;
				int i;
				int iStrLen;
				for (i=0;*fmt>='0'&&*fmt<='9';i++,fmt++)
				{
					//_atoi(&(*fmt),itempnum);
					itempnum=*fmt-48;
					itotal=itotal*10+itempnum;
				}
				itotal=itotal%20;
				if (*fmt=='d')
				{
					_itoa(tmp, *((int *)p_next_arg));		
					iStrLen = strlen(tmp);
					if (iStrLen<itotal)
					{
						for (i=0;i<itotal-iStrLen;i++)
						{
							*p=' ';
							p++;
						}
					}
					strcpy(p, tmp);
					p += iStrLen;
					p_next_arg += 4;
				}
				else if (*fmt=='c')
				{
					for (i=0;i<itotal-1;i++)
					{
						*p=' ';
						p++;
					}
					*p++ = *p_next_arg;
					p_next_arg += 4;
				}
				else if (*fmt =='s')
				{
					strcpy(p, *(char **)(p_next_arg));
					iStrLen = strlen(*(char **)(p_next_arg));
					if (iStrLen<itotal)
					{
						for (i=0;i<itotal-iStrLen;i++)
						{
							*p=' ';
							p++;
						}
					}
					p[iStrLen]=0;
					p += iStrLen;
					p_next_arg += 4;
				}
			}
			break;
		}
	}
	return (p - buf);
}

