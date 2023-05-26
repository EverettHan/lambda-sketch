/* -*-C++-*- */

#ifndef CATlsoTransformFaceInputVertexList_H
#define CATlsoTransformFaceInputVertexList_H

#include "AdvTrimOpe.h"
#include "CATlsoTransformFaceInputCellList.h"
#include "CATMathInline.h"

// Includes des listes d'objets
#include "ListPOfCATVertex.h"
#include "ListPOfCATPersistentVertices.h"

class CATVertex;
class CATlsoPersistentContext;
class CATlsoTransformFaceContext;
class CATMathPoint;
class CATMathTransformation;
class CATBody;
class CATlsoDynMetaData;
class CATCellHashTable;
class CATlsoRevolPrismData;

#define InputVertexListType                      CATlsoTransformFaceInputVertexList::InputType
#define InputVertexListTransformationType        CATlsoTransformFaceInputVertexList::TRANSFORMATION
#define InputVertexListMathPointType             CATlsoTransformFaceInputVertexList::MATHPOINT

class ExportedByAdvTrimOpe CATlsoTransformFaceInputVertexList : public CATlsoTransformFaceInputCellList
{

public:

  // Constructor for CATlsoTransformFaceContext
  CATlsoTransformFaceInputVertexList(const ListPOfCATVertex    & iInputVertexList,
                                   const CATMathTransformation & iMathTransformation,
                                   CATlsoTransformFaceContext  * iContext);

  CATlsoTransformFaceInputVertexList(const ListPOfCATVertex    & iInputVertexList,
                                   CATMathPoint                & iMathPoint,
                                   CATlsoTransformFaceContext  * iContext);

  // Constructor for CATlsoVariationalTransformCellContext
  CATlsoTransformFaceInputVertexList(const ListPOfCATVertex          & iInputVertexList,
                                   const CATMathTransformation & iMathTransformation,
                                   CATlsoPersistentContext     * iContext,
                                   CATlsoChainMaster           * iAdmin);

  CATlsoTransformFaceInputVertexList(const ListPOfCATVertex    & iInputVertexList,
                                   CATMathPoint                & iMathPoint,
                                   CATlsoPersistentContext     * iContext,
                                   CATlsoChainMaster           * iAdmin);

  // ------------------
  // ConfigurationType
  // ------------------
  enum InputType { UNKNOWN=0,
                   TRANSFORMATION,
                   MATHPOINT};

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  // Destructeur
  ~CATlsoTransformFaceInputVertexList();

  // -------------
  // Run Methodes
  // -------------
  void CreatePersistentVertices();

  CATBoolean SomeBorderVerticesOrOnWire();

  // -------------
  // Get Methodes
  // -------------
  INLINE    InputVertexListType GetType() const;
  void      GetInputVertexList(ListPOfCATVertex & oInputVertexList) const;
  void      GetInputPersistentVertexList(ListPOfCATPersistentVertices & oInputPersistentVertexList, CATListOfInt *oMandatoryStatus=NULL);
  void      SetInputVertexList(const ListPOfCATVertex & iInputVertexList);
            // return index of tab where inputVertices were found
  int       LocateInputVertexInHashTable(CATCellHashTable **iTabOfCellHTable /*tableau*/, const int &iTabSize) const;
  CATMathPoint                * GetMathPoint() const;
  const CATMathTransformation & GetTransformation() const;

  // --------
  // Dump
  // --------
  void DumpObj(CATCGMOutput& s, short iLongDump=0, short iZtrNoDump=0) const;

  // -----------------
  // Static Methodes
  // ------------------
  // Balayage de tous les objets de la classe
  INLINE static CATlsoTransformFaceInputVertexList * Next(CATlsoChainMaster * iAdmin, 
                                        CATlsoTransformFaceInputVertexList* iCur);

  // RecordInputParameters
  static void RecordInputParameters(const ListPOfCATVertex      & iInputVertexList,
                                    const CATMathTransformation & iMathTransformation,
                                    const CATlsoRevolPrismData  & iRevolPrismData,                                   
                                    CATlsoPersistentContext     & iContext,
                                    CATPersistentBody           * iUpToPersistentBody=NULL,
                                    CATlsoChainMaster           * iAdmin=NULL);

  // RecordInputParameters
  static void RecordInputParameters(const ListPOfCATVertex           & iInputVertexList,
                                    CATMathPoint               & iMathPoint,
                                    CATlsoPersistentContext    & iContext,
                                    CATlsoChainMaster          * iAdmin=NULL);

  // RecordOneInput
  static void RecordOneInput(CATVertex            & iVertex,
                      const CATMathTransformation & iMathTransformation,
                      const CATlsoRevolPrismData  & iRevolPrismData,
                      CATBody                     * iInputBody,
                      CATlsoPersistentContext     & iContext,
                      CATlsoChainMaster           * iAdmin=NULL,
                      CATPersistentBody           * iUpToPersistentBody=NULL,
                      CATlsoDynMetaData           * iVarAdditionalInputData=NULL);

  // RecordAdditionalData
  static int RecordAdditionalData(ListPOfCATVertex & iInputVertexList, CATlsoTransformFaceContext & iContext, CATlsoDynMetaData & iOptionalData);

  // GetAllInputVertexList
  static void GetAllInputVertexList(ListPOfCATVertex            & oInputVertexList,
                                    CATlsoTransformFaceContext  & iContext);

protected :

  virtual void GetInputCellList(ListPOfCATCell & oInputCellList) const;
  virtual void RemoveElementAt(int position);
  virtual void CleanPersistentCells();
  virtual void CreatePersistentCells();

private: 

  // Copy-constructeur et affectation (ne compilera pas)
  CATlsoTransformFaceInputVertexList(CATlsoTransformFaceInputVertexList& iOrig);
  CATlsoTransformFaceInputVertexList& operator= (const CATlsoTransformFaceInputVertexList& iRight);

  // -------------------
  // Internal Methodes
  // -------------------
  // Set Input Vertex
  void SetInputVertices(const ListPOfCATVertex & iInputVertexList, CATListOfInt *iMandatoryStatus=NULL);

  // SetTransformation
  void SetTransformation(const CATMathTransformation & iMathTransformation);

  // CleanAfterRun
  void CleanAfterRun();

  // HasSameList
  CATBoolean HasSameList(const ListPOfCATVertex & iInputVertexList) const;

  // AddVertexToList
  void AddVertexToList(CATVertex & iVertex, int &iMandatoryStatus);


  // SetCATMathPoint
  void SetCATMathPoint(CATMathPoint & iMathPoint);


  // ---------------
  // Internal Data
  // ---------------
  ListPOfCATVertex           _InputVertexList;
  CATMathPoint             * _MathPoint;
  InputVertexListType        _Type;

  ListPOfCATPersistentVertices  _InputPersistentVertexList;
};

//----------------------------------------------------------------------------
// Implementations INLINE
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Next
//----------------------------------------------------------------------------
INLINE CATlsoTransformFaceInputVertexList * CATlsoTransformFaceInputVertexList::Next(CATlsoChainMaster * iAdmin,
                                                CATlsoTransformFaceInputVertexList * iCur) {
  return (CATlsoTransformFaceInputVertexList*) CATlsoAlgoElt::NextElt(iAdmin, iCur); }


//----------------------------------------------------------------------------
// Type Methodes
//----------------------------------------------------------------------------

INLINE InputVertexListType CATlsoTransformFaceInputVertexList::GetType() const {
  return _Type; }

#endif

