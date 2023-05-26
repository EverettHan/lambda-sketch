/**
* @level Private 
* @usage U1
*/
/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//								   
// CATV4CSCommon :
//  Definition of shared common variables and constants.
//
//=============================================================================
//
// Considerations of usage:								   
//								   
//=============================================================================
//								   
// July 1998                                                      Creation LJH
//								   
//=============================================================================
#ifndef CATV4CSCommon_H
#define CATV4CSCommon_H

//
// Real encoding
#define S370                 1 // Real encoding on MVS/VM
#define IEEE                 2 // Real encoding on UNIX/Windows NT

//
// LITTLE and BIG ENDIAN definitions
#define BIG_ENDIAN           1
#define LITTLE_ENDIAN        2

//
// Constant for CATAIX conversion decision.
#define NOTHING              0 // No conversion
#define CONVERT              1 // Full conversion ( strings, real and integer )
#define PARTIAL              2 // Partial conversion ( real and integer )

//
// Special Unicode characters
#define DEFAULT_REPLACE      0x005F // Default replace character
#define DEFAULT_REPLACE_DBCS 0xFF3F // Default DBCS replace character
#define FORBID               0xFFFE // Forbidden character in a code set
#define NODEF                0xFFFF // Undefined character

//
// Type of code set
#define SBCS                 1      // Single  Byte Character Set
#define DBCS                 2      // Double  Byte Character Set
#define MBCSet               4      // Multi   Byte Character Set (On ne peut utiliser MBCS
                                    // car existe deja sous NT).
#define UNICODE_2            8      // UNICODE UCS2 Character Set (Unicode 2 bytes -ISO10646-)
#define UNICODE_4           16      // UNICODE UCS4 Character Set (Unicode 4 bytes -ISO10646-)

//
// MAX number of code sets.
#define MAX_NB_CS          336

//
// MAX number of description files of V4 code sets.
#define MAX_NB_CSFILE       75

//
// MAX number of characters in a code set by type
#define MAX_SBCS_NCAR      256  // Single  Byte Character Set => 256
#define MAX_DBCS_NCAR    65536  // Double  Byte Character Set => 65536
#define MAX_MBCS_NCAR    65536  // Multi   Byte Character Set => 65536
#define MAX_UCS2_NCAR    65536  // UNICODE UCS2 Character Set => 65536

//
// Base coding of code set
#define EBCDIC               1      // EBCDIC base coding (Mainframe)
#define ASCII                2
#define ISO                  4

//
// Font code information
#define MIN_FONT           301      // Minimum index for font code in the list bellow
#define MAX_FONT           335      // Maximum index for font code in the list bellow

//
// Code set identifiers
//
//    Ces valeurs NE DOIVENT JAMAIS ETRE CHANGEES
//    car elles servent au MARQUAGE DES DONNEES
//
// REM : Les valeurs ne doivent jamais etre de la forme : 0X20202020 OU 0X40404040.
//       En effet, elles correspondent aux BLANCS ASCII et EBCDIC pouvant servir
//       a des applis pour mettre en place elles-memes un marquage.
//
//       De plus, le numero de code set etant decale de 1 vers la gauche au marquage,
//       la valeur 0X10101010 doit egalement etre evite.
//
//       => Consequence : SUR UN OCTET, 16, 32 ET 64 SONT INTERDITS
//
//..... DS Code Sets
#define ASCII_DS             1
#define EBCDIC_DS            2
#define ASCII_JP             3 // ASCII DS MODE JAPONAIS (IBM_932_SBCS)
#define ASCII_DS_US          5
#define ASCII_DS_UK          6
#define ASCII_DS_SW          7
#define ASCII_DS_DT          8
#define ASCII_DS_IT          9
#define ASCII_DS_JP         10
#define ASCII_DS_FR         11
#define ASCII_DS_KJI        12 // IBM_932 + ASCII_DS
#define ASCII_JP_KJI        13 // IBM_932 + ASCII_JP
#define ASCII_DS_HGL        14 // EUC_KR + ASCII_DS
#define ASCII_DS_TWN        15 // EUC_TW + ASCII_DS
//
//.................................... ATTENTION : 16 INTERDIT
//
#define EBCDIC_DS_US        20
#define EBCDIC_DS_UK        21
#define EBCDIC_DS_SW        22
#define EBCDIC_DS_DT        23
#define EBCDIC_DS_IT        24
#define EBCDIC_DS_JP        25
#define EBCDIC_DS_FR        26
#define EBCDIC_DS_KJI       27 // EBCDIC_KJI + EBCDIC_DS
#define EBCDIC_DS_HGL       28 // EBCDIC_HGL + EBCDIC_DS
//
//..... IBM Code Sets
#define IBM_850             30 // ASCII 850
#define IBM_932_SBCS        31 // IBM JAPONAIS SBCS SEUL
//
//.................................... ATTENTION : 32 INTERDIT
//
#define IBM_932             33 // IBM JAPONAIS DBCS (ET SBCS)
#define IBM_930             34 // EBCDIC IBM JAPONAIS DBCS (NON OFFICIEL)
#define IBM_933             35 // EBCDIC IBM CORREEN  DBCS (NON OFFICIEL)
#define IBM_938_SBCS        36 // ASCII  IBM CHINOIS  SBCS
#define IBM_938             37 // ASCII  IBM CHINOIS  DBCS
#define EBCDIC_881          40 // EBCDIC US (IBM)
#define EBCDIC_882          41 // EBCDIC UK (IBM)
#define EBCDIC_883          42 // EBCDIC SW (IBM)
#define EBCDIC_884          43 // EBCDIC DT (IBM)
#define EBCDIC_886          44 // EBCDIC IT (IBM)
#define EBCDIC_887          45 // EBCDIC JP (IBM)
#define EBCDIC_888          46 // EBCDIC FR (IBM)
#define EBCDIC_KJI          47 // EBCDIC_KJI + EBCDIC_887
#define EBCDIC_HGL          48 // EBCDIC_HGL + EBCDIC_881
//
//..... ISO Code Sets
#define ISO646              59
#define ISO8859_1           60
#define ISO8859_2           61
#define ISO8859_3           62
#define ISO8859_4           63
//
//.................................... ATTENTION : 64 INTERDIT
//
#define ISO8859_5           65
#define ISO8859_6           66
#define ISO8859_7           67
#define ISO8859_8           68
#define ISO8859_9           69
//
//..... EUC Code Sets
#define EUC_KR              80 // EUC KOREEN DBCS (ET SBCS)
#define EUC_TW              81 // EUC CHINOIS DBCS (ET SBCS)
#define EUC_CN              82 // EUC CHINOIS SIMPLIFIE DBCS (ET SBCS)
#define EUC_JP              83 // EUC JAPONAIS DBCS (ET SBCS)
//
//..... HP Code Sets
#define HP15_JP_SBCS        90 // HP JAPONAIS SBCS SEUL
#define HP15_JP             91 // HP JAPONAIS DBCS (ET SBCS)
//
//..... Unicode Code Sets
#define UCS_2              120 // UNICODE 16 BITS SELON ISO-10646
#define UCS_4              121 // UNICODE 32 BITS SELON ISO-10646
//
//....  FONT Code Sets (allowed from 301 to 350
#define DSIT               301
#define DSHB               302
#define S932               303
#define DSFT               304
#define DSIS               305
#define DSES               306
#define DSDC               307
#define SET9               308
#define SF01               309
#define SF02               310
#define SF03               311
#define DSJP               312
 		      
#define USER1              320
#define USER2              321
#define USER3              322
#define USER4              323
#define USER5              324
#define USER6              325
#define USER7              326
#define USER8              327
#define USER9              328
#define USER10             329
#define USER11             330
#define USER12             331
#define USER13             332
#define USER14             333
#define USER15             334
#define USER16             335

#endif
