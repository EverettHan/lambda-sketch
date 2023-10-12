

#include <stdint.h>

#include <CATGeoFactory.h>
#include <CATSoftwareConfiguration.h>
#include <CATBody.h>
#include <CATFace.h>
#include <CATDomain.h>
#include <CATErrorMacros.h>
#include <CATICGMTopWire.h>
#include <CATShell.h>
#include <CATBoundedCellsIterator.h>
#include "CATIPGMTopToolsCreateDomains.h"

#include <SWXUtAssert.h>
#include <SWXUtTraceTime.h>

#include "ECFaceUtilities.h"



CATShell * ECFaceUtilities::GetShell(CATFace* iFace, CATBody* iBody)
{
	SWX_DEBUG_TRACE("SWXMoFace::GetShell");
	CATShell* shell=NULL;
	if(iFace!=NULL && iBody!=NULL)
	{
		CATDomain * domain=NULL;
		CATBoundedCellsIterator * iterator=NULL;
		CATLISTP(CATCell) faces;
		iBody->GetAllCells(faces, 2);
		if (faces.Locate((CATCell*)iFace))
			iterator=iFace->CreateBoundedCellsIterator(iBody);
		else
			return shell;

		if(iterator!=NULL)
		{
			CATSide side;
			while(iterator->Next(&side, &domain) )
			{
				if (  NULL != domain && domain->IsATypeOf(CATShellType))
					break;
			}
			if ( NULL != domain && domain->IsATypeOf(CATShellType)) 
				shell =  (CATShell *) domain ;
			if(iterator) 
				CATRemove(iterator);
		}
	}
	return shell;
}

// Removes the first face from the input and all other faces connected together by edges and puts
// them to the output list. Normally it is called several times with the same input face collection
// while it is not empty. It must not be called with empty input.
void ECFaceUtilities::ExtractOneConnectedFaceGroup (
	CATBody* iBody, // the body
	CATLISTP(CATFace)& ioFaces, // input faces; one (the first) or more (connected) faces will be removed
	CATLISTP(CATFace)& oConnectedFaces, // one (the first input face) or more (connected) faces
	CATListOfInt & oOrientations // result faces orientations in a shell
)
{
	oConnectedFaces.RemoveAll();
	oOrientations.RemoveAll();
	if(iBody!=NULL && ioFaces.Size()>0)
	{
		CATOrientation orientation=CATOrientationPositive;
		CATFace* faceBase=ioFaces[1];
		if(faceBase!=NULL)
		{
			ioFaces.RemovePosition(1);
			oConnectedFaces.Append(faceBase);
			CATShell* shellBase=GetShell(faceBase, iBody);	
			if(shellBase!=NULL)
			{
				shellBase->GetCellRank(faceBase, &orientation);
				oOrientations.Append(orientation);
				CATLISTP(CATCell) edges;
				faceBase->GetAllCells(edges, 1);
				for(int ii=1;ii<=ioFaces.Size();ii++) // process other faces
				{
					CATFace* face=ioFaces[ii];
					if(face!=NULL)
					{
						CATLISTP(CATCell) edgesTmp, edgesCommon;
						face->GetAllCells(edgesTmp, 1);
						CATLISTP(CATCell)::Intersection(edges, edgesTmp, edgesCommon);
						if(edgesCommon.Size()>0)
						{
							edges.Append(edgesTmp);
							edges.RemoveDuplicates();
							edges.Remove(edgesCommon);
							shellBase->GetCellRank(face, &orientation);
							oConnectedFaces.Append(face);
							oOrientations.Append(orientation);
							ioFaces.RemovePosition(ii);
							ii=0;
						}
					}
				}
			}
		}
	}
	if ( oConnectedFaces.Size() != oOrientations.Size() )
	{
		oConnectedFaces.RemoveAll();
		oOrientations.RemoveAll();
	}

}


//Note that this function does not (and should not) copy faces
CATBody* ECFaceUtilities::MakeSheetFromFaces(CATBody* iBody, const CATListPtrCATFace& iFaces, bool iNewVersion)
{
	CATBody* pBodyResult = NULL;
	if(iBody!=NULL && iFaces.Size()>0)
	{
		if(iNewVersion)
		{
			CATSoftwareConfiguration* pConfig = CATCreateSoftwareConfiguration();
			if(pConfig!=NULL)
			{
				CATTopData topdata(pConfig);
				pBodyResult = MakeSheetFromFaces((CATLISTP(CATCell)&) iFaces, iBody->GetContainer(), &topdata);
				pConfig->Release();
			}
		}
		else
		{
			pBodyResult= iBody->GetContainer()->CreateBody(CatBodyMode_Delayed);
			if(pBodyResult!=NULL) 
			{
				CATTry
				{
					CATListPtrCATFace InFaces=iFaces;
					CATLISTP(CATFace) connectedFaceList;
					CATListOfInt orientations;
					while(InFaces.Size()>0)
					{
						ExtractOneConnectedFaceGroup((CATBody*)iBody, InFaces, connectedFaceList, orientations); // get connected face group
						if(connectedFaceList.Size()>0) // create one result shell
						{						
							// RVK: use CATLocationIn3DSpace: see note "Creates the shell" in CAATobTetra.cpp
							CATShell* shellNew=pBodyResult->CreateShell(CATLocationIn3DSpace);
							if(shellNew!=NULL) 
							{
								for(int ii=1;ii<=connectedFaceList.Size();ii++)
									shellNew->AddCell(connectedFaceList[ii], orientations[ii]);							
								pBodyResult->AddDomain(shellNew); // add the result shell
							}
						}
					}
					pBodyResult->Completed();
				}
				CATCatch(CATError, error)
				{
					iBody->GetContainer()->Remove(pBodyResult);
					pBodyResult=NULL;
				}
				CATEndTry;
			}
		}
	}
	return pBodyResult;
} 


CATBody *ECFaceUtilities::MakeSheetFromFaces(	CATLISTP(CATCell)		&iCells,
										CATGeoFactory			*iGeoFactory,
										CATTopData				*iTopData)
{
	CATListOfInt  OrientList;
	return MakeSheetFromFaces(iTopData, iGeoFactory, (CATLISTP(CATFace)&) iCells, OrientList);
}

CATBody* ECFaceUtilities::MakeSheetFromFaces(CATTopData *iTopData, CATGeoFactory* iGeoFactory, CATLISTP(CATFace)& iCells, CATListOfInt& iOrientList)										
{
	if (iGeoFactory == NULL || iTopData == NULL || iCells.Size() == 0)
		return NULL;

	CATLISTP(CATDomain) CreatedDomains;

	CATBody *newBody = iGeoFactory->CreateBody(CatBodyMode_Delayed);


	CATIPGMTopToolsCreateDomains *domainCreator = CATPGMCreateTopCreateDomains( newBody,
																				(CATLISTP(CATCell)&) iCells,
																				iOrientList,
																				CreatedDomains,
																				*iTopData);  
	if (domainCreator == NULL)
		return NULL;

	CATTry
	{
		domainCreator->Run();
	}
	CATCatch(CATError, error)
	{
		CATUnicodeString err = error->GetNLSMessage();
	}
	CATEndTry;

	domainCreator->Release();

	if (newBody)
	{
		newBody->Freeze();
	}

	return newBody;
}

