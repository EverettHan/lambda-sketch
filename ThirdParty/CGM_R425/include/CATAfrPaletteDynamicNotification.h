#ifndef CATAfrPaletteDynamicNotification_h
#define CATAfrPaletteDynamicNotification_h
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATNotification.h"
#include "CATListOfCATCommandHeader.h"


/**
 * Evenement permettant de modifier la palette. La modification est prise en compte jusqu'au prochain changement
 * d'etat de la commande courante.
 */

class ExportedByCATAfrFoundation CATAfrPaletteDynamicNotification : public CATNotification
{

 CATDeclareClass;

public:

  /** @nodoc */
  CATAfrPaletteDynamicNotification (CATLISTP(CATCommandHeader) & iHeaderList);
  virtual ~CATAfrPaletteDynamicNotification (); 

  CATLISTP(CATCommandHeader) & GetHeaderList ();
  
private:

  CATLISTP(CATCommandHeader) _HeaderList;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAfrPaletteDynamicNotification ();
  CATAfrPaletteDynamicNotification (const CATAfrPaletteDynamicNotification &);
  CATAfrPaletteDynamicNotification & operator= (const CATAfrPaletteDynamicNotification &);

};

#endif
