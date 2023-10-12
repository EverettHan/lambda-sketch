#include <stdint.h>
#include <stdio.h>

#include "ECEdgeUtilities.h"

#include <CATEdge.h>
#include <CATBody.h>
#include <ListVOfLong.h>


CATBoolean   ECEdgeUtilities::IsLaminar( CATEdge * iEdge, CATBody * iBody, CATLISTP(CATCell)  * oFaceList ) 
{
	CATBoolean  isLaminar = FALSE ;
	if ( NULL == iEdge ||  NULL == iBody ) 
        return isLaminar ;

	CATLISTP(CATCell ) bordered;
	CATListOfLong nf;
	iEdge->GetBorderedFaces(iBody, bordered, nf);
	if ( NULL != oFaceList ) 
        *oFaceList = bordered ;
	isLaminar = ( 1 == bordered.Size() ) ;
	return isLaminar ;
}
