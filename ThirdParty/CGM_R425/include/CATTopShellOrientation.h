#ifndef CATTopShellOrientation_h
#define CATTopShellOrientation_h

//COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"

#include "AdvTopoUtil.h"
#include "CATTopOperator.h"

class CATShell;
class CATSurface;
class CATTransfoManager;
class CATSurLimits;

 /**
 * Class defining the operator that modifies the orientation of the faces of a shell  
 * as well as the underlying surfaces so that the faces, the surfaces and the shell 
 * all have the same orientation.
 * This operator follows the general scheme of the topological operators:
 * <ul>
 *<li> Creates the operator with the <tt>CATCreateTopShellOrientation</tt> global function, which defines
 * the body which contains the faces to be inverted.
 *<li> Runs with the <tt>Run</tt> method. 
 *<li> Gets the result body by the <tt>GetResult</tt> method. 
 *<li> Deletes the operator with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */ 
//-----------------------------------------------------------------------------
class ExportedByAdvTopoUtil CATTopShellOrientation : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopShellOrientation);
public :

   /**
   * @nodoc
   * Constructor. Do not use. Use <tt>CATCreateTopShellOrientation</tt> to create an
   * <tt>CATTopShellOrientation</tt>.
   */
                CATTopShellOrientation(CATGeoFactory* iGeoFactory,
                                       CATTopData   * iTopData   );

   virtual     ~CATTopShellOrientation();
   
   /**
   * Runs <tt>this</tt> operator. Returns 0 if the operation completes properly.
   */
   virtual int  Run                   ();

#if defined ( CATIACGMV5R22 )
   /**
   * @nodoc
   * Change Specification To Simple Skin Inversion Without Any Surface Consideration.
   * Be carefull , input conditions are restricted to Surfacic Body (not volumic or wireframe) 
   */
   virtual void ChangeSpecificationToSimpleSkinInversionWithoutAnySurfaceConsideration() = 0 ;

#endif

};
#endif
