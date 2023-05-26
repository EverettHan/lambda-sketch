/**
 * @level Protected
 * @usage U2
 */

// ----------------------------------------
//     COPYRIGHT DASSAULT SYSTEMES 1998 
// ----------------------------------------
//
//   Class : CATUAXElement
//
// ----------------------------------------
//       Creation : OGM le 11/12/1998
// ----------------------------------------

// ------------------------------------------------------------------------------
//  Cette classe va permettre de recuperer les donnees contenues dans un UAE.
// ------------------------------------------------------------------------------

#ifndef CATUAXElement_H
#define CATUAXElement_H

#include "ExportedByCATIAEntity.h"
#include "CATIAModel.h"
#include "CATIAEntity.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"

#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#define ListOfVarBaseUnknown CATLISTV(CATBaseUnknown_var)

class ExportedByCATIAEntity CATUAXElement
{
  public :
    CATUAXElement() ;
    CATUAXElement( CATIAEntity* ) ;
    CATUAXElement( CATIAModel*, int ) ;
    ~CATUAXElement() ;

    CATIAModel*                   GetModel () ;
    CATIAEntity*                  GetEntity() ;
    int                           GetJele() ;

    int                           GetMode() ;
    CATUnicodeString              GetCurrentAppli() ;
    CATUnicodeString              GetAppli() ;
    CATUnicodeString              GetIdent() ;
    int                           GetClasse() ;

    // Recuperation des UDB
    // ---------------------
    CATListOfInt                  GetListOfUDBV1() ;
    CATListOfInt                  GetListOfUDBV2() ;

    // La methode GetDataFromUDBV1 decode une description de type UDBV1
    // En entree :
    //    - le numero ( le type ) de la description
    // En sortie :
    //    - nb_I4  : le nombre de I4
    //    - tab_I4 : un pointeur vers le tableau des I4
    //    - nb_R4  : le nombre de R4
    //    - tab_R4 : un pointeur vers le tableau des R4
    //    - nb_R8  : le nombre de R8
    //    - tab_R8 : un pointeur vers le tableau des R8
    //    - nb_C8  : le nombre de C8
    //    - tab_C8 : un pointeur vers le tableau des C8
    // ATTENTION : un C8 correspond a 8 char. Le nombre de char contenus dans tab_C8 est 8*nb_C8 
    int                           GetDataFromUDBV1( int descr, int& nb_I4, int*& tab_I4,
                                                               int& nb_R4, float*& tab_R4,
                                                               int& nb_R8, double*& tab_R8,
                                                               int& nb_C8, char*& tab_C8 ) ;
    CATListOfDouble               GetDataFromUDBV2( int descr ) ;

    // Recuperation des elements pointes
    // ---------------------------------
    CATListOfInt                  GetParents() ;

    // Erased pointed elements are not in the list
    CATListOfInt                  GetUWL() ;

  private :
    CATIAModel* _Model ;
    int _Jele ;

    CATIAEntity* _Entity ;

    union R8enHexa {
      double reel ;
      unsigned char octet[8] ;
    } ;

    union R8enI4 {
      double reel ;
      int i4[2] ;
    } ;
} ;

#endif
