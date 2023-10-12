
#include <stdint.h>
#include "CATGeoFactory.h"
#include "CATSoftwareConfiguration.h"
#include "CATBody.h"
#include <CATErrorMacros.h>
#include <CATSurface.h>
#include <CATIPGMTopSkin.h>
#include <CATCGMContainerMngt.h>
#include <CATCloneManager.h>
#include <CATMathStreamDef.h>
#include <CATCGMStream.h>

#include "ECBodyUtilities.h"
#include "ECSurfaceUtilities.h"
#include "ECEdgeUtilities.h"

#include <fstream.h>

using namespace std;

#define TRACE_ERR(...)                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }

CATBody * ECBodyUtilities::MakeBodyFromSurface(
	CATTopData                 *iTopData,
	CATSurface                 *iSurface, 
	CATSurLimits               *iLimits,
	bool						iAllowInfinite)
{	
	// RVK 080528 use limits parameter
	CATBody  * pBody = NULL ;
	if ( NULL == iTopData || NULL == iSurface ) return pBody ;
	CATSurLimits surf_limits;
	CATBoolean is_surface_finite;
	if (iLimits)
	{
		surf_limits = *iLimits;
		is_surface_finite = TRUE;
	}
	else
	{
		iSurface->GetMaxLimits(surf_limits); // make sure we have full limits of the surface
		is_surface_finite = ECSurfaceUtilities::IsSurfaceFinite(iSurface) ;
	}

	if ( ! is_surface_finite && !iAllowInfinite)
	{
		return NULL ;
	}

	
	CATGeoFactory * p_factory = iSurface->GetContainer() ;
	

	CATTry {
		pBody = CATPGMCreateSkin (p_factory,
								  iTopData,
								  iSurface,
								  &surf_limits) ;

	}
	CATCatch(CATError, error)
	{
		CATUnicodeString param1 = error->GetNLSMessage() ;
	
	}
	CATEndTry ;
	if ( pBody ) pBody->Freeze() ;
	return pBody ;
}


int ECBodyUtilities::Save( CATLISTP(CATBody) &  iBodies, const char * iFileName) 
{
	return Save( (CATLISTP(CATICGMObject) &) iBodies, iFileName) ;
}

int ECBodyUtilities::Save( CATBody * iBody,  const char *  iFileName ) 
{
  if ( NULL == iBody )
	  return 0 ;
  CATLISTP(CATBody) bodyList(&iBody,1) ;
  return Save(bodyList, iFileName) ;
}

int ECBodyUtilities::Save(CATLISTP(CATICGMObject) & iObjList, const char * iFileName ) 
{
	CATGeoFactory* pContainer = NULL;
	if ( 0 >=  iObjList.Size() ) 
		return 0 ;

	CATTry
	{
		int ii ;
		pContainer = ::CATCreateCGMContainer();

		CATCloneManager cloneMan(pContainer, CatCGMFullDuplicate, NULL);
		CATICGMObject* pClone = NULL;
        CATICGMObject* pToClone = NULL;
		for ( ii = 1 ; ii <= iObjList.Size() ; ii++ )  {
			pToClone = iObjList[ii] ;
			cloneMan.Add(pToClone);
		}
		cloneMan.Run();
		//
		//  XBE need this otherwise there is no reference of
		//  of the object and they vanish when container is saved.
		for ( ii = 1 ; ii <= iObjList.Size() ; ii++ ) {
			pToClone = iObjList[ii] ;
			pClone =  cloneMan.ReadImage( pToClone ) ;
			if ( NULL == pClone ) 
				return 0 ;
		}

		
		ofstream filetowrite(iFileName, ios::binary);

        CATSaveCGMContainer(pContainer, filetowrite);

        filetowrite.close();

        if (!filetowrite)
            TRACE_ERR("\t Failed writing the body into ofstream \n")

		::CATCloseCGMContainer(pContainer) ;

	}
	CATCatch(CATError, error)
	{
		if (pContainer) {
			::CATCloseCGMContainer(pContainer) ;

		}
		return 0 ;
	}
	CATEndTry;

	return 1 ;
}

// new body will be returned when total #lumps > 0
CATBody *ECBodyUtilities::Combine(CATSoftwareConfiguration *iConfig, CATLISTP(CATBody) &iBodyList)
{
	CATBody *newBody = NULL;
	if (iBodyList.Size() == 1)
		newBody = ECBodyUtilities::CopyBody(iBodyList[1]);
	else
	{
		CATGeoFactory *pFactory = NULL;
		CATLISTP(CATBody) clones;
		for (int i=1; i<=iBodyList.Size(); i++)
		{
			CATBody *pBody = iBodyList[i];
			if (pBody)
			{
				if (!pFactory)
				{
					pFactory = pBody->GetContainer();
					if ( pFactory == NULL)
						return NULL;
				}
				else if(pFactory!=pBody->GetContainer()) // create a clone at the target factory
				{
					CATBody* clone=ECBodyUtilities::Clone(pBody, NULL, pFactory);
					if(clone!=NULL)
					{
						clones.Append(clone);
						pBody=clone;
					}
				}
				int numDomain = pBody->GetNbDomains();
				for (int j=1; j<=numDomain; j++)
				{
					CATLocation loc;
					CATDomain *pDomain = pBody->GetDomain(j, &loc);
					if (pDomain) 
					{
						if (newBody == NULL)
						{
							newBody = pFactory->CreateBody(CatBodyMode_Delayed);
							if (newBody == NULL)
								return NULL;
						}
						CATTry
						{
							if (newBody) {
								newBody->AddDomainWithLocation(pDomain, loc);
							}
						}
						CATCatch(CATError, errobj)
						{
							CATUnicodeString err = errobj->GetNLSMessage();
							continue;
						}
						CATEndTry
					}
				}
			}
		}
		if (newBody)
			newBody->Completed(TRUE);
		ECBodyUtilities::RemoveBodies(clones);
	}
	return newBody;
}


void ECBodyUtilities::RemoveBodies(CATLISTP(CATBody)& ioBodies)
{
	ioBodies.RemoveDuplicates();
	for(int ii=1;ii<=ioBodies.Size();ii++)
	{
		CATBody* body=ioBodies[ii];
		if(body!=NULL)
			body->GetContainer()->Remove(body);	
	}
	ioBodies.RemoveAll();
}

CATBody* ECBodyUtilities::CopyBody(CATBody* iBody)
{
	if(NULL_var != iBody)
	{
		CATGeoFactory *pFactory = iBody->GetFactory();
		if(pFactory)
		{
			CATBody* pNewBody = pFactory->CreateBody(CatBodyMode_Delayed);
			int nd = iBody->GetNbDomains();
			for(int i=1; i<=nd; i++)
			{
				CATDomain *pDomain = iBody->GetDomain(i);

				CATTry
				{
					if (pNewBody != NULL) {
						pNewBody->AddDomain(pDomain);
					}
				}
				CATCatch(CATError, errobj)
				{
					CATUnicodeString err = errobj->GetNLSMessage();
					continue;
				}
				CATEndTry
			}
			pNewBody->Freeze();
			return pNewBody;
		}
	}
	return NULL;
}


CATBody *ECBodyUtilities::Clone( CATBody *                       iBody,
						   CATCGMJournalList *             ioJournal /*= NULL*/,
						   CATGeoFactory     *             iFactory /*= NULL*/,
						   CATCGMJournal::Type             iType    /*= CATCGMJournal::Creation */) 
{
	if ( NULL == iBody) 
        return NULL;
	CATGeoFactory * pFactory = iFactory;
	if ( NULL == iFactory ) {
		  pFactory = iBody->GetContainer() ;
		  if ( NULL == pFactory ) 
            return NULL;
	}

	CATBody * pResult = NULL ;
	CATLISTP(CATCell)  edgeList,
					   laminarList ;
	iBody->GetAllCells(edgeList,1) ;
	int i;
	for ( i = 1 ; i <= edgeList.Size() ; i++ ) {
		 CATEdge * pEdge = (CATEdge *) edgeList[i] ;
		 CATBoolean isLaminarFlag = ECEdgeUtilities::IsLaminar(pEdge, iBody ) ;
		 if ( isLaminarFlag ) 
			 laminarList.Append( edgeList[i] ) ;
	}
		
	CATTry
	{		
		CATCloneManager cloneMan(pFactory, CatCGMFullDuplicate, NULL);
		CATICGMObject  * pToClone = iBody  ;
	

		cloneMan.Add(pToClone);
		
		cloneMan.Run();
		//
		//  XBE need this otherwise there is no reference of
		//  of the object and they vanish when container is saved.
	
		pResult = (CATBody *) cloneMan.ReadImage( pToClone ) ;
		if ( NULL != pResult && NULL != ioJournal  ) {
			cloneMan.WriteReport(ioJournal, iType ) ;
			for ( i =1  ; i <= laminarList.Size() ; i++ ) {
			  CATICGMObject * pObj = laminarList[i] ;
			  cloneMan.WriteReport( pObj, ioJournal, iType ) ;
			}
		}
	}
	CATCatch(CATError, error)
	{
		CATUnicodeString param1 = error->GetNLSMessage() ;
	
	}
	CATEndTry ;

	return pResult ;
}
