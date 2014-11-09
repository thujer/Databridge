cls
@echo off

c:\prgdos\c51\bin\c51 time.c51 db sb cd | more
c:\prgdos\c51\bin\c51 hcom_drv.c51 db sb cd | more
c:\prgdos\c51\bin\c51 cmd_get.c51 db sb cd | more
c:\prgdos\c51\bin\c51 gsm_drv.c51 db sb cd | more
c:\prgdos\c51\bin\c51 rg320drv.c51 db sb cd | more
c:\prgdos\c51\bin\c51 termmenu.c51 db sb cd | more
c:\prgdos\c51\bin\c51 err_drv.c51 db sb cd | more
c:\prgdos\c51\bin\c51 strutils.c51 db sb cd | more
c:\prgdos\c51\bin\c51 report.c51 db sb cd | more
c:\prgdos\c51\bin\c51 pins.c51 db sb cd | more
c:\prgdos\c51\bin\c51 actions.c51 db sb cd | more
c:\prgdos\c51\bin\c51 eep_drv.c51 db sb cd | more
c:\prgdos\c51\bin\c51 pnum_drv.c51 db sb cd | more
c:\prgdos\c51\bin\c51 looptest.c51 db sb cd | more
c:\prgdos\c51\bin\c51 %1.c51 db sb cd | more

c:\prgdos\c51\bin\bl51 @linker.cmd

c:\prgdos\c51\bin\oh51 %1.omf | more
pause
@echo on
