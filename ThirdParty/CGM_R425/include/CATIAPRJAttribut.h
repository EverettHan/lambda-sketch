/**
 * @level Protected
 * @usage U1
 */
/*                    */
/* CATIAPRJAttribut.h */
/* SCZ le 07/04/99    */
/*                    */
#include "CATIAEntityAttribut.h"
#ifndef CATIAPRJAttribut_h
#define CATIAPRJAttribut_h
#include "CATIAEntity.h"
//...................................................................|
//                                                                   |
//                                                                   |
//        ________________  PRJ EXTERNE ________________             |
//                                                                   |
//                                                                   |
//...................................................................|
//                                                                   |
//                     STRUCTURE DE LA TABLE DES ATTRIBUTS           |
//                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~           |
//  ======   =========================================================
//           |      |      |      |      |      |      |      |      |
//           |                                                       |
// ATTHDR    |                                                       |
// 15*R8     |                                                       |
//   AU      |                                                       |
// TOTAL     |                                                       |
//           |                                                       |
//           |                                                       |
//           |         NBALNG            |         TBALNG(1)         |
//           |  .....  TBALNG(10)        |                           |
//           |                       S T A T A T                     |
//  ======   =========================================================
// OFATTR(1) |  NB ATTR. DISCRETS        |  0   |  0   |  0   |  0   |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |          NUMATT           |   0  |   0  |LAPPAT|LLOKAT|
//   1ER     |NBR DE VAL=CHINFO(1)       |       CHINFO(2)           |
//           |IDEATT ( 2 R*8 ) ......................................|
//  ATTRIBUT |.................................................IDEATT|
//           |LIBATT ( 70 L*1 ) .....................................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |             2             |  0   |  0   |  0   |   1  |
//   2EME    |             2             |            0              |
//           |  C   |  O   |  U   |  L   |  E   |  U   |  R   |      |
//  ATTRIBUT |      |      |      |      |      |      |      |      |
//           |COULEUR DU MATERIAU UTILISE ...........................|
//           |.......................................................|
//           |...........................|......|......|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                           .                           |
//           |                           .                           |
//  ======   =========================================================
// OFATTR(2) |  NB ATTR. NUMERIQUES      |  0   |  0   |  0   |  0   |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |          NUMATT           |   0  |   0  |LAPPAT|LLOKAT|
//   1ER     |                  U N I T E                            |
//           |IDEATT ( 2 R*8 ) ......................................|
//  ATTRIBUT |.................................................IDEATT|
//           |LIBATT ( 70 L*1 ) .....................................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |            2              |   0  |   0  |LAPPAT|LLOKAT|
//   2EME    |   D  |  O   |  L   |  L   |  A   |  R   |  S   |      |
//           |   P  |  R   |  I   |  X   |      |      |      |      |
//  ATTRIBUT |      |      |      |      |      |      |      |      |
//           |PRIX D'ACHAT A LA DATE DU XXXXXXX......................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                           .                           |
//           |                           .                           |
//  ======   =========================================================
// OFATTR(3) |  NB ATTR. ALPHANUMERIQUES |  0   |  0   |  0   |  0   |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |          NUMATT           |   0  |   0  |LAPPAT|LLOKAT|
//   1ER     | CHINFO(1) INUTILISE       |  CHINFO(2)    INUTILISE   |
//           |IDEATT ( 2 R*8 ) ......................................|
//  ATTRIBUT |.................................................IDEATT|
//           |LIBATT ( 70 L*1 ) .....................................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |            2              |   0  |   0  |LAPPAT|LLOKAT|
//   2EME    |      |      |      |      |      |      |      |      |
//           |   R  |  E   |  F   |  E   |  R   |  E   |  N   |  C   |
//  ATTRIBUT |   E  |      |  E   |  X   |  T   |  E   |  R   |  N   |
//           |REFERENCE CONSTRUCTEUR.................................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                           .                           |
//           |                           .                           |
//  ======   =========================================================
// OFATTR(4) |  NB ATTR. BINAIRES        |  0   |  0   |  0   |  0   |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |          NUMATT           |   0  |   0  |LAPPAT|LLOKAT|
//   1ER     | CHINFO(1) INUTILISE       |  CHINFO(2)    INUTILISE   |
//           |IDEATT ( 2 R*8 ) ......................................|
//  ATTRIBUT |.................................................IDEATT|
//           |LIBATT ( 70 L*1 ) .....................................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                       O W N A T T                     |
//           |            2              |   0  |   0  |LAPPAT|LLOKAT|
//   2EME    |      |      |      |      |      |      |      |      |
//           |   D  |  I   |  S   |  P   |  O   |  N   |  I   |  B   |
//  ATTRIBUT |   L  |  E   |      |  S   |  T   |  O   |  C   |  K   |
//           |DISPONIBILITE STOCK MAISON.............................|
//           |.......................................................|
//           |...................................LIBATT|      |      |
//           |                       A P P A T T                     |
//  ------   ---------------------------------------------------------
//           |                           .                           |
//           |                           .                           |
//  ======   =========================================================
// OFATTR(5) | NB VAL LOCKEE ATTRIBUT 1  | ..........................|
//           ---------------------------------------------------------
//           |IDEVAL 70 L*1 AU TOTAL ................................|
// 1ERE VAL. |.......................................................|
// DU 1ER    |.......................................................|
// ATTRIBUT  |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.........................................|LSTSVA|LLOKVA|
//  ------   ---------------------------------------------------------
//           |.......................................................|
// 2EME VAL. |.......................................................|
// DU 1ER    |.......................................................|
// ATTRIBUT  |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.........................................|LSTSVA|LLOKVA|
//  ------   ---------------------------------------------------------
//           | NB VAL LOCKEE ATTRIBUT 2  | ..........................|
//  ------   ---------------------------------------------------------
//           |ROUGE..................................................|
// 1ERE VAL. |.......................................................|
// DU 2EME   |.......................................................|
// ATTRIBUT  |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.........................................|LSTSVA|LLOKVA|
//  ------   ---------------------------------------------------------
//           |VERT...................................................|
// 2EME VAL. |.......................................................|
// DU 2EME   |.......................................................|
// ATTRIBUT  |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.......................................................|
//           |.........................................|LSTSVA|LLOKVA|
//  ------   ---------------------------------------------------------
//           |                           .                           |
//           |                           .                           |
//   ======   ========================================================
//                                                                   |
//...................................................................|



typedef char prj_string17[17];

// Definition d'une structure liste pour la 
// recuperation des caracteristiques des attributs du Prj 

struct liste
{
  char            l_owner[ 9 ];    
  int             l_numAtt;      
  unsigned char   l_lockD[ 4 ];  
  char            l_unite[ 9 ]; 
  char            l_idAtt[ 17 ]; 
  char            l_comment[ 72 ]; 
  char            l_chAppli[ 9 ];
};


// Definition d'une structure liste pour la 
// recuperation des caracteristiques des attributs discrets

struct liste_discret
{
  char l_commentlock[ 71 ];
  unsigned char  l_lockAtt[ 4 ];
};




extern "C"
{
  // Exploitation des tables Attributs
  
  ExportedByCATIAEntity int GetListOffPrjAttributes(const CATIAProject * iPrjToDump ,int & NbVal_disc, liste *& ListOffPrj , liste_discret *& ListOffDiscret);
  
  ExportedByCATIAEntity int GetPrjDiscretValues(const CATIAProject * iPrjToDump ,prj_string17 & Ideat , string71 *& Ideval , int & NbVal );
  
  ExportedByCATIAEntity int IsPrjAtrributesDefined(const CATIAProject * iPrjToDump);
  
  ExportedByCATIAEntity int GetPrjNbrAttributes(const CATIAProject * iPrjToDump , int  TabNbTypAtt [4] );
  
  ExportedByCATIAEntity int GetPrjIdAttributes(const CATIAProject * iPrjToDump , int  typatt , prj_string17 *&  Ideat , int & size);

 ExportedByCATIAEntity  int GetListOfAttributes( CATIAProject * Project,CATIAEntity *const current, int & size, REFERENCE *& ListeReference ) ;
  
 ExportedByCATIAEntity   int GetDiscretValues( CATIAProject * Project, CATIAEntity *const current, const string17 idattdis, int & size, string71 *& ListeValeurs); 
}

//___________________________________________________________________//
// Attention : pensez a faire une desallocation de memoire apres     //
// l'appel des methodes sur les objets  ListOffPrj , ListOffDiscret, //
// Ideval , Ideat ...                                                    //
//___________________________________________________________________//


#endif












