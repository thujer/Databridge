// ======================================================================= //
//                    Hlavni inicializace a nastaveni                      //
// ----------------------------------------------------------------------- //

static void CPU_Init()
{ IE=0;          // Zakaz vsech preruseni
  //CKCON=0x01;    // 6 taktovy rezim (Pouze pro procesory TEMIC !!!)
  IP=0;          // Nulovani vsech priorit

  RS0=0;         // Nastaveni registrove banky 0
  RS1=0;         // Nastaveni registrove banky 0

  // Povolovaci bity preruseni (v IE)
  //ET0=0;         // Zakaz preruseni casovace 0
  //ET1=0;         // Zakaz preruseni casovace 1
  //ET2=0;         // Zakaz preruseni casovace 2
  //EX0=0;         // Zakaz vnejsiho preruseni 0
  //EX1=0;         // Zakaz vnejsiho preruseni 1
  //ES=0;          // Zakaz preruseni serialu

  SCON=0x50;     // Rizeni serioveho rozhrani SCON
  //REN=1;         // Povoleni prijmu serialu
  //RI=0;          // Nulovani priznaku prichoziho znaku
  //TI=0;          // Nulovani priznaku odchoziho znaku
  //PS=1;          // Nastaveni vyssi priority preruseni serialu
  RXD=1;         // Nastaveni pocatecni urovne vstupu serialu
  TXD=1;         // Nastaveni pocatecni urovne vystupu
  TI=0;          // Povoleni (nastaveni priznaku) odesilani znaku

  TMOD=0x21;     // Nastaveni casovacu 1 a 0

  PCON&=0x7F;    // Power Controll - null SMODE (double speed)

  TL1=0xFB;      // Nastaveni default baud rate
  TH1=0xFB;      // Nastaveni default baud rate
  TR1=1;         // Start casovace 1

  // Timer 2
  RCAP2L=0xFF;   // Timer 2 control low
  RCAP2H=0xF3;   // Timer 2 control high

  T2CON=0;       // Timer control
  TR2=1;         // Start citace
  ET2=1;         // Timer 2 - povoleni preruseni
  TF2=0;
  //PT2=1;         // 1 = Nastaveni vyssi priority

  // Serial
  ES=1;          // Povoleni preruseni od serialu
  EA=1;          // Povoleni vsech preruseni

}

/*
// ------------------------------------------------------------------------
//
//                  Specialni funkce bitu portu 3
//                 +---------------------------------------+
//                 ¦ RD ¦ WR ¦ T1 ¦ T0 ¦INT1¦INT0¦ TXD¦ RXD¦
//                 +---------------------------------------+
//                    ^    ^    ^    ^    ^    ^    ^    ^
//                P3.7+    ¦    ¦    ¦    ¦    ¦    ¦    + P3.0
//     Cteni z externi     ¦    ¦    ¦    ¦    ¦    ¦      Seriovy port-
//     pameti dat          ¦    ¦    ¦    ¦    ¦    ¦      -vstupni data
//                         ¦    ¦    ¦    ¦    ¦    ¦
//                P3.6 ----+    ¦    ¦    ¦    ¦    +----- P3.1
//     Zapis do externi         ¦    ¦    ¦    ¦           Seriovy port-
//     pameti dat               ¦    ¦    ¦    ¦           vystupni data
//                              ¦    ¦    ¦    ¦
//                P3.5 ---------+    ¦    ¦    +---------- P3.2
//     Vnejsi  impulsy               ¦    ¦                Vnejsi  zdroj
//     citace c. 1                   ¦    ¦                preruseni 0
//                                   ¦    ¦
//                P3.4 --------------+    +--------------- P3.3
//     Vnejsi  impulsy                                     Vnejsi  zdroj
//     citace c. 0                                         preruseni 1
//
// ------------------------------------------------------------------------
//                    Rizeni serioveho rozhrani SCON
//                   +-------------------------------+
//                   ¦SM0¦SM1¦SM2¦REN¦TB8¦RB8¦ TI¦ RI¦
//                   +-------------------------------+
//                     7   6   5   4   3   2   1   0
//
//     SM0..SM2 - mod funkce serioveho rozhrani
//     -------------------------------------------
//      0    0    0    shift register   f osc/12
//      0    1    1    8-bit UART       variable
//      1    0    2    9-bit UART       f osc/64 nebo f osc/32
//      1    1    3    9-bit UART       variable
//
//     REN      - povoleni prijmu
//     RI       - preruseni po ukonceni prijmu
//     TI       - preruseni po ukonceni vysilani
//     RB8      - prijimany bit c. 8
//     TB8      - vysilany bit c. 8
//
//
// ------------------------------------------------------------------------
// TMOD
// --------------------
// Address = 89h
// Non bit addressable
// Reset value = 00h
// --------------------
//
//  <------ TIMER 0 ----------> <--------- TIMER 1 ------->
// +------+------+------+------+------+------+------+------+
// | GATE | C/~T |  M1  |  M0  | GATE | C/~T |  M1  |  M0  |
// +------+------+------+------+------+------+------+------+
//
//   Bit     Symbol      Function
//  ----------------------------------------------------------------------
//  TMOD.3/  GATE        Gating control when set. Timer/Counter "n" is
//  TMOD.7               enabled only while "~INTn" pin is high and
//                       "TRn" control pin is set. When cleared Timer "n"
//                       is enabled whenever "TRn" control bit is set.
//  TMOD.2/  C/~T        Timer or Counter Selector cleared for Timer
//  TMOD.6               operation (input from internal system clock.)
//                       Set for Counter operation (input from "Tn" input
//                       pin).
//
//       M1  M0      Operating
//    ----------------------------------------------------------------
//        0   0      8048 Timer: "TLn" serves as 5bit prescaler
//
//
//        0   1      16-bit Timer/Counter" "THn" and "TLn" are cascaded;
//                   There is no prescaler.
//
//        1   0      8-bit auto-reload Timer/Counter: "THn" holds a value
//                   which is to be reloaded into "TLn" each time it
//                   overflows.
//
//        1   1 Timer 0: TL0 is an 8-bit Timer/Counter controlled
//                       by the standard Timer 0 control bits.
//                       TH0 is an 8-bit timer only controlled
//                       by Timer 1 control bits.
//
//        1   1 Timer 1: Timer/Counter 1 stopped.
//
//
// ------------------------------------------------------------------------
//
//             Registr rizeni behu citace/casovace TCON
//                  +-------------------------------+
//                  ¦TF1¦TR1¦TF0¦TR0¦IE1¦IT1¦IE0¦IT0¦
//                  +-------------------------------+
//                    ^   ^   ^   ^   ^   ^   ^   ^
//             TCON.7 +   |   |   |   |   |   ¦   + TCON.0
//    Preteceni casovace  |   |   |   |   |   ¦     Rizeni typu  preruseni
//    c. 1                |   |   |   |   |   ¦     urovni 0
//                        |   |   |   |   |   ¦
//             TCON.6 ----+   |   |   |   |   +---- TCON.1
//    Rizeni behu citace 1    |   |   |   |         Preruseni 0 citlive
//    pri scitani             |   |   |   |         na hranu ci uroven
//                            |   |   |   |
//                            |   |   |   |
//             TCON.5 --------+   |   |   +-------- TCON.2
//    Preteceni casovace c.0      |   |             Rizeni typu  preru-
//                                |   |             seni urovni 1
//                                |   |
//             TCON.4 ------------+   +------------ TCON.3
//    Rizeni behu citace 0                          Preruseni 1 citlive
//                                                  na hranu ci uroven
//
//
// ------------------------------------------------------------------------
//
//                 Rizeni prerusovaciho mechanismu
//
//                         Interrupt Control (IC)
//                    +-------------------------------+
//                    ¦ EA¦ EC¦ET2¦ ES¦ET1¦EX1¦ET0¦EX0¦
//                    +-------------------------------+
//                      7   6   5   4   3   2   1   0
//
//      EA         - povoleni vsech preruseni
//      EC         - povoleni PCA preruseni
//      ET0..ET2   - povoleni preruseni od citace/casovace 0..2
//      EX0,EX1    - povoleni vnejsich preruseni 0 a 1
//      ES         - povoleni preruseni od serioveho rozhrani
//
//
//                         Interrupt Priority (IP)
//                    +-------------------------------+
//                    ¦ - ¦PPC¦PT2¦ PS¦PT1¦PX1¦PT0¦PX0¦
//                    +-------------------------------+
//                      7   6   5   4   3   2   1   0
//
//      PPC        - priorita PCA preruseni
//      PT0..PT2   - priorita preruseni od citacu/casovacu 0..2
//      PX0,PX1    - priorita vnejsich preruseni 0 a 1
//      PS         - priorita preruseni od serioveho rozhrani
//
// ------------------------------------------------------------------------
//
//                   Stavove slovo programu (PSW)
//                  +-------------------------------+
//                  ¦ C ¦AC ¦F0 ¦RS1¦RS0¦OV ¦   ¦ P ¦
//                  +-------------------------------+
//                    ^   ^   ^   ^   ^   ^   ^   ^
//              PSW.7 +   ¦   ¦   ¦   ¦   ¦   ¦   + PSW.0
//    Priznak prenosu     ¦   ¦   ¦   ¦   ¦   ¦     Parita akumulatoru,
//    prijima  prenos     ¦   ¦   ¦   ¦   ¦   ¦     nastavena hardwarem
//    z   ACC.7   pri     ¦   ¦   ¦   ¦   ¦   ¦     na "1", je-li pocet
//    operacich arit-     ¦   ¦   ¦   ¦   ¦   ¦     jednicek v akumulá-
//    meticko-logicke     ¦   ¦   ¦   ¦   ¦   ¦     toru  lichy,  jinak
//    jednotky            ¦   ¦   ¦   ¦   ¦   ¦     nastavena na "0"
//                        ¦   ¦   ¦   ¦   ¦   ¦
//              PSW.6 ----+   ¦   ¦   ¦   ¦   +---- PSW.1
//    Pomocny  prenos         ¦   ¦   ¦   ¦         Volne pouzitelne
//    prenos z  ACC.3         ¦   ¦   ¦   ¦
//    pri scitani             ¦   ¦   ¦   ¦
//                            ¦   ¦   ¦   ¦
//              PSW.5 --------+   ¦   ¦   +-------- PSW.2
//    Bit pro vseobec-            ¦   ¦             Priznak  preteceni,
//    ne pouziti                  ¦   ¦             nastavuji  aritmet-
//                                ¦   ¦             meticke instrukce
//                                ¦   ¦
//              PSW.4 ------------+   +------------ PSW.3
//    Vyber banky re-                               Vyber  banky regis-
//    gistru, bit 1                                 tru, bit 0
//
//
*/