// COPYRIGHT DASSAULT SYSTEMES 2009
//=============================================================================
// May. 09  Creation                                                    SOU
//=============================================================================
//Class for a multiprocessed connect computations
//=============================================================================


#ifndef CATMProcConnectManager_H
#define CATMProcConnectManager_H

//#include "CATTopologicalOperators.h"
#include "IUnknown.h"
#include "CATMProcAppliManagerCGM.h"
#include "CATICGMObject.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATConnect.h"
#include "CATListOfInt.h"
#include "CATTopRibDef.h"

class CATMProcAppliTask;
class CATMProcAppliData;
class CATEdgeRibbon;
class CATEdge;
class CATFace;
class CATBlendMacroTool;
class CATGeoFactory;
class CATConnect;
class CATBody;
class CATShell;

//class ExportedByCATFDGImpl CATMProcConnectManager : public CATMProcAppliManagerCGM
//class ExportedByCATTopologicalOperators CATMProcConnectManager : public CATMProcAppliManagerCGM
class CATMProcConnectManager : public CATMProcAppliManagerCGM
{
public:

	CATMProcConnectManager();

	// This constructor must be called by the derived class with the applicative function reference
	CATMProcConnectManager(const char* iFunctionName
                        ,const char* iFunctionLibrary
                        ,CATGeoFactory* iFactory
                        ,CATBlendMacroTool* iMacroTool
                        ,CATEdgeRibbon* iRibbon
                        ,CATEdge* iInitialEdge
                        ,const ListPOfCATFace& iInitialFaces);

	virtual ~CATMProcConnectManager();

	CATMProcConnectManager & operator =(const CATMProcConnectManager& iOneOf);

	//functions from catapplimanager to redefine
	//create the next task to be computed in parallel
	CATMProcAppliTask* NextTask(void*& oBuffer,unsigned int& oLgBuffer,unsigned int& oLgDataIn, CATMProcAppliData*& ioUsefulData);
	
	//handles the results of a task computed in parallel
	HRESULT EndTask(CATMProcAppliTask* iTaskToEnd,void* iBuffer,unsigned int iLgResults);

  void GetConnects(ListPOfCATConnect &oConnects);

protected:
	//
	CATBoolean PrepareTask(CATConnect*& oConnect);

  //input
  CATBlendMacroTool*  _MacroTool;
  CATEdgeRibbon*      _EdgeRibbon;
  CATEdge*            _InitialEdge;
  CATFace*            _AdjacentFaces[2]; 

  //frequently used
  CATBody*            _InitialBody;
  CATShell*           _InitialShell;
  CATListOfInt        _Senses;
  CATEdge*            _CurrEdge;
  CATTopRibSign       _Direction;

  //results
  ListPOfCATConnect   _Connects;  
  
};

#endif

