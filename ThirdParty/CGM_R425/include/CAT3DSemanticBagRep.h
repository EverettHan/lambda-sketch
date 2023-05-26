#ifndef CAT3DSemanticBagRep_H
#define CAT3DSemanticBagRep_H

// COPYRIGHT DASSAULT SYSTEMES 2003

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 2003
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DBagRep.h"

/** @nodoc */
#define SEMANTIC3DBAGREP_V4TEXT       0x1
#define SEMANTIC3DBAGREP_V4GEOMETRY   0x2
/** @nodoc */
/** do not use  */
#define SEMANTIC3DBAGREP_AXES         0x3
#define SEMANTIC3DBAGREP_WIRES        0x4
#define SEMANTIC3DBAGREP_POINTS       0x5

/** Class to create a collection (bag) of representations with a semantic value. */
class ExportedBySGInfra CAT3DSemanticBagRep : public CAT3DBagRep
{
  friend class CATDmuStream3DSemanticBagRep;
  friend class SGCGRStreamerFor3DSemanticBagRep;
  friend class SGCGRNodesFactoryA;

  CATDeclareClass;
protected:
  virtual ~CAT3DSemanticBagRep();

public:
  static CAT3DSemanticBagRep* CreateRep();
  static CAT3DSemanticBagRep* CreateRep(unsigned char iType);
  
protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DSemanticBagRep();

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DSemanticBagRep(unsigned char iType);

public:
  
  /** @nodoc */
  void SetType(unsigned char iType);
  
  /** @nodoc */
  unsigned char GetType();
  
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading(CATRender &ioRender, int iInside) FUNC_OVERRIDE_FINAL;

  /** @nodoc */
  virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) FUNC_OVERRIDE_FINAL;

  /** @nodoc */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;

  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CAT3DSemanticBagRep (CAT3DSemanticBagRep &);
  CAT3DSemanticBagRep& operator=(CAT3DSemanticBagRep&);

  unsigned char _bagType;
};

#endif // CAT3DSemanticBagRep_H
