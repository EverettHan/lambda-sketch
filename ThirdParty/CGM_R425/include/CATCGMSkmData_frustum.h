#ifndef FRUSTUM_H
#define FRUSTUM_H

#if defined(CATIAR215) || defined(CATIAV5R29)
#include "CATCGMSkmDataTypes.h"
#else
#include "dcmtypes.h"
#endif

typedef DCM_g_type (*DCM_g_identify_function)(
		void* geom);

typedef void (*DCM_point_point_function)(
		double point[2], void* geom);

typedef void (*DCM_line_point_function)(
		double point[2], void* geom);	

typedef void (*DCM_line_direction_function)(
		double dir[2], void* geom);

typedef void (*DCM_circle_center_function)(
		double point[2], void* geom);

typedef double (*DCM_circle_radius_function)(
		void* geom);

typedef void (*DCM_ellipse_center_function)(
		double point[2], void* geom);

typedef void (*DCM_ellipse_direction_function)(
		double dir[2], void* geom);

typedef double (*DCM_ellipse_major_radius_function)(
		void* geom);

typedef double (*DCM_ellipse_minor_radius_function)(
		void* geom);
	
typedef DCM_allow_zero_radius (*DCM_circle_allow_zero_radius_function)(
		void* geom);

typedef DCM_allow_circle_inversion (*DCM_circle_allow_inversion_function)(
		void* geom);

typedef DCM_d_type (*DCM_dimension_type_function)(
		void* dim);

typedef double (*DCM_dimension_value_function)(
		void* dim);

typedef DCM_logical (*DCM_dimension_point_function)(
		double hpoint[2], void* dim, void* geom);

typedef DCM_logical (*DCM_equal_distance_dimension_point_function)(
		double hpoint[2], void* dim, void* geom1, void* geom2);

typedef void (*DCM_dimension_point_update_function)(
		double hpoint[2], void* dim, void* geom);

typedef void (*DCM_equal_distance_dimension_point_update_function)(
		double hpoint[2], void* dim, void* geom1, void* geom2);

typedef DCM_directed_type (*DCM_directed_distance_function)(
		void* dim, double dir[2], void** gn);

typedef int (*DCM_pattern_multiplier_function)(
		void* dim, void* geom1, void* geom2);

typedef DCM_diamond_type (*DCM_resolve_zero_diamond_function)(
		void* line1, void* line2, 
		void* point1, void* point2,
    DCM_diamond_type deduced);

typedef DCM_ed_alignment
	(*DCM_equal_derivative_alignment_function)(void* dim);

typedef DCM_tan_alignment (*DCM_tangent_alignment_function)(void* dim);

typedef DCM_transform_bias (*DCM_g_transform_bias_function)(
		void* geom, double* weight);

typedef DCM_d_rigidity (*DCM_dimension_rigid_function)(void* dim);

typedef void (*DCM_transform_function)(
		double mat[3][3], void* geom);

typedef void (*DCM_scale_transform_function)(
		double scale, void* geom);

typedef void (*DCM_set_radius_function)(
		double radius, void* geom);

typedef void (*DCM_set_major_radius_function)(
		double maj_radius, void* geom);

typedef void (*DCM_set_minor_radius_function)(
		double min_radius, void* geom);

typedef void (*DCM_g_status_function)(
		g_node_status old_status, g_node_status new_status, void* geom);

typedef void (*DCM_new_underdefined_status_function)(
		int old_status, int new_status, void* geom);

typedef void (*DCM_d_status_function)(
		d_node_status old_status, d_node_status new_status, void* dim);

typedef void (*DCM_circle_inverted)(void* geom);

typedef DCM_logical (*DCM_parametric_limits_function)(
		double *up, double *low, void* geom);

typedef double (*DCM_parametric_period_function)(
		void* geom);

typedef void (*DCM_parametric_direction_function)(
		double dir[2], void* geom);

typedef void (*DCM_parametric_evaluator_function)(
		double point[2], double p1[2], double p2[2], 
		void* geom, double t);

typedef int (*DCM_parametric_n_discons_function)(
		void* geom);

typedef void (*DCM_parametric_discon_data_function)(
		double* t, double point[2], double p1[2], double p2[2],
		void* geom, int dcon_indx, DCM_discontinuity_side side);

typedef DCM_pn_discon_side (*DCM_p_node_discon_side_function)(
		void* ap);

typedef DCM_para_ext (*DCM_parametric_extension_data_function)(
		DCM_para_ext_type* type,
		DCM_para_ext_start_type* start_type,
		DCM_para_ext_end_type* end_type,
		void* geom, DCM_para_ext_end end);

typedef void (*DCM_parametric_extension_parameters_function)(
		double* start_parameter, double* end_parameter,
		void* geom, DCM_para_ext_end end);

typedef void (*DCM_parametric_extension_evaluator_function)(
		double point[2], double p1[2], double p2[2], 
		void* geom, double t, DCM_para_ext_end end);

typedef void (*DCM_parametric_regenerate_function)(
		void* geom);

typedef DCM_logical (*DCM_parametric_undo_regenerate_function)(
			void* geom);

typedef double (*DCM_dimension_parameter_function)(
		void* dim, void* geom);

typedef void (*DCM_dimension_parameters_function)(
		void* dim,double t[2]);

typedef void (*DCM_dimension_parameter_update_function)(
		double hpar, void* dim, void* geom);

typedef void (*DCM_dimension_parameters_update_function)(
		void* dim,double t[2]);

typedef DCM_ellipse_parameter (*DCM_ellipse_dimension_parameter_function)(
		void* dim, void* geom, double* t);

typedef void (*DCM_p_status_function)(
		g_node_status old_status, g_node_status new_status, void* ap);

typedef void (*DCM_spline_update_function)(void* geom, unsigned int m);

typedef void (*DCM_spline_changed_function)(
		void* geom);

typedef void (*DCM_spline_status_function)(
		void* geom);

typedef DCM_offset_side (*DCM_offset_orientation_function)(
		void* off_g, void* parent_g);

typedef double (*DCM_offset_distance_function)(
		void* off_g, void* parent_g);

typedef void (*DCM_update_offset_data_function)(
		void* off_g, void* parent_g,
		DCM_offset_side o_side, double offset, int mask);

typedef double (*DCM_variable_start_value_function)(
		void* var);

typedef DCM_var_dist_sign (*DCM_variable_dist_start_sign_function)(
		void* var);

typedef DCM_variable_angle_return (*DCM_variable_angle_value_function)(
		void* var, double* val);

typedef void (*DCM_variable_new_value_function)(
		double val, void* var);

typedef DCM_e_type (*DCM_equation_type_function)(
		void* eq);

typedef double (*DCM_equation_constant_value_function)(
		void* eq);

typedef double (*DCM_equation_coefficient_value_function)(
		void* eq, void* var, void* coeff);

typedef DCM_equation_status (*DCM_equation_residual_function)(
		void* eq, double* residual_value);

typedef DCM_equation_status (*DCM_equation_derivative_value_function)(
		void* eq, void* var, void* coeff, double* deriv);

typedef DCM_equation_status (*DCM_equation_p_node_derivative_value_function)(
		void* eq, void* var, void* coeff, double* deriv);

typedef DCM_logical (*DCM_inequality_minimum_function)(
		double* min, void* eq);
typedef DCM_logical (*DCM_inequality_maximum_function)(
		double* max, void* eq);

typedef void (*DCM_v_status_function)(
		g_node_status old_status, g_node_status new_status, void* geom);

typedef void (*DCM_e_status_function)(
		d_node_status old_status, d_node_status new_status, void* dim);

typedef double (*DCM_autodim_weight_function)(
		DCM_d_type type, double value,
		void* geom1, void* geom2,    
		double hpt1[2], double hpt2[2],	
		double hpar1, double hpar2	
		);

typedef double (*DCM_autodim_dir_weight_function)(
		DCM_directed_type type, double value,
		void* geom1, void* geom2,         	
		double* dir, void* gl,     
		double hpt1[2], double hpt2[2],	
		double hpar1, double hpar2   
		);

typedef void (*DCM_automatic_dimension_function)(
		DCM_d_type type, double value,
		void* gn1, void* gn2,         	
		void* geom1, void* geom2,    
		double hpt1[2], double hpt2[2],
		double hpar1, double hpar2   
		);

typedef void (*DCM_automatic_dir_dimension_function)(
		DCM_directed_type type, double value,
		void* gn1, void* gn2,         
		void* geom1, void* geom2,  
		double dir[2], 
		void* gnl, void* geoml, 
		double hpt1[2], double hpt2[2], 
		double hpar1, double hpar2);  

typedef double (*DCM_autocon_weight_function)(
		DCM_d_type type,		
		void* gn1, void* gn2,	
		void* geom1, void* geom2,   
		double hpt1[2], double hpt2[2],	
		double hpar1, double hpar2	
		);

typedef double (*DCM_autocon_weight3_function)(
		DCM_d_type type,	
		void* gn1, void* gn2, void* gn3,
		void* geom1, void* geom2, void* geom3	
		);

typedef void (*DCM_automatic_class_function)(
		DCM_d_type type,	
		int n_gn, 
		void** gn_array,	 
		void** ag_array);	 

typedef void (*DCM_automatic_constraint_function)(
		DCM_d_type type,
		void* gn1, void* gn2,  
		void* geom1, void* geom2,
		double hpt1[2], double hpt2[2],	
		double hpar1, double hpar2  
		);

typedef void (*DCM_automatic_constraint3_function)(
		DCM_d_type type,
		void* gn1, void* gn2, void* gn3,
		void* geom1, void* geom2, void* geom3 
		);

typedef void (*DCM_deduced_class_function)(
		DCM_d_type type,	
		int n_gn,	
		void** gn_array,	
		void** ag_array);	

typedef void (*DCM_deduced_constraint_function)(
		DCM_d_type type, 			
		void* gn1, void* gn2, void* gn3,
		void* geom1, void* geom2, void* geom3,
		double hpt1[2], double hpt2[2],	
		double hpar1, double hpar2);   

typedef void (*DCM_deduced_constraint4_function)(
		DCM_d_type type,
		void* gn1, void* gn2,   
		void* gn3, void* gn4, 
		void* geom1, void* geom2,  
		void* geom3, void* geom4);

typedef DCM_logical (*DCM_abort_function)(void);

typedef void (*DCM_erased_node_function)(
		DCM_node_type type, void* node_ptr, void* app_ptr);

typedef void (*DCM_debug_message_function)(
		DCM_debug_message_type, const char* message, const char* details);

#ifdef __cplusplus
extern "C" {
#endif
void DCM_license_message(char* message, char* ref_string);

#ifdef __cplusplus
}
#endif

typedef struct DCM_frustum_functions
	{
	DCM_g_identify_function g_identify;
	DCM_point_point_function point_point;
	DCM_line_point_function line_point;
	DCM_line_direction_function line_direction;
	DCM_circle_center_function circle_center;
	DCM_circle_radius_function circle_radius;
	DCM_ellipse_center_function ellipse_center;
	DCM_ellipse_direction_function ellipse_direction;
	DCM_ellipse_major_radius_function ellipse_major_radius;
	DCM_ellipse_minor_radius_function ellipse_minor_radius;
	DCM_circle_allow_zero_radius_function circle_allow_zero_radius;
	DCM_circle_allow_inversion_function circle_allow_inversion;
	DCM_g_transform_bias_function g_transform_bias;
	DCM_dimension_type_function dimension_type;
	DCM_dimension_value_function dimension_value;
	DCM_dimension_point_function dimension_point;
	DCM_dimension_point_update_function dimension_point_update;
	DCM_equal_distance_dimension_point_function equal_distance_dimension_point;
	DCM_equal_distance_dimension_point_update_function equal_distance_dimension_point_update;
	DCM_directed_distance_function directed_distance;
	DCM_pattern_multiplier_function pattern_multiplier;
	DCM_resolve_zero_diamond_function resolve_zero_diamond;
	DCM_equal_derivative_alignment_function equal_derivative_alignment;
	DCM_tangent_alignment_function tangent_alignment;
	DCM_dimension_rigid_function dimension_rigid;
	DCM_transform_function transform;
	DCM_scale_transform_function scale_transform;
	DCM_set_radius_function set_radius;
	DCM_set_major_radius_function set_major_radius;
	DCM_set_minor_radius_function set_minor_radius;
	DCM_g_status_function g_status;
	DCM_new_underdefined_status_function new_underdefined_status;
	DCM_d_status_function d_status;
	DCM_circle_inverted circle_inverted;
	DCM_parametric_limits_function parametric_limits;
	DCM_parametric_period_function parametric_period;
	DCM_parametric_direction_function parametric_direction;
	DCM_parametric_evaluator_function parametric_evaluator;
	DCM_parametric_n_discons_function parametric_n_discons;
	DCM_parametric_discon_data_function parametric_discon_data;
	DCM_p_node_discon_side_function p_node_discon_side;
	DCM_parametric_extension_data_function parametric_extension_data;
	DCM_parametric_extension_parameters_function parametric_extension_parameters;
	DCM_parametric_extension_evaluator_function parametric_extension_evaluator;
	DCM_parametric_regenerate_function parametric_regenerate;
	DCM_parametric_undo_regenerate_function parametric_undo_regenerate;
	DCM_dimension_parameter_function dimension_parameter;
	DCM_dimension_parameters_function dimension_parameters;
	DCM_dimension_parameter_update_function dimension_parameter_update;
	DCM_dimension_parameters_update_function dimension_parameters_update;
	DCM_ellipse_dimension_parameter_function ellipse_dimension_parameter;
	DCM_p_status_function p_status;
	DCM_spline_update_function spline_update;
	DCM_spline_changed_function spline_changed;
	DCM_spline_status_function spline_status;
	DCM_offset_orientation_function offset_orientation;
	DCM_offset_distance_function offset_distance;
	DCM_update_offset_data_function update_offset_data;
	DCM_variable_start_value_function variable_start_value;
	DCM_variable_dist_start_sign_function variable_dist_start_sign;
	DCM_variable_angle_value_function variable_angle_value;
	DCM_variable_new_value_function variable_new_value;
	DCM_equation_type_function equation_type;
	DCM_equation_constant_value_function equation_constant_value;
	DCM_equation_coefficient_value_function equation_coefficient_value;
	DCM_equation_residual_function equation_residual;
	DCM_equation_derivative_value_function equation_derivative_value;
	DCM_equation_p_node_derivative_value_function equation_p_node_derivative_value;
	DCM_inequality_minimum_function inequality_minimum;
	DCM_inequality_maximum_function inequality_maximum;
	DCM_v_status_function v_status;
	DCM_e_status_function e_status;
	DCM_autodim_weight_function autodim_weight;
	DCM_autodim_dir_weight_function autodim_dir_weight;
	DCM_automatic_dimension_function automatic_dimension;
	DCM_automatic_dir_dimension_function automatic_dir_dimension;
	DCM_autocon_weight_function autocon_weight;
	DCM_autocon_weight3_function autocon_weight3;
	DCM_automatic_class_function automatic_class;
	DCM_automatic_constraint_function automatic_constraint;
	DCM_automatic_constraint3_function automatic_constraint3;
	DCM_deduced_class_function deduced_class;
	DCM_deduced_constraint_function deduced_constraint;
	DCM_deduced_constraint4_function deduced_constraint4;
	DCM_abort_function abort;
	DCM_erased_node_function erased_node;
	DCM_debug_message_function debug_message; 
	} DCM_frustum_functions;


DCM_g_type DCM_g_identify(void* geom);
void DCM_point_point(double point[2], void* geom);
void DCM_line_point(double point[2], void* geom);	
void DCM_line_direction(double dir[2], void* geom);
void DCM_circle_center(double point[2], void* geom);
double DCM_circle_radius(void* geom);
void DCM_set_radius(double radius, void* geom);
void DCM_ellipse_center(double point[2], void* geom);
void DCM_ellipse_direction(double dir[2], void* geom);
double DCM_ellipse_major_radius(void* geom);
double DCM_ellipse_minor_radius(void* geom);
void DCM_set_major_radius(double maj_radius, void* geom);
void DCM_set_minor_radius(double min_radius, void* geom);
DCM_allow_zero_radius DCM_circle_allow_zero_radius(void* geom);
DCM_allow_circle_inversion DCM_circle_allow_inversion(void* geom);
void DCM_circle_inverted_notification(void* geom);
void DCM_transform(double mat[3][3], void* geom);
DCM_d_type DCM_dimension_type(void* dim);
double DCM_dimension_value(void* dim);
DCM_directed_type DCM_directed_distance(void* dim, double dir[2], void** gn);
DCM_logical DCM_dimension_point(double hpoint[2], void* dim, void* geom);
void DCM_dimension_point_update(double hpoint[2], void* dim, void* geom);
DCM_logical DCM_equal_distance_dimension_point(double hpoint[2], void* dim, void* geom1, void* geom2);
void DCM_equal_distance_dimension_point_update(double hpoint[2], void* dim, void* geom1, void* geom2);
int DCM_pattern_multiplier(void* dim, void* geom1, void* geom2);
DCM_logical DCM_parametric_limits(double *up, double *low, void* geom);
double DCM_parametric_period(void* geom);
void DCM_parametric_evaluator(double point[2], double p1[2], double p2[2], void* geom, double t);
void DCM_parametric_direction(double dir[2], void* geom);
void DCM_parametric_regenerate(void* geom);
DCM_logical DCM_parametric_undo_regenerate(void* geom);
double DCM_dimension_parameter(void* dim, void* geom);
void DCM_dimension_parameters(void* dim,double t[2]);
void DCM_dimension_parameter_update(double hpar, void* dim, void* geom);
void DCM_dimension_parameters_update(void* dim,double t[2]);
DCM_ellipse_parameter DCM_ellipse_dimension_parameter(void* dim,void* geom,double* t);
int DCM_parametric_n_discons(void* geom);
void DCM_parametric_discon_data(double* t, double point[2], double p1[2], double p2[2],
	void* geom, int dcon_indx, DCM_discontinuity_side side);
DCM_pn_discon_side DCM_p_node_discon_side(void* ap);
DCM_para_ext DCM_parametric_extension_data(DCM_para_ext_type*,
					   DCM_para_ext_start_type*,
					   DCM_para_ext_end_type*,
					   void*, DCM_para_ext_end);
void DCM_parametric_extension_parameters(double*,double*,void*,DCM_para_ext_end);
void DCM_parametric_extension_evaluator(double point[2], double p1[2], double p2[2],
					void* geom, double t,
					DCM_para_ext_end);
DCM_offset_side DCM_offset_orientation(void* off_g, void* parent_g);
double DCM_offset_distance(void* off_g, void* parent_g);
void DCM_update_offset_data(void* off_g, void* parent_g, DCM_offset_side o_side,
	double offset, int mask);
void DCM_spline_changed(void* geom);
double DCM_variable_start_value(void* var);
DCM_var_dist_sign DCM_variable_dist_start_sign(void* var);
void DCM_variable_new_value(double val, void* var);
DCM_variable_angle_return DCM_variable_angle_value(void* var, double* val);
DCM_e_type DCM_equation_type(void* eq);
double DCM_equation_constant_value(void* eq);
double DCM_equation_coefficient_value(void* eq, void* var, void* coeff);
DCM_equation_status DCM_equation_derivative_value(void* eq, void* var, void* coeff, double* deriv);
DCM_equation_status DCM_equation_p_node_derivative_value(void* eq, void* var, void* coeff,
	double* deriv);
DCM_equation_status DCM_equation_residual(void* eq, double* residual_value);
DCM_logical DCM_inequality_minimum(double* min, void* eq);
DCM_logical DCM_inequality_maximum(double* max, void* eq);
void DCM_g_status(g_node_status old_status, g_node_status new_status, void* geom);
void DCM_new_underdefined_status(int old_status, int new_status, void* geom);
void DCM_v_status(g_node_status old_status, g_node_status new_status, void* geom);
void DCM_d_status(d_node_status old_status, d_node_status new_status, void* dim);
void DCM_e_status(d_node_status old_status, d_node_status new_status, void* dim);
void DCM_p_status(g_node_status old_status, g_node_status new_status, void* ap);
DCM_logical DCM_abort(void);
DCM_diamond_type DCM_resolve_zero_diamond(void* line1, void* line2, void* point1, void* point2,
	DCM_diamond_type deduced);
DCM_ed_alignment DCM_equal_derivative_alignment(void* dim);
DCM_tan_alignment DCM_tangent_alignment(void* dim);
DCM_d_rigidity DCM_dimension_rigid(void* dim);
DCM_transform_bias DCM_g_transform_bias(void* geom, double* weight);
double DCM_autodim_weight(DCM_d_type type, double value, void* geom1, void* geom2,
	double hpt1[2], double hpt2[2], double hpar1, double hpar2);
double DCM_autodim_dir_weight(DCM_directed_type type, double value, void* geom1, void* geom2,
	double* dir, void* gl, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
void DCM_automatic_dimension(DCM_d_type type, double value, void* gn1, void* gn2,
	void* geom1, void* geom2, double hpt1[2], double hpt2[2], double hpar1, double hpar2);
void DCM_automatic_dir_dimension(DCM_directed_type type, double value, void* gn1, void* gn2,
	void* geom1, void* geom2, double dir[2], void* gnl, void* geoml, double hpt1[2], double hpt2[2],
	double hpar1, double hpar2);
double DCM_autocon_weight(DCM_d_type type, void* gn1, void* gn2,
	void* geom1, void* geom2, double hpt1tmp[2], double hpt2tmp[2],
	double hpar1, double hpar2);
double DCM_autocon_weight3(DCM_d_type type, void* gn1, void* gn2, void* gn3,
	void* geom1, void* geom2, void* geom3);
void DCM_automatic_class(DCM_d_type type, int n_gn, void** gn_array, void** ag_array);
void DCM_automatic_constraint(DCM_d_type type, void* gn1, void* gn2, void* geom1, void* geom2,
	double hpt1[2], double hpt2[2], double hpar1, double hpar2);
void DCM_automatic_constraint3(DCM_d_type type, void* gn1, void* gn2, void* gn3,
	void* geom1, void* geom2, void* geom3);
void DCM_deduced_class(DCM_d_type type, int n_gn, void** gn_array, void** ag_array);
void DCM_deduced_constraint(DCM_d_type type, void* gn1, void* gn2, void* gn3,
	void* geom1, void* geom2, void* geom3, double hpt1[2], double hpt2[2],
	double hpar1, double hpar2);
void DCM_deduced_constraint4(DCM_d_type type, void* gn1, void* gn2, void* gn3, void* gn4,
	void* geom1, void* geom2, void* geom3, void* geom4);
void DCM_erased_node(DCM_node_type type, void* node_ptr, void* app_ptr);
void DCM_scale_transform(double scale, void* geom);
void DCM_spline_status(void* geom);
void DCM_spline_update(void* geom, unsigned int mask);
void DCM_debug_message(DCM_debug_message_type, const char* message, const char* details);

#endif
