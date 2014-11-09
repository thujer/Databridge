#define uchar unsigned char
#define uint unsigned int

extern void  LED_ON(uchar LED_ID);
extern void  LED_OFF(uchar LED_ID);
extern void  LED_Stay(uchar LED_ID);
extern void  LED_Init();
extern void  LED_Proc();
extern uchar LED_GetStayTime(uchar LED_ID);
