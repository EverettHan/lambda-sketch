//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCDSVarSweepDriverImp.h
// CDS driver implementation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 07.12.2005  Creation                                          FCX
//
// xx.04.2007 JSX : Modifications pour CGMReplay, listp de CSMark et divers
// 20 02 2009 JSX : On enregistre aussi les contraintes (on garde le HelpParam)
// 28 02 2013 NLD : Ajout _CSPlane
//                  Ajout argument iPlane a SetCSParameter()
//===================================================================

#ifndef CATCDSVarSweepDriverImp_H
#define CATCDSVarSweepDriverImp_H

#include "VarSweepDriver.h"

#include "CATCDSVarSweepDriver.h" // For Constant
#include "CATDataType.h"
#include "CATCGMStream.h"
#include "CATCollec.h"
#include "CATCGMOutput.h"

#include "CATCDSEnums.h"
#include "CATGeoFactory.h"
#include "CATSoftwareConfiguration.h"
#include "CATCDSString.h"

class CATICDSAdvanced;
class CATLaw;
class CATBody;
class CATPlane;
class CATICDSGeomConstraint;
class CATICDSGeometryLeaf;
class CATGeoFactory;
class CATCDSString;
class CATICDSEntity;
class CATICDSConstraint;
class CATICDSSketch;

//=========================================================================================
// Classe d'enregistrment des liens entre la geo et les CATICDSEntity
//=========================================================================================
class CSMark
{
public:
  CSMark();
  CSMark(CATBody * iSkin, int iMType, CATICDSGeometryLeaf * iCSGeometry,
         int iEType, CATICDSGeometryLeaf * iCSFirstExtremity, CATICDSGeometryLeaf * iCSSecondExtremity );

  CSMark(CATBody * iGuide, CATBody * iGuideSupport, int iMType, CATICDSGeometryLeaf * iCSGeometry );
  CSMark(CATBody * iPoint, int iMType, CATICDSGeometryLeaf * iCSGeometry );
  CSMark(CATBody * iPoint, int iMType, CATICDSConstraint * iCSConstraint); // JSX200109 det type contrainte
  virtual ~CSMark();

  // pour CGMreplay
  static CSMark * Read(CATCGMStream &stream,CATGeoFactory *fac,CATICDSAdvanced *solver);
  static CATBoolean Write(CSMark *CS,CATCGMStream &stream,CATICDSAdvanced *solver);
  void Dump(CATCGMOutput& os);
private:
  void Init();

  // DATA
public:
  int                   _GeoType; // 0: from shell, 1: from wire, 2: from vertex
  int                   _MType;
  CATICDSEntity       * _CSGeometry;//JSX200109 en plus des geo on sauve les contraintes, qui derivent aussi de Entity
  CATBody             * _Skin;
  int                   _EType;
  CATICDSGeometryLeaf * _CSFirstExtremity;
  CATICDSGeometryLeaf * _CSSecondExtremity;  
  CATBody             * _Guide;
  CATBody             * _GuideSupport;
  CATBody             * _Point;
  CATBoolean            _Alive;
  CATCDSString        _Name;
};

#include "CATLISTP_Clean.h"        // Clean previous method requests
#define CATLISTP_Append            // Request the methods to create
#define CATLISTP_AppendList        // Request the methods to create
#define CATLISTP_RemoveValue
#include "CATLISTP_Declare.h"      // Include macros
CATLISTP_DECLARE(CSMark);         // Declare the collection class


//================================================================================
class ExportedByVarSweepDriver CATCDSVarSweepDriverImp
{
public:
  CATCDSVarSweepDriverImp(CATBody * iSpine);
  virtual ~CATCDSVarSweepDriverImp();

  void SetLaws(CATLONG32 iNbLaws, CATLaw ** iLawTable, CATLaw * iMvFrToLawParamMapping);
  void SetFunctions(CATLONG32 iNbFunctions, void ** iFunctionTable);

  // Defines the sktech parameter (and optionnaly the sketch plane)
  void SetCSParameter(double iT, CATPlane* iPlane = NULL);

  CATBoolean IsSupported() const;
  
  void SetConstraintSolver(CATICDSAdvanced * iConstraintSolver,CATBoolean ToBeRemoved);
  void SetConstraintTable(CATICDSGeomConstraint ** iCSConstraintTable);

  void SetMarkFromShell( CATBody              * iSkin,
                         int                    iMType,
                         CATICDSGeometryLeaf  * iCSGeometry,
                         int                    iEType, 
                         CATICDSGeometryLeaf  * iCSFirstExtremity,
                         CATICDSGeometryLeaf  * iCSSecondExtremity);

  void SetMarkFromWire( CATBody             * iGuide,
                        CATBody             * iGuideSupport,
                        int                   iMType,
                        CATICDSGeometryLeaf * iCSGeometry);

  void SetMarkFromVertex( CATBody             * iPoint,
                          int                   iMType,
                          CATICDSGeometryLeaf * iCSGeometry);

  void SetProfileItems(CATLONG32 iNumberOfGeometries, CATICDSGeometryLeaf ** iCSGeometryTable, double * iStartParamTable, double * iEndParamTable);

  // Specific to CATCDSVarSweepDriverImp

  CATICDSAdvanced* GetConstraintSolver();
  double GetCSParameter();
  CATBody* GetSpine();

  void GetProfileItems( CATLONG32             & oNumberOfGeometries,
                        CATICDSGeometryLeaf **& oCSGeometryTable,
                        double               *& oStartParamTable,
                        double               *& oEndParamTable);

  void GetMarks(  CATLONG32 & oNbShellMarks , CSMark **& oShellMarkTable,
                  CATLONG32 & oNbWireMarks  , CSMark **& oWireMarkTable,
                  CATLONG32 & oNbVertexMarks, CSMark **& oVertexMarkTable,
                  CATLONG32 & oNbHelpMarks  , CSMark **& oHelpMArkTable);

  void GetLaws( CATLONG32 & oNbLaws, CATLaw **& oLawTable, CATICDSGeomConstraint **& oCSConstraintTable, CATLaw *& oMvFrToLawParamMapping);
  

  // Extract Data from links with Sketcher Black Box Implementation
  void ExtractDataFromBlackBoxes();

  // Replay
  void Read(CATGeoFactory* fac,CATCGMStream &Str);
  void Write(CATCGMStream &Str);
  void Dump(CATCGMOutput& os);
  void GetListOfGeometry(CATLISTP(CATICGMObject) &Liste);


  CATICDSSketch* GetCSSketch();
private:
  CATBoolean GetHelpParameters(CATICDSGeomConstraint * iConstraint, CATICDSGeometryLeaf *GeomUE,CATMathPoint &MP);

//=================================
//  DATA
//=================================
private:
  // Données non relues ( defénie par un Set)
  CATICDSAdvanced          * _CS;
  CATBoolean                 _Removed_CS;
  CATGeoFactory            * _Factory;
  CATSoftwareConfiguration * _Config;

  CATLONG32 _PureConstraintSolver; // True if constraint solver does not used black boxes (ie no underlying Sktecher Data)
                                   // Alway to TRUE when laoded from a CGMReplay (Sktecher Data are not streamed)
                                   // Before storing data for Replay, All links to sketcher have to be removed/replaced
                                   // => The same for interpolation 

  CATBoolean _CS_Given ; // The solver has been transmitted to another software. Related data (irMArks) may be invalid

  // 
  // Description dans l'odre du CGMReplay
  CATBody * _SmoothedSpine;

  // Profile data
  CATLONG32 _NbProfileGeometries;
  CATICDSGeometryLeaf ** _ProfileGeometryTable;
  double * _StartParamTable;
  double * _EndParamTable;

  // Les Marks (Pour les UsedEdges)
  CATLISTP(CSMark) _ShellMarks;
  CATLISTP(CSMark) _WireMarks;
  CATLISTP(CSMark) _VertexMarks;
  CATLISTP(CSMark) _HelpParamMarks;

  // Parametre initial correspondant au profil fourni. (est aussi stocké dans le ReplayCDS)
  double    _CSParameter;
  CATPlane* _CSPlane;

  // Loi
  CATLaw   * _MvFrToLawParamMapping; // Loi provenant de la relimitation de la spine et du smoothing
  CATLaw   * _MvFrToLawParamMappingStream;
  CATLONG32  _NbLaws;
  CATBoolean _TableToBeRemoved ;
  CATBoolean _StreamLawcomputed;
  CATICDSGeomConstraint ** _CSConstraintTableLaws;
  CATLaw  ** _LawTable;
  CATLaw  ** _LawTableStream;

  // Function ? pas tres clair pour le moment
  CATLONG32 _NbFunctions;
  void **   _FunctionTable;

  CATBoolean _ExtractDataFromBlackBoxes_Done;
};

//
// Fonctions globales pour simplifier les IOs
//
  ExportedByVarSweepDriver void WriteCDSName(CATCGMStream &Str,CATCDSString *CSName, CATLONG32 &NameLength );
  ExportedByVarSweepDriver void  ReadCDSName(CATCGMStream &Str,CATCDSString &CSName, CATLONG32 &NameLength );
  ExportedByVarSweepDriver CATICDSEntity * GetCDSGeoLeafFromName(CATICDSAdvanced *CDSgeo, CATCDSType iType,CATCDSString *LeafName);//CATICDSGeometryLeaf *&oLeaf);
  ExportedByVarSweepDriver void  WriteEntity(CATCGMStream &Str,CATICDSEntity *entity);

#endif
