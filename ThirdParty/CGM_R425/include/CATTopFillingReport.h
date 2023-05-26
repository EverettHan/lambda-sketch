/* -*-C++-*- */
#ifndef CATTopFillingReport_H
#define CATTopFillingReport_H

// COPYRIGHT DASSAULT SYSTEMES 1997

#include "Ribbon.h"
#include "CATMathDef.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATFace.h"
class CATSoftwareConfiguration;

#include "CATSafe.h"
CATSafeDefine(CATTopFillingReport);

class ExportedByRibbon  CATTopFillingReport

{
  public:
  
  enum CATFillTypeResult {noresult,analytic,powerfill,powerloft};
  
  //------------------------------------------------------------------------------
  // constructor 
  //------------------------------------------------------------------------------
  CATTopFillingReport(CATSoftwareConfiguration *iConfig);
  CATCGMNewClassArrayDeclare;        // Pool allocation
  CATTopFillingReport(); // A remplacer par le constructeur avec CATSoftwareConfiguration

  //------------------------------------------------------------------------------
  //  destructor 
  //------------------------------------------------------------------------------
  ~CATTopFillingReport();
  
  //------------------------------------------------------------------------------
  // Set Software Configuration to be used 
  //------------------------------------------------------------------------------
  void SetConfig(CATSoftwareConfiguration *iConfig);

  //------------------------------------------------------------------------------
  // Set the  face result from filling 
  //------------------------------------------------------------------------------
  void SetFace(CATFace * iFace, const int iFaceNumber=1);
  
  //------------------------------------------------------------------------------
  // Get the resulting faces from filling 
  //------------------------------------------------------------------------------
  int      GetNumberOfFaces() const;
  CATFace* GetFace (const int iFaceNumber=1) const;
  
  //------------------------------------------------------------------------------
  // set the maximum continuity gap on the  fill result. 
  //------------------------------------------------------------------------------
  void  SetG0MaxDeviation (const double iG0Max );
  
  //------------------------------------------------------------------------------
  // Get the maximum continuity gap on the  fill result. 
  //------------------------------------------------------------------------------
  double GetG0MaxDeviation ();
  
  //------------------------------------------------------------------------------
  // set the maximum continuity accuracy on the  fill result. 
  //------------------------------------------------------------------------------
  void  SetG0MaxAccuracy (const double iG0Max );
  
  //------------------------------------------------------------------------------
  // Get the maximum continuity accuracy on the  fill result. 
  //------------------------------------------------------------------------------
  double GetG0MaxAccuracy ();
  
  //------------------------------------------------------------------------------
  // Set  the maximum  tangency gap (in radians) on the  fill result.
  //------------------------------------------------------------------------------
  void  SetG1MaxDeviation(const double iG1Max);

  //------------------------------------------------------------------------------
  // Get  the maximum  tangency accuracy (in radians) on the  fill result.
  //------------------------------------------------------------------------------
  CATAngle GetG1MaxAccuracy();

   //------------------------------------------------------------------------------
  // Set  the maximum  tangency accuracy (in radians) on the  fill result.
  //------------------------------------------------------------------------------
  void  SetG1MaxAccuracy(const double iG1Max);

  //------------------------------------------------------------------------------
  // Get  the maximum  tangency gap (in radians) on the  fill result.
  //------------------------------------------------------------------------------
  CATAngle GetG1MaxDeviation();

 //------------------------------------------------------------------------------
  //Set  the type (analytic or powerfill) of the fill result 
  //------------------------------------------------------------------------------
  void  SetFillTypeResult (const CATFillTypeResult iFillType);
  //------------------------------------------------------------------------------
  // Get the type (analytic or powerfill) of the fill result 
  //------------------------------------------------------------------------------
  CATFillTypeResult GetFillTypeResult ();
  
  //------------------------------------------------------------------------------
  CATBoolean IsFaceTwisted(const int iFaceNumber=1);
  
  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private: 
  CATLISTP(CATFace)         _Faces ;
  double                    _G0MaxDeviation;
  double                    _G0MaxAccuracy;
  double                    _G1MaxDeviation; 
  double                    _G1MaxAccuracy; 
  CATFillTypeResult         _FillType;
  CATSoftwareConfiguration* _Config;

};
#endif
 





















