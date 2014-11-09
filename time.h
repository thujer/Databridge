#define uchar unsigned char
#define uint unsigned int

extern void Time_SetTime(uchar Hour,uchar Min,uchar Sec);
extern void Time_SetDate(uchar Year,uchar Month,uchar Day);
extern uchar Time_GetHour();
extern uchar Time_GetMin();
extern uchar Time_GetSec();
extern uchar Time_GetYear();
extern uchar Time_GetMonth();
extern uchar Time_GetDay();
extern void Time_SetHour(uchar Hour);
extern void Time_SetMin(uchar Min);
extern void Time_SetSec(uchar Sec);
extern void Time_SetYear(uchar Year);
extern void Time_SetMonth(uchar Month);
extern void Time_SetDay(uchar Day);
extern void Time_Init();

extern bit  bTimeout_1Sec;
extern void Timeout_Set(uchar Counter, uint Time);
extern bit  Timeout(uchar Counter);
extern uint Timeout_Value(uchar Counter);

