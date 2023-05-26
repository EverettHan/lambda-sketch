/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATBindParameters_h
#define CATBindParameters_h

/**
 * @level Private
 * @usage U1
 */

#include "CATObjectModelerBase.h"
#include "CATIBindParameters.h"
#include "CATDataType.h"


class ExportedByCATObjectModelerBase CATBindParameters : public CATIBindParameters
{
	friend class CATLinkPrivateServices;

public:
  CATDeclareClass;

    static CATIBindParameters*	Default () ;
    static void			ResetDefault () ;

	//Accesseur statique eu parametre par defaut
	static CATLONG32 GetDefaultParams (CATParameterKind kind);

	// For internal use only
	static void ProhibitLoad ();
	//
    CATBindParameters ();
    virtual ~CATBindParameters () ;

    virtual CATLONG32 Get (CATParameterKind kind) const;
    virtual void Set (CATParameterKind kind, CATLONG32 value_) ;

	static CATIBindParameters* GetInSessionBindParameters();

    CATBindParameters (const CATIBindParameters& from);
 
	ULONG   __stdcall AddRef();

	ULONG   __stdcall Release();

private:    
	
	CATLONG32 CATSessionParameters_ ;
    CATLONG32 CATOnlyAmongLoadedObjects_ ;
    CATLONG32 CATGetMinimumObjectData_ ;

	static void RemoveAll();

	static CATIBindParameters* _InSession;

	static void InitVal();

    CATBindParameters (const CATBindParameters & from);
    CATBindParameters& operator= (const CATBindParameters& from);    
	
	CATBindParameters (CATLONG32,CATLONG32,CATLONG32);

};

#endif
