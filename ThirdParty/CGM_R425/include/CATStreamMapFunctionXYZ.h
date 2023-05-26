// COPYRIGHT DASSAULT SYSTEMES 2010
//==========================================================================
// 2010  KTU  creation
//==========================================================================
#ifndef CATStreamMapFunctionXYZ_h
#define  CATStreamMapFunctionXYZ_h

#include "InfraMorph.h"

#include "CATMapFunctionXYZ.h"
#include "CATMathStream.h"
#include "CATListOfCATICGMObjects.h"
#include "CATCGMStreamVersion.h"

class CATGeoFactory;
class CATSoftwareConfiguration;

class ExportedByInfraMorph  CATStreamMapFunctionXYZ : public CATMapFunctionXYZ
{

public :


	/**
	*
	* <br><b>Tells if the object supports Stream or not</b>: 
	* @return
	* <br><b>Legal values</b>: <tt>TRUE</tt> if stream is implemented,
	* <tt>FALSE</tt> otherwise.
	* 
	*/
	virtual CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible )const =0;

	/**
	*
	* <br><b>To Stream this. Unstream must be done by CreateCATStreamMapFunctionXYZ </b>: 
	* @param ioStream
	* the stream
	* 
	*/
	virtual void Stream( CATMathStream& ioWriteStream )const  = 0;

	// master
	virtual void GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const = 0;
	virtual CATBoolean IsAKindOf(const char* ic) const{
		return ( (ic) ? (!(strcmp(ic, "CATStreamMapFunctionXYZ"))) : (FALSE) );
	}

protected :
  CATStreamMapFunctionXYZ();
  ~CATStreamMapFunctionXYZ();


};

ExportedByInfraMorph  CATStreamMapFunctionXYZ * CreateCATStreamMapFunctionXYZ(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig, CATMathStream& ioReadStream);
#endif





