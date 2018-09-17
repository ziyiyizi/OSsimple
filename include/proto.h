
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            proto.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

/* klib.asm */
PUBLIC void	out_byte(t_port port, t_8 value);
PUBLIC t_8	in_byte(t_port port);
//PUBLIC void	disable_int();
//PUBLIC void	enable_int();
PUBLIC void	disp_str(char * info);
PUBLIC void	disp_color_str(char * info, int color);

/* protect.c */
PUBLIC void	init_prot();
PUBLIC t_32	seg2phys(t_16 seg);
PUBLIC void	disable_irq(int irq);
PUBLIC void	enable_irq(int irq);

/* klib.c */
PUBLIC void	delay(int time);
PUBLIC char *	_itoa(char * str, int num);
PUBLIC t_bool _atoi(const char * str, int * pRet);
/* kernel.asm */
PUBLIC void	restart();
void sys_call();

/* main.c */
void Begin();
void MineGame();
void ProcessMaster();
void SysShutdown(PROCESS * p_proc);
void CreateSysProcess(int id);
void CreateUserProcess(int id);
int strcmp(char * src, char * dst);
void strtolower(char * src);
void DisPlay();
void Play();
/* i8259.c */
PUBLIC void	put_irq_handler(int iIRQ, t_pf_irq_handler handler);
PUBLIC void	spurious_irq(int irq);

/* clock.c */
PUBLIC void clock_handler(int irq);
PUBLIC void milli_delay(int milli_sec);
PUBLIC void schedule();
PUBLIC void init_clock();

/* keyboard.c */
PUBLIC void keyboard_handler(int irq);
PUBLIC void init_keyboard();
PUBLIC void keyboard_read();

/* printf.c */
PUBLIC int printf(const char *fmt, ...);
PUBLIC int printf_c(int color, const char *fmt, ...);

/* tty.c */
PUBLIC void task_tty();
PUBLIC void in_process(TTY* p_tty, t_32 key);
PUBLIC int sys_write(PROCESS * p_proc, char * buf, int len);
PUBLIC int sys_write_c(PROCESS * p_proc, char * buf, int len, int color);
PUBLIC char sys_getchar(PROCESS * p_proc);
PUBLIC void setecho(TTY * p_tty, t_bool flag);
PUBLIC void sys_echoon(PROCESS * p_proc);
PUBLIC void sys_echooff(PROCESS * p_proc);
PUBLIC void sys_accepton(PROCESS * p_proc);
PUBLIC void sys_acceptoff(PROCESS * p_proc);
PUBLIC void sys_flush(PROCESS * p_proc);

/* console.c */
PUBLIC t_bool is_current_console(CONSOLE * p_con);
PUBLIC void out_char(CONSOLE * p_con, char ch);
PUBLIC void out_color_char(CONSOLE* p_con, char ch , int color);
PUBLIC void init_screen(TTY *p_tty);
PUBLIC void select_console(int nr_console);
PUBLIC int scroll_screen(CONSOLE * p_con, int direction);
PUBLIC int sys_clear(PROCESS * p_proc);

/*readchar.c*/
PUBLIC char getchar();
void readacommand(char * pStr);


/************************************************************************/
/*                        ������ϵͳ�������                            */
/************************************************************************/


/*------------*/
/* ϵͳ������ */
/*------------*/

/* proc.c */
PUBLIC	int	sys_get_ticks();

/*------------*/
/* �û������� */
/*------------*/
/* syscall.asm */
PUBLIC int get_ticks();
PUBLIC void write(char * buf, int len);
PUBLIC void write_c(char * buf , int len , int color);
PUBLIC char getchar();
PUBLIC void shutdown();
PUBLIC void echoon();
PUBLIC void echooff();
PUBLIC void accepton();
PUBLIC void acceptoff();
PUBLIC void flush();
/* main.c */
void sys_shutdown(PROCESS * p_proc);
