//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2020
//
// CATGMPolyAnomaly
//
// DESCRIPTION :
//
// History
//
// 20200618 WMN Creation
//
//=============================================================================
#ifndef _CATGMPolyAnomaly_H
#define _CATGMPolyAnomaly_H

#include "GMPolyTopTools.h"
#include "CATPolyRefCounted.h"
#include "CATUnicodeString.h"

class CATListPtrCATGMPolyAnomaly;
class CATTopology;
class CATPolyBody;
class CATPolyCell;

// On arrête l'héritage, ces classes deviennent membres de CATGMPolyAnomaly
class CATGMPolyAnomalyTOPO;
class CATGMPolyAnomalyICBR;

class CATMapOfPtrToPtr;
class CATCGMDiagnosis;

#include "CATCollec.h"
class CATListPtrCATBody;

class CATError;

#ifndef GMPolyInFile
#define GMPolyInFile "GMPolyOperators"
#endif

class CATSoftwareConfiguration;

// Une anomalie va désormais décrire les différents états par lesquels elle passe :
// - Création via ICBR ?
// - Création via Completed ?
// - Enrichissement ICBR => TOPO ?
// - Enrichissement des parents ?

// Pour cela, elle va agréger 3 anomalies :
// - une ICBR, si elle est créée par ICBR
// - une TOPO, si elle est créée par Completed  OU  si elle est enrichie après ICBR
// - une TOPO, la seconde, si elle est enrichie pour remonter aux cellules inputs (utile pour conversion et wrapping)

// Les deux endroits amenés a creer de l'anomalie directement sont le CheckReport (qui accumule les anomalies pendant un Completed/CheckTopo)
//                                                              et le ICBR
// C'est à dire deux contextes ou on connait forcement le body et/ou les cellules
// Les autres endroits qui voient passer de l'anomalie passeront par une autre méthode, nouvelle, pour enrichir les anomalies.
// Terminé les histoires de CheckReport sur la pile, de conversion avec nouvelles anomalies créées etc.

// On cherche ainsi à décrire les différents scénarios de création d'erreur existants
// Opérateur => Checker(CATBodyResultat) => choix d'enrichir les anomalies pour remonter aux inputs ou non
// Wrapping => ICBR(PolyBodyResultat) => remontée aux inputs systématique

class ExportedByGMPolyTopTools CATGMPolyAnomaly : public CATPolyRefCounted
{
public:

  enum Type
  {
    Warning = 0,
    Error = 1
  };

  // Vs bitfield ?
  enum Description
  {
    // Valeurs pertinentes
    Unspecified = 0,
    Watertightness,
    Warning_LoopsSharingVtx,
    Autochk_FaceFaceIntersection,
    VertexProximity,
    InvalidTopology,
    InvalidGeometry,
    ModelSize,
    ICBRError,
    ICBRFaceFaceIntersection,
    ICBRBadEdgeFaceOrientation,
    ICBRFaceSelfIntersection,
    ICBRFaceSelfContact,
    Mac2Mic,
    LinearExtrusion_Closed_or_NonManifold_Surf,
    LinearExtrusion_Closed_or_NonManifold_Planar_Curv_in_Same_Plane,
    LinearExtrusion_Profile_Locally_Parallel_To_Extrusion_Direction,
    // Nombre de valeurs pertinentes : pour boucler tranquillou
    NbAnomalies
  };

public:
  public:
  static CATGMPolyAnomaly * Offense(CATPolyBody * iPolyBody, CATPolyCell** itPolyCells, int iSize, CATGMPolyAnomaly::Description iDesc, const char* iFormat=NULL,...);
  static CATGMPolyAnomaly * Offense(CATTopology * iGlobalContext, CATTopology * iLocalContext, CATTopology ** itTopo, int iSize, CATGMPolyAnomaly::Description iDesc, const char* iFormat = NULL, ...);
  
  static void UpdateList(CATListPtrCATGMPolyAnomaly & ioList, CATMapOfPtrToPtr & iMap, CATBoolean iCellCellMap = TRUE);
  static void DumpList(CATListPtrCATGMPolyAnomaly & ioList, int iCounterId);
  
  // Return value : number of anomalies with invalid data : useless if not detailed, better off stored in each anomaly.
  // Here, I need something high level :
  // - 0 : all configs OK in exact
  // - 1 : all configs OK w/ VoB but at least one KO w/ Autocheck (warning)
  // - 2 : at least one config KO w/ VoB (error)
  static int  CheckList(CATListPtrCATGMPolyAnomaly & iList, CATSoftwareConfiguration * iConfig, CATBoolean debug_mode);

  // rc=0 OK, rc=1 KO
  // iLErrors = list of anomalies to turn into CGMDiagnosis
  // iOpeName = CATNls string identifying the operation that generated the anomalies
  // iErrName = CATNls string identifying the message to use (if NULL, default will be GMPolyInPolyOperatorCurrentRestriction_ERR_9010)
  static int BuildError(CATListPtrCATGMPolyAnomaly & iLErrors, CATSoftwareConfiguration * iConfig, const CATString & iOpeName, const char * iErrName, CATError *& oError);
  // Version without iErrName : reuses first anomaly's error as main message
  static int BuildError(CATListPtrCATGMPolyAnomaly & iLErrors, CATSoftwareConfiguration * iConfig, const CATString & iOpeName, CATError *& oError);

private:
  void BuildErrorData(CATSoftwareConfiguration * iConfig, CATCGMDiagnosis ** iotDiag, CATLISTP(CATBody) * iolLocation, CATLISTP(CATBody) * iolContext, CATUnicodeString & iOpeName);
  void ProcessGeometries(CATTopology * ipGloContext, CATTopology * ipLocContext, CATTopology ** itpTopo, int & inpTopo, CATSoftwareConfiguration * iConfig, CATCGMDiagnosis *& ioDiag, CATLISTP(CATBody) & oLocationList, CATLISTP(CATBody) & oContextList, const char * MsgId, CATUnicodeString &opeName);

private:
  void Update(CATMapOfPtrToPtr&, CATBoolean iCellCellMap);
  void CreateTOPOparent(CATMapOfPtrToPtr&, CATBoolean);
  void CreateTOPO(CATMapOfPtrToPtr&, CATBoolean);

  void CreateTOPOfromICBR(CATMapOfPtrToPtr & iMap);
  void CreateTOPOfromTOPO(CATMapOfPtrToPtr & iMap);
  void CreateTOPOparentfromICBR(CATMapOfPtrToPtr & iMap);
  void CreateTOPOparentfromTOPO(CATMapOfPtrToPtr & iMap);

public:
  /** Create an anomaly with CATTopology
   * iGlobalContext : the checked topology, most likely a body but Completed can be called on any topology
   * iLocalContext  : optional, provides context info for the error. Example : the edge is provided when a vertex does not match the extremities of the polycurve.
   * itTopo         : array of invalid topologies
   * iSize          : size of the array
   * iType          : type of anomaly (see enum)
   * iDesc          : description of anomaly (see enum)
   * iMsg           : internal debug string */
  CATGMPolyAnomaly(CATTopology * iGlobalContext, CATTopology * iLocalContext, CATTopology ** itTopo, int iSize, CATGMPolyAnomaly::Type iType,CATGMPolyAnomaly::Description iDesc,CATUnicodeString iMsg);

  /** Create an anomaly with CATPolyTopology
   * iPolyBody : the polybody being checked
   * itCell    : array of invalid polycells
   * iSize     : size of the array
   * iType          : type of anomaly (see enum)
   * iDesc          : description of anomaly (see enum)
   * iMsg           : internal debug string */

  CATGMPolyAnomaly(CATPolyBody * iPolyBody, CATPolyCell ** itCell, int iSize, CATGMPolyAnomaly::Type iType,CATGMPolyAnomaly::Description iDesc,CATUnicodeString iMsg);

  ~CATGMPolyAnomaly();

public:
  // Une fois créées, les anomalies peuvent alors être enrichies aux niveaux supérieurs :
  // - Le checker va utiliser la map de l'adapter pour PolyBody => CATBody
  //                                                   PolyCell => CATCell
  //
  // - La map de l'opérateur pour CATBody => CATBody
  //                              CATCell => CATCell si opérateur bijectif (conversion)
  //
  // - La map plus complexe issue du journaling pour wrapping & co

  // int Enrich(map ptr to ptr or something like that)
  // must be able to find all of its data in the map
  // the map will allow to switch from poly to gm or from ph to cx, for example
  // but even gm to gm is possible, ph to ph, ph to cx

public:
  // Accéder aux géométries
  //   ICBR       telles que fournies (donc anomalie créée par ICBR)
  void GetGeometriesICBR(CATPolyBody *& oPolyBody, CATPolyCell **& otCell, int & oSize);
  //   TOPO       telles que fournies (donc anomalie créée par CheckTopo/Completed)
  void GetGeometriesTOPO(CATTopology *& oGlobalContext, CATTopology *& oLocalContext, CATTopology **& otTopo, int & oSize);
  //   TOPOparent tells que mises a jour via update depuis un operateur (ex. Tessellation)
  void GetGeometriesTOPOparent(CATTopology **& oGlobalContext, CATTopology **& oLocalContext, CATTopology ***& otTopo, int *& oSize, int & oNbParents);

  // => Implique bien trois structures sous-jacentes si on part sur ces trois interfaces
  // - Operateur => Checker => Anomalies TOPO                                                     => Enrichissement complexe via operateur (itf à définir) avec map TOPO => TOPO
  //                                  ou ICBR => Adapter => Enrichissement TOPO "simple" bijectif => Enrichissement complexe via operateur (itf à définir) avec map TOPO => TOPO
  //
  // Moralité, dans ce cas, on utilise toujours GetGeometriesOPER pour récupérer les données et créer du body d'erreur
  //
  // - Wrapping => ICBR => Anomalies ICBR => Enrichissement complexe via operateur (itf à définir) avec map POLY => TOPO
  // Là encore, on utilisera donc GetGeometriesOPER pour récupérer les données dans le but de créer du body d'erreur.
  //
  // L'itf à définir (mapping) doit fournir les infos de mapping.
  // Dans tous les cas, on doit etre sur une base ICBR ou TOPO avec un body et des cellules
  // Le mapping sera peut-etre simplement bijectif (conversion)
  // ou alors plus complexe pour cause de journaling (wrapping, autre ?)
  //
  // Le but de ce mapping est d'avoir au final une liste de bodies et pour chaque body, une structure regroupant les cellules "context" et les cellules en erreur
  //
  //                            (Body1,Context1,Cellules1)
  // (Body,Context,Cellules) => ...
  //                            (BodyN,ContextN,CellulesN)
  //
  // Que ce soit monobody (conversion) ou plus complexe (join ?) , la representation doit etre la meme
  // Un body input peut se voir associer que du context ou que des cellules : au moins une des deux données est mandatory
  // Peu importe les operandes, on créera ainsi des bodies de context et/ou de location cohérents car constitués de cellules venant d'un meme body input.
  //
  // GetGeometriesOPER(ListPOfCATTopology & olGlobalContext, CATMapOfPtrToPtr & oMapOfTopoToData)
  // Copie bit à bit de la map interne dans la map fournie ?
  // Je vois pas trpo l'intéret de s'embêter à parcourir la map interne pour insérer les couples dans la nouvelle.
  // Je veux surtout pas partager la map interne à l'extérieur : c'est risquer un ptr invalide.
  //
  // Si on suit la logique des GetGeometries, en fait on devrait avoir
  // - CATGMPolyAnomalyICBR : contient polybody + polycells
  // - CATGMPolyAnomalyTOPO : contient catbody + context et/ou catcells => on peut utiliser une struct (context,catcells) ici
  // - CATGMPolyAnomalyOPER : contient N (catbody,context,catcells) => on peut réutiliser la struct ici
  //
  // La struct doit donc être exposée pour pouvoir récupérer la map via GetGeometriesOPER et l'interpréter.
  // Les différentes sous anomalies par contre restent cachées.
  //
  // Mais si le GetGeometriesOper renvoie les struct dans une liste ou map, elles doivent être elle-m^mes copiées
  // en fait, l'anomalie ne devrait-elle pas simplement construire les bodies de context/location ?
  //
  // Je pousse l'idée au bout : à quoi sert le GMPolyErrorBuilder ? Il prend jutse une liste , boucle dessus et traite les anomalies
  // On peut aussi bien avoir une méthode statique CATGMPolyAnomaly::BuildErrors() avec les memes arguemnts que le Run de ErrorBuilder
  // et ainsi déléguer éventuellement certains traitements aux anomalies plutot que de les décortiquer.
  //
  // Mon seul soucis reste l'intersection shellshell faisable dans Operators, donc par la tessellation qui a besoin d'interroger les anomalies d'intersection,
  // récupérer les cellules et créer des bodies temporaire, mais c'est pas méchant.

public:

  static CATUnicodeString Desc2Str(Description iDesc);

  static void ReleaseList(CATListPtrCATGMPolyAnomaly & ioList);
  static void AddRefList(CATListPtrCATGMPolyAnomaly & ioList);

  void Dump(int iCounterId);
  
  // Return value : 0 if data is OK, 1 if data is KO Autochec, 2 if data is KO VoB
  int  Check(CATSoftwareConfiguration * iConfig, CATBoolean debug_mode);

  inline CATUnicodeString GetMessage();
  inline CATGMPolyAnomaly::Description GetDescription();
  inline CATGMPolyAnomaly::Type GetType();

  const char* Desc2Err();

private:

  CATGMPolyAnomalyICBR        * _ICBR;       // Créée par CATGMPolyIsCATBodyReady
  CATGMPolyAnomalyTOPO        * _TOPO;       // Créée par Completed                OU  Enrichie par Checker après ICBR
  CATGMPolyAnomalyTOPO       ** _TOPOparent; //                                        Enrichie par opérateur (Conversion, Wrapping)
  int                           _SIZEparent;

  CATGMPolyAnomaly::Type        _Type;
  CATGMPolyAnomaly::Description _Desc;
  CATUnicodeString              _Mesg;

  int _id;
};

inline CATUnicodeString CATGMPolyAnomaly::GetMessage() {
  return _Mesg; }

inline CATGMPolyAnomaly::Description CATGMPolyAnomaly::GetDescription() {
  return _Desc; }

inline CATGMPolyAnomaly::Type CATGMPolyAnomaly::GetType() {
  return _Type; }

#endif
