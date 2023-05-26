// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//
// CATCkeMethodDictionary: Internal dictionary. Applications are invited to use CATParmDictionary
//
// Dictionnary used by CKE : Note that there is a current Dictionnary 
// that you can find in CATCkeEquationContext: Define CATCKEMethodDictionary
//
// Methods :
// ------- 
//    - add methods to dictionnary
//
// Scan : 
// ----
//    - capability to scan methods 
//    - direct access to some methods
//
// Retrieving methods by "name"
// --------------------------------------
//    - capability to find a method that looks like one in input
//    Those capabilities are linked to parsing expressions they must be as
//    quick as possible 
//
// Access of Generic Methods (automatically filled or retrieved when adding  
// -------------------------  real methods)
//    - Scan generic methods
// 
//=============================================================================
// Usage Notes:
//
//=============================================================================
//
// Oct. 00   Creation                                   T.Dehove
//=============================================================================


#ifndef CATCkeMethodDictionary_H
#define CATCkeMethodDictionary_H   


// module
#include "CATLifExpressions.h"

// Includes Vom
#include "CATCkeContext.h"
#include "CATICkeSignature.h"
#include "CATICkeForwards.h"
#include "CATICkeConstraintForwards.h"
#include "CATListValCATICkeTerm.h"

#include "CATIContainer.h"
#include "CATListOfCATString.h"
#include "CATITypeDictionary.h"
#include "CATITypeDictionaryListener.h"
#include "CATICkeTerm.h"
#include "CATICkeArg.h"
class CATCkeMajordome;
class CATHashDico;
#include "CATListPV.h"
class CATCkeSignatureFromExprTree;


//-----------------------------------------------------------------------------
class ExportedByCATLifExpressions CATCkeMethodDictionary : public CATCkeContext
{
public:

  //-------------------------------
  // Construction 
  //-------------------------------
  CATCkeMethodDictionary();
  virtual ~CATCkeMethodDictionary();

  // Add a method
  void AddMethod(const CATICkeMethod_var&);

  // Add a method from a reusable lib
  void AddReusableMethod(const CATUnicodeString &iPLMIDOfLib, const CATICkeMethod_var &iMethod);

  // Add a constant (true, false)
  void AddConstant(const CATICkeParm_var&);



  //-------------------------------
  // Managing fake types and methods
  //-------------------------------

   // tracing 
  CATUnicodeString Trace() const;

  //-------------------------------
  // Scan
  //-------------------------------

  // returns shape (1 to N)
  CATCkeListOfSignature           Methods() const;

  // liste des cst du dictionnaire
  CATCkeListOfParm                Constants() const;


  //------------------------------------------
  // Retrieving types or shapes by "name"
  //------------------------------------------
  // find a shape that is like the input one
  CATICkeParm_var   FindConstant(const CATUnicodeString &name) const;

  // find the best shape that looks like the input one
  CATICkeMethod_var FindBestMethod(const CATICkeMethod_var&, const Boolean & = 0,
    CATCkeSignatureFromExprTree *psigTree = NULL, CATUnicodeString *errorMsg = NULL);

  // find the best shape that looks like the input one
  CATICkeMethod_var FindBestEvent(const CATICkeMethod_var&);

  CATICkeMethod_var FindMethodByName(const CATUnicodeString & iName, CATLISTV(CATBaseUnknown_var)  * iParams = NULL);

  CATICkeMethod_var FindBestMethodInLib(const CATUnicodeString &iLibID, const CATICkeMethod_var &iMethod,
    CATCkeSignatureFromExprTree *psigTree);


  // Dans le style effet de bord desastreux, lorsque l'on n'a pas trouve de
  // best method, on stocke la plus proche pour generer une erreur digne de ce nom
  // cette methode vous permet d'y acceder juste apres un findBestMethod
  CATICkeMethod_var SoLetsGetTheNearestMethod();

  int LastMethodUsedListForMultipleArgs()
  {
    return _LastUsedListForMultipleArgs;
  };



  //--------------------------------
  // Accessing basic methods
  //--------------------------------

  // special methods ; of/then/and/or
  CATICkeMethod_var GetMethodIfThenDeclarative() const;
  CATICkeMethod_var GetMethodAnd() const;
  CATICkeMethod_var GetMethodOr() const;
  CATICkeMethod_var GetMethodBlock() const;
  CATICkeMethod_var GetMethodSingleLineIfElse(const CATUnicodeString &, const CATICkeType_var &) const;
  // if/then/else methods
  enum IfThenElseNode { ElseAlone, ElseIfAlone, ElseIfElse, IfAlone, IfElse, For, ForWhile, ForWhileWithInit };
  CATICkeMethod_var GetMethodIfThenElse(const IfThenElseNode &) const;

  // Initialise le container et le recupere
  virtual void Init(const CATIContainer_var&);
  virtual CATIContainer_var  Container() const;

  // recherche de la liste des attributs
  CATCkeListOfSignature           Attributes() const;

  virtual void InitMethods() const;
  void SortMethods();

  static CATCkeMethodDictionary *GetMethodDictionary();
  static void  DeleteStaticMethodDictionary();

  static CATBoolean AreCompatibleTypes(const CATUnicodeString &iType1, const CATUnicodeString &iType2);
private:
  CATCkeMethodDictionary(const CATCkeMethodDictionary &);
  void operator=(const CATCkeMethodDictionary&);

  //-------------------------------
  // Acces aux types particuliers
  //-------------------------------

  int testFitMethod(const CATICkeMethod_var &mReference,
    int nbparam,
    const Boolean &lazzy,
    CATCkeSignatureFromExprTree *psigTree,
    const CATICkeMethod_var &mToCompare,
    CATICkeMethod_var& mfound);



  // temporaire FRH
  Boolean FirstCanBeUsedForSecond(const CATICkeMethod_var&, const CATICkeMethod_var&,
    CATCkeSignatureFromExprTree *psigTree);

  Boolean FullFillArgumentType(const CATICkeArg::Mode mode, const CATICkeType_var &, const CATICkeType_var &,
    const int rank,
    CATCkeSignatureFromExprTree *psigTree,
    CATListValCATICkeTerm_var* plisteFvar,
    CATCkeListOfType plisteType, int manageListCase = 0);

  void InitConstants();
  static CATCkeMethodDictionary *_MethodDictionary;

  CATICkeMethod_var methodIfThenDeclarative_;
  CATICkeMethod_var methodAnd_;
  CATICkeMethod_var methodOr_;
  CATICkeMethod_var methodBlock_;

  // if/then/else
  CATICkeMethod_var methodElse_;
  CATICkeMethod_var methodElseIf_;
  CATICkeMethod_var methodElseIfElse_;
  CATICkeMethod_var methodIf_;
  CATICkeMethod_var methodIfElse_;
  CATICkeMethod_var methodFor_;
  CATICkeMethod_var methodForWhile_;
  CATICkeMethod_var methodForWhileWithInit_;

  // libere les statiques

     // last method found with best method : not the best but almost....
  CATICkeMethod_var lastNotBestMethod_;
  double               rankingNotBestMethod_;

  // liste des cst du dictionnaire
  CATCkeListOfParm      plisteConstantes_;

  // liste des formes du dictionnaire
  CATHashDico           *pHashMethods_;
  CATCkeListOfSignature  plisteMethods_;

  CATHashDico * _ReusableMethods;


  CATCkeListOfSignature  plistLast_;

  //	unsigned int sortOk_:1; 
  unsigned int _LastUsedListForMultipleArgs : 1;

  friend class CATCkeMethodRemover;

};

#endif
