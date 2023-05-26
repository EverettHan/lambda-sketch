// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATBaseUnknown_Associations_H
#define CATBaseUnknown_Associations_H

/**
  * @CAA2Level L1
  * @CAA2Usage U1
  */
///////////////////////////////////////////////////////////////////////////////////
// Didier LARUEL
// Fev -96    
// To enable Object associations to be defined:
//
//     InterfaceObject_ptr <-> InterfaceObject_ptr
//
// This is Particulary useful for Create/Update operations....
//
// Remarks: should be implemented onto Hash code for improved performances
//
///////////////////////////////////////////////////////////////////////////////////

#include <CATBaseUnknown.h>

//for VarBaseUnknown && ListOfVarBaseUnknown definition
#include <CATBaseUnknowns.h>
#include <CP0CLIP.h>

class CATBaseUnknown_Association;
class CATArrayIndex;
class CATHTAB(CATArrayIndex);

/**
 * Class used to enable object associations to be defined. 
 */
class ExportedByCP0CLIP CATBaseUnknown_Associations
 {
  public:
   /** @nodoc */
   CATBaseUnknown_Associations(const ListOfVarBaseUnknown& lst_was);

   /** @nodoc */
   CATBaseUnknown_Associations(int nb_alloc=0);
   
   /** @nodoc */
   ~CATBaseUnknown_Associations();

   /** @nodoc */
   void AddAssociation(VarBaseUnknown was, VarBaseUnknown is=NULL_varBaseUnknown);

   /** @nodoc */
   int Size() const;

   /** @nodoc */
   ListOfVarBaseUnknown  GetWasAssociatedTo() const;

	 /** @nodoc */
	 int LocateIndexFromIs(VarBaseUnknown& is_now) const;

	 /** @nodoc */
   VarBaseUnknown WasAssociatedTo(int is_now) const;

   /** @nodoc */
   VarBaseUnknown WasAssociatedTo(VarBaseUnknown is_now) const;

   /** @nodoc */
   ListOfVarBaseUnknown  GetIsAssociatedTo() const;

	 /** @nodoc */
	 int LocateIndexFromWas(VarBaseUnknown& was) const;

   /** @nodoc */
   VarBaseUnknown IsAssociatedTo(int was) const;

   /** @nodoc */
   VarBaseUnknown IsAssociatedTo(VarBaseUnknown was) const;
   
   /** @nodoc */
   CATBaseUnknown_Associations(const CATBaseUnknown_Associations& was);
   
   /** @nodoc */
   CATBaseUnknown_Associations& operator=(const CATBaseUnknown_Associations& was);


  private:
   void extent_tb(int nb_new);
 
  private:
   CATBaseUnknown_Association* _tb;
   CATHTAB(CATArrayIndex)* _hIs,*_hWas;
   int _insertions;
   int _nb;
 };

#endif

