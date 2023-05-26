//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATFDFZone:
// Interface to define if a point must be modified
//
//==========================================================================
// Usage Notes
//==========================================================================
// Dec. 99     Creation                       PMG
//========================================================================== 
#ifndef CATFDFZone_H
#define CATFDFZone_H

#include "InfraMorph.h"
#include "CATMathDef.h"
#include "CATMathPoint.h"
//#include "CATMathPlane.h"

#include "CATMathStream.h"
#include "CATListOfCATICGMObjects.h"
#include "CATCGMStreamVersion.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATFace;
class CATMathPlane;

class CATFDFZone
{
  public:

 //===========
	//Memory Management
	//===========

	virtual CATLONG32 AddRef()=0;
	virtual CATLONG32 Release()=0;

  //===========
	//Information
	//===========
	virtual CATBoolean IsA3dZone() const = 0;
	virtual CATBoolean IsA2dZone() const = 0;


  virtual CATLONG32 SetPlane(const CATMathPlane &  iPlane)=0;


  //===========
	//Evaluators
	//===========	
    virtual CATBoolean IsInsideZone(const CATMathPoint& iPInitial) const = 0 ;
	virtual CATBoolean IsInsideZone(const double u, const double v) const = 0 ;
	
	virtual CATBoolean IsAKindOf(const char* iMapClassName) const = 0;
	virtual CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible )const =0;
	virtual void Stream( CATMathStream& ioStream )const  = 0;

	// master
	virtual void GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const = 0;

};

ExportedByInfraMorph CATFDFZone * CATCreateCATFDFZone(const CATFace *, CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, const CATMathPlane * iPlane=0);
#endif
