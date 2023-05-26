/* -*-C++-*- */

#ifndef CATlsoVariationalAdditionalInputData_H
#define CATlsoVariationalAdditionalInputData_H

#include "AdvTrimOpe.h"
#include "CATlsoDynMetaData.h"
#include "CATThrowForNullPointer.h"
#include "CATTopOpInError.h"
#include "CATDataType.h"
#include "CATMathInline.h"

enum VarAdditionalInputData
{
  // [InputData Name]           = [Key value]
  
  KEY_MandatoryStatus = 1,  // Int
  KEY_MandatoryStatusList = 2  // Int
  // ....
  //  /\
  //  ||   Add InputData here
  //  ||                                                                                                   
  // 
};

class ExportedByAdvTrimOpe CATlsoVariationalAdditionalInputData : public CATlsoDynMetaData
{

public:

  // Constructor
  CATlsoVariationalAdditionalInputData();

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  // Destructor
  virtual ~CATlsoVariationalAdditionalInputData();


  void  AttachData (CATListOfInt &iListOfMandatoryStatus);
  void  AttachData (int &iMandatoryStatus);

  int  GetData ( CATListOfInt *&oListOfMandatoryStatus );
  int  GetData  (int *&oMandatoryStatus );

protected:


};




#endif
  
