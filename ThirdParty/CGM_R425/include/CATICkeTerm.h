// Copyright Dassault Systemes 2000
#ifndef CATICkeTerm_h
#define CATICkeTerm_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Engineering Equations 
// 	declaration of Terms
//
//////////////////////////////////////////////////////////////////////////

//#include "CATCkeExprDecls.h"
#include "CATBaseUnknown.h"
#include "CATICkeExpressionForwards.h"
#include "CATIParmPublisher.h"
#include "CATCkeStream.h"
#include "CATICkeArg.h"
#include "CATKweActivateEKLPerfos.h"

// streams
typedef CATCkeStream& CATICkeStream;

class CATCkeEvalContext;
class CATListValCATICkeTerm_var;
class CATListValCATICkeFvar_var;

#include "CATLifSpecs.h"


// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeTerm;
#else
extern "C" const IID IID_CATICkeTerm;
#endif

class ExportedByCATLifSpecs CATICkeTerm : public CATBaseUnknown
{

public:

  // name
  //virtual CATUnicodeString  Name    () const =0;
  //virtual void            Rename    (CATUnicodeString s) =0;

  // way of seeing an object
  // return user view
  virtual CATUnicodeString  Show() const = 0;

  // dump the content
  //virtual void    Dump      () const =0;

  // an object has a type 
  virtual CATICkeType_var Type() const = 0;


  /**
   *  Output arguments
  */
  virtual CATICkeArg_var      	ReturnedArg() const = 0;
  virtual const CATICkeParm_var	& Result() const = 0;
  virtual const CATICkeFvar_var &OutVar() const = 0;

  /**
   *  Layers management
   */
   // layer selection 
  virtual int     	      	Layers() const = 0;
  virtual int     		CurrentLayer() const = 0;

  // layer management
  virtual void        		NewLayer(int i = -1) = 0;
  virtual void	      		DeleteLayers() = 0;
  virtual void	      		RemoveLayer(int i) = 0;
  virtual void	      		SelectLayer(int i) = 0;
  virtual void              Clear() = 0;  // resets current layer


#ifdef _EKLPerfos_
  virtual CATListValCATICkeFvar_var*    	FormalVars() const = 0;
#else
  virtual CATCkeListOfFvar    	FormalVars() const = 0;
#endif


  // misc
  virtual CATUnicodeString      		Content() const = 0;
  virtual CATICkeStream		Gen(CATICkeStream os, const CATIParmPublisher_var &iRoot = NULL_var) const = 0;

  virtual CATICkeArg::Mode 		CheckMode(const CATICkeFvar_var &v, CATICkeArg::Mode m) const = 0;


  /*
   *  External method evaluation of term
   **/
  virtual CATCke::Boolean     IsRunnable() const = 0;
  virtual void        Eval(const CATCkeEvalContext *pevalcontext = NULL) = 0;

  /*
   *  Check magnitude homogeneity : Raise CATCkeErrorMKS
   **/
  virtual CATCke::Boolean    CheckMagnitude(const CATCkeEvalContext *p = NULL) const = 0;




  // term management
  virtual void	      		AddVars(const CATICkeTerm_var &t) = 0;
  virtual void	      		Add(const CATICkeFvar_var &v) = 0;

  // help a presentation of content
  virtual CATUnicodeString Identify() const = 0;


  // methodes d'expr

    /*
     * Signature  : only available on some functional expressions
     */
  virtual const CATICkeSignature_var &	Signature() const = 0;
  virtual void                  SetPrototype(const CATICkeSignature_var &s) = 0;


  /*
   * Internal Eval Methods
   **/
   // evaluation des sous termes
  virtual void EvalSubTerm(int i, const CATCkeEvalContext *pevalcontext = NULL) = 0;

  // Get the results of the sub expressions
  // Be careful there is allocation of the list. Must be deleted by user.
  virtual CATCkeListOfParm Interface() const = 0;

  // Results valuation
  virtual void             SetResult(const CATICkeInst_var &v) = 0;


  /*
   * Local variables : only available on clauses
   */
  virtual void             SetLocalVars(CATListValCATICkeFvar_var *l) = 0;
  virtual CATListValCATICkeFvar_var* LocalVars() const = 0;


  /*
   * Get Access methods to sub expressions (unavailable on variables)
   * for a procedure, only one term is available
   **/
  virtual CATListValCATICkeTerm_var*     	SubExpressions() const = 0;
  virtual const CATICkeTerm_var&	GetSubExpr(const int i) const = 0;

  /*
  * Set Access methods to sub expressions (unavailable on variables)
  **/
  virtual void                  AddSubExpr(const CATICkeTerm_var &t) = 0;

  /*
  * Set line location of sub expressions
  **/
  virtual void                  SetLineno(const int &iStartLineno, const int &iEndLineno) = 0;
  virtual void                  SetLineno(const int &iLineno) = 0;
  virtual int GetStartLineno() = 0;
  virtual int GetLineno() = 0;

  // Parse sub expressions if any
  virtual HRESULT ParseSubExpression(CATCke::Boolean &oBool) const = 0;


  //Check si l'expression est debugable
  virtual int IsDebugable()const = 0;


private:

  // 2 define ClassName
  CATDeclareInterface;

};

CATDeclareHandler(CATICkeTerm, CATBaseUnknown);

#endif

