#ifndef CATSorted3DBagRep_H
#define CATSorted3DBagRep_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2001



//**********************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 2001
//**********************************************************************
//  Abstract:
//  ---------
//    
//
//**********************************************************************
//  Usage:
//  ------
//   
///
//**********************************************************************
//  Main Methods:
//  -------------
//   
//
//**********************************************************************


#include "CAT3DBagRep.h"
#include "CATSortedSetOfObject.h"



class CATSorted3DBagRep : public CAT3DBagRep
{
  CATDeclareClass;
  
  
public:

  /** Constructs an observable empty bag representation. */
  static CATSorted3DBagRep* CreateRep();

protected:

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CATSorted3DBagRep();

public:

   virtual ~CATSorted3DBagRep();

   /** Adds a child representation to the bag.
   * @param iRep
   * Child representation to be added.
   */
  virtual HRESULT AddChild(CATRep &iRep);

  /** Removes a child representation from the bag.
   * The bounding element of the bag is updated.
   * @param iRep
   * Child representation to be removed.
   */
  virtual void RemoveChild(CAT3DRep &iRep);
  
  /** Removes a child representation from the bag.
   * The bounding element of the bag is not updated.
   * @param iRep
   * Child representation to be removed.
   */
  virtual void RemoveChildren(CAT3DRep &iRep);
  
  void EndRemoveChildren ();
 
  void EmptyHighlightBag ();

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
  /** @nodoc */
  virtual void DrawShading(CATRender&, int) FUNC_OVERRIDE_FINAL;
#ifdef CATIAR426
  /** @nodoc */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /** @nodoc */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

protected:
  CATSortedSetOfObject _Child;


private:
  static unsigned int HashFunction(const void* iEntry);
  static int CompareFunction(const void* iEntry1, const void* iEntry2);
  void CompressHighlightBag ();

  /** @nodoc */
  CATSorted3DBagRep (const CATSorted3DBagRep &);
  /** @nodoc */
  CATSorted3DBagRep & operator = (const CATSorted3DBagRep &);

  int _compressNeed;
  CAT3DBagRep* _paCompressedSorted3DBagRep;
};

#endif // CATSorted3DBagRep_H
