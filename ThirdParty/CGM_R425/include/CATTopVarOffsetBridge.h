/* -*-C++-*- */

#ifndef CATTopVarOffsetBridge_H
#define CATTopVarOffsetBridge_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// Class and functions are @nodoc and will soon be destroyed : Do not use

//=============================================================================
//=============================================================================
//
// CATTopVarOffsetBridge : Pile "Topo" du Pont logiciel
//                             permettant l'utilisation du VarOffset
//                             dans le fw Topo.
//
// Classe abstraite qui permet d'appeler les fonctions de VarOffset
// via le pont
// + definition de la fonction de chargement dynamique de la librairie
//
//=============================================================================

//=============================================================================
// Nov  2003  Creation                                        L. Marini
// June 2004  Add methode SetBase                             L. Marini
//=============================================================================
//=============================================================================

// Pour le ExportBy
#include "Thick.h"

// Includes 
#include "CATCGMVirtual.h"
#include "CATMathDef.h"
#include "ListPOfCATBody.h"
#include "CATListOfDouble.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATEdge.h"
#include "CATLISTV_CATMathLine.h"


//--------------------------------------------------------------------
// Signature CallBack de Nettoyage
//--------------------------------------------------------------------
class CATTopVarOffsetBridge;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATMathPoint;
class CATSpaceDeformationMapDefine;
class CATTopOperator;


typedef CATTopVarOffsetBridge*  (*CATTopVarOffsetCreator)  
       (CATGeoFactory *iFactory, CATTopData *iTopData, CATBody * iSkin,
															              const ListPOfCATBody& iWires,
															              const CATListOfDouble& iOffsetLaw);


class ExportedByThick CATTopVarOffsetBridge : public CATCGMVirtual
{

public :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Creation d'un objet cree comme un CATSurfTopVarOffsetBridge 
  //                     & vu comme un CATTopVarOffsetBridge 
  //------------------------------------------------------------------------------
  static CATTopVarOffsetBridge * Create(CATGeoFactory     *iFactory, 
                                            CATTopData        *iTopData,  
                                            CATBody * iSkin,
															              const ListPOfCATBody& iWires,
															              const CATListOfDouble& iOffsetLaw);
  //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATTopVarOffsetBridge() {};

  //-------------------------------------------------------------
  // Method for warning via CATTopOperator
  //-------------------------------------------------------------
  virtual CATTopOperator * GetTopOperator()=0;

  //-------------------------------------------------------------
  // RUN Method
  //------------------------------------------------------------- 
  virtual int Run()=0;
  //-------------------------------------------------------------
  // SET Methods pour piloter le VarOffset
  //------------------------------------------------------------- 
	virtual	int AddConstraintOnLaw(CATBody * iWire, double iFirstVal, double iLastVal)=0;

  virtual int AddConstraintOnLaw(CATBody * iWire, double iFirstVal, double iLastVal,
												 CATLISTV(CATMathLine)& intermediatePointsAndDir,
												 CATListOfDouble& intermediateValues)=0;

  /**
	@nodoc
	*/
	virtual int SetMandatoryFacesToRemove(ListPOfCATFace & iFacesToRemove)=0;


	/**
	 * @nodoc
	 * default value is FALSE
	 * 
	 */
	virtual CATLONG32 CorrectAll(const CATBoolean iYesOrNo)=0;

  /**
	 * @nodoc
	 */
	virtual int SetBase(CATBody * iBase)=0;
  virtual int SetListOfConstFaces(ListPOfCATFace& ioListOfFace)=0;

  //-------------------------------------------------------------
	//SET Methods pour piloter le VarOffset
	//------------------------------------------------------------- 
	virtual int AddMediumCurve(CATBody * iWire, double iMediumVal)=0;
	

  //-------------------------------------------------------------
  //GET Methods
  //------------------------------------------------------------- 
  virtual CATBody * GetResult() const = 0;

  //Getting the max error between real and result offset
  //virtual double GetMaxDeviation() const =0;

	virtual int GetMinMaxInputOffset (double& oMinOffset, double& oMaxOffset) const =0;

  /**
   * Retrieves the G0 continuity diagnosis for a given edge.
   * The edges have to belong to one of the deformed faces.
   * @param iE
   * The pointer to the edge to test.
   * @param ioG0Error
   * The value of the maximum G0 deviation along the edge.
	 * @param isAfterOffset
	 * To have error on the offset result or on the initial body
   * @return
   * -1 if the edge has not been impacted by the deformation
   */
   virtual int G0MaxError(CATEdge * iE , double &ioG0Error, const CATBoolean isAfterOffset = TRUE) const = 0;

  /**
   * Retrieves the G1 continuity diagnosis for a given edge.
   * The edges have to belong to one of the deformed faces.
   * @param iE
   * The pointer to the edge to test.
   * @param ioG0Error
   * The value of the maximum G0 deviation along the edge.
	 * @param isAfterOffset
	 * To have error on the offset result or on the initial body
   * @return
   * -1 if the edge has not been impacted by the deformation
   */
   virtual int G1MaxError(CATEdge * iE , double &ioG1Error, const CATBoolean isAfterOffset = TRUE) const = 0; 


	/**
	 * This method can be called  after the deformation
	 * It returns the list of the edges with remaining G0 
	 * continuity default relativly to the tolerance.
	 * @param ioListOfEdges
	 * The list of the pointers to the Edges that have been oppened by the operator.
	 * @return
	**/
	virtual int GetOpenEdges(ListPOfCATEdge & ioListOfEdges)=0;

	/**
	 * This method after deformation
	 * It returns the list of the "G1-edges" with remaining G1 
	 * continuity default relativly to the tolerance.
	 * The "G1-edges" are the wiche are G1 before the deformation and must 
	 * keep this continuity relatively to the MapDefine.
	 * @param ioListOfEdges
	 * The list of the pointers to the Edges that have not been corrected.
	 * @return
	**/
	virtual int GetSharpEdges(ListPOfCATEdge & ioListOfEdges)=0;


  /** nodoc
	*/
	virtual void GetTrickyFaces(ListPOfCATFace & oTrickyFaces) const=0; 


	/**
	* This method can be call before the run.
	* It detect if exist a high variation of 
	* @param oRatio
	* it contain the maximum variation detected ie | Offset2- Offset1 | / Dist(Object1, Object2)
	* @param oPnts
	* it contain two points, oPnts[0], oPnts[1] wich localize the the maximum variation.
	* @return
   * TRUE  if nothing is detected
	 * FALSE if HighVariation is detected.
	*/
	virtual CATBoolean CheckHighVariation(double* oMaxRatio=NULL,  
																				CATMathPoint* oP1=NULL,
																				CATMathPoint*oP2=NULL) const=0;

	/**
	*  Retrives the Map wich is used, this methode, it is usful for offset 's simulation
	*  @return a pointer to the SpaceDeformationMapDefine .
	*/
	virtual CATSpaceDeformationMapDefine * GetDefine()=0;

  /**
	 * @nodoc
   * Methode for proto
	 */
	virtual int SetG1Mode (const CATBoolean isG1Mode)=0; 


private:
//===========================================================================================================

};

#endif

