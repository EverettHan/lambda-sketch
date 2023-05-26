#ifndef _CATGMPolyCheckReport_h
#define _CATGMPolyCheckReport_h

#include "GMPolyTopTools.h"

class CATGMPolyTopology;
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATGMPolyAnomaly.h"
#include "CATListPtrCATGMPolyAnomaly.h"
#include "CATSetOfPtr.h"
#include "ListPOfCATTopology.h"


class CATGMPolyBody;
class CATGMPolyVolume;
class CATGMPolyFace;
class CATGMPolyEdge;

class CATGMPolyLump;
class CATGMPolyShell;
class CATGMPolyLoop;
class CATGMPolyWire;

class CATSoftwareConfiguration;
class CATLISTP(CATCell);

class CATBody;
class CATEdge;
class CATLoop;
class CATTopology;

class CATGeoFactory;
class CATMapOfPtrToPtr;

class ExportedByGMPolyTopTools CATGMPolyCheckReport
{
public:

  CATGMPolyCheckReport(CATSoftwareConfiguration * iConfig, CATGMPolyTopology * iContextTopo);
  CATGMPolyCheckReport(CATSoftwareConfiguration * iConfig, CATTopology * iContextTopo);
  ~CATGMPolyCheckReport();

public:

//  void ConvertToCXAnomaly(CATGMPolyAnomaly & iAnomaly, CATMapOfPtrToPtr & iMapPHToCX);

//  void ConvertToPHAnomaly(CATGMPolyAnomaly & iAnomaly, CATMapOfPtrToPtr & iMapPCToGm);
//  void ConvertToPHAnomalyFromList(CATGMPolyAnomaly & iAnomaly, CATMapOfPtrToPtr & iMapPCToListGM);

  inline CATSoftwareConfiguration * GetConfig();

  /*******************************************************************************/
  /*                              ERROR DECLARATION                              */
  /*******************************************************************************/

  // CATGMPoly specific : allows lighter code in CheckUp (will probably become ptrs)
  void Offense(const CATGMPolyTopology & iTopoInError,                                         CATGMPolyAnomaly::Description, const char * iFormat=NULL,...);
  void Offense(const CATGMPolyTopology & iTopoContext, const CATGMPolyTopology & iTopoInError, CATGMPolyAnomaly::Description, const char * iFormat=NULL,...);

  // Generic itf version : allows external use such as CATGMPolyIsCATBodyReady
  void Offense(CATTopology * iTopoInError,                             CATGMPolyAnomaly::Description, const char * iFormat=NULL,...);
  void Offense(CATTopology * iTopoContext, CATTopology * iTopoInError, CATGMPolyAnomaly::Description, const char * iFormat=NULL,...);

  // New : et si on avait plusieurs cellules impliquées dans un accident ?
  void Offense(CATTopology * iTopoContext, CATTopology ** iTabTopoInError, int iSizTopoInError, CATGMPolyAnomaly::Description, const char * iFormat=NULL,...);

  /*******************************************************************************/
  /*                            WARNING DECLARATION                              */
  /*******************************************************************************/

  // Why no description ? (compared to Offense for GMPolyTopo)
  void Warning(const CATGMPolyTopology & iTopoInWarning,                                         const char * iFormat=NULL,...);
  void Warning(const CATGMPolyTopology & iTopoContext, const CATGMPolyTopology & iTopoInWarning, const char * iFormat=NULL,...);

  //
  void Warning(CATTopology * iTopoInWarning,                             const char * iFormat=NULL,...);
  void Warning(CATTopology * iTopoContext, CATTopology * iTopoInWarning, const char * iFormat=NULL,...);

private:

  /*******************************************************************************/
  /*                     ERROR / WARNING DECLARATION                             */
  /*******************************************************************************/

  // Lowest level => instanciation of CATGMPolyAnomalies
  void _Offense(CATTopology * itfContext, CATTopology ** itfError, int itfErrorSize, CATGMPolyAnomaly::Description iDesc, CATUnicodeString & iMsg);
  // void _Offense(CATTopology * itfContext, CATTopology ** itfError, int itfErrorSize, CATGMPolyAnomaly::Description iDesc, CATUnicodeString & iMsg, CATLISTP(CATCell) & iNeighborhood);
  //
  void _Warning(CATTopology * itfContext, CATTopology * itfWarning, CATGMPolyAnomaly::Description iDesc, CATUnicodeString & iMsg);

public:

  //
  void Dump(int iCounterId);

  // **** Caller MUST CALL CATGMPolyAnomaly::AddRefList and ReleaseList on these lists ****
  void GetErrors(CATLISTP(CATGMPolyAnomaly) & oErrors);
  void GetWarnings(CATLISTP(CATGMPolyAnomaly) & oWarnings);

  // Methode qui permet de savoir rapidement si un element a deja ete checke (primordial pour le CheckUp)
  CATBoolean HaveYouSeenThisGuy(CATGMPolyTopology * iTopo);

public:

  static int _DoThrow;

private:

  CATLISTP(CATGMPolyAnomaly) _Errors;
  CATLISTP(CATGMPolyAnomaly) _Warnings;

  CATSoftwareConfiguration * _Config;

  CATSetOfPtr                _ThingsIveSeen;

  CATTopology              * _ContextITF;

};

CATSoftwareConfiguration * CATGMPolyCheckReport::GetConfig() {
  return _Config;
}
#endif
