#ifndef FrFCompositeCurveDump_H
#define FrFCompositeCurveDump_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//-----------------------------------------------------------------------------
//--  FrFCompositeCurveDump.h: external dump of a  composite curve  -----
//-----------------------------------------------------------------------------
// Use Sample
//----------------------------------------------------------------------------
// !---------------------------------------------------------------------------
// ! // Definition of the macros
// ! #include "FrFCompositeCurveDump.h"
// ! // definition of the composite curve  to dump
// ! CATFrFCompositeCurve* *Ccv1=; *Ccv2= ;
// ! // dump of the composite curves 
// ! FrFCompositeCurveDump(Ccv1,cout,"CCV 1") 
// !---------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Prerequis 
//----------------------------------------------------------------------------
#include <CATCurve.h>
#include <CATPCurve.h>
#include <CATCrvLimits.h>
#include <CATMathPoint.h>
#include <CATFrFCompositeCurve.h>
//----------------------------------------------------------------------------
// Dump of a composite curve
// FrFCompositeCurveDump(CATFrFCompositeCurve* CCV,
//                       ostream&              OSTREAM,
//                       char*                 TITLE)
// ex: FrFCompositeCurve(Ccv, cout, "guide du sweep")
//----------------------------------------------------------------------------
#define FrFCompositeCurveDump(CCV, OSTREAM, TITLE)\
   {\
    int NbCrv_DumpCCV =  CCV->GetNumberOfCurves() ;\
    int Closed_DumpCCV = CCV->GetClosure() ;\
    OSTREAM <<" - start Dump CCV "<<CCV<< " ------"<<TITLE<<endl;\
    OSTREAM <<"  NbCrv = "<<NbCrv_DumpCCV;\
    if (Closed_DumpCCV) OSTREAM <<" (Closed)"<<endl;\
    else        OSTREAM <<" (opened)"<<endl;\
    for (int NumCrv_DumpCCV = 1 ; NumCrv_DumpCCV <=  NbCrv_DumpCCV ; NumCrv_DumpCCV ++){\
       CATCurve* Crv_DumpCCV = CCV->GetOneCurve(NumCrv_DumpCCV-1) ;\
       int CrvTag_DumpCCV = ((CATICGMObject*)Crv_DumpCCV)->GetPersistentTag();\
       CATLONG32 Ori_DumpCCV=CCV->GetOneCrvOrientation(NumCrv_DumpCCV-1);\
       CATCrvLimits CrvLimits_DumpCCV = CCV->GetOneCrvLimits(NumCrv_DumpCCV-1) ;\
       CATCrvParam  CrvStart_DumpCCV=CrvLimits_DumpCCV.GetStartParam();\
       CATCrvParam  CrvEnd_DumpCCV=CrvLimits_DumpCCV.GetEndParam();\
       OSTREAM <<"   curve "<<NumCrv_DumpCCV<<"(index="<<NumCrv_DumpCCV-1<<") (tag="\
               <<CrvTag_DumpCCV<<") :";\
       if (Crv_DumpCCV->IsAKindOf("CATPCurve"))\
       OSTREAM<<Crv_DumpCCV<<" "<<Crv_DumpCCV->IsA()<<"   Ori="<<Ori_DumpCCV\
       <<" support:"<<((CATPCurve*)Crv_DumpCCV)->GetSurface()\
       <<" orisupport:"<<CCV->GetOneSupportOrientation(NumCrv_DumpCCV-1)<<endl;\
       else\
       OSTREAM<<Crv_DumpCCV<<" "<<Crv_DumpCCV->IsA()<<"   Ori="<<Ori_DumpCCV<<endl;\
       CATMathPoint StartPoint_DumpCCV=Crv_DumpCCV->EvalPoint(CrvStart_DumpCCV) ;\
       OSTREAM<< "    start:"<<StartPoint_DumpCCV<<" param="<<CrvStart_DumpCCV<<endl;\
       CATMathPoint EndPoint_DumpCCV=Crv_DumpCCV->EvalPoint(CrvEnd_DumpCCV) ;\
       OSTREAM<< "    end  :"<<EndPoint_DumpCCV<<" param="<<CrvEnd_DumpCCV<<endl;}\
    OSTREAM <<" - end   Dump CCV ------"<<endl;}
//  } // pb compilation with last } alone on the line
//----------------------------------------------------------------------------
//-- end FrFCompositeCurveDump.h: debug visualization of geometric elements ---------
//-----------------------------------------------------------------------------
#endif





