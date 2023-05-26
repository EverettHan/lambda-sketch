// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATCVMStreamUtilities_H
#define CATCVMStreamUtilities_H

#include "CATCVMGeoObjects.h"
#include "CATBoolean.h"
#include "CATCVMGeoContainer.h"

class CATTopData;
class CATCVMStreamArea;
class CATCGMStream;
class CAT3DRep;
class CATCVMImportExportDATA;
class CAT3DViewpoint;
class CATPixelImage;

struct CATCVMStreamStatistics;


#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif



class ExportedByCATCVMGeoObjects CATCVMStreamUtilities
{
  public:
    static CATBoolean Save(CATCVMGeoContainer * iCVMGeoContainer, char* iFileName);
    static CATBoolean Open(CATCVMGeoContainer *& oCVMGeoContainer, char* iFileName,
                           CATBoolean iKarcherIsolatedVertices=FALSE);

	static CATBoolean Stream(CATCVMGeoContainer * iCVMGeoContainer, CATCVMStreamArea*& where, CATCVMStreamStatistics* Statistics = NULL, CATBoolean iExportMode=FALSE,
                             CATBoolean iForDebug=FALSE);
    static CATBoolean UnStream(CATCVMGeoContainer *& oCVMGeoContainer, CATCVMStreamArea* where, 
                               CATCVMReference * iFederator=NULL,
                               CATBoolean iKarcherIsolatedVertices=FALSE);

    static CATBoolean Insert(CATCVMGeoContainer * iCVMGeoContainer, char               * iFileName,
                             CATTopData         * iTopData);

	static CATBoolean Insert(CATCVMGeoContainer * iRecipient, CATCVMGeoContainer * iToBeCopied, 
		                      CATTopData         * iTopData);

	public:
    static CATBoolean WriteCVMFile(CATCVMGeoContainer * iCVMGeoContainer, char* iFileName);
    static CATBoolean WriteCVMFile(CATCVMGeoContainer * iCVMGeoContainer, CATCGMStream * iStream, CATCVMStreamStatistics* iStatistics=NULL, CATBoolean iExportMode=FALSE,CATBoolean iForDebug=FALSE);
    static CATBoolean ReadCVMFile(CATCVMGeoContainer *& ioCVMGeoContainer, char* iFileName, CATCVMReference *iFederator=NULL, CATBoolean iKarcherIsolatedVertices=FALSE);
    static CATBoolean ReadCVMFile(CATCVMGeoContainer *& ioCVMGeoContainer, CATCGMStream * iStream, CATCVMReference *iFederator=NULL, CATBoolean iKarcherIsolatedVertices=FALSE);

	//for CGMReplay :
	static CATBoolean CATLoadCVMContainer(CATCVMGeoContainer *& ioCVMGeoContainer, CATCVMGeoStream * iStream, CATCVMReference *iFederator=NULL);
	static CATBoolean CATStreamCVMContainer(CATCVMGeoContainer *& iCVMGeoContainer, CATCVMGeoStream * iStream);
    static CATBoolean Open3dxmlFile (const CATUnicodeString & iFileName , CATCVMPSContainer *ipCVMPSContainer, 
                                                           CATCVMSystem *& oReference, CAT3DRep *& op3DRep,
                                                           CATCVMImportExportDATA * opDat, CAT3DViewpoint * iopViewpoint,
                                                           CATUnicodeString *iExtention=NULL);
    static CATBoolean Save3dxmlFile (CATUnicodeString& iFileName,CAT3DRep * ipRep, CATCVMPSContainer * ipCVMPSContainer,
                                                CATCVMImportExportDATA *iData, CAT3DViewpoint * ipViewpoint, CATPixelImage * ipThumbnail,
                                                CATUnicodeString * iExtention=NULL);




    //for export
	static CATBoolean SaveAsCAT3DShape(CATCVMGeoContainer * iCVMGeoContainer, char* iFileName);
    static CATBoolean SaveAsNCGM (CATCVMGeoContainer * iCVMGeoContainer, char* iFileName);
	static CATBoolean SaveAsCATPart (CATCVMGeoContainer * iCVMGeoContainer, char* iFileName);
	static CATBoolean SaveAs3DXML (CATCVMGeoContainer * iCVMGeoContainer, CAT3DRep *pRep,char* iFileName);
	static CATBoolean SaveAs3DXMLWithMesh (CATCVMGeoContainer * iCVMGeoContainer, CAT3DRep *pRep,char* iFileName);




};
#endif


