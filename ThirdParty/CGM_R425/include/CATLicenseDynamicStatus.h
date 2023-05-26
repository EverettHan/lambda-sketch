/*
 * @fullReview LAI JBT 02:03:26
 */
#ifndef CATLicenseDynamicStatus_H
#define CATLicenseDynamicStatus_H
// COPYRIGHT DASSAULT SYSTEMES 2002

#define _SETTINGS_NOKIA_R15	1
// - Un Filtre sur les produits qui acceptent d'etre actives/desactives
#include "LicensingFR.h"  // exportedby
#ifdef _SETTINGS_NOKIA_R15
#include "CATDynProd.h"  
#endif

class CATTrace;

class ExportedByLicensingFR CATLicenseDynamicStatus
{
   public:
   enum ProdDynStatus
   {
      Dynamic = 0,
      Static,
      Undef
   };
   static ProdDynStatus GetStatus ( const char * iprodname );
#ifdef _SETTINGS_NOKIA_R15
   static ProdDynStatus GetStatus ( CATDynProd * iconfname );
#endif
   static int UnMake ();
   
   private:
   CATLicenseDynamicStatus ();
   ~CATLicenseDynamicStatus ();

   void Dump ( );
 
   static CATLicenseDynamicStatus * _anchor;
   static CATTrace *                _t;
   static char **                   _handle;

};
#endif
