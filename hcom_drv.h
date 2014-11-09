#define uchar unsigned char
#define uint unsigned int

extern bit          bHCOM_RIBUF;
extern uchar  data  HCOM_RW_IX;
extern uchar  data  HCOM_RR_IX;
extern uchar  data  HCOM_RBIB;
extern uchar  data  HCOM_RByte;
extern bit          bHCOM_RB_Overflow;

extern uchar  data  HCOM_SW_IX;
extern uchar  data  HCOM_SR_IX;
extern uchar  data  HCOM_SBIB;
extern uchar  data  HCOM_SDELAY;
extern bit          bHCOM_SB_Overflow;

extern void HCOM_PROC();
extern void HCOM_Init();
extern bit  HCOM_WriteChar(uchar Ch);
extern void HCOM_WriteString(uchar *Text, uchar MaxSize);
extern void HCOM_StartSend();
extern void HCOM_Start_NI_TXD();
extern void HCOM_End_NI_TXD();

extern bit HCOM_SendPtr(uchar *Ptr, uchar MaxIndex);

extern bit HCOM_Get_Var(uint VarID);
