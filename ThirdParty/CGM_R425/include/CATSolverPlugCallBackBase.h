// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATSolverPlugCallBackBase.h
// Header definition of CATSolverPlugCallBackBase
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2004  Creation:                Evgueni ROUKOLEEV.
//===================================================================
#ifndef CATSolverPlugCallBackBase_H
#define CATSolverPlugCallBackBase_H

#include "CATIAV5Level.h"
#include "Plug2DBase.h"
#if defined(CATIAR215) || defined(CATIAV5R29)
#include "CATCGMSkmDataTypes.h"
#else
#include "dcmtypes.h"
#endif
#include "solvertypes.h"
#include "CATErrorDef.h"

#define KUB_RegenerateWithRc

//-----------------------------------------------------------------------

/**
 * Describe your class here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedByPlug2DBase CATSolverPlugCallBackBase
{
public:
  CATSolverPlugCallBackBase();
  virtual ~CATSolverPlugCallBackBase();

  static DCM_g_type DCM_g_identify(void* ag);
  static void DCM_point_point(double pt[2], void* ag);
  static void DCM_line_point(double pt[2], void* ag);
  static void DCM_line_direction(double dir[2], void* ag);
  static void DCM_circle_center(double pt[2], void* ag);
  static double DCM_circle_radius(void* ag);
  static void DCM_set_radius(double rad, void* ag);
  static void DCM_ellipse_center(double pt[2], void* ag);
  static void DCM_ellipse_direction(double dir[2], void* ag);
  static double DCM_ellipse_major_radius(void* ag);
  static double DCM_ellipse_minor_radius(void* ag);
  static void DCM_set_major_radius(double maj, void* ag);
  static void DCM_set_minor_radius(double min, void* ag);
  static void DCM_transform(double mat[3][3], void* ag);
  static DCM_d_type DCM_dimension_type(void* ad);
  static double DCM_dimension_value(void* ad);
  static DCM_directed_type DCM_directed_distance(void* ad, double dir[2], void** gn);
  static DCM_logical DCM_dimension_point(double hpt[2], void* ad, void* ag);
  static void DCM_dimension_point_update(double hpt[2], void* ad, void* ag);
  static int DCM_pattern_multiplier(void* ad, void* ag1, void* ag2);
  static DCM_logical DCM_parametric_limits(double* t_up, double* t_low, void* ag);
  static double DCM_parametric_period(void* ag);
  static void DCM_parametric_evaluator(double pt[2], double p1[2], double p2[2], void* ag, double t);
  static void DCM_parametric_direction(double dir[2], void* ag);
  static void DCM_parametric_regenerate(void* ag);
  static HRESULT DCM_parametric_regenerate_rc(void* ag);
  static double DCM_dimension_parameter(void* ad, void* ag);
  static void DCM_dimension_parameter_update(double hpar, void* ad, void* ag);
  static void DCM_dimension_parameters(void* ad, double oParams[2]); // te9 12.2011
  static void DCM_dimension_parameters_update(void* ad, double iParams[2]); // te9 12.2011
  static int DCM_parametric_n_discons(void* ag);
  static void DCM_parametric_discon_data(double* t, double pt[2], double p1[2], double p2[2], void* ag, int dcon_indx, DCM_discontinuity_side side);
  static DCM_offset_side DCM_offset_orientation(void* off_g, void* parent_g);
  static double DCM_offset_distance(void* off_g, void* parent_g);
  static void DCM_update_offset_data(void* off_g, void* parent_g, DCM_offset_side o_side, double offset, int mask);
  static void DCM_spline_changed(void* ag);
  static double DCM_variable_start_value(void* av);
  static DCM_var_dist_sign DCM_variable_dist_start_sign(void* av);
  static void DCM_variable_new_value(double val, void* av);
  static DCM_e_type DCM_equation_type(void* ae);
  static double DCM_equation_constant_value(void* ae);
  static double DCM_equation_coefficient_value(void* ae, void* av, void* ac);
  static DCM_equation_status DCM_equation_derivative_value(void* ae, void* av, void* ac, double* df);
  static DCM_equation_status DCM_equation_p_node_derivative_value(void* ae, void* av, void* ac, double* df);
  static DCM_equation_status DCM_equation_residual(void* ae, double* residual_value);
  static DCM_logical DCM_inequality_minimum(double* min, void* ae);
  static DCM_logical DCM_inequality_maximum(double* max, void* ae);
  static void DCM_g_status(g_node_status old_status, g_node_status new_status, void* ag);
  static void DCM_new_underdefined_status(int old_status, int new_status, void* ag);
  static void DCM_v_status(g_node_status old_status, g_node_status new_status, void* ag);
  static void DCM_d_status(d_node_status old_status, d_node_status new_status, void* ad);
  static void DCM_e_status(d_node_status old_status, d_node_status new_status, void* ad);
  static void DCM_p_status(g_node_status old_status, g_node_status new_status, void* ap);
  static DCM_logical DCM_abort(void);
  static DCM_diamond_type DCM_resolve_zero_diamond(void* al1, void* al2, void* apt1, void* apt2, DCM_diamond_type deduced);
  static void DCM_license_message(char* message, char* ref_string);
  static double DCM_autodim_weight(DCM_d_type type, double value, void* ag1, void* ag2, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
  static double DCM_autodim_dir_weight(DCM_directed_type type, double value, void* ag1, void* ag2, double* dir, void* gl, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
  static void DCM_automatic_dimension(DCM_d_type type, double value, void* gn1, void* gn2, void* ag1, void* ag2, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
  static void DCM_automatic_dir_dimension(DCM_directed_type type, double value, void* gn1, void* gn2, void* ag1, void* ag2, double dir[2], void* gnl, void* agl, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
  static void DCM_automatic_class(DCM_d_type type, int n_gn, void** gn_array, void** ag_array);
  static void DCM_automatic_constraint(DCM_d_type type, void* gn1, void* gn2, void* ag1, void* ag2, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
  static void DCM_automatic_constraint3(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* ag1, void* ag2, void* ag3);
  static void DCM_deduced_class(DCM_d_type type, int n_gn, void** gn_array, void** ag_array);
  static void DCM_deduced_constraint(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* ag1, void* ag2, void* ag3, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
  static void DCM_deduced_constraint4(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* gn4, void* ag1, void* ag2, void* ag3, void* ag4);
  static void DCM_erased_node(DCM_node_type type, void* node_ptr, void* app_ptr);
  static void DCM_scale_transform(double sc, void* ag);
  static void DCM_spline_status(void* ag);
  static void DCM_spline_update(void* ag, unsigned int mask);
  static void DCM_debug_message(DCM_debug_message_type, const char* message, const char* details);
  
  // FCX 4.2010 : specific to CDS
  static SOLVER_alignment dimension_align(void* ad);
  static SOLVER_half_space dimension_half_space(void* ad, void* ag);

  // KUB, 5.2011
  static double evaluate_length(void *ad, double iStart, double iEnd);

  // FCX 09.2015 : to get the application name of an object
  static char* application_name(void* ipObj);

  // TE9 : 10/2016 : type des courbes dépendantes Sketcher
  static DCM_curve_type DCM_get_curve_type(void* ipCurve);

  //BF8 : recuperation des objets de la clothoide
  static void CDS_update_clothoide_data(void* clothoid, void *& oInitialPt, void *& oInitialTgt, void *& oInitialCircle, int& oInitialOrient, int& oInitialSide, void *& oFinalPt, void *& oFinalTgt, int& oFinalOrient, void *& oFinalCircle, double*& oA2, double*& oLength, double*& oRadius, double*& oAngle, double*& oShift, void *& oGeoFactory);

  // get offset data
  static void CDS_offset_data(void* g, double& oOffsetValue);

protected:
  static CATSolverPlugCallBackBase *_pBridge;

  virtual DCM_g_type _DCM_g_identify(void* ag) = 0;
  virtual void _DCM_point_point(double pt[2], void* ag) = 0;
  virtual void _DCM_line_point(double pt[2], void* ag) = 0;
  virtual void _DCM_line_direction(double dir[2], void* ag) = 0;
  virtual void _DCM_circle_center(double pt[2], void* ag) = 0;
  virtual double _DCM_circle_radius(void* ag) = 0;
  virtual void _DCM_set_radius(double rad, void* ag) = 0;
  virtual void _DCM_ellipse_center(double pt[2], void* ag) = 0;
  virtual void _DCM_ellipse_direction(double dir[2], void* ag) = 0;
  virtual double _DCM_ellipse_major_radius(void* ag) = 0;
  virtual double _DCM_ellipse_minor_radius(void* ag) = 0;
  virtual void _DCM_set_major_radius(double maj, void* ag) = 0;
  virtual void _DCM_set_minor_radius(double min, void* ag) = 0;
  virtual void _DCM_transform(double mat[3][3], void* ag) = 0;
  virtual DCM_d_type _DCM_dimension_type(void* ad) = 0;
  virtual double _DCM_dimension_value(void* ad) = 0;
  virtual DCM_directed_type _DCM_directed_distance(void* ad, double dir[2], void** gn) = 0;
  virtual DCM_logical _DCM_dimension_point(double hpt[2], void* ad, void* ag) = 0;
  virtual void _DCM_dimension_point_update(double hpt[2], void* ad, void* ag) = 0;
  virtual int _DCM_pattern_multiplier(void* ad, void* ag1, void* ag2) = 0;
  virtual DCM_logical _DCM_parametric_limits(double* t_up, double* t_low, void* ag) = 0;
  virtual double _DCM_parametric_period(void* ag) = 0;
  virtual void _DCM_parametric_evaluator(double pt[2], double p1[2], double p2[2], void* ag, double t) = 0;
  virtual void _DCM_parametric_direction(double dir[2], void* ag) = 0;
  virtual void _DCM_parametric_regenerate(void* ag) = 0;
#ifdef KUB_RegenerateWithRc
  virtual HRESULT _DCM_parametric_regenerate_rc(void* ag) = 0;
#endif
  virtual double _DCM_dimension_parameter(void* ad, void* ag) = 0;
  virtual void _DCM_dimension_parameter_update(double hpar, void* ad, void* ag) = 0;
  virtual void _DCM_dimension_parameters(void* ad, double oParams[2]) {oParams[0] = 0.; oParams[1] = 0.;}; // te9 12.2011
  virtual void _DCM_dimension_parameters_update(void* ad, double iParams[2]) {}; // te9 12.2011
  virtual int _DCM_parametric_n_discons(void* ag) = 0;
  virtual void _DCM_parametric_discon_data(double* t, double pt[2], double p1[2], double p2[2], void* ag, int dcon_indx, DCM_discontinuity_side side) = 0;
  virtual DCM_offset_side _DCM_offset_orientation(void* off_g, void* parent_g) = 0;
  virtual double _DCM_offset_distance(void* off_g, void* parent_g) = 0;
  virtual void _DCM_update_offset_data(void* off_g, void* parent_g, DCM_offset_side o_side, double offset, int mask) = 0;
  virtual void _DCM_spline_changed(void* ag) = 0;
  virtual double _DCM_variable_start_value(void* av) = 0;
  virtual DCM_var_dist_sign _DCM_variable_dist_start_sign(void* av) = 0;
  virtual void _DCM_variable_new_value(double val, void* av) = 0;
  virtual DCM_e_type _DCM_equation_type(void* ae) = 0;
  virtual double _DCM_equation_constant_value(void* ae) = 0;
  virtual double _DCM_equation_coefficient_value(void* ae, void* av, void* ac) = 0;
  virtual DCM_equation_status _DCM_equation_derivative_value(void* ae, void* av, void* ac, double* df) = 0;
  virtual DCM_equation_status _DCM_equation_p_node_derivative_value(void* ae, void* av, void* ac, double* df) = 0;
  virtual DCM_equation_status _DCM_equation_residual(void* ae, double* residual_value) = 0;
  virtual DCM_logical _DCM_inequality_minimum(double* min, void* ae) = 0;
  virtual DCM_logical _DCM_inequality_maximum(double* max, void* ae) = 0;
  virtual void _DCM_g_status(g_node_status old_status, g_node_status new_status, void* ag) = 0;
  virtual void _DCM_new_underdefined_status(int old_status, int new_status, void* ag) = 0;
  virtual void _DCM_v_status(g_node_status old_status, g_node_status new_status, void* ag) = 0;
  virtual void _DCM_d_status(d_node_status old_status, d_node_status new_status, void* ad) = 0;
  virtual void _DCM_e_status(d_node_status old_status, d_node_status new_status, void* ad) = 0;
  virtual void _DCM_p_status(g_node_status old_status, g_node_status new_status, void* ap) = 0;
  virtual DCM_logical _DCM_abort(void) = 0;
  virtual DCM_diamond_type _DCM_resolve_zero_diamond(void* al1, void* al2, void* apt1, void* apt2, DCM_diamond_type deduced) = 0;
  virtual void _DCM_license_message(char* message, char* ref_string) = 0;
  virtual double _DCM_autodim_weight(DCM_d_type type, double value, void* ag1, void* ag2, double hpt1[2], double hpt2[2], double hpar1, double hpar2) = 0;
  virtual double _DCM_autodim_dir_weight(DCM_directed_type type, double value, void* ag1, void* ag2, double* dir, void* gl, double hpt1[2], double hpt2[2], double hpar1, double hpar2) = 0;
  virtual void _DCM_automatic_dimension(DCM_d_type type, double value, void* gn1, void* gn2, void* ag1, void* ag2, double hpt1[2], double hpt2[2], double hpar1, double hpar2) = 0;
  virtual void _DCM_automatic_dir_dimension(DCM_directed_type type, double value, void* gn1, void* gn2, void* ag1, void* ag2, double dir[2], void* gnl, void* agl, double hpt1[2], double hpt2[2], double hpar1, double hpar2) = 0;
  virtual void _DCM_automatic_class(DCM_d_type type, int n_gn, void** gn_array, void** ag_array) = 0;
  virtual void _DCM_automatic_constraint(DCM_d_type type, void* gn1, void* gn2, void* ag1, void* ag2, double hpt1[2], double hpt2[2], double hpar1, double hpar2) = 0;
  virtual void _DCM_automatic_constraint3(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* ag1, void* ag2, void* ag3) = 0;
  virtual void _DCM_deduced_class(DCM_d_type type, int n_gn, void** gn_array, void** ag_array) = 0;
  virtual void _DCM_deduced_constraint(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* ag1, void* ag2, void* ag3, double hpt1[2], double hpt2[2], double hpar1, double hpar2) = 0;
  virtual void _DCM_deduced_constraint4(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* gn4, void* ag1, void* ag2, void* ag3, void* ag4) = 0;
  virtual void _DCM_erased_node(DCM_node_type type, void* node_ptr, void* app_ptr) = 0;
  virtual void _DCM_scale_transform(double sc, void* ag) = 0;
  virtual void _DCM_spline_status(void* ag) = 0;
  virtual void _DCM_spline_update(void* ag, unsigned int mask) = 0;
  virtual void _DCM_debug_message(DCM_debug_message_type, const char* message, const char* details) = 0;

  // FCX 4.2010 : specific to CDS
  virtual SOLVER_alignment _dimension_align(void* ad);
  virtual SOLVER_half_space _dimension_half_space(void* ad, void* ag);

  // KUB 5.2011
  virtual double _evaluate_length(void *ad, double iStart, double iEnd);

  // FCX 09.2015
  virtual char* _application_name(void* ipObj);

  // TE9 : 10/2016
  virtual DCM_curve_type _DCM_get_curve_type(void* ipCurve);

  // BF8
  virtual void _CDS_update_clothoide_data(
    void*   clothoid,
    void *& oInitialPt,
    void *& oInitialTgt,
    void *& oInitialCircle,
    int&    oInitialOrient,
    int&    oInitialSide,
    void *& oFinalPt,
    void *& oFinalTgt,
    int&    oFinalOrient,
    void *& oFinalCircle,
    double*& oA2,
    double*& oLength,
    double*& oRadius,
    double*& oAngle,
    double*& oShift,
	void *& oGeoFactory){};

  virtual void _CDS_offset_data(void* g, double& oOffsetValue);

private:
  CATSolverPlugCallBackBase(const CATSolverPlugCallBackBase&);
  void operator=(const CATSolverPlugCallBackBase&);
};

//-----------------------------------------------------------------------

#endif
