
// Definice pro textovy report
#define  cTime_TimeoutsReport  1
#define  cTime_SysTimeReport   2

// Prirazeni timeoutu rutinam
#define cMain_TimeGuard          0  // Main:     Spousteni casovych akci
#define cMain_Delay              1  // Main:     Akce "Zpozdeni"
#define cAction_Timeout          2  // Main:     Process driver
#define cAction_Timeout2         3  // Main:     Process driver 2
#define cEEP_WriteData           4  // EEPROM:   Sekvencni zapis dat
#define cEEP_Clear               5  // EEPROM:   Sekvencni vymazani
#define cHCOM_IntUp              6  // HCOM:     Konec vysilani bez preruseni
#define cLoopTest                7  // LoopTest: Test hlavni smycky
#define cLED_Timer               8  // LED:      Rizeni doby svitu signalizacnich LED
#define cSYNCH                   9  // SYNCH:    Synchronni komunikace
// ----------------------------
#define No_Timeouts             10  // Pocet timeoutu celkem

