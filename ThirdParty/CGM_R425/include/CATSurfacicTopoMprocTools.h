// --------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011 
//==========================================================================
//
//    CATSurfacicTopoMprocTools       
//
//==========================================================================
// Aug 2011 KTU : Creation 
//==========================================================================

#ifndef CATSurfacicTopoMprocTools_h
#define CATSurfacicTopoMprocTools_h
#include "CATSurfacicTopoOperators.h"
#include "CATCGMStream.h"
#include "CATSysErrorDef.h"
#include "CATBoolean.h"

class CATMProcManager;
class CATMProcAppliManager;

class ExportedByCATSurfacicTopoOperators CATSurfacicTopoMprocTools
{
public:

	//------------------------------------------------------------------------------------------------------------------------
	// GetNbProcessesToUse
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int GetNbProcessesToUse(   );
	
	//------------------------------------------------------------------------------------------------------------------------
	// GetMProcManager
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static CATMProcManager *GetMProcManager(const int iNbProcToUse);
	
	//------------------------------------------------------------------------------------------------------------------------
	// RunMProcAppliAndEndAppli
	// Purpose : 
	//------------------------------------------------------------------------------------------------------------------------
	static int RunMProcAppliAndEndAppli(CATMProcManager *&ipMProcManager, CATMProcAppliManager*&ipAppli, const int iNbProcToUse,const CATBoolean iEndTransaction=TRUE) ;
	
	
	//--------------------------------------------------------------------------------------------------------------
	//function : EndMProcTransaction
	//purpose  : 
	//--------------------------------------------------------------------------------------------------------------
	//static void EndMProcTransaction(CATMProcManager *&iopMProcManager );

	//--------------------------------------------------------------------------------------------------------------
	//function : GetBuffer
	//purpose  : 
	//--------------------------------------------------------------------------------------------------------------
	static HRESULT GetBuffer(CATCGMStream& iStream, void *&iopBuffer, unsigned int  &ioBufferLg, unsigned int  &ioDataLg);

};




#endif
