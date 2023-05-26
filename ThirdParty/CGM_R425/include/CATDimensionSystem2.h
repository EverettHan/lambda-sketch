// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATDimensionSystem2.h
// Header definition of CATDimensionSystem2
//
//===================================================================
//
//
//  Mar 2004  Creation:                Evgueni ROUKOLEEV.
//===================================================================
#ifndef CATDimensionSystem2_H
#define CATDimensionSystem2_H

#include "CATCDSPlugMigrationTool.h"
#ifdef FORCE_NEW_PLUG
#include "CATDimensionSystemCDS.h"
#else

#include "CATIAV5Level.h"
#include <stdio.h>
#include "CATErrorDef.h"
#include "Plug2DBase.h"
#if defined(CATIAR215) || defined(CATIAV5R29)
#include "CATCGMSkmDataTypes.h"
#else
#include "dcmtypes.h"
#endif
#include "solvertypes.h"
#include <CATListPV.h>

class CATConstraintSolver;
class CATSoftwareConfiguration;
class g_node; // geometry node
class d_node; // dimension node
class r_node; // radius node
class v_node; // variable node
class e_node; // equation node
class p_node; // parameter node
class dimension_system;


extern ExportedByPlug2DBase void* Solver_application_pointer;

//-----------------------------------------------------------------------

enum CATDimensionSystem2Type {CATUseDCM2D, CATUseDCM2DIfEnv, CATCGMSkmDataAct, CATCGMSkmDataActIfEnv};

class ExportedByPlug2DBase CATDimensionSystem2
{
public:
  // 1. Constructing and deleting a dimension_system
  CATDimensionSystem2(CATSoftwareConfiguration *ipSoftwareConfiguration,
                      double res_linear, double size, void* ap = DCM_NULL,
                      CATDimensionSystem2Type iType = CATCGMSkmDataActIfEnv);
  virtual ~CATDimensionSystem2();

  CATConstraintSolver* GetConstraintSolver(); // FCX 9.2005

  // Set options which control behaviour of other functions
  void set_option(DCM_option opt);

  // Debug facilities
  void set_stream_tool (void* st);

  // Register frustum functions (callbacks)
  DCM_logical register_frustum_functions(struct DCM_frustum_functions*);
  // Enquire which frustum functions are registered
  void enquire_frustum_functions(struct DCM_frustum_functions*);

  // 2. Adding and erasing model data

  // Add a geometry (including a set)
  g_node* add_g(void* ag);

  // Add an offset-parametric or -ellipse, offset from parent_gn
  g_node* add_offset_g(void* off_g, g_node* parent_gn);

  // Add dimensions with different numbers of g_nodes:
  // 1 - a radius dimension; creates an r_node
  // 2 - most other dimensions
  // 3 - symmetry or midpoint; last g_node is the axis or midpoint
  // 4 - equal_distance
  r_node* add_r(void* ad, g_node* gn);
  d_node* add_d(void* ad, g_node* gn1, g_node* gn2);
  d_node* add_d(void* ad, g_node* gn, v_node* vn);
  d_node* add_d(void* ad, g_node* gn1, g_node* gn2, g_node* midg);
  d_node* add_d(void* ad, g_node* gn1, g_node* gn2, g_node* gn3, g_node* gn4);

  // Add equal parameter value constraint between two p_nodes
  d_node* add_d(void* ad, p_node* pn1, p_node* pn2);

  // Fix or unfix a geometry or a parameter node
  void fix(g_node* gn);
  void fix(p_node* pn);

  // Freeze or unfreeze a geometry
  void freeze(g_node* gn);

  // Add a reference node for pattern constraints
  g_node* add_pattern(void* ag, g_node* gnpat);

  // Move a g_node to a set
  DCM_logical move_to_set(g_node* gn, g_node* setgn);

  // Return the p_node for a given parametric or ellipse
  p_node* parameter_node(void* ap, g_node* gn, d_node* dn);

  // Erasing data
  void erase(g_node* gn);
  void erase(d_node* dn);
  void erase(r_node* rn);
  void erase(v_node* vn);
  void erase(e_node* en);
  void erase(p_node* pn);

  // 3. Variables and equations

  // Add simple variable
  v_node* add_v(void* av);

  // Change a dimension into a variable dimension
  v_node* add_v(void* av, d_node* dn);
  v_node* add_v(void* av, r_node* rn);

  // Add equation with Frustum pointer, value or both
  e_node* add_e(void* ae);
  e_node* add_e(double c);
  e_node* add_e(void* ae, double c);

  // Add variable to an equation
  DCM_logical add_v_to_e(void* ac, e_node* en, v_node* vn);

  // Add variable with specific coefficient value
  DCM_logical add_v_to_e(double cf, e_node* en, v_node* vn);

  // Add geometry to an equation
  DCM_logical add_g_to_e(void* ac, e_node* en, g_node* gn);

  // Add parameter node to an equation
  DCM_logical add_p_to_e(void* v, e_node* en, p_node* pn);

  // 4. Enquiring status and other information

  // Individual node status
  g_node_status status(g_node* gn);
  d_node_status status(d_node* dn);
  d_node_status status(r_node* rn);
  d_node_status status(e_node* en);
  g_node_status status(v_node* vn);
  g_node_status status(p_node* pn);

  // Return more information about underdefined geometry
  int underdefined_status(g_node* gn);

  // Return current transformation on a geometry
  int transform(g_node* gn, double mat[3][3], double* r_offset=DCM_NULL, double* min_r_offset=DCM_NULL, double* scale=DCM_NULL);

  int transform_from_initial(g_node* gn, double mat[3][3], double* r_offset=DCM_NULL, double* min_r_offset=DCM_NULL, double* scale=DCM_NULL);

  // Return current value of variable
  double value(v_node* vn);

  // Return current help point position
  void help_point(g_node* gn, d_node* dn, double* loc);

  // Return current help parameter value
  double help_parameter(g_node* gn, d_node* dn);

  // Return degrees of freedom information
  void constraint_balance(int* d_of_f, int* constraints, int* rigid_body);

  // Return evaluation type information
  DCM_evaluation_type last_evaluation_type();
  DCM_evaluation_type last_evaluation_type(g_node* gn);
  DCM_evaluation_type last_evaluation_type(d_node* dn);
  DCM_evaluation_type last_evaluation_type(r_node* rn);
  DCM_evaluation_type last_evaluation_type(e_node* en);
  DCM_evaluation_type last_evaluation_type(v_node* vn);
  DCM_evaluation_type last_evaluation_type(p_node* pn);

  // 5. Model evaluation

  // Evaluate the model
  DCM_evaluation_type evaluate(int ng = 0, g_node** gn = DCM_NULL, DCM_solving_mode mode = DCM_STANDARD_SOLVE);

  // Incremental evaluation
  DCM_evaluation_type re_evaluate(int ng = 0, g_node** gn = DCM_NULL, DCM_logical calc_status = DCM_FALSE, DCM_solving_mode mode = DCM_STANDARD_SOLVE);

  // Move geometry and then evaluate preserving original chiralities
  DCM_m_and_e_outcome move_and_evaluate(int n_geom, 
                                        g_node** gn,
                                        double (**mat)[3],
                                        double* rad = DCM_NULL,
                                        double* rad_2 = DCM_NULL,
                                        DCM_solving_mode =
                                        DCM_WEIGHTED_STANDARD_SOLVE);

  // Indicate that a value has changed - used by re_evaluate
  void changed(g_node* gn, DCM_changed_longevity longevity);
  void changed(d_node* dn, DCM_changed_longevity longevity);
  void changed(r_node* rn, DCM_changed_longevity longevity);
  void changed(e_node* en, DCM_changed_longevity longevity);

  // Indicate that incremental evaluation should not be used
  void reset(DCM_logical cancel_chirality = DCM_FALSE);

  // Indicate that incremental evaluation should not
  // be used for a particular node's partition only
  void reset(g_node* gn);
  void reset(d_node* dn);
  void reset(r_node* rn);
  void reset(e_node* en);
  void reset(v_node* vn);
  void reset(p_node* pn);

  // Change chirality during next evaluation
  DCM_chirality_status change_chirality(d_node* dn, g_node* gn1 = DCM_NULL, g_node* gn2 = DCM_NULL);

  // Restore model to state prior to evaluation or dragging
  void undo_evaluation(DCM_undo_mode um);

  // 6. Dragging geometry

  DCM_evaluation_type dynamic_evaluate(int n_geom, g_node** gn,
                                       double (**mat)[3], double* rad,
                                       DCM_dragging_transformation* dragt,
                                       DCM_dragging_result* res,
                                       DCM_dragging_option opt = DCM_DRAG_POSSIBLE,
                                       DCM_solving_mode = DCM_MINIMUM_MOVE_SOLVE);

  // 7. Autodimensioning and autoconstraining

  // Generate dimensions to make the model as well defined as possible
  DCM_autodim_status autodimension();

  // Select classes of dimensions that autodimension will consider
  void add_autodimension_mask(DCM_autodim_g_type g1t,
                              DCM_autodim_g_type g2t,
                              DCM_autodim_d_type dt, DCM_autodim_mask_option mo,
                              int n_gnodes = 0, g_node** g_array = DCM_NULL,
                              g_node** g_array2 = DCM_NULL,
                              double* dir = DCM_NULL, g_node* gdir = DCM_NULL);

  // Generate constraints that can be added to the model
  void autoconstrain(double tol_lin, double tol_ang,
                     int mask,
                     g_node** g_from, int n_from,
                     g_node** g_region, int n_region,
                     g_node** g_preferred, int n_preferred,
                     g_node** g_sym_axes, int n_sym_axes,
                     g_node** g_ed_from = DCM_NULL, int n_ed_from = 0,
                     g_node** g_ed_to = DCM_NULL, int n_ed_to = 0);

  // Deduce constraints from geometry positions
  int deduce_constraints(double tol_lin, double tol_ang, DCM_d_type dt);
  int deduce_constraints(double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn);
  int deduce_constraints(double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2);
  int deduce_constraints(double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2, g_node* gn3);
  int deduce_constraints(double tol_lin, double tol_ang, DCM_d_type dt, g_node* gn1, g_node* gn2, g_node* gn3, g_node* gn4);

  // 8. Pre-evaluate checking of dimensions

  // Check whether a dimension can be added without making the system
  // overconstrained

  // DCM will enquire dimension information via the Frustum

  DCM_check_result check(void* ad, g_node* gn1, g_node* gn2 = DCM_NULL, g_node* gn3 = DCM_NULL, g_node* gn4 = DCM_NULL);

  // No application dimension information needs to be created
  DCM_check_result check(DCM_d_type dt, g_node* gn1, g_node* gn2 = DCM_NULL, g_node* gn3 = DCM_NULL, g_node* gn4 = DCM_NULL);

  // This one is for a directed distance enquiry
  DCM_check_result check(g_node* gn1, g_node* gn2, double dir[2]);

  // 9. Model enquiry

  // The following functions return pointers to nodes of the specified
  // type within the DCM and the corresponding application pointers.
  int list_g_nodes(int ng = 0, g_node** gna = DCM_NULL, void** aga = DCM_NULL);
  int list_d_nodes(int nd = 0, d_node** dna = DCM_NULL, v_node** vna = DCM_NULL, void** ada = DCM_NULL);
  int list_r_nodes(int nr = 0, r_node** rna = DCM_NULL, v_node** vna = DCM_NULL, void** ara = DCM_NULL);
  int list_e_nodes(int ne = 0, e_node** ena = DCM_NULL, void** app = DCM_NULL);
  int list_v_nodes(int nv = 0, v_node** vna = DCM_NULL, void** app = DCM_NULL);
  int list_p_nodes(int np = 0, p_node** pna = DCM_NULL, void** app = DCM_NULL);

  // The following functions return the application pointer corresponding
  // to the given node within the DCM
  void* application_pointer(g_node* gn);
  void* application_pointer(d_node* gn);
  void* application_pointer(r_node* gn);
  void* application_pointer(e_node* gn);
  void* application_pointer(v_node* gn);
  void* application_pointer(p_node* gn);

  // The following functions return the nodes associated to a given node.
  // get_x_of_y take an input node of type y and output nodes of type x.

  // 1 - Functions for returning nodes associated with a given g_node
  int get_g_of_g(g_node* gn, int ng = 0, g_node** gna = DCM_NULL, void** aga = DCM_NULL);
  int get_d_of_g(g_node* gn, int nd = 0, d_node** dna = DCM_NULL, void** ada = DCM_NULL);
  int get_r_of_g(g_node* gn, int nr = 0, r_node** rna = DCM_NULL, void** ara = DCM_NULL);
  int get_e_of_g(g_node* gn, int ne = 0, e_node** ena = DCM_NULL, void** aea = DCM_NULL);
  int get_p_of_g(g_node* gn, int np = 0, p_node** pna = DCM_NULL, void** apa = DCM_NULL);
  int get_s_of_g(g_node* gn, g_node** set = DCM_NULL, void** as=DCM_NULL);

  // 2 - Functions for returning nodes associated with a given d_node
  int get_g_of_d(d_node* dn, int ng = 0, g_node** gna = DCM_NULL, void** aga = DCM_NULL);
  int get_v_of_d(d_node* dn, v_node** vn = DCM_NULL, void** av=DCM_NULL);
  int get_p_of_d(d_node* dn, int np = 0, p_node** pna = DCM_NULL, void** apa = DCM_NULL);

  // 3 - Functions for returning nodes associated with a given r_node
  int get_g_of_r(r_node* rn, g_node** gn = DCM_NULL, void** ag=DCM_NULL);
  int get_v_of_r(r_node* rn, v_node** vn = DCM_NULL, void** av=DCM_NULL);

  // 4 - Functions for returning nodes associated with a given e_node
  int get_g_of_e(e_node* en, int ng = 0, g_node** gna = DCM_NULL, void** aga = DCM_NULL);
  int get_v_of_e(e_node* en, int nv = 0, v_node** vna = DCM_NULL, void** ava = DCM_NULL);
  int get_p_of_e(e_node* en, int np = 0, p_node** pna = DCM_NULL,
    void** apa = DCM_NULL);

  // 5 - Functions for returning nodes associated with a given v_node
  int get_r_of_v(v_node* vn, r_node** rn = DCM_NULL, void** ad=DCM_NULL);
  int get_d_of_v(v_node* vn, int nd = 0, d_node** dna = DCM_NULL, void** ada = DCM_NULL);
  int get_e_of_v(v_node* vn, int ne = 0, e_node** ena = DCM_NULL, void** aea = DCM_NULL);

  // 6 - Functions for returning nodes associated with a given p_node
  int get_d_of_p(p_node* pn, int nd = 0, d_node** dna = DCM_NULL, void** ada = DCM_NULL);
  int get_g_of_p(p_node* pn, g_node** gn = DCM_NULL, void** ag=DCM_NULL);
  int get_e_of_p(p_node* pn, int ne = 0, e_node** ena = DCM_NULL, void** aea = DCM_NULL);

  // 10. SPLINES

  // Add a spline curve
  g_node* add_spline_g(void* ag, DCM_bs_data* spline_data, DCM_bs_status* status);

  // Modify the properties of a spline
  DCM_bs_status update_spline(g_node* sgn,DCM_bs_data* spline_data);

  // Enquire the properties of a spline
  DCM_bs_status enquire_spline(g_node* sgn,DCM_bs_data* spline_data);

  // Apply a transform to a spline
  DCM_bs_status transform_spline(g_node* sgn, double mat [3][3]);

  // Enquire the parameter limits of a spline
  DCM_bs_status spline_parameter_limits(g_node* sgn,
    double* min, double* max);

  // Enquire the position and derivatives of a spline at the given parameter
  DCM_bs_status spline_evaluator(g_node* sgn, double t, int n_der, DCM_discontinuity_side side, double* c_array);

  // Return the number of discontinuities in the nth derivative
  // and their parameters
  DCM_bs_status spline_discontinuities(g_node* sgn, int nth_der, int* n_discons, double* discons);

  // 11. Testing and debugging

  // Write a debug transmit file
  DCM_logical debug_xmit(const char* f_name = "dcmdebug.xmt", int p_segs = 10);

  // Write all interface and Frustum calls and data
  // to the specified file, given by name
  DCM_logical journal_by_name(const char* file_name, 
                              unsigned int options = DCM_JOU_OPT_ON | DCM_JOU_OPT_XMIT | DCM_JOU_OPT_XMIT_START,
                              int p_segs = 10);

  // 12. Miscellaneous

  // Change the Frustum void* pointer
  void change_pointer(g_node* gn, void* ag);
  void change_pointer(d_node* dn, void* ad);
  void change_pointer(r_node* rn, void* ad);
  void change_pointer(v_node* vn, void* av);
  void change_pointer(e_node* en, void* ae);
  void change_pointer(p_node* pn, void* ap);

  // Get the alignment of a dimensional constraint (to be called after solving) 
  HRESULT get_alignment(d_node* dn, SOLVER_alignment & align);

  // Get the half space of a dimensional constraint for one of the argument geometry (to be called after solving) 
  HRESULT get_half_space(d_node* dn, g_node* gn, SOLVER_half_space & hs);

  // Get the connex components of a constraint network
  HRESULT get_connex_component(CATConstraintSolver* ipCS, int n_geom, g_node ** iNonCuttingElements, CATListPV & oListOfConnexGeometries, CATListPV & oListOfConnexConstraints);

  // Get the variable associated to several dimensional distance (for equal length distances)
  v_node* add_distance_equality(CATConstraintSolver* ipCS, void* ad, int ndist, d_node** dn, int nrad, r_node** rn);


  // 13. Obsolete functions - retained for compatibility

  // The functions below have been superseded by new functions but are
  // retained for compatibility reasons.
  // New applications should not these functions.

  // Replaced by a new function of same name and arguments but slightly
  // different functionality.  This function did an undo to the initial
  // position but new function does an undo to the previous position.
  DCM_logical old_re_evaluate(int ng = 0, g_node** gn = DCM_NULL,
                              DCM_logical calc_status = DCM_FALSE,
                              DCM_solving_mode mode = DCM_STANDARD_SOLVE);

  // The following have been superseded by dynamic_evaluate.
  DCM_logical old_transform_and_evaluate(int n_geom, g_node** gn,
                                         double mat [3][3], double* rad,
                                         DCM_dragging_option opt = DCM_DRAG_POSSIBLE,
                                         DCM_dragging_result* res = DCM_NULL,
                                         DCM_solving_mode = DCM_MINIMUM_MOVE_SOLVE);
  DCM_logical old_transform_and_evaluate(int n_geom, g_node** gn,
                                         double (**mat)[3], double* rad,
                                         DCM_dragging_option opt = DCM_DRAG_POSSIBLE,
                                         DCM_dragging_result* res = DCM_NULL,
                                         DCM_solving_mode = DCM_MINIMUM_MOVE_SOLVE);
  DCM_logical old_transform_and_evaluate(int n_geom, g_node** gn,
                                         double (**mat)[3], double* rad,
                                         DCM_dragging_transformation* dragt,
                                         DCM_dragging_option opt = DCM_DRAG_POSSIBLE,
                                         DCM_dragging_result* res = DCM_NULL,
                                         DCM_solving_mode = DCM_MINIMUM_MOVE_SOLVE);

  // Superseded by the function set_option
  void set_non_algebraic(DCM_logical non_alg);

  // Superseded by journal_by_name, journal_by_ptr
  DCM_logical journal(const char* file_name = "dcm.jou");

  int is_solved_by();

  // start fcx temporary debug
  char TrStr[1000];
  char TrStr2[200];
  char TrStr3[200];
  char TrStr4[200];
  void Trace(int niveau, char *iString);
  void g_node_status_string(int n, char * s);
  void d_node_status_string(int n, char * s);
  void DCM_evaluation_type_string(int n, char * s);
  void DCM_m_and_e_outcome_string(int n, char * s);
  void DCM_solving_mode_string(int n, char * s);
  void DCM_logical_string(int n, char * s);
  void DCM_chirality_status_string(int n, char * s);
  void DCM_undo_mode_string(int n, char * s);
  void DCM_dragging_option_string(int n, char * s);
  // end fcx temporary debug

private:
  CATDimensionSystem2(const CATDimensionSystem2&);
  void operator=(const CATDimensionSystem2&);

  CATConstraintSolver *_Solver;
  dimension_system      *_DCM;
  void *_application_pointer;
};

//-----------------------------------------------------------------------

#endif
#endif
