/**
 * @fullreview CVE-ERS 02:02:21
 * @error MISC Y pas de constructeur par defaut, constructeur par copie et pas d'operateur =
*/
#ifndef __CATRepParams_h
#define __CATRepParams_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <CATAfrFoundation.h>

class CATDialog;
class CATCmdStarter;

// constantes symbolique : type de rep
//------------------------------------
enum CATKindOfRep {
  CATNoRep,
  CATMenuRep,
  CATCtxMenuRep,
  CATToolBarRep      // non-utilise
};


// classe contenant les parametres necessaires a la
// creation d'une rep. La sauvegarde de ces informa-
// tions est necessaires pour le menu contextuel :
// si le contenu du CSO change, la rep du menu con-
// textuel doit etre detruite, puis reconstruite
//--------------------------------------------------

class ExportedByCATAfrFoundation CATRepParams {

public:

  // constructeur
  CATRepParams (
    CATCmdStarter    * = 0, 
    CATDialog        * = 0, 
    CATKindOfRep       = CATMenuRep
    );
    
  // accesseurs
  CATDialog          * GetDialog    ();
  CATCmdStarter      * GetStarter   ();
  CATKindOfRep         GetKindOfRep ();
  
protected:
  
  CATDialog          * _repDialog;
  CATCmdStarter      * _repStarter;
  CATKindOfRep         _kindOfRep;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATRepParams (const CATRepParams &);
  CATRepParams & operator= (const CATRepParams &);
  
};




#endif//__CATRepParams_h
