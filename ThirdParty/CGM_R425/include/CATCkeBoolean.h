#ifndef CATCkeBoolean_h
#define CATCkeBoolean_h

#ifdef CATCkeBooleanActive
// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */


/*  CAA2Reviewed by FRH */

// include module definition
#include "CATLifSpecs.h"

/**   
 *  Class for boolean definition. 
 *  <b>Role</b>: Boolean value management.<br>
 *  In some seldom case depending on the order of your includes, you may have compilation error in the lines where you use CATCke::True or CATCke::False.
 *  This problem can not be fixed anymore on DS side because of huge impacts.
 *  To avoid this compilation error switch from CATCke::True/CATCke::False to 1/0 in your code.
 */

 class ExportedByCATLifSpecs Boolean
 {
     public :

	  /** 
       * Constructs a Boolean (valuated by default to False).
       */ 
      Boolean();   
 
	  /** 
       * Constructs a Boolean from an integer.
       * @param iValue Legal values 
	   * <li><tt>1</tt> corresponds to a CATCke::True boolean.</li>  
       * <li><tt>0</tt> corresponds to a CATCke::False boolean.</li>
  	   */ 
      Boolean(int iValue);

	  /** 
	   * Copy constructor.
	   */
      Boolean(const Boolean&);

	  /** 
	   * Destructor.
	   */
      ~Boolean();

	  /** 
	   * Affects the right hand side boolean to the left hand side boolean.
       * @param iBoolean a CATCkeBoolean
	   * @return The result of the affectation.
	   */
      Boolean operator = (const Boolean & iBoolean);

	  /** 
	   * Tests the equivalence of two CATCkeBooleans.
       * @param iBoolean a CATCkeBoolean
	   * @return The result of the comparison
	   */
      Boolean operator == (const Boolean& iBoolean) const;
 
      /** 
 	   * Tests the non equivalence of two CATCkeBooleans.
       * @param b a CATCkeBoolean
	   * @return The result of the analysis of the difference
	   */
      Boolean operator != (const Boolean& b) const { return ! (*this == b); }

	  /** 
	   * Returns the integer correspondant value of a CATCkeBoolean. 1 for CATCkeTrue, 0 for CATCkeFalse. 
	   */
      operator int () const { return _bv; }

     protected:
      short _bv;
  };

 /** 
  * True = 1.
  */ 
#ifdef True
 /** 
  * Internal modifications to avoid naming conflicts.
  */ 
#define cke_old_true True
#undef True
 static const Boolean True;
 /** 
  * Internal modifications to avoid naming conflicts.
  */ 
#define True cke_old_true
#undef cke_old_true
#else
 static const Boolean True;
#endif

 /** 
  * False = 0.
  */
#ifdef False
 /**  
  * Internal modifications to avoid naming conflicts.
  */ 
#define cke_old_false False
#undef False
 static const Boolean False;
 /**  
  * Internal modifications to avoid naming conflicts.
  */ 
#define False cke_old_false
#undef cke_old_false
#else
 static const Boolean False;
#endif

#endif
#endif



