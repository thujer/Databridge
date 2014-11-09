@echo off

set FilesPath=E:\PRGJAZ\_Prac\GSM_3~1.10_

call compile %FilesPath% EEP_DRV  .C51 X NOLINK
call compile %FilesPath% GSM_DRV  .C51 X NOLINK
call compile %FilesPath% HCOM_DRV .C51 X NOLINK
call compile %FilesPath% CMD_GET  .C51 X NOLINK
call compile %FilesPath% RG320DRV .C51 X NOLINK
call compile %FilesPath% TERMMENU .C51 X NOLINK
call compile %FilesPath% STRUTILS .C51 X NOLINK
call compile %FilesPath% PINS     .C51 X NOLINK
call compile %FilesPath% REPORT   .C51 X NOLINK
call compile %FilesPath% ACTIONS  .C51 X NOLINK
call compile %FilesPath% PNUM_DRV .C51 X NOLINK
call compile %FilesPath% LOOPTEST .C51 X NOLINK
call compile %FilesPath% TIME     .C51 X NOLINK
call compile %FilesPath% EVENTS   .C51 X NOLINK
call compile %FilesPath% EVNT_LST .C51 X NOLINK
call compile %FilesPath% LEDS     .C51 X NOLINK
call compile %FilesPath% SYNCHSER .C51 X NOLINK

call compile %FilesPath% GSM_MAIN .C51
