// COPYRIGHT DASSAULT SYSTEMES 2003
//============================================
//objets dedies a la decoupe de body
//
//Aug 03  Creation                         AOV
//============================================
#ifndef CATCuttingElt_H
#define CATCuttingElt_H

#include "Primitives.h"
#include "CATFace.h"
#include "CATMathInline.h"
#include "ListPOfCATFace.h"
#include "CATListOfDouble.h"





//-----------------------------------------------------------------------------
class ExportedByPrimitives CATCuttingElt
{
 public:

   //----------------------------
   // constructeur, destructeur
   //----------------------------
	 CATCuttingElt();
   virtual ~CATCuttingElt();

   void SetListOfFace    ( const CATLISTP(CATFace) & iListOfFace );
   void SetListOfIsoParU ( const CATListOfDouble   & iListOfU    );
   void SetListOfIsoParV ( const CATListOfDouble   & iListOfV    );

   INLINE CATLISTP(CATFace) GetListOfFace()   {return _ListOfFace;};
   INLINE CATListOfDouble   GetListOfIsoParU(){return _ListOfIsoParU;};
   INLINE CATListOfDouble   GetListOfIsoParV(){return _ListOfIsoParV;};


 private:

   CATLISTP(CATFace) _ListOfFace;
   CATListOfDouble   _ListOfIsoParU;
   CATListOfDouble   _ListOfIsoParV;

	
};

#endif
