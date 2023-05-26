/* -*-C++-*- */

#ifndef CATlsoTransformFaceInputCellList_H
#define CATlsoTransformFaceInputCellList_H

#include "AdvTrimOpe.h"
#include "CATlsoTransformFaceAlgoElt.h"
#include "CATMathInline.h"
#include "CATBoolean.h"
#include "CATMathTransformation.h"
#include "ListPOfCATBody.h"
#include "CATListOfInt.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATCell.h"
#include "CATlsoRevolPrismData.h"


class CATlsoChainMaster;
class CATlsoTransformFaceConnectedInputCells;
class CATlsoContext;
class CATlsoTransformFaceInputFaceList;
class CATlsoTransformFaceInputEdgeList;
class CATlsoTransformFaceInputVertexList;
class CATPersistentBody;


// Input Type
#define CellOriginType   CATlsoTransformFaceInputCellList::OriginType
#define FromInputType    CATlsoTransformFaceInputCellList::INPUT
#define FromMirrorType   CATlsoTransformFaceInputCellList::MIRROR
#define FromPatternType  CATlsoTransformFaceInputCellList::PATTERN_ISO
#define FromOffsetType   CATlsoTransformFaceInputCellList::OFFSET_ISO

class ExportedByAdvTrimOpe CATlsoTransformFaceInputCellList : public CATlsoTransformFaceAlgoElt
{

public:

  // Constructor for CATlsoTransformFaceContext
  CATlsoTransformFaceInputCellList(CATlsoPersistentContext * iContext,
                                   CATlsoChainMaster * iAdmin);

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  // Destructeur
  virtual ~CATlsoTransformFaceInputCellList();

  // ------------------
  // ConfigurationType
  // ------------------
  enum OriginType { INPUT=0,
                    MIRROR,
                    PATTERN_ISO,
                    OFFSET_ISO
  };

  INLINE void SetInputBody(CATBody * iInputBody);
  INLINE void SetUpdatedParameter(CATBoolean iUpdateParam);
  void SetConnectedInputWithCheck(CATlsoTransformFaceConnectedInputCells * iConnectedInput);
  void RemoveConnectedInput();
  
  // -------------
  // Get Methodes
  // -------------
  INLINE  CATBoolean                    GetUpdatedParameter() const;
  INLINE  const CATMathTransformation & GetTransfo() const;
  virtual const CATMathTransformation & GetTransformation() const=0;
  INLINE  CATlsoTransformFaceConnectedInputCells * GetConnectedInput() const;
  INLINE  CATBody * GetInputBody() const;
  INLINE CellOriginType GetOriginType();
  INLINE void SetOriginType(CellOriginType iOriginType);
  INLINE const CATListOfInt & GetMandatoryStatus() const;
  INLINE void GetMandatoryStatus(CATListOfInt &oMandatoryStatus) const;
  INLINE CATPersistentBody * GetUpToPersistentBody() const;
  INLINE void SetUpToPersistentBody(CATPersistentBody * iUpToPBody);
  INLINE void SetRevolPrismData(const CATlsoRevolPrismData &iRevolPrismData);
  INLINE CATGMLiveShapeRevolPrismMode GetRevolPrismMode() const;
  INLINE CATAngle                     GetRevolModeAngle() const;
  INLINE const CATlsoRevolPrismData & GetRevolPrismData() const;

  virtual CATlsoTransformFaceInputFaceList * GetAsInputFaceList() const { return NULL; }
  virtual CATlsoTransformFaceInputFaceList * GetAsInputEdgeList() const { return NULL; }
  virtual CATlsoTransformFaceInputFaceList * GetAsInputVertexList() const { return NULL; }

  INLINE void CleanConnectedInput ();

  // --------
  // Dump
  // --------
  void DumpTransfo(CATCGMOutput& s) const;
  void DumpObj(CATCGMOutput& s, short iLongDump=0, short iZtrNoDump=0) const;

  // -----------------
  // Static Methodes
  // ------------------

  // AllParametersUpdated
  static CATBoolean AllParametersUpdated(CATlsoContext & iContext, CATlsoChainMaster * iAdmin);
  static void SetAllTransfoToIdentity(CATlsoContext & iContext, CATlsoChainMaster * iAdmin);

  static void SetOneTransfoToIdentity(CATlsoContext & iContext, CATlsoTransformFaceInputCellList * iTransformFaceInputCellList, CATlsoChainMaster * iAdmin);

  static void AddInputBodies(CATlsoContext     & iContext,
                             CATlsoChainMaster * iAdmin,
                             ListPOfCATBody    & ioInputBodyList);

  // CleanInputParametersAfterRun
  static void CleanInputParametersAfterRun(CATlsoContext & iContext, CATlsoChainMaster * iAdmin);

  // Balayage de tous les objets de la classe
  static CATlsoTransformFaceInputCellList * Next(CATlsoChainMaster * iAdmin, 
                                        CATlsoTransformFaceInputCellList* iCur);

protected:

  static void  ManageInputParametersToRecord (const CATlsoContext & iContext,
                                              CATlsoChainMaster * iAdmin, 
                                              const CATMathTransformation & iMathTransformation, 
                                              CATPersistentBody           * ipUpToPersistentBody,
                                              const ListPOfCATCell &iInputCellList, 
                                              ListPOfCATCell &oCellListToRecord);

  virtual void GetInputCellList(ListPOfCATCell & oInputCellList) const = 0;
  virtual void RemoveElementAt(int position);
  virtual void CleanPersistentCells();
  virtual void CreatePersistentCells();

  // Manage with inputcellList. Check, Replace or Add new InputCells. Also Manage MandatoryStatus and PersistentCell
  int         InsertAndReorganize(const ListPOfCATCell &iInputCellList, ListPOfCATCell &oCellListToAppend);

  INLINE void SetTransfo(const CATMathTransformation & iMathTransformation);
  INLINE void SetConnectedInput(CATlsoTransformFaceConnectedInputCells * iConnectedInput);

  INLINE CATListOfInt & GetMandatoryStatus_Protected();

  // CleanAfterRun
  virtual void CleanAfterRun()=0;

  // HasSameTransfo
  CATBoolean HasSameTransfo(const CATMathTransformation & iMathTransformation) const;

  // HasSameInputBody
  CATBoolean HasSameInputBody(CATBody * iInputBody) const;

  void AddMandatoryStatusToList (int &iMandatoryStatus) ;
  void SetListOfMandatoryStatus (CATListOfInt &iListOfMandatoryStatus);

private: 

  // Copy-constructeur et affectation (ne compilera pas)
  CATlsoTransformFaceInputCellList(const CATlsoTransformFaceInputCellList& iOrig);
  CATlsoTransformFaceInputCellList& operator= (const CATlsoTransformFaceInputCellList& iRight);

  // -------------------
  // Internal Methodes
  // -------------------

  // SetTransformation
  virtual void SetTransformation(const CATMathTransformation & iMathTransformation)=0;

  // ---------------------------------
  // Input Internal Data for Stream
  // ---------------------------------
  CATMathTransformation                    _Transformation;
  CATPersistentBody                     *  _UpToPersistentBody;
  CATlsoRevolPrismData                     _RevolPrismData;

  // ---------------
  // Internal Data
  // ---------------
  CATBoolean                               _UpdatedParameter;
  CATlsoTransformFaceConnectedInputCells * _ConnectedInput;
  CATBody                                * _InputBody;
  CellOriginType                           _OriginType;
  //
  CATListOfInt                             _ListOfMandatoryStatus; // !! Parallel to ListOfPersistentCell !!
};


//----------------------------------------------------------------------------
// Implementations INLINE
//----------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceInputCellList::GetUpdatedParameter() const {
  return _UpdatedParameter; }

INLINE void CATlsoTransformFaceInputCellList::SetUpdatedParameter(CATBoolean iUpdateParam) {
  _UpdatedParameter = iUpdateParam; }

INLINE void CATlsoTransformFaceInputCellList::SetInputBody(CATBody * iInputBody) {
 _InputBody = iInputBody; }

INLINE const CATMathTransformation & CATlsoTransformFaceInputCellList::GetTransfo() const {
  return _Transformation; }

INLINE void CATlsoTransformFaceInputCellList::SetTransfo(const CATMathTransformation & iMathTransformation) {
  _Transformation = iMathTransformation; }

INLINE CATlsoTransformFaceConnectedInputCells * CATlsoTransformFaceInputCellList::GetConnectedInput() const {
  return _ConnectedInput; }

INLINE void CATlsoTransformFaceInputCellList::SetConnectedInput(CATlsoTransformFaceConnectedInputCells * iConnectedInput) {
  _ConnectedInput = iConnectedInput; }

INLINE CATListOfInt & CATlsoTransformFaceInputCellList::GetMandatoryStatus_Protected() {
  return _ListOfMandatoryStatus; }

INLINE  CATBody * CATlsoTransformFaceInputCellList::GetInputBody() const {
  return _InputBody; }

INLINE CellOriginType CATlsoTransformFaceInputCellList::GetOriginType() {
  return _OriginType;}

INLINE const CATListOfInt & CATlsoTransformFaceInputCellList::GetMandatoryStatus() const {
  return _ListOfMandatoryStatus; }

INLINE void CATlsoTransformFaceInputCellList::GetMandatoryStatus(CATListOfInt &oMandatoryStatus) const {
  oMandatoryStatus = _ListOfMandatoryStatus; }

INLINE void CATlsoTransformFaceInputCellList::SetOriginType(CellOriginType iOriginType) {
  _OriginType = iOriginType; }

INLINE CATPersistentBody * CATlsoTransformFaceInputCellList::GetUpToPersistentBody() const {
  return _UpToPersistentBody ; }

INLINE void CATlsoTransformFaceInputCellList::SetUpToPersistentBody(CATPersistentBody * iUpToPBody)  {
  _UpToPersistentBody = iUpToPBody ; }

INLINE void CATlsoTransformFaceInputCellList::SetRevolPrismData(const CATlsoRevolPrismData &iRevolPrismData) {
    _RevolPrismData = iRevolPrismData; }

INLINE CATGMLiveShapeRevolPrismMode CATlsoTransformFaceInputCellList::GetRevolPrismMode() const {
  return _RevolPrismData.GetRevolPrismMode(); }

INLINE CATAngle CATlsoTransformFaceInputCellList::GetRevolModeAngle() const {
   return _RevolPrismData.GetRevolAngle(); }

INLINE const CATlsoRevolPrismData & CATlsoTransformFaceInputCellList::GetRevolPrismData() const {
  return _RevolPrismData; }

INLINE void CATlsoTransformFaceInputCellList::CleanConnectedInput ()
{
  _ConnectedInput = NULL;
}

#endif

