#ifndef _CATDialogBuilder_H
#define _CATDialogBuilder_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "DI0BUILD.h"
#include "CATString.h"
class CATDBDialogGenerator;
class CATDialog;

class ExportedByDI0BUILD CATDialogBuilder
{
  public :

  CATDialogBuilder( );
  CATDialogBuilder( const CATString &rscName );
  ~CATDialogBuilder();

  int Build ( CATDialog *father = NULL );

  CATDialog *GetDialog ( const CATString &dlgName ) const;


  private :

  CATString             _builderName  ;
  CATDBDialogGenerator *_dlgGenerator ;
};

#endif
