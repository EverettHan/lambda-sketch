#ifndef CAT3DBagRepWithBox_H
#define CAT3DBagRepWithBox_H

// COPYRIGHT DASSAULT SYSTEMES 2002

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 2002
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DFinalBagRep.h"

/** Class to create a collection (bag) of representations. */
class ExportedBySGInfra CAT3DBagRepWithBox : public CAT3DFinalBagRep
{
  CATDeclareClass;

protected:

  virtual ~CAT3DBagRepWithBox();

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DBagRepWithBox();

public:

  static CAT3DBagRepWithBox* CreateRep();

  /** @nodoc */
  virtual void SetInvalid();

  /** @nodoc */
  void SetBoundingBox(float *i_pBox);
  const float* GetBoundingBox();

private:
  float *_pBoundingBox;
};

#endif // CAT3DBagRepWithBox_H
