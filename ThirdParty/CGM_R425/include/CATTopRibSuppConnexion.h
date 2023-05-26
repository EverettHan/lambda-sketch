/* -*-C++-*- */

#ifndef CATTopRibSuppConnexion_H
#define CATTopRibSuppConnexion_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibSuppConnexion
// Definit la connexion "objectif" entre deux supports, i.e l'endroit 
// (topologique et geometrique) ou les traces sur les supports doivent
// se raccorder pour maintenir l'etancheite du B-Rep. 
// Le racoord etudie ici concerne la fin de la trace du support de 
// gauche (dans le sens de progression du ruban) et le debut de celle
// sur le support de droite.
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"
#include "CATTopRibDef.h"
#include "CATMathDef.h"   
#include "CATTopRibSupport.h"
#include "CATXParam.h"
#include "CATCGMNewArray.h" // Pool allocation

class CATGeometry;
class CATCell;
class CATVertex;
class CATCrvParam;
class CATSurParam;

#include "CATSafe.h"
CATSafeDefine(CATTopRibSuppConnexion);

class ExportedByRIBLight CATTopRibSuppConnexion   : public CATTopRibObject
{
 private:
  CATCell            * _CommonCell;     // Cellule commune 
  CATGeometry        * _CommonGeometry; // Geometrie commune qd une cell commune n'est pas cree (connexion relimitation)
//  CATXParam            _TargetParm;     // Parametre objectif sur la cellule comune 
  CATOrientation       _OrientationCommonCellVsGeometry; // orientation Cell/Geo commune

 public: // a rendre privees 
  CATVertex          * _TargetVertex;   // Vertex objectif
  CATTopRibSupport   * _Support[2];     // Supports sur les deux nuplets separes par la connexion
  CATTopRibConnexion   _TypeDef[3];     // Type de deformation: geometrique ou geo+topo
  double               _Gap[4];         // Trou entre les traces 

  //-----------------------------------------------------------------
  // Donnees pour l'hermetisation
  //-----------------------------------------------------------------
  CATBoolean               _HermetisationNeeded[2];
  CATCrvParam            * _ParamHermOnTrack [2];

  //-----------------------------------------------------------------
  // Is a deformation needed ?
  //-----------------------------------------------------------------
  CATBoolean               _DefNeeded[2];
  CATCrvParam            * _ParamOnTrack [2];
  CATCrvParam            * _ParamOnEC [2];
  CATSurParam            * _TargetParam [2];
  CATBoolean               _HealingNeeded;

 public:
  //-----------------------------------------------------------------
  // Read the common cell
  //-----------------------------------------------------------------
  CATCell *GetCommonCell() const;
  CATGeometry* GetCommonGeometry(CATOrientation *iOrientationCommonCellVsGeometry = NULL) const;

  void SetDataForDeformationStart(CATCrvParam &iParamOnTrack,CATSurParam &iTargetParam,CATCrvParam * iParamOnEC=0);
  void SetDataForDeformationEnd(CATCrvParam &iParamOnTrack,CATSurParam &iTargetParam,CATCrvParam * iParamOnEC=0);

  void RemoveDataForDeformationStart();
  void RemoveDataForDeformationEnd();

  //-----------------------------------------------------------------
  // Methodes pour l'hermetisation
  //-----------------------------------------------------------------
  void SetDataForHermetisationStart(const CATCrvParam &iParamHermOnTrack);
  void SetDataForHermetisationEnd(const CATCrvParam &iParamHermOnTrack);

  //-----------------------------------------------------------------
  // Constructor
  //-----------------------------------------------------------------
  CATTopRibSuppConnexion( CATCell* iCommonCell=NULL, 
                          CATVertex* iTargetVertex=NULL);
  CATTopRibSuppConnexion( CATGeometry* iCommonGeometry, 
                          CATOrientation iOrient,
                          CATTopRibSupport * iSupport[2]);

  CATCGMNewClassArrayDeclare; // Pool allocation

  /*
  CATTopRibSuppConnexion(const CATTopRibSuppConnexion * iToCopy);
  */

  //-----------------------------------------------------------------
  // Destructor
  //-----------------------------------------------------------------
  ~CATTopRibSuppConnexion();

  //-----------------------------------------------------------------
  // Reading methods 
  //-----------------------------------------------------------------
  CATBoolean HasDefGeo();
  
  void GetSupports(CATTopRibSupport *oSupport[2]);

  //-----------------------------------------------------------------
  // Set the common cell
  //-----------------------------------------------------------------
  void SetCommonCell(CATCell *iCommonCell);

  //-----------------------------------------------------------------
  // Unset the common cell
  //-----------------------------------------------------------------
  void UnsetCommonCell();
};

#endif
