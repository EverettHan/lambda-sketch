// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATDimensionSystem2Plug.h
// Header definition of CATDimensionSystem2Plug
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2004  Creation:                Evgueni ROUKOLEEV.
//===================================================================
#ifndef CATDimensionSystem2Plug_H
#define CATDimensionSystem2Plug_H

#include "CATCDSPlugMigrationTool.h"
#ifdef FORCE_NEW_PLUG
#include "CATDimensionSystemCDSPlug.h"
#else

#include "CATErrorDef.h"
#include "Plug2DBase.h"
#include "CATCDSBoolean.h"
#include "CATIAV5Level.h"
#if defined(CATIAR215) || defined(CATIAV5R29)
#include "CATCGMSkmDataTypes.h"
#else
#include "dcmtypes.h"
#endif
#include "solvertypes.h"

#include "CATCollec.h"

class CATConstraintSolver;
class CATSoftwareConfiguration;
class g_node; // geometry node
class d_node; // dimension node
class r_node; // radius node
class v_node; // variable node

//-----------------------------------------------------------------------

/**
 * Describe your class here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedByPlug2DBase CATDimensionSystem2Plug
{
protected:
  CATDimensionSystem2Plug();
  virtual ~CATDimensionSystem2Plug();

  static void GetBridgeOnce();

public:
  static CATCDSBoolean IsAvailable();
  static CATCDSBoolean IsAvailableAndEnv();
  static CATCDSBoolean IsAvailableAndNoEnv();

  inline static CATConstraintSolver* Create(CATSoftwareConfiguration *ipSoftwareConfiguration, double res_linear, double size, void* ap);
  inline static void Delete(CATConstraintSolver* ipCS);
  inline static void SetStreamTool(CATConstraintSolver* ipCS, void* iST); // Debug facilities
  inline static void SetOption(CATConstraintSolver* ipCS, DCM_option opt);

  inline static g_node* add_g(CATConstraintSolver* ipCS, void* ag);
  inline static r_node* add_r(CATConstraintSolver* ipCS, void* ad, g_node* gn);
  inline static d_node* add_d(CATConstraintSolver* ipCS, void* ad, g_node* gn1, g_node* gn2);
  inline static d_node* add_d(CATConstraintSolver* ipCS, void* ad, g_node* gn1, g_node* gn2, g_node* midg);
  inline static void fix(CATConstraintSolver* ipCS, g_node* gn);
  inline static DCM_logical move_to_set(CATConstraintSolver* ipCS, g_node* gn, g_node* setgn);
  inline static void erase(CATConstraintSolver* ipCS, g_node* gn);
  inline static void erase(CATConstraintSolver* ipCS, d_node* dn);
  inline static void erase(CATConstraintSolver* ipCS, r_node* rn);
  inline static g_node_status status(CATConstraintSolver* ipCS, g_node* gn);
  inline static d_node_status status(CATConstraintSolver* ipCS, d_node* dn);
  inline static d_node_status status(CATConstraintSolver* ipCS, r_node* rn);
  inline static int underdefined_status(CATConstraintSolver* ipCS, g_node* gn);
  inline static int transform(CATConstraintSolver* ipCS, g_node* gn, double mat[3][3], double* r_offset, double* min_r_offset, double* scale);
  inline static void help_point(CATConstraintSolver* ipCS, g_node* gn, d_node* dn, double* loc);
  inline static double help_parameter(CATConstraintSolver* ipCS, g_node* gn, d_node* dn);
  inline static DCM_evaluation_type evaluate(CATConstraintSolver* ipCS, int ng, g_node** gn, DCM_solving_mode mode);
  inline static DCM_evaluation_type re_evaluate(CATConstraintSolver* ipCS, int ng, g_node** gn, DCM_logical calc_status, DCM_solving_mode mode);
  inline static DCM_m_and_e_outcome move_and_evaluate(CATConstraintSolver* ipCS, int n_geom, g_node** gn, double (**mat)[3], double* rad, double* rad_2, DCM_solving_mode m);
  inline static void reset(CATConstraintSolver* ipCS, DCM_logical cancel_chirality);
  inline static DCM_chirality_status change_chirality(CATConstraintSolver* ipCS, d_node* dn, g_node* gn1, g_node* gn2);
  inline static void undo_evaluation(CATConstraintSolver* ipCS, DCM_undo_mode um);
  inline static DCM_evaluation_type dynamic_evaluate(CATConstraintSolver* ipCS, int n_geom, g_node** gn, double (**mat)[3], double* rad, DCM_dragging_transformation* dragt, DCM_dragging_result* res, DCM_dragging_option opt, DCM_solving_mode);

  // PKC 20/01/2006 plug for auto-dimensionning
  inline static DCM_autodim_status autodimension(CATConstraintSolver* ipCS);
  inline static void add_autodimension_mask(CATConstraintSolver* ipCS, DCM_autodim_g_type g1t, DCM_autodim_g_type g2t, DCM_autodim_d_type dt, DCM_autodim_mask_option mo, int n_gnodes, g_node** g_array, g_node** g_array2, double* dir, g_node* gdir);
  inline static int deduce_constraints(CATConstraintSolver* ipCS, double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2);
  inline static int deduce_constraints(CATConstraintSolver* ipCS, double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2, g_node* gn3);

  // FCX 13/04/2010
  inline static HRESULT get_alignment(CATConstraintSolver* ipCS, d_node* dn, SOLVER_alignment & align);
  inline static HRESULT get_half_space(CATConstraintSolver* ipCS, d_node* dn, g_node* gn, SOLVER_half_space & hs);

  // KUB, 11/10/2010
  inline static HRESULT get_connex_component(CATConstraintSolver* ipCS, int n_geom, g_node ** iNonCuttingElements, CATListPV & oListOfConnexGeometries, CATListPV & oListOfConnexConstraint);

  // KUB, 05.2011
  inline static v_node* add_distance_equality(CATConstraintSolver* ipCS, void* ad, int ndist, d_node** dn, int nrad, r_node** rn);
  inline static double value(CATConstraintSolver* ipCS, v_node * vn);
  inline static void erase(CATConstraintSolver* ipCS, v_node* vn);

  
  inline static void * application_pointer(CATConstraintSolver* ipCS , g_node * gn);


protected:
  virtual CATConstraintSolver* _Create(CATSoftwareConfiguration *ipSoftwareConfiguration, double res_linear, double size, void* ap) = 0;
  virtual void _Delete(CATConstraintSolver* ipCS) = 0;
  virtual void _GetEnv() = 0;
  virtual void _GetEnv2() = 0;
  virtual void _SetStreamTool(CATConstraintSolver* ipCS, void* iST) = 0; // Debug facilities
  virtual void _SetOption(CATConstraintSolver* ipCS, DCM_option opt) = 0; 


  virtual g_node* _add_g(CATConstraintSolver* ipCS, void* ag) = 0;
  virtual r_node* _add_r(CATConstraintSolver* ipCS, void* ad, g_node* gn) = 0;
  virtual d_node* _add_d(CATConstraintSolver* ipCS, void* ad, g_node* gn1, g_node* gn2) = 0;
  virtual d_node* _add_d(CATConstraintSolver* ipCS, void* ad, g_node* gn1, g_node* gn2, g_node* midg) = 0;
  virtual void _fix(CATConstraintSolver* ipCS, g_node* gn) = 0;
  virtual DCM_logical _move_to_set(CATConstraintSolver* ipCS, g_node* gn, g_node* setgn) = 0;
  virtual void _erase(CATConstraintSolver* ipCS, g_node* gn) = 0;
  virtual void _erase(CATConstraintSolver* ipCS, d_node* dn) = 0;
  virtual void _erase(CATConstraintSolver* ipCS, r_node* rn) = 0;
  virtual g_node_status _status(CATConstraintSolver* ipCS, g_node* gn) = 0;
  virtual d_node_status _status(CATConstraintSolver* ipCS, d_node* dn) = 0;
  virtual d_node_status _status(CATConstraintSolver* ipCS, r_node* rn) = 0;
  virtual int _underdefined_status(CATConstraintSolver* ipCS, g_node* gn) = 0;
  virtual int _transform(CATConstraintSolver* ipCS, g_node* gn, double mat[3][3], double* r_offset, double* min_r_offset, double* scale) = 0;
  virtual void _help_point(CATConstraintSolver* ipCS, g_node* gn, d_node* dn, double* loc) = 0;
  virtual double _help_parameter(CATConstraintSolver* ipCS, g_node* gn, d_node* dn) = 0;
  virtual DCM_evaluation_type _evaluate(CATConstraintSolver* ipCS, int ng, g_node** gn, DCM_solving_mode mode) = 0;
  virtual DCM_evaluation_type _re_evaluate(CATConstraintSolver* ipCS, int ng, g_node** gn, DCM_logical calc_status, DCM_solving_mode mode) = 0;
  virtual DCM_m_and_e_outcome _move_and_evaluate(CATConstraintSolver* ipCS, int n_geom, g_node** gn, double (**mat)[3], double* rad, double* rad_2, DCM_solving_mode m) = 0;
  virtual void _reset(CATConstraintSolver* ipCS, DCM_logical cancel_chirality) = 0;
  virtual DCM_chirality_status _change_chirality(CATConstraintSolver* ipCS, d_node* dn, g_node* gn1, g_node* gn2) = 0;
  virtual void _undo_evaluation(CATConstraintSolver* ipCS, DCM_undo_mode um) = 0;
  virtual DCM_evaluation_type _dynamic_evaluate(CATConstraintSolver* ipCS, int n_geom, g_node** gn, double (**mat)[3], double* rad, DCM_dragging_transformation* dragt, DCM_dragging_result* res, DCM_dragging_option opt, DCM_solving_mode) = 0;

  // PKC 20/01/2006
  virtual DCM_autodim_status _autodimension(CATConstraintSolver* ipCS)=0;
  virtual void _add_autodimension_mask(CATConstraintSolver* ipCS, DCM_autodim_g_type g1t, DCM_autodim_g_type g2t, DCM_autodim_d_type dt, DCM_autodim_mask_option mo, int n_gnodes, g_node** g_array, g_node** g_array2, double* dir, g_node* gdir)=0;
  virtual int _deduce_constraints(CATConstraintSolver* ipCS, double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2)=0;
  virtual int _deduce_constraints(CATConstraintSolver* ipCS, double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2, g_node* gn3)=0;

  // FCX 13/04/2010
  virtual HRESULT _get_alignment(CATConstraintSolver* ipCS, d_node* dn, SOLVER_alignment & align)=0;
  virtual HRESULT _get_half_space(CATConstraintSolver* ipCS, d_node* dn, g_node* gn, SOLVER_half_space & hs)=0;


  //KUB, 10/10/2010
  virtual HRESULT _get_connex_component(CATConstraintSolver* ipCS, int n_geom, g_node ** iNonCuttingElements, CATListPV & oListOfConnexGeometries,  CATListPV & oListOfConnexConstraints) = 0;

  // KUB, 05.2011
  virtual v_node* _add_distance_equality(CATConstraintSolver* ipCS, void* ad, int ndist, d_node** dn, int nrad, r_node** rn) = 0;
  virtual double _value(CATConstraintSolver* ipCS, v_node * vn) = 0;
  virtual void _erase(CATConstraintSolver* ipCS, v_node* vn) = 0;

  virtual void * _application_pointer(CATConstraintSolver* ipCS , g_node * gn) = 0;


  static CATDimensionSystem2Plug *_pBridge;
  static CATCDSBoolean _Once;
  static CATCDSBoolean _EnvOnce;
  static CATCDSBoolean _Env;

private:
  CATDimensionSystem2Plug(const CATDimensionSystem2Plug&);
  void operator=(const CATDimensionSystem2Plug&);
};

//-----------------------------------------------------------------------

inline void*  CATDimensionSystem2Plug::application_pointer(CATConstraintSolver* ipCS , g_node * gn)
{
   if (_pBridge) return _pBridge->_application_pointer(ipCS,gn);
   return 0;
}


inline CATConstraintSolver* CATDimensionSystem2Plug::Create(CATSoftwareConfiguration *ipSoftwareConfiguration,
                                                              double res_linear, double size, void* ap)
{
  if (_pBridge) return _pBridge->_Create(ipSoftwareConfiguration,res_linear,size,ap);
  return 0;
}

inline void CATDimensionSystem2Plug::Delete(CATConstraintSolver* ipCS)
{
  if (_pBridge) _pBridge->_Delete(ipCS);
}

inline void CATDimensionSystem2Plug::SetStreamTool(CATConstraintSolver* ipCS, void* iST)
{
  if (_pBridge) _pBridge->_SetStreamTool(ipCS, iST);
}

inline void CATDimensionSystem2Plug::SetOption(CATConstraintSolver* ipCS, DCM_option opt)
{
   if (_pBridge) _pBridge->_SetOption(ipCS, opt);
}

inline g_node* CATDimensionSystem2Plug::add_g(CATConstraintSolver* ipCS, void* ag)
{
  if (_pBridge) return _pBridge->_add_g(ipCS, ag);
  return 0;
}

inline r_node* CATDimensionSystem2Plug::add_r(CATConstraintSolver* ipCS, void* ad, g_node* gn)
{
  if (_pBridge) return _pBridge->_add_r(ipCS, ad, gn);
  return 0;
}

inline d_node* CATDimensionSystem2Plug::add_d(CATConstraintSolver* ipCS, void* ad, g_node* gn1, g_node* gn2)
{
  if (_pBridge) return _pBridge->_add_d(ipCS, ad, gn1, gn2);
  return 0;
}

inline d_node* CATDimensionSystem2Plug::add_d(CATConstraintSolver* ipCS, void* ad, g_node* gn1, g_node* gn2, g_node* midg)
{
  if (_pBridge) return _pBridge->_add_d(ipCS, ad, gn1, gn2, midg);
  return 0;
}

inline void CATDimensionSystem2Plug::fix(CATConstraintSolver* ipCS, g_node* gn)
{
  if (_pBridge) _pBridge->_fix(ipCS, gn);
}

inline DCM_logical CATDimensionSystem2Plug::move_to_set(CATConstraintSolver* ipCS, g_node* gn, g_node* setgn)
{
  if (_pBridge) return _pBridge->_move_to_set(ipCS, gn, setgn);
  return 0;
}

inline void CATDimensionSystem2Plug::erase(CATConstraintSolver* ipCS, g_node* gn)
{
  if (_pBridge) _pBridge->_erase(ipCS, gn);
}

inline void CATDimensionSystem2Plug::erase(CATConstraintSolver* ipCS, d_node* dn)
{
  if (_pBridge) _pBridge->_erase(ipCS, dn);
}

inline void CATDimensionSystem2Plug::erase(CATConstraintSolver* ipCS, r_node* rn)
{
  if (_pBridge) _pBridge->_erase(ipCS, rn);
}
inline void CATDimensionSystem2Plug::erase(CATConstraintSolver* ipCS, v_node* vn)
{
  if (_pBridge) _pBridge->_erase(ipCS, vn);
}
inline g_node_status CATDimensionSystem2Plug::status(CATConstraintSolver* ipCS, g_node* gn)
{
  if (_pBridge) return _pBridge->_status(ipCS, gn);
  return g_node_status(0);
}

inline d_node_status CATDimensionSystem2Plug::status(CATConstraintSolver* ipCS, d_node* dn)
{
  if (_pBridge) return _pBridge->_status(ipCS, dn);
  return d_node_status(0);
}

inline d_node_status CATDimensionSystem2Plug::status(CATConstraintSolver* ipCS, r_node* rn)
{
  if (_pBridge) return _pBridge->_status(ipCS, rn);
  return d_node_status(0);
}

inline int CATDimensionSystem2Plug::underdefined_status(CATConstraintSolver* ipCS, g_node* gn)
{
  if (_pBridge) return _pBridge->_underdefined_status(ipCS, gn);
  return 0;
}

inline int CATDimensionSystem2Plug::transform(CATConstraintSolver* ipCS, g_node* gn, double mat[3][3], double* r_offset, double* min_r_offset, double* scale)
{
  if (_pBridge) return _pBridge->_transform(ipCS, gn, mat, r_offset, min_r_offset, scale);
  return 0;
}

inline void CATDimensionSystem2Plug::help_point(CATConstraintSolver* ipCS, g_node* gn, d_node* dn, double* loc)
{
  if (_pBridge) _pBridge->_help_point(ipCS, gn, dn, loc);
}

inline double CATDimensionSystem2Plug::help_parameter(CATConstraintSolver* ipCS, g_node* gn, d_node* dn)
{
  if (_pBridge) return _pBridge->_help_parameter(ipCS, gn, dn);
  return 0.;
}

inline DCM_evaluation_type CATDimensionSystem2Plug::evaluate(CATConstraintSolver* ipCS, int ng, g_node** gn, DCM_solving_mode mode)
{
  if (_pBridge) return _pBridge->_evaluate(ipCS, ng, gn, mode);
  return DCM_evaluation_type(0);
}

inline DCM_evaluation_type CATDimensionSystem2Plug::re_evaluate(CATConstraintSolver* ipCS, int ng, g_node** gn, DCM_logical calc_status, DCM_solving_mode mode)
{
  if (_pBridge) return _pBridge->_re_evaluate(ipCS, ng, gn, calc_status, mode);
  return DCM_evaluation_type(0);
}

inline DCM_m_and_e_outcome CATDimensionSystem2Plug::move_and_evaluate(CATConstraintSolver* ipCS, int n_geom, g_node** gn, double (**mat)[3], double* rad, double* rad_2, DCM_solving_mode m)
{
  if (_pBridge) return _pBridge->_move_and_evaluate(ipCS, n_geom, gn, mat, rad, rad_2, m);
  return DCM_m_and_e_outcome(0);
}

inline void CATDimensionSystem2Plug::reset(CATConstraintSolver* ipCS, DCM_logical cancel_chirality)
{
  if (_pBridge) _pBridge->_reset(ipCS, cancel_chirality);
}

inline DCM_chirality_status CATDimensionSystem2Plug::change_chirality(CATConstraintSolver* ipCS, d_node* dn, g_node* gn1, g_node* gn2)
{
  if (_pBridge) return _pBridge->_change_chirality(ipCS, dn, gn1, gn2);
  return DCM_chirality_status(0);
}

inline void CATDimensionSystem2Plug::undo_evaluation(CATConstraintSolver* ipCS, DCM_undo_mode um)
{
  if (_pBridge) _pBridge->_undo_evaluation(ipCS, um);
}

inline DCM_evaluation_type CATDimensionSystem2Plug::dynamic_evaluate(CATConstraintSolver* ipCS, int n_geom, g_node** gn, double (**mat)[3], double* rad, DCM_dragging_transformation* dragt, DCM_dragging_result* res, DCM_dragging_option opt, DCM_solving_mode mode)
{
  if (_pBridge) return _pBridge->_dynamic_evaluate(ipCS, n_geom, gn, mat, rad, dragt, res, opt, mode);
  return DCM_evaluation_type(0);
}
// pkc 20/01/2006
inline DCM_autodim_status CATDimensionSystem2Plug::autodimension(CATConstraintSolver* ipCS)
{
  if (_pBridge) return _pBridge->_autodimension(ipCS);
  return DCM_autodim_status(0);
}
// PKC suite
inline void CATDimensionSystem2Plug::add_autodimension_mask(CATConstraintSolver* ipCS, DCM_autodim_g_type g1t, DCM_autodim_g_type g2t, DCM_autodim_d_type dt, DCM_autodim_mask_option mo, int n_gnodes, g_node** g_array, g_node** g_array2, double* dir, g_node* gdir)
{
  if (_pBridge) _pBridge->_add_autodimension_mask(ipCS, g1t, g2t, dt, mo, n_gnodes, g_array, g_array2, dir, gdir);
}

inline int CATDimensionSystem2Plug::deduce_constraints(CATConstraintSolver* ipCS, double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2)
{
  if (_pBridge) return _pBridge->_deduce_constraints(ipCS, tol_lin, tol_ang, dt, gn1, gn2);
  return 0;
}
inline int CATDimensionSystem2Plug::deduce_constraints(CATConstraintSolver* ipCS, double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2, g_node* gn3)
{
  if (_pBridge) return _pBridge->_deduce_constraints(ipCS, tol_lin, tol_ang, dt, gn1, gn2, gn3);
  return 0;
}
// FCX 13/04/2010
inline HRESULT CATDimensionSystem2Plug::get_alignment(CATConstraintSolver* ipCS, d_node* dn, SOLVER_alignment & align)
{
  if (_pBridge) return _pBridge->_get_alignment(ipCS, dn, align);
  return S_OK;
}
// FCX 13/04/2010
inline HRESULT CATDimensionSystem2Plug::get_half_space(CATConstraintSolver* ipCS, d_node* dn, g_node* gn, SOLVER_half_space & hs)
{
  if (_pBridge) return _pBridge->_get_half_space(ipCS, dn, gn, hs);
  return S_OK;
}
// kub, 11/10/2010
inline HRESULT CATDimensionSystem2Plug::get_connex_component(CATConstraintSolver* ipCS, int n_geom, g_node ** iNonCuttingElements, CATListPV & oListOfConnexGeometries, CATListPV & oListOfConnexConstraints)
{
  if (_pBridge) return _pBridge->_get_connex_component(ipCS, n_geom, iNonCuttingElements, oListOfConnexGeometries, oListOfConnexConstraints);
  return E_FAIL;
}

// kub, 05.2011
inline v_node* CATDimensionSystem2Plug::add_distance_equality(CATConstraintSolver* ipCS, void* ad, int ndist, d_node** dn, int nrad, r_node** rn)
{
  if (_pBridge) return _pBridge->_add_distance_equality(ipCS, ad, ndist, dn, nrad, rn);
  return 0;
}

inline double CATDimensionSystem2Plug::value(CATConstraintSolver* ipCS, v_node * vn)
{
  if (_pBridge) return _pBridge->_value(ipCS,vn);
  return 0.;
}



//-----------------------------------------------------------------------

#endif
#endif
