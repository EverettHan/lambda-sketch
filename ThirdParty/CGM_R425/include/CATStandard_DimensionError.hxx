// File generated by CPPExt (Exception)
//                     Copyright (C) 1991,1995 by
//  
//                      MATRA DATAVISION, FRANCE
//  
// This software is furnished in accordance with the terms and conditions
// of the contract and with the inclusion of the above copyright notice.
// This software or any other copy thereof may not be provided or otherwise
// be made available to any other person. No title to an ownership of the
// software is hereby transferred.
//  
// At the termination of the contract, the software and all copies of this
// software must be deleted.
//
#ifndef _CATStandard_DimensionError_HeaderFile
#define _CATStandard_DimensionError_HeaderFile

/*
#ifndef _Handle_CATStandard_DimensionError_HeaderFile
#include "Handle_CATStandard_DimensionError.hxx"
#endif

#ifndef _CATStandard_SStream_HeaderFile
#include "CATStandard_SStream.hxx"
#endif
*/

#ifndef _CATStandard_DomainError_HeaderFile
#include "CATStandard_DomainError.hxx"
#endif


#if !defined No_Exception && !defined No_CATStandard_DimensionError
#define CATStandard_DimensionError_Raise_if(CONDITION,MESSAGE) \
  if (CONDITION) CATStandard_DimensionError::Raise(MESSAGE);
#else
#define CATStandard_DimensionError_Raise_if(CONDITION,MESSAGE)
#endif

//#include "SysCascade.h"

class CATStandard_DimensionError : public CATStandard_DomainError {
/*
public:
 ExportedBySysCascade  static void Raise(const CATStandard_CString aMessage = "");
 ExportedBySysCascade  static void Raise(CATStandard_SStream& aReason);
#ifndef NO_CXX_EXCEPTION
 ExportedBySysCascade  virtual void Throw() const ;
#endif

 ExportedBySysCascade  ~CATStandard_DimensionError();

 // Type methods
 //
 ExportedBySysCascade  friend Handle_CATStandard_Type& CATStandard_DimensionError_Type_();
 ExportedBySysCascade  const Handle(CATStandard_Type)& DynamicType() const;			
 ExportedBySysCascade  CATStandard_Boolean             IsKind(const Handle(CATStandard_Type)&) const;
 */
};

#endif
