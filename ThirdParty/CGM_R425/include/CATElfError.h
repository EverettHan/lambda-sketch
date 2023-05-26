#ifndef CATElfError_H
#define CATElfError_H

//----------------------------------------------------------------
// Classe de gestion des erreurs - ELFINI
//----------------------------------------------------------------
// 
// heritage de CATError
//----------------------------------------------------------------

#include "CATELFMathKernel.h"
#include "CATResourceError.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATListOfCATUnicodeString.h"


class ExportedByCATELFMathKernel CATElfError : public CATResourceError
{
    CATDeclareError ( CATElfError , CATResourceError )

  public :

    // constructeur
    CATElfError ( const CATUnicodeString * String );

    // creation de l'erreur avec son message
    void CreateElfiniError ( int ier , char * etiquette , CATUnicodeString * parameters );

    // creation de l'erreur avec son message
    void CreateElfiniError ( int ier, 
                             const CATListOfInt& ParamInt,
                             const CATListOfDouble& ParamDble,
                             const CATListOfCATUnicodeString& ParamStr);

    // impression message erreur pour debug
    void PrintMsgError ( int ier ,
                         CATUnicodeString message ,
                         int type = 0 );

    // retourne le type de l erreur
    int GetSeverity();

  private :

    // Print, CallStack + SetLastError
    void Activate ();

    // Affichage de l entete et du message d erreur
    void Print ();
    
    // Affichage de l entete et du message d erreur
    void PrintStack ();

    // severity a partir du catalogue
    void GetSeverityFromCatalog( int IER );

    // mise a jour des parametres
    void SetParameters ( const CATListOfInt& ParamInt,
                         const CATListOfDouble& ParamDble,
                         const CATListOfCATUnicodeString& ParamStr);
 
    int _Type;
};

extern "C" ExportedByCATELFMathKernel 
int ehrprog(int* type, char* msg, int* ier);

    // Error Log

static void (*_ErrLog) (CATElfError *error)=NULL;
    
extern "C" ExportedByCATELFMathKernel 
void SetErrorLog (void (*ErrLog) (CATElfError *error));

extern "C" ExportedByCATELFMathKernel 
void  GetErrorLog (void (*&ErrLog) (CATElfError *error));

#endif
