
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#define GLOBAL_VARIABLES_HERE

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "keyboard.h"

PUBLIC PROCESS proc_table[MAX_TASKS_PROCS];

PUBLIC TASK task_whole_list[] =	
{
	//������ڵ�ַ,������,�Ƿ�����,��Ӧ��tty,���ȼ�
	{CreateUserProcess,"UserProcess  ",FALSE,3,0},//��ʾ�´������û�����
	{task_tty,"tty0         ",TRUE,0,15},//�����̨
	{Begin,"Main         ",TRUE,0,10},//ϵͳ��ʼ�����е�������
	{MineGame,"MineGame     ",FALSE,1,5 },//ɨ����Ϸ
	{ProcessMaster,"ProcessMaster",TRUE,2,10},//�������
	{CreateSysProcess,"SysProcess   ",TRUE,3,10},//��ʾ�´�����ϵͳ����
    {Play,"Play         ",FALSE,3,10}//ģ����Ļ����
};

PUBLIC int task_proc_table[NR_TASKS_PROCS] = {1, 2};

PUBLIC char task_stack[STACK_SIZE_TOTAL];

PUBLIC t_pf_irq_handler	irq_table[NR_IRQ];
PUBLIC TTY tty_table[NR_CONSOLES];
PUBLIC CONSOLE console_table[NR_CONSOLES];

PUBLIC t_sys_call sys_call_table[NR_SYS_CALL] = 
{
	//ϵͳ���ú�����
	sys_get_ticks, 
	sys_write, 
	sys_getchar, 
	sys_clear, 
	sys_shutdown, 
	sys_echoon, 
	sys_echooff, 
	sys_accepton, 
	sys_acceptoff, 
	sys_flush,
	sys_write_c
};
PUBLIC char ContentOfConsoleOrder[16][32];
PUBLIC int  SumofConsoleOrder;
PUBLIC char show_mine[22][22];
PUBLIC char real_mine[22][22];
PUBLIC char flag[22][22];

