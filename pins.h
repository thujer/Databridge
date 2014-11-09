
// Konfigurace HW prepinacu
sbit    swtchTestMode   = P1^0;    // Testovaci mod, SMS nejsou skutecne odeslany
sbit    swtchBridge     = P1^1;    // Prepinac komunikace - 232<->485 bridge
sbit    swtchDebugMsgs  = P1^2;    // Povoleni ladicich zprav
sbit    swtchConfigMode = P1^3;    // Konfiguracni mod

// Prirazeni ovladacich bitu k pinum
sbit    SCL             = P1^4;    // Sit - Komunikace 485 (Hodiny)
sbit    SDA             = P1^5;    // Sit - Komunikace 485 (Data)
sbit    M_S             = P1^7;    // Propojeni komunikace
sbit    IGN             = P2^7;    // Ignition GSM modemu
#define RXD1              INT0     // Emulovany serial (Prijem)
#define TXD1                T1     // Emulovany serial (Vysilani)
#define DIR1                T0     // T0 ... prepinani smeru toku dat
#define RXM               INT1

// Prirazeni pinu pro synchronni komunikaci s externim zarizenim
sbit pin_HSI = P2^0;
sbit pin_HSO = P2^1;
sbit pin_D0  = P2^2;
sbit pin_D1  = P2^3;
sbit pin_D2  = P2^4;
sbit pin_D3  = P2^5;

// Prirazeni LED
sbit pin_LED0 = P0^0;    // Pin pro LED0
sbit pin_LED1 = P0^1;    // Pin pro LED1
sbit pin_LED2 = P0^2;    // Pin pro LED2
sbit pin_LED3 = P0^3;    // Pin pro LED3
sbit pin_LED4 = P0^4;    // Pin pro LED4
sbit pin_LED5 = P0^5;    // Pin pro LED5
sbit pin_LED6 = P0^6;    // Pin pro LED4
sbit pin_LED7 = P0^7;    // Pin pro LED5

