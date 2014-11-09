
//------------------------------------------------------------------------------
extern uchar SYNCH_SendMsg(uchar *pSrcBuf, uchar SrcBytes);
extern uchar SYNCH_GetSrcByte();
extern void  SYNCH_SendByte();
extern bit   SYNCH_SaveNibble(bit H_L);
extern void  SYNCH_GetByte();
extern uchar SYNCH_GetChar();
extern void  SYNCH_Init();
extern void  SYNCH_Proc();

extern bit SYNCH_LogWriteChar(uchar Ch);
extern void SYNCH_LogWriteString(uchar *Text, uchar MaxSize);

extern uchar xdata SYNCH_BytesInRecBuf;
extern uchar xdata SYNCH_BytesInSndBuf;
extern uchar xdata SYNCH_BytesInLogBuf;
extern bit         SYNCH_RIBUF;

extern uchar xdata sSYNCH_RecStep;
extern uchar xdata sSYNCH_SndStep;
extern uchar xdata SYNCH_RecBufIx_w;
extern uchar xdata SYNCH_RecBufIx_r;
extern uchar xdata SYNCH_LogBufIx_w;
extern uchar xdata SYNCH_LogBufIx_r;
extern uchar xdata SYNCH_SrcPtrIx_w;
extern uchar xdata SYNCH_SrcPtrIx_r;
extern uchar xdata SYNCH_BytesInSndBuf;
extern uchar xdata SYNCH_BytesInRecBuf;
extern uchar xdata SYNCH_ByteInLogBuf;
extern uchar xdata SYNCH_PtrInBuf;

//------------------------------------------------------------------------------
