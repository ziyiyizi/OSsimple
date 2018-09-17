
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            main.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                         2018��9��          
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

void Begin();

void ProcessMaster();
int CreateProcess(int TaskID);//���һ�����̵���
void CreateSysProcess(int id);
void CreateUserProcess(int id);
t_bool KillProcess(int Pid);//����pid�Ž���

void Help();
void Help2();
void ProcessInfo();

void init_mine(int row, int col);
void init_flag(int row, int col);
void print_player(int row, int col);
void print_mine(int row, int col);
void set_mine(int row, int col);
int count_mine(int x, int y);
void open_mine_dfs(int x, int y);
int count_show_mine(int row, int col);

void MineGame();
void Play();
void Play2();

void sys_shutdown(PROCESS * p_proc);
void DisPlay();

void strtolower(char * src);
int strcmp(char * src, char * dst);

PUBLIC int main()//������
{
	disp_color_str("===== \"Uinix init...\" =====\n",BLUE);
	int i;
	for(i = 0;i < NR_TASKS_PROCS;i++)
	{
		if (i < NR_TASKS_PROCS)
		{
			if(CreateProcess(task_proc_table[i]) < 0)//���ϵͳ�ĳ�ʼ����
			{
				disp_str("Sorry, there's something wrong with kernel!\n");
				while (1);
			} 
		}
	}
	p_proc_ready = proc_table;
	k_reenter = 0;
	ticks = 0;
	init_clock();
	restart();
	while(1){}
}

void Play()
{
	while(1)
	{
clear();
printf("                                                                               \n");
printf("                                                                               \n");
printf("                                                                               \n");
printf("                                                                               \n");
printf("                                                                               \n");
printf("                                                                               \n");     
printf("                                                                          .... \n");
printf("                                                                      -:!!:::;*\n");
printf("                                                                   ,~=#! -.    \n");
printf("                                                                   !!!;        \n");
printf("                                                                     -!        \n");
printf("                                                                     $.        \n");
printf("                                                                    =-         \n");
printf("                                                                    *          \n");
printf("                                                                    =          \n");
printf("                                                                    #.         \n");
printf("                                                                    .=,        \n");
printf("                                                                      ;;.      \n");
printf("                                                                       .;!:-   \n");
printf("                                                                          .:!;-\n");
printf("                                                                              :\n");
printf("                                                                               \n");

milli_delay(1000);
clear(); 
printf("                                                                               \n");
printf("                                                                               \n");
printf("                                                                               \n");
printf("                                                                             -:\n");
printf("                                                                          ~!*~,\n");
printf("                                                                        .=:    \n");
printf("                                                              ....      ~#     \n");
printf("                                                          -:!!:::;**-   :=     \n");
printf("                                                       ,~=#! -.    .@, .#,     \n");
printf("                                                       !!!;         ,@-#-      \n");
printf("                                                         -!          :@.       \n");
printf("                                                         $.           .$#*;!=#$\n");
printf("                                                        =-                     \n");
printf("                                                        *                      \n");
printf("                                                        =                      \n");
printf("                                                        #.                     \n");
printf("                                                        .=,                  ~*\n");
printf("                                                          ;;.                  \n");
printf("                                                           .;!:-               \n");
printf("                                                              .:!;-.           \n");
printf("                                                                  :**;~,..     \n");
printf("                                                                      .~;!!****\n");

milli_delay(1000);clear(); 
printf("                                                                             !$\n");
printf("                                                                         ,!$*, \n");
printf("                                                                     .~**:,    \n");
printf("                                                                 -:*!~-.       \n");
printf("                                                              ~!*~,       ,~;;*\n");
printf("                                                            .=:          ,==!!$\n");
printf("                                                  ....      ~#              ;$-\n");
printf("                                              -:!!:::;**-   :=            ,=!  \n");
printf("                                           ,~=#! -.    .@, .#,          ,==.   \n");
printf("                                           !!!;         ,@-#-          :#,     \n");
printf("                                             -!          :@.        ,*#:       \n");
printf("                                             $.           .$#*;!=#$!,          \n");
printf("                                            =-                                 \n");
printf("                                            *                              *#!*\n");
printf("                                            =                              .-!=\n");
printf("                                            #.                                 \n");
printf("                                            .=,                  ~***;::~~~:!=$\n");
printf("                                              ;;.                    .,-~~~-,. \n");
printf("                                               .;!:-                           \n");
printf("                                                  .:!;-.                       \n");
printf("                                                      :**;~,..           ..,,-:\n");
printf("                                                          .~;!!******===**!;:,\n");

milli_delay(1000);clear(); 

printf("                                                                 !$*!,\n");
printf("                                                             ,!$*,  .;#,\n");
printf("                                                         .~**:,       ;#\n");
printf("                                                     -:*!~-.         -#:    ...\n");
printf("                                                  ~!*~,       ,~;;**=@=;;!!;~~-\n");
printf("                                                .=:          ,==!!$$*~.        \n");
printf("                                      ....      ~#              ;$-            \n");
printf("                                  -:!!:::;**-   :=            ,=!              \n");
printf("                               ,~=#! -.    .@, .#,          ,==.               \n");
printf("                               !!!;         ,@-#-          :#,             ....\n");
printf("                                 -!          :@.        ,*#:              -@#;~\n");
printf("                                 $.           .$#*;!=#$!,                    -:\n");
printf("                                =-                                             \n");
printf("                                *                              *#!*$*,         \n");
printf("                                =                              .-!=$@@*;;;;*=$=\n");
printf("                                #.                                 ,@$,,,,,,.\n");
printf("                                .=,                  ~***;::~~~:!=$!--:!===*;;:\n");
printf("                                  ;;.                    .,-~~~-,.         ..,-\n");
printf("                                   .;!:-                                       \n");
printf("                                      .:!;-.                          .-~!**===\n");
printf("                                          :**;~,..           ..,,-:!===!~.\n");
printf("                                              .~;!!******===**!;:,\n");

milli_delay(1000);clear(); 
printf("                                                     !$*!,                     \n");
printf("                                                 ,!$*,  .;#,                   \n");
printf("                                             .~**:,       ;#                   \n");
printf("                                         -:*!~-.         -#:    ...,---~~:~~::~\n");
printf("                                      ~!*~,       ,~;;**=@=;;!!;~~----,,,...   \n");
printf("                                    .=:          ,==!!$$*~.                    \n");
printf("                          ....      ~#              ;$-                 ---,.  \n");
printf("                      -:!!:::;**-   :=            ,=!                  .=*!!=##\n");
printf("                   ,~=#! -.    .@, .#,          ,==.                           \n");
printf("                   !!!;         ,@-#-          :#,             .....          .\n");
printf("                     -!          :@.        ,*#:              -@#;~;==-    .-=$\n");
printf("                     $.           .$#*;!=#$!,                    -:!*!#$;;:~.  \n");
printf("                    =-                                                #;       \n");
printf("                    *                              *#!*$*,         .!@~        \n");
printf("                    =                              .-!=$@@*;;;;*=$=:,          \n");
printf("                    #.                                 ,@$,,,,,,.              \n");
printf("                    .=,                  ~***;::~~~:!=$!--:!===*;;:~:::;;;.    \n");
printf("                      ;;.                    .,-~~~-,.         ..,--~-,,,:@,   \n");
printf("                       .;!:-                                              #;   \n");
printf("                          .:!;-.                          .-~!**===***!**$!    \n");
printf("                              :**;~,..           ..,,-:!===!~.                 \n");
printf("                                  .~;!!******===**!;:,                         \n");
milli_delay(1000);clear(); 
printf("                                         !$*!,                                 \n");
printf("                                     ,!$*,  .;#,                               \n");
printf("                                 .~**:,       ;#                               \n");
printf("                             -:*!~-.         -#:    ...,---~~:~~::~~           \n");
printf("                          ~!*~,       ,~;;**=@=;;!!;~~----,,,...   .;.         \n");
printf("                        .=:          ,==!!$$*~.                     :-         \n");
printf("              ....      ~#              ;$-                 ---,.  -$.         \n");
printf("          -:!!:::;**-   :=            ,=!                  .=*!!=##!           \n");
printf("       ,~=#! -.    .@, .#,          ,==.                           $,          \n");
printf("       !!!;         ,@-#-          :#,             .....          .@-          \n");
printf("         -!          :@.        ,*#:              -@#;~;==-    .-=$            \n");
printf("         $.           .$#*;!=#$!,                    -:!*!#$;;:~.              \n");
printf("        =-                                                #;                   \n");
printf("        *                              *#!*$*,         .!@~                    \n");
printf("        =                              .-!=$@@*;;;;*=$=:,                      \n");
printf("        #.                                 ,@$,,,,,,.                          \n");
printf("        .=,                  ~***;::~~~:!=$!--:!===*;;:~:::;;;.                \n");
printf("          ;;.                    .,-~~~-,.         ..,--~-,,,:@,               \n");
printf("           .;!:-                                              #;               \n");
printf("              .:!;-.                          .-~!**===***!**$!                \n");
printf("                  :**;~,..           ..,,-:!===!~.                             \n");
printf("                      .~;!!******===**!;:,                              \n");
milli_delay(1000);clear(); 
printf("                             !$*!,                                             \n");
printf("                         ,!$*,  .;#,                                           \n");
printf("                     .~**:,       ;#                                           \n");
printf("                 -:*!~-.         -#:    ...,---~~:~~::~~                       \n");
printf("              ~!*~,       ,~;;**=@=;;!!;~~----,,,...   .;.                   \n");
printf("            .=:          ,==!!$$*~.                     :-                \n");
printf("  ....      ~#              ;$-                 ---,.  -$.                 \n");
printf("!!:::;**-   :=            ,=!                  .=*!!=##!                       \n");
printf(" -.    .@, .#,          ,==.                           $,                \n");
printf("        ,@-#-          :#,             .....          .@-                  \n");
printf("         :@.        ,*#:              -@#;~;==-    .-=$                    \n");
printf("          .$#*;!=#$!,                    -:!*!#$;;:~.                    \n");
printf("                                              #;                                \n");
printf("                           *#!*$*,         .!@~                             \n");
printf("                           .-!=$@@*;;;;*=$=:,                            \n");
printf("                               ,@$,,,,,,.                                 \n");
printf("                 ~***;::~~~:!=$!--:!===*;;:~:::;;;.                     \n");
printf(".                    .,-~~~-,.         ..,--~-,,,:@,                   \n");
printf(";!:-                                              #;                   \n");
printf("  .:!;-.                          .-~!**===***!**$!                   \n");
printf("      :**;~,..           ..,,-:!===!~.                                   \n");
printf("          .~;!!******===**!;:,                              \n");
milli_delay(1000);clear(); 
printf("                 !$*!,                                                  \n");
printf("             ,!$*,  .;#,                                                \n");
printf("         .~**:,       ;#                                                \n");
printf("     -:*!~-.         -#:    ...,---~~:~~::~~                            \n");
printf("  ~!*~,       ,~;;**=@=;;!!;~~----,,,...   .;.                          \n");
printf(".=:          ,==!!$$*~.                     :-                          \n");
printf("~#              ;$-                 ---,.  -$.                          \n");
printf(":=            ,=!                  .=*!!=##!                            \n");
printf("#,          ,==.                           $,                           \n");
printf("-          :#,             .....          .@-                           \n");
printf("        ,*#:              -@#;~;==-    .-=$                             \n");
printf("#*;!=#$!,                    -:!*!#$;;:~.                               \n");
printf("                                  #;                                    \n");
printf("               *#!*$*,         .!@~                                     \n");
printf("               .-!=$@@*;;;;*=$=:,                                       \n");
printf("                   ,@$,,,,,,.                                           \n");
printf("     ~***;::~~~:!=$!--:!===*;;:~:::;;;.                                 \n");
printf(".        .,-~~~-,.         ..,--~-,,,:@,                                \n");
printf("                                      #;                                \n");
printf("                      .-~!**===***!**$!                                 \n");
printf("..           ..,,-:!===!~.                                              \n");
printf(";!!******===**!;:,                              \n");
milli_delay(1000);clear(); 

printf(" !$*!,                                                  \n");
printf("*,  .;#,                                                \n");
printf("      ;#                                                \n");
printf("     -#:    ...,---~~:~~::~~                            \n");
printf(";;**=@=;;!!;~~----,,,...   .;.                          \n");
printf("!!$$*~.                     :-                          \n");
printf(";$-                 ---,.  -$.                          \n");
printf("!                  .=*!!=##!                            \n");
printf("                           $,                           \n");
printf("           .....          .@-                           \n");
printf("          -@#;~;==-    .-=$                             \n");
printf("             -:!*!#$;;:~.                               \n");
printf("                  #;                                    \n");
printf("#!*$*,         .!@~                                     \n");
printf("-!=$@@*;;;;*=$=:,                                       \n");
printf("   ,@$,,,,,,.                                           \n");
printf("!=$!--:!===*;;:~:::;;;.                                 \n");
printf(",.         ..,--~-,,,:@,                                \n");
printf("                      #;                                \n");
printf("      .-~!**===***!**$!                                 \n");
printf(",-:!===!~.                                              \n");
printf(":,                              \n");
milli_delay(3000);clear(); 
    }
}

void Play2()
{
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("             BBBB             YY              YY        EEEEEEEEEEEEE\n");
	printf("             BB BB             YY            YY         EE\n");
	printf("             BB   BB            YY          YY          EE\n");
	printf("             BB    BB            YY        YY           EE\n");
	printf("             BB     BB            YY      YY            EE\n");
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("             BBBB             YY              YY        EEEEEEEEEEEEE\n");
	printf("             BB BB             YY            YY         EE\n");
	printf("             BB   BB            YY          YY          EE\n");
	printf("             BB    BB            YY        YY           EE\n");
	printf("             BB     BB            YY      YY            EE\n");
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n\n\n\n\n");
	printf("             BBBB             YY              YY        EEEEEEEEEEEEE\n");
	printf("             BB BB             YY            YY         EE\n");
	printf("             BB   BB            YY          YY          EE\n");
	printf("             BB    BB            YY        YY           EE\n");
	printf("             BB     BB            YY      YY            EE\n");
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n");
	printf("             BBBB             YY              YY        EEEEEEEEEEEEE\n");
	printf("             BB BB             YY            YY         EE\n");
	printf("             BB   BB            YY          YY          EE\n");
	printf("             BB    BB            YY        YY           EE\n");
	printf("             BB     BB            YY      YY            EE\n");
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("\n\n");
	printf("             BBBB             YY              YY        EEEEEEEEEEEEE\n");
	printf("             BB BB             YY            YY         EE\n");
	printf("             BB   BB            YY          YY          EE\n");
	printf("             BB    BB            YY        YY           EE\n");
	printf("             BB     BB            YY      YY            EE\n");
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("             BBBB             YY              YY        EEEEEEEEEEEEE\n");
	printf("             BB BB             YY            YY         EE\n");
	printf("             BB   BB            YY          YY          EE\n");
	printf("             BB    BB            YY        YY           EE\n");
	printf("             BB     BB            YY      YY            EE\n");
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("             BB    BB              YY    YY             EE\n");
	printf("             BB   BB                YY  YY              EE\n");
	printf("             BB BB                   YYYY               EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
	
	clear();
	printf("             BB     BB                YY                EE\n");
	printf("             BB    BB                 YY                EE\n");
	printf("             BB   BB                  YY                EE\n");
	printf("             BB BB                    YY                EE\n");
	printf("             BBBB                     YY                EEEEEEEEEEEEE\n");
	milli_delay(1000);
}

int CreateProcess(int TaskID)//��������
{
	int i;
	t_8 privilege;
	t_8 rpl;
	int eflags;
	if(task_whole_list[TaskID].task_or_no == TRUE)
	{
		privilege = PRIVILEGE_TASK;
		rpl = RPL_TASK;
		eflags = 0x1202;
		i = 0;
	}
	else
	{
		privilege = PRIVILEGE_USER;
		rpl = RPL_USER;
		eflags = 0x202;
		i = 7;
	}
	for(i = i;i < MAX_TASKS_PROCS;++i)
	{
		if(proc_table[i].priority == 0)
		{
			break;
		}
	}

	if(i == MAX_TASKS_PROCS)
	{
		return -1;
	}	

	strcpy(proc_table[i].p_name, task_whole_list[TaskID].name);// name of the process
	proc_table[i].pid = i;// pid

	proc_table[i].ldt_sel	= SELECTOR_LDT_FIRST + 8 * i;
	memcpy(&proc_table[i].ldts[0], &gdt[SELECTOR_KERNEL_CS >> 3], sizeof(DESCRIPTOR));
	proc_table[i].ldts[0].attr1 = DA_C | privilege << 5;	// change the DPL
	memcpy(&proc_table[i].ldts[1], &gdt[SELECTOR_KERNEL_DS >> 3], sizeof(DESCRIPTOR));
	proc_table[i].ldts[1].attr1 = DA_DRW | privilege << 5;	// change the DPL
	proc_table[i].regs.cs = ((8 * 0) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.ds = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.es = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.fs = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.ss = ((8 * 1) & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
	proc_table[i].regs.gs = (SELECTOR_KERNEL_GS & SA_RPL_MASK) | rpl;
	proc_table[i].regs.eip = (t_32)task_whole_list[TaskID].initial_eip;
	proc_table[i].regs.esp = (t_32)task_stack + STACK_SIZE_TOTAL - STACK_SIZE_COMMON * i;
	proc_table[i].regs.eflags = eflags;
	proc_table[i].nr_tty = task_whole_list[TaskID].defaultTTY;
	proc_table[i].ticks = proc_table[i].priority = task_whole_list[TaskID].priority;
	proc_table[i].task_or_no = task_whole_list[TaskID].task_or_no;

	return i;
}


t_bool KillProcess(int Pid)//��������
{
	if(proc_table[Pid].priority == 0)
	{
		return FALSE;
	}
	proc_table[Pid].priority = 0;
	proc_table[Pid].p_name[0] = 0;
	return TRUE;
}


void ProcessMaster()//���̹�����
{
	clear();
	printf("                 ###################################################\n");
	printf("                                    Welcome! Process Master ver1.0 \n");
	printf("                                        Created By\n");
	printf("                                          Xia,Yang\n");
	printf("                 ###################################################\n");
	
	do
	{
		printf("[PM(hp for help)]:");
		char szCmd[256];
		char szCmd_id[32];
		char szCmd_sys[32];
		int  id;
		readacommand(szCmd);
		strtolower(szCmd);
		if (!strcmp(szCmd, "kill"))
		{
			printf("[PID]:");
			readacommand(szCmd_id);
			if (_atoi(szCmd_id,&id))
			{
				if (proc_table[id].task_or_no)
				{
					printf("system processes are not allowed to kill\n");
				}
				else
				{
					if(KillProcess(id)==TRUE)
					printf("kill successfully!\n");
					else
					printf("process is not running!\n");
				}
			}
			else
			{
				printf("wrong input\n",id);
			}
			
		}
		else if(!strcmp(szCmd,"add"))
		{
			printf("[Manage Master(Please select your operation(sys/user))]:");
			readacommand(szCmd_sys);
			strtolower(szCmd_sys);
			int i;
			if(!strcmp(szCmd_sys, "sys"))
			{
				for(i = 0 ;i < 7;i ++)
				{
					if (proc_table[i].priority == 0)
					{
						break;
					}
				}
				if(i == 7)
				{
					printf("Sys process pool is full\n");
				}
				else
				{
					CreateProcess(5);
					proc_table[i].priority=10;	
					printf("sys process add successfully\n");
				}
			}
			else if(!strcmp(szCmd_sys,"user"))
			{	
					for(i = 7;i < MAX_TASKS_PROCS;i ++)
					{
						if (proc_table[i].priority == 0)
						{
							break;
						}
					}
					if(i == MAX_TASKS_PROCS)
					{
						printf("User process pool is full\n");
					}
					else
					{
						CreateProcess(0);
						proc_table[i].priority=5;	
						printf("user process add successfully\n");
					}
			}
			else 
			{
				printf("wrong input\n");
				continue;
			}
		
		}
		else if(!strcmp(szCmd, "clear")||!strcmp(szCmd, "cls"))
		{
			clear();
			printf("                 ###################################################\n");
			printf("                                    Welcome! Process Master ver1.0 \n");
			printf("                                        Created By\n");
			printf("                                          Xia,Yang\n");
			printf("                 ###################################################\n");
		}
		else if(!strcmp(szCmd, "help")||!strcmp(szCmd, "hp"))
		{
			Help2();
			
		}
		else if(!strcmp(szCmd,"processinfo")||!strcmp(szCmd,"list"))
		{
			ProcessInfo();
		}
		else
		{
			printf("Command is invalid\n");
		}
		milli_delay(200);
	}
	while (1);
}

void init_mine(int row, int col)//��ʼ����������
{
    int i, j;

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++)
        {
            show_mine[i][j] = '*';//�û����� 
            real_mine[i][j] = '0';//������� 
            
        }
    }
}

void init_flag(int row, int col)//��ʼ��DFS��ʶ����ֹ�ظ����� 
{
	int i, j;

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++)
        {
            if(i == 0||i == row-1||j == 0||j == col-1)
            {
            	flag[i][j] = '1';
			}
            else
            {
            	flag[i][j] = '0';
			}
        }
    }
}
void print_player(int row, int col)//��ӡ�������
{
    int i = 0;
    int j = 0;
    printf("0  ");
    for (i = 1; i <row-1; i++)
    {
    	if(i < 10)
    	{
    		printf("%d  ", i);
		}
        else
        {
        	printf("%d ", i);
		};//��ӡ��꣨1--10��
    }
    printf("\n");
    for (i = 1; i <row-2; i++)
    {
    	if(i < 10)
    	{
    		printf("%d  ", i);
		}
        else
        {
        	printf("%d ", i);
		};//��ӡ���꣨1--10��
		
        for (j = 1; j < col-1; j++)
        {
            printf("%c  ", show_mine[i][j]);//�����������
        }
        printf("\n");
    }
    printf("%d ",row-2);//��ʼ��ӡ���һ��
    for (i = 1; i < row-1; i++)
    {
    	printf("%c  ", show_mine[row-2][i]);
    }
    printf("\n");
}

void print_mine(int row, int col)//��ӡ�������
{
    int i = 0;
    int j = 0;
    printf("0  ");
    for (i = 1; i <row - 1; i++)
    {  
//��ӡ��꣨0--10��
    	if(i < 10)
    	{
    		printf("%d  ", i);
		}
        else
        {
        	printf("%d ", i);
		};
    }
    printf("\n");
    for (i = 1; i <row - 2; i++)
    {
        if(i < 10)
    	{
    		printf("%d  ", i);
		}
        else
        {
        	printf("%d ", i);
		};//��ӡ���꣨1--10��
        for (j = 1; j < col - 1; j++)
        {
            printf("%c  ", real_mine[i][j]);
        }
        printf("\n");
    }
    printf("%d ",col-2);//��ʼ��ӡ���һ��
    for (i = 1; i < row - 1; i++)
    {
        printf("%c  ", real_mine[row-2][i]);	
    }
    printf("\n");
}

void set_mine(int row, int col)//����������̲���
{
    int x = 0;
    int y = 0;
    int count = 40;//������
    row = row - 2;
    col = col - 2;
    while (count)//�ײ��������ѭ��
    {
        int x = (int)((get_ticks() * 314159 / 7) % row) + 1;//����1��row����������������±�Ϊ1��row-2�ķ�Χ�ڲ���
        int y = (int)((get_ticks() * 314159 / 13) % col) + 1;//����1��col����������������±�Ϊ1��col-2�ķ�Χ�ڲ���
        if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
        {
            real_mine[x][y] = '1';
            count--;
        }
    }
}

int count_mine(int x, int y)//�����Χ8�������׵ĸ���
{
    int count = 0;
    int x3[] = {x - 1, x , x + 1};
    int y3[] = {y - 1, y , y + 1};
    int i ,j;
    for(i = 0; i < 3; i++)
    {
    	for(j = 0; j < 3; j++)
    	{
    		if(real_mine[x3[i]][y3[j]] == '1')
    		{
    			count++;
			}
		}
	}

    return count;
}
void open_mine_dfs(int x, int y)//�հ���ը������ DFS 
{
	if(x<1||x>20||y<1||y>20)return;
	if(flag[x][y] == '0')
	{
		flag[x][y] = '1';
		if(show_mine[x][y] == '0')
		{
			int x3[] = {x - 1, x , x + 1};
    		int y3[] = {y - 1, y , y + 1};
    		int i ,j;
    		for(i = 0; i < 3; i++)
    		{
    			for(j = 0; j < 3; j++)
    			{
    		
    				int rowx = x3[i];
    				int coly = y3[j];
    				show_mine[rowx][coly] = count_mine(rowx, coly) + '0';//��ʾ��������Χ����
    				if(flag[rowx][coly] == '0' && show_mine[rowx][coly] == '0')
    				{
    					open_mine_dfs(x3[i], y3[j]);
					}
    				
					
				}
			}
		}
		
	}
	return;

}

int count_show_mine(int row, int col)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
{
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i <= row - 2; i++)
    {
        for (j = 1; j <= col - 2; j++)
        {
            if (show_mine[i][j] == '*')
            {
                count++;
            }
        }

    }
    return count;
}


void MineGame()//ɨ����Ϸ
{
	int i,j,time;
	int wix,wiy;
	int row = 22;
	int col = 22; 

	char temp1[64];
	char temp2[64];


	do 
	{
		
		int result = 0;
		init_mine(row,col);//��ʼ��������̺����������
    	set_mine(row,col);//����������̲���
    	clear();
		print_player(row,col);//��ӡ�������
		while(1)
		{
			int x = 0;
    		int y = 0;
    		int count = 0;
    
    		init_flag(row,col);
    	
    		printf("Please input row and col number(restart:-1)\n");
    		
    		for(wix = 1;wix <= 2;)
			{
				//scanf("%d,%d",&row,&colum);
				for (wiy = 0;wiy < 64;wiy++)
				{
					temp1[i] = '\0';
					temp2[i] = '\0';
				}
				readacommand(temp1);
				readacommand(temp2);
				_atoi(temp1,&x);
				_atoi(temp2,&y);
				if (x == -1 || y == -1)
				{
					break;
				}
				else
				{
					if ((x >= 1 && x <= row-2) && (y >= 1 && y <= col-2))//�ж����������Ƿ��������������������
    				{
        				if (real_mine[x][y] == '0')//û�ȵ���
        				{
            				char ch = count_mine(x,y);
            				show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
            				open_mine_dfs(x, y);
        				}
        				else if (real_mine[x][y]=='1')//�ȵ���
        				{
            				result = 1;
        				}
        				break;

    				}
    				else
    				{
        				printf("input error!\n");
        				wix = 2;
    				}

				}

			}
			
			if (count_show_mine(row,col) == 40)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
        	{
        		clear();
            	print_mine(row,col);//��ӡ���������
            	printf("player win!\n");
//            finish = clock();//ȡ����ʱ��
//            printf("spend %d s\n",(int) (finish - start) / CLOCKS_PER_SEC);
            	break;
        	}
        	if (result)//�ж��Ƿ�ȵ���
        	{
        		clear();
            	
//            	finish = clock();//ȡ����ʱ��
//            	printf("spend %d s\n", (int)(finish - start) / CLOCKS_PER_SEC);
            	print_mine(row,col);//��ӡ���������鿴�׵ķֲ�
            	printf("you died.\n");

            	break;
        	}
        	clear();
			print_player(row,col);//��ӡ�������
		}

		printf("------Now You Will Enter The Next Game----\n");
		for(time = 0;time < 10;time++)
		{
			milli_delay(500);
			printf("=====>");
		}
		

	} while (1);
	//KillProcess(3);
	
}


void CreateSysProcess(int id)//ϵͳ���̴�����ʾ
{
	clear();
	printf("\n");
	printf("A New System Process Has Been Created!");
	while(1);
}
void CreateUserProcess(int id)//�û����̴�����ʾ
{
	clear();
	printf("\n");
	printf("A New User Process Has Been Created!");
	while(1);
}


void Begin()//��������
{
	DisPlay();
	char szCmd[256];
	int i;
	t_bool fIsRunning = TRUE;
	clear();
	printf("                 ###################################################\n");
	printf("                                    Welcome! Uinix ver1.0\n");
	printf("                                        Created By\n");
	printf("                                          Xia,Yang\n");
	printf("                 ###################################################\n");
	printf_c(RED,"hello\n");
	do{
		printf("[cmd:]");
		readMainConsole(szCmd);
		strtolower(szCmd);
		if(!strcmp(szCmd,"exit"))
		{
			break;
		}
		else if(!strcmp(szCmd,"play"))
		{
			CreateProcess(6);
			//proc_table[i].priority=5;	
			printf("Play is running on CONSOLE-3\n");
		}
		else if(!strcmp(szCmd,"help")||!strcmp(szCmd,"hp"))
		{
			Help();
		}
		else if(!strcmp(szCmd,"minegame")||!strcmp(szCmd,"mg"))
		{
			int i;
			for(i = 0;i < MAX_TASKS_PROCS;++i)
			{
				if(!strcmp(proc_table[i].p_name, task_whole_list[3].name))
				{
					printf("minegame Had Been Created And It Is Still Running On CONSOLE-1\n");
					break;
				}
			}
			if(i == MAX_TASKS_PROCS)
			{
				printf("minegame Has Been Created Successfully And It Is Running On CONSOLE-1\n",CreateProcess(3));
			}			
		}
		else if(!strcmp(szCmd,"processmaster")||!strcmp(szCmd,"pm"))
		{
			int i;
			for(i = 0;i < MAX_TASKS_PROCS;++i)
			{
				if(!strcmp(proc_table[i].p_name, task_whole_list[4].name))
				{
					printf("\nCONSOLE-2 is running processmaster\n");
					break;
				}
			}
			if(i == MAX_TASKS_PROCS)
			{
				printf("\nCONSOLE-2 is running processmaster\n", CreateProcess(4));
			}	
		}
		else if(!strcmp(szCmd,"clear")||!strcmp(szCmd,"cls"))
		{
			clear();
			printf("                 ###################################################\n");
			printf("                                    Welcome! Uinix ver1.0 \n");
			printf("                                        Created By\n");
			printf("                                          Xia,Yang\n");
			printf("                 ###################################################\n");
		}
		else
		{
			printf("command is invalid\n");
		}
		milli_delay(200);
	}while(TRUE);
	
	Play2();
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                 ===================================================\n");
	printf("                                     Uinix\n");
	printf("                                 Has Been Ended!\n");
	printf("                 ===================================================\n");
	for(i = 0;i < 20; ++i)
	{
		milli_delay(100);
	}
	shutdown();
}

void Help()//������Ϣ
{
	printf("================================================================================\n");
	printf("================================================================================\n");
	printf("#HELP\n");
    printf("pm - processmaster/--You can add or kill processes through pm--\n");
    printf("mg - MineGame/--Play MineGame--\n");
    printf("play - /---Play screen saver animation--\n");	
	printf("cls - clear/--Clear the screen--\n");
	printf("exit - /--Exit the system--\n");
	printf("hp - help/--Display the help information--\n");
	printf("================================================================================\n");
	printf("================================================================================\n");	
}

void Help2()//������Ϣ
{
	printf("================================================================================\n");
	printf("================================================================================\n");
	printf("#HELP\n");
    printf("add - /--You can add a sys or user process--\n");
	printf("kill - /--You can kill process through PID--\n");
	printf("list - processinfo/--Display the information of processes--\n");
	printf("cls - clear/--Clear the screen--\n");
	printf("hp - help/--Display the help information--\n");
	printf("================================================================================\n");
	printf("================================================================================\n");	
}


void ProcessInfo()//��ʾ������Ϣ
{
	int i;
	printf("================================================================================\n");
	printf("Process ID -- Process Name -- Process Priority -- IsUserProc\n");
	for ( i = 0 ; i < MAX_TASKS_PROCS ; ++i )
	{
		if ( proc_table[i].priority == 0) continue;
		printf("     %d          %s            %2d            %d\n", proc_table[i].pid, proc_table[i].p_name, proc_table[i].priority,
        proc_table[i].task_or_no);
	}
	printf("================================================================================\n");
}

void sys_shutdown(PROCESS * p_proc)//�ر�ϵͳ
{
	int i;
	disable_int();
	for ( i = 0 ; i < 16 ; ++i )
	{
		disable_irq(i);
	}
	while(1) {}
}


void DisPlay()//��������
{
	int color = 0x7f;
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n\n\n\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	
	clear();
	printf("\n\n\n\n\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);	
	clear();
	printf("\n\n\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);		
	clear();
	printf("\n\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	
	clear();
	printf("                            HH                 HH    IIIIIIIIIII\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	clear();
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HHHHHHHHHHHHHHHHHHHHH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);
	
	clear();
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH         II\n");
	printf("                            HH                 HH    IIIIIIIIIII\n");
	
	milli_delay(1000);

}

void strtolower(char * src)//��Сд��ĸת��
{
	while (*src)
	{
		if ((*src >= 'A') && (*src <= 'Z'))
		{
			*src += 'a' - 'A';
		}
		++src;
	}
}

int strcmp(char * src, char * dst)//ƥ���ַ���
{
	while ( *src && *dst && *src == *dst) { ++src, ++dst; };
	return *src - *dst;
}
