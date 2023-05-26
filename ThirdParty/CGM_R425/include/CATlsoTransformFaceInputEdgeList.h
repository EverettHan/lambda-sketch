/* -*-C++-*- */

#ifndef CATlsoTransformFaceInputEdgeList_H
#define CATlsoTransformFaceInputEdgeList_H

#include "AdvTrimOpe.h"
#include "CATlsoTransformFaceInputCellList.h"

// Includes des listes d'objets
#include "ListPOfCATEdge.h"
#include "CATTopDefine.h"
#include "CATMathInline.h"
#include "ListPOfCATPersistentEdges.h"
#include "ListPOfCATCell.h"

class CATEdge;
class CATlsoTransformFaceContext;
class CATEdgeCurve;
class CATMathTransformation;
class CATCrvLimits;
class CATBody;
class CATlsoDynMetaData;
class CATCellHashTable;
class CATlsoPersistentContext;

#define InputEdgeListType                      CATlsoTransformFaceInputEdgeList::InputType
#define InputEdgeListTransformationType        CATlsoTransformFaceInputEdgeList::TRANSFORMATION
#define InputEdgeListEdgeCurveType             CATlsoTransformFaceInputEdgeList::EDGECURVE
#define InputEdgeListCanonicalType             CATlsoTransformFaceInputEdgeList::CANONICAL
#define InputEdgeListIsoParametricType         CATlsoTransformFaceInputEdgeList::ISOPARAMETRIC

class ExportedByAdvTrimOpe CATlsoTransformFaceInputEdgeList : public CATlsoTransformFaceInputCellList
{

public:

  // ------------------
  // ConfigurationType
  // ------------------
  enum InputType { UNKNOWN=0,
                   TRANSFORMATION,
                   EDGECURVE,
                   CANONICAL,
                   ISOPARAMETRIC};

  // Constructor for CATlsoTransformFaceContext
  CATlsoTransformFaceInputEdgeList(const ListPOfCATEdge        & iInputEdgeList,
                                   const CATMathTransformation & iMathTransformation,
                                   CATlsoTransformFaceContext  * iContext);

  CATlsoTransformFaceInputEdgeList(const ListPOfCATEdge        & iInputEdgeList,
                                   CATEdgeCurve                & iEdgeCurve,
                                   CATCrvLimits                * iWorkingDomain,
                                   CATOrientation                iOrientation,
                                   CATlsoTransformFaceContext  * iContext);

  CATlsoTransformFaceInputEdgeList(const ListPOfCATEdge        & iInputEdgeList,
                                   InputEdgeListType             iType,
                                   CATlsoPersistentContext    * iContext,
                                   CATlsoChainMaster           * iAdmin);

  // Constructor for CATlsoVariationalTransformCellContext
  CATlsoTransformFaceInputEdgeList(const ListPOfCATEdge        & iInputEdgeList,
                                   const CATMathTransformation & iMathTransformation,
                                   CATlsoPersistentContext     * iContext,
                                   CATlsoChainMaster           * iAdmin);

  CATlsoTransformFaceInputEdgeList(const ListPOfCATEdge        & iInputEdgeList,
                                   CATEdgeCurve                & iEdgeCurve,
                                   CATCrvLimits                * iWorkingDomain,
                                   CATOrientation                iOrientation,
                                   CATlsoPersistentContext     * iContext,
                                   CATlsoChainMaster           * iAdmin);

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  // Destructeur
  ~CATlsoTransformFaceInputEdgeList();

  // -------------
  // Run Methodes
  // -------------
  void       CreatePersistentEdges();

  CATBoolean SomeBorderEdgesOrOnWire();

  void       RemoveEdgeList(const ListPOfCATEdge &iEdgeList);

  // -------------
  // Get Methodes
  // -------------
  INLINE    InputEdgeListType GetType() const;
  void      GetInputEdgeList(ListPOfCATEdge & oInputEdgeList) const;
  void      GetInputPersistentEdgeList(ListPOfCATPersistentEdges & oInputPersistentEdgeList, CATListOfInt *oMandatoryStatus=NULL) const;
  void      SetInputEdgeList(const ListPOfCATEdge & iInputEdgeList);
  void      GetEdgeCurve(CATEdgeCurve *& oEdgeCurve,CATCrvLimits *& oCrvLimits,CATOrientation & oECOrientation) const;
            // return index of tab where inputEdges were found
  int       LocateInputEdgeInHashTable(CATCellHashTable **iTabOfCellHTable /*tableau*/, const int &iTabSize) const;
  const CATMathTransformation & GetTransformation() const;

  // --------
  // Dump
  // --------
  void DumpObj(CATCGMOutput& s, short iLongDump=0, short iZtrNoDump=0) const;

  // -----------------
  // Static Methodes
  // ------------------
   // Balayage de tous les objets de la classe
  INLINE static CATlsoTransformFaceInputEdgeList * Next(CATlsoChainMaster * iAdmin, 
                                        CATlsoTransformFaceInputEdgeList* iCur);

  // RecordInputParameters
  static void RecordInputParameters(const ListPOfCATEdge        & iInputEdgeList,
                                    const CATMathTransformation & iMathTransformation,
                                    const CATlsoRevolPrismData  & iRevolPrismData, 
                                    CATlsoPersistentContext     & iContext,
                                    CATPersistentBody           * iUpToPersistentBody=NULL,
                                    CATlsoChainMaster           * iAdmin=NULL);

  // RecordInputParameters
  static void RecordInputParameters(const ListPOfCATEdge       & iInputEdgeList,
                                    CATEdgeCurve               & iEdgeCurve,
                                    CATCrvLimits               * iWorkingDomain,
                                    CATOrientation               iOrientation,
                                    CATlsoPersistentContext    & iContext,
                                    CATlsoChainMaster          * iAdmin=NULL);

  // RecordInputParametersSpecificType
  static void RecordInputParametersSpecificType(ListPOfCATEdge          & iInputEdgeList,
                                             InputEdgeListType            iType,
                                             CATlsoPersistentContext    & iContext,
                                             CATlsoChainMaster          * iAdmin=NULL);

  // RecordOneInput
  static void RecordOneInput(CATEdge                        & iEdge,
                      const CATMathTransformation           & iMathTransformation,
                      const CATlsoRevolPrismData            & iRevolPrismData,
                      CATBody                               * iInputBody,
                      CATlsoPersistentContext               & iContext,
                      CATlsoChainMaster                     * iAdmin=NULL,                      
                      CATPersistentBody                     * iUpToPersistentBody=NULL,
                      CATlsoDynMetaData                     * iVarAdditionalInputData=NULL);

  // RecordAdditionalData
  static int RecordAdditionalData(ListPOfCATEdge & iInputEdgeList, CATlsoTransformFaceContext & iContext, CATlsoDynMetaData & iOptionalData);

  // GetAllInputEdgeList
  static void GetAllInputEdgeList(ListPOfCATEdge              & oInputEdgeList,
                                  CATlsoTransformFaceContext  & iContext);


  static CATBoolean AreSomeCanonicalType(CATlsoTransformFaceContext  & iContext,
                                         ListPOfCATEdge              & oInputCanoEdgeList);

protected:
  // HasSameList
  CATBoolean HasSameList(const ListPOfCATEdge & iInputEdgeList) const;
   // IncludedInList
  CATBoolean IncludedInList(const ListPOfCATEdge & iInputEdgeList) const;
  // SetTransformation
  void SetTransformation(const CATMathTransformation & iMathTransformation);

  virtual void GetInputCellList(ListPOfCATCell & oInputCellList) const;
  virtual void RemoveElementAt(int position);
  virtual void CleanPersistentCells();
  virtual void CreatePersistentCells();

private: 

  // Copy-constructeur et affectation (ne compilera pas)
  CATlsoTransformFaceInputEdgeList(CATlsoTransformFaceInputEdgeList& iOrig);
  CATlsoTransformFaceInputEdgeList& operator= (const CATlsoTransformFaceInputEdgeList& iRight);

  // -------------------
  // Internal Methodes
  // -------------------
  void SetInputEdges(const ListPOfCATEdge & iInputEdgeList, CATListOfInt *iMandatoryStatus=NULL);

  // CleanAfterRun
  void CleanAfterRun();

  // AddEdgeToList
  void AddEdgeToList(CATEdge & iEdge, int &iMandatoryStatus);


  // SetCATEdgeCurve
  void SetCATEdgeCurve(CATEdgeCurve & iEdgeCurve);


  // ---------------
  // Internal Data
  // ---------------
  ListPOfCATEdge             _InputEdgeList;
  CATEdgeCurve             * _EdgeCurve;
  InputEdgeListType          _Type;
  CATCrvLimits             * _CrvLimits;
  CATOrientation             _ECOrientation;

  ListPOfCATPersistentEdges  _InputPersistentEdgeList;
};

//----------------------------------------------------------------------------
// Implementations INLINE
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Next
//----------------------------------------------------------------------------
INLINE CATlsoTransformFaceInputEdgeList * CATlsoTransformFaceInputEdgeList::Next(CATlsoChainMaster * iAdmin,
                                                CATlsoTransformFaceInputEdgeList * iCur) {
  return (CATlsoTransformFaceInputEdgeList*) CATlsoAlgoElt::NextElt(iAdmin, iCur); }


//----------------------------------------------------------------------------
// Type Methodes
//----------------------------------------------------------------------------

INLINE InputEdgeListType CATlsoTransformFaceInputEdgeList::GetType() const {
  return _Type; }

#endif

