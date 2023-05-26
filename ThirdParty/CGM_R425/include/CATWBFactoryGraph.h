// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBFactoryGraph.h
// Header definition of CATWBFactoryGraph
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /04/2009 KJD Creation (E.-M. Duclairoir, DS)
// 01/06/2022 Q48 Small file tidy (const etc)
//===================================================================

#ifndef CATWBFactoryGraph_h
#define CATWBFactoryGraph_h

#include "CATWBExpression.h"
#include "CATWBEquation.h"

#include "WhiteBoxUtilities.h"
#include "CATCDSStream.h"

//-----------------------------------------------------------------------

class ExportedByWhiteBoxUtilities CATWBFactoryGraph 
{
public:
   CATWBFactoryGraph(const CATWBExpression * iExpr);
   CATWBFactoryGraph(const CATWBExpression * iExpr, CATCDSString & OutputPath);

   CATWBFactoryGraph(const CATWBEquation * iEqu);
   CATWBFactoryGraph(const CATWBEquation * iEqu, CATCDSString & OutputPath);

   CATWBFactoryGraph(CATWBFactory * Factory);
   CATWBFactoryGraph(CATWBFactory * Factory, CATCDSString & OutputPath);


   ~CATWBFactoryGraph();
   void GenerateWBTreeFile(CATCDSBoolean iWithValue = FALSE);

private : 
   void GenerateBasicWBTreeFile(CATCDSBoolean iWithValue);
   void ChildTreatment(const CATWBExpression * iExpr, CATCDSBoolean & iWithValue, CATCDSStream * iDump, CATCDSLISTP(CATWBExpression)  & List);

   CATWBFactory * _Factory; 
   const CATWBExpression * _Expr;
   const CATWBEquation * _Equ;
   CATCDSString _OutputPath;
   int _CtorType;

};

//-----------------------------------------------------------------------

#endif
