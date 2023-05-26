#ifndef DCMTYPES_H
#define DCMTYPES_H

#include <stdio.h>
#include "DSYExport.h"

#ifndef DCM_logical
#define DCM_logical int
#define DCM_TRUE 1
#define DCM_FALSE 0
#endif

#define DCM_NULL 0

#define DCM_EXPORT

#if defined(DCM_MAKE_DLL) && defined(DCM_NT)
#undef DCM_EXPORT
#define DCM_EXPORT DSYExport
#endif

#if (defined(DCM_DLL) || defined(DCM2_DLL)) && defined(DCM_NT)
#undef DCM_EXPORT
#define DCM_EXPORT DSYImport
#endif

typedef enum DCM_g_type {
	DCM_POINT,
	DCM_LINE,
	DCM_CIRCLE,
	DCM_ELLIPSE,
	DCM_PARAMETRIC,
	DCM_SPLINE,
	DCM_SCALABLE_SET,
	DCM_SET
	} DCM_g_type;

typedef enum DCM_d_type {
	DCM_DISTANCE = 0,
	DCM_ANGLE = 1,
	DCM_CONCENTRIC = 2,
	DCM_RADIUS = 3,
	DCM_PARALLEL = 4, 
	DCM_PERPENDICULAR = 5,
	DCM_COINCIDENT = 6,
	DCM_TANGENT = 7,
	DCM_IDENTICAL = 8,
	DCM_SYMMETRIC = 9,
	DCM_MAJOR_RADIUS = 10,
	DCM_MINOR_RADIUS = 11,
	DCM_EQUAL_RADIUS = 12,
	DCM_EQUAL_DISTANCE = 13,
	DCM_MIDPOINT = 14,
	DCM_DEPENDENCE = 15,
	DCM_PATTERNED = 16,
	DCM_EQUAL_PARAMETER = 17,
	DCM_NORMAL = 18,
	DCM_EQUAL_DIRECTION = 19,
	DCM_EQUAL_CURVATURE = 20,
	DCM_EQUAL_FIRST_DERIVATIVE = 21,
	DCM_EQUAL_SECOND_DERIVATIVE = 22,
	DCM_OFFSET = 23,
	DCM_SIMPLE_DEPENDENCE = 24,
	DCM_CURVE_LENGTH = 25
#ifdef GRIFFON_PROJECT
  ,
  DCM_PATTERNED_2D = 26,
  DCM_PATTERN_VALUE = 27,
  DCM_PATTERN_2D_VALUE_1 = 28,
  DCM_PATTERN_2D_VALUE_2 = 29
#endif
	} DCM_d_type;

typedef enum DCM_e_type {
	DCM_LINEAR_EQUATION,
	DCM_NON_LINEAR_EQUATION,
	DCM_INEQUALITY
	} DCM_e_type;

typedef enum DCM_directed_type {
	DCM_NOT_DIRECTED,
	DCM_FIXED_DIRECTION, 
	DCM_PERPENDICULAR_TO_LINE,
	DCM_PARALLEL_TO_LINE
	} DCM_directed_type;

typedef enum DCM_var_dist_sign {
	DCM_VDIST_POSITIVE,
	DCM_VDIST_NEGATIVE,
	DCM_VDIST_KEEP
	} DCM_var_dist_sign;

typedef enum DCM_diamond_type {
	DCM_ZD_DEFAULT,
	DCM_ZD_LINES,
	DCM_ZD_POINTS
	} DCM_diamond_type;

typedef enum DCM_discontinuity_side {
	DCM_DS_LOWER,
	DCM_DS_UPPER
	} DCM_discontinuity_side;

typedef enum DCM_pn_discon_side {
	DCM_PN_UPPER,
	DCM_PN_LOWER,
	DCM_PN_DEFAULT
	} DCM_pn_discon_side;

typedef enum g_node_status {
	G_UNKNOWN,	
	G_FIXED,       	      	
	G_FROZEN,	
	G_OVER_DEFINED,		
	G_NON_ALGEBRAIC,	
	G_NOT_CONSISTENT,	
	G_NOT_CONSISTENT_DIMENSIONS,
	G_NOT_CONSISTENT_OTHER,
	G_NOT_CONSISTENT_UNKNOWN, 
	G_NOT_CHANGED,		
	G_WELL_DEFINED,		
	G_UNDER_DEFINED		
	} g_node_status;	

typedef enum d_node_status {
	D_UNKNOWN,	
	D_BETWEEN_FIXED,
	D_BETWEEN_SET_MEMBERS,	
	D_OVER_DEFINED,	
	D_NON_ALGEBRAIC,      
	D_NOT_CONSISTENT,	
	D_NOT_CONSISTENT_DIMENSIONS,
	D_NOT_CONSISTENT_OTHER, 
	D_NOT_CONSISTENT_UNKNOWN, 
	D_NOT_SOLVED,		
	D_NOT_CHANGED,		
	D_SOLVED  
	} d_node_status;

typedef enum DCM_underdefined_g_status {
	DCM_RADIUS_UNDERDEFINED = 1,
	DCM_MAJOR_RADIUS_UNDERDEFINED = 2,
	DCM_MINOR_RADIUS_UNDERDEFINED = 4,
	DCM_ANGLE_UNDERDEFINED = 8,
	DCM_POSITION_UNDERDEFINED = 16
	} DCM_underdefined_g_status;
	
typedef enum DCM_transform_status {
	DCM_NON_IDENTITY_TRANSFORM_MATRIX = 1,
	DCM_NON_ZERO_RADIUS_OFFSET1 = 2,
	DCM_NON_ZERO_RADIUS_OFFSET2 = 4,
	DCM_NON_UNIT_SCALE = 8,
	DCM_CIRCLE_INVERTED = 16
	} DCM_transform_status;

typedef enum DCM_equation_status {
	DCM_EQUATION_OK,
	DCM_EQUATION_FAIL
	} DCM_equation_status;

typedef enum DCM_dof_result_status {
	DCM_DOF_NOT_EVALUATED, 
	DCM_DOF_UNKNOWN,
	DCM_DOF_SUCCESS
	} DCM_dof_result_status;

typedef enum DCM_dof_info_type {
	DCM_DOF_NO_INFO,
	DCM_DOF_ROT_CENTRE,
	DCM_DOF_TRANS_DIRECTION,
	DCM_DOF_TRANS_INST_DIRECTION,
	DCM_DOF_TRANS_AROUND
	} DCM_dof_info_type;

typedef enum DCM_allow_zero_radius {
	DCM_ALLOW_ZERO_RADIUS_ON,
	DCM_ALLOW_ZERO_RADIUS_OFF,
	DCM_ALLOW_ZERO_RADIUS_DEFAULT
	} DCM_allow_zero_radius;

typedef enum DCM_allow_circle_inversion {
	DCM_ALLOW_CIRCLE_INVERSION_ON,
	DCM_ALLOW_CIRCLE_INVERSION_OFF,
	DCM_ALLOW_CIRCLE_INVERSION_DEFAULT
	} DCM_allow_circle_inversion;

typedef enum DCM_solving_mode {
	DCM_MINIMUM_MOVE_SOLVE,	
	DCM_STANDARD_SOLVE,	
	DCM_RELAXATION_SOLVE,	
	DCM_WEIGHTED_STANDARD_SOLVE
	} DCM_solving_mode;
	
typedef enum DCM_option {
	DCM_OP_CACHE_FRUSTUM_OFF,	
	DCM_OP_CACHE_FRUSTUM_ON,
	DCM_OP_ANALYSE_UNSOLVED_OFF,	
	DCM_OP_ANALYSE_UNSOLVED_ON,
	DCM_OP_ANALYSE_OVERDEFINED_OFF,
	DCM_OP_ANALYSE_OVERDEFINED_ON,
	DCM_OP_SOLVE_NON_ALGEBRAIC_OFF,
	DCM_OP_SOLVE_NON_ALGEBRAIC_ON,
	DCM_OP_ABORT_ON,	
	DCM_OP_ABORT_OFF,	
	DCM_OP_ALLOW_ZERO_RADIUS_OFF,	
	DCM_OP_ALLOW_ZERO_RADIUS_ON,
	DCM_OP_STATUS_400,
	DCM_OP_STATUS_410,
	DCM_OP_STATUS_420,	
	DCM_OP_STATUS_CURRENT,
	DCM_OP_EVAL_RESOLVE_NOT_CONSISTENT_OFF, 
	DCM_OP_EVAL_RESOLVE_NOT_CONSISTENT_ON,
	DCM_OP_DRAG_RESOLVE_NOT_CONSISTENT_OFF,	
	DCM_OP_DRAG_RESOLVE_NOT_CONSISTENT_ON,
	DCM_OP_AUTOCON_HELP_POINTS_OFF,	
	DCM_OP_AUTOCON_HELP_POINTS_ON,                     
	DCM_OP_AUTOCON_MIN_CONSTRAINTS,	
	DCM_OP_AUTOCON_MAX_CONSTRAINTS,	
	DCM_OP_AUTOCON_V49_OFF,	
	DCM_OP_AUTOCON_V49_ON,	
	DCM_OP_MINIMIZE_HELP_PARAMETER_CHANGE_OFF, 
	DCM_OP_MINIMIZE_HELP_PARAMETER_CHANGE_ON, 
	DCM_OP_ALLOW_CIRCLE_INVERSION_OFF,
	DCM_OP_ALLOW_CIRCLE_INVERSION_ON,	
	DCM_OP_INCREMENTAL_HELP_POINT_UPDATE_ON, 
	DCM_OP_INCREMENTAL_HELP_POINT_UPDATE_OFF, 
	DCM_OP_CHIRALITY_STRICT_ON,	
	DCM_OP_CHIRALITY_STRICT_OFF,
	DCM_OP_DRAG_CONSISTENT_BEHAVIOUR_OFF,	
	DCM_OP_DRAG_CONSISTENT_BEHAVIOUR_ON,
	DCM_OP_SOLVE_ALL_OVER_RIGID_OFF, 
	DCM_OP_SOLVE_ALL_OVER_RIGID_ON,	
	DCM_OP_CHAIN_SOLVING_OFF,	
	DCM_OP_CHAIN_SOLVING_ON,
	DCM_OP_MANAGE_CHANGING_SOFT_REFERENCES_OFF,
	DCM_OP_MANAGE_CHANGING_SOFT_REFERENCES_ON,
	DCM_OP_DIAGNOSTICS_MODE_NOT_SOLVED,
	DCM_OP_DIAGNOSTICS_MODE_ALWAYS,
	DCM_OP_DIAGNOSTICS_MODE_NEVER
	} DCM_option;

typedef enum DCM_changed_longevity {
	CHANGED_UNTIL_RE_EVALUATE,	
	CHANGED_UNTIL_EVALUATE	
	} DCM_changed_longevity;

typedef enum DCM_undo_mode {
	DCM_UNDO_TO_INITIAL,
	DCM_UNDO_TO_PREVIOUS
	} DCM_undo_mode;

typedef enum DCM_m_and_e_outcome {
	DCM_M_AND_E_SOLVED,		
	DCM_M_AND_E_SOLVED_EXACTLY,	
	DCM_M_AND_E_FAILED,		
	DCM_M_AND_E_ABORTED		
	} DCM_m_and_e_outcome;

typedef enum DCM_evaluation_type {
	DCM_FULL_EVAL,
	DCM_PARTIALLY_INCREMENTAL_EVAL,	
	DCM_FULLY_INCREMENTAL_EVAL,	
	DCM_EVAL_ABORTED,	
	DCM_NOT_EVAL	
	} DCM_evaluation_type;

typedef enum DCM_dragging_option {
	DCM_DRAG_POSSIBLE,	
	DCM_DRAG_SPECIFIC 
	} DCM_dragging_option;

typedef enum DCM_dragging_result {
	DCM_DRAG_SUCCEEDED,	
	DCM_DRAG_FAILED	
	} DCM_dragging_result;
	
typedef enum DCM_dragging_transformation {
	DCM_DT_GENERAL,              
	DCM_DT_TRANSLATION,           
	DCM_DT_RADIUS,  
	DCM_DT_MAJOR_RADIUS, 
	DCM_DT_MINOR_RADIUS,  
	DCM_DT_OFFSET_DISTANCE	
	} DCM_dragging_transformation;

typedef enum DCM_chirality_status {
	DCM_CHIRALITY_UNKNOWN,
	DCM_CHIRALITY_NO_CHANGE, 
	DCM_CHIRALITY_CHANGE	
	} DCM_chirality_status;

typedef enum DCM_offset_side {
	DCM_OFFSET_LEFT,	
	DCM_OFFSET_RIGHT,	
	DCM_OFFSET_INSIDE,
	DCM_OFFSET_OUTSIDE	
	} DCM_offset_side;

typedef enum DCM_offset_data_mask {
	DCM_OFFSET_SIDE_CHANGED = 1,	
	DCM_OFFSET_DIST_CHANGED = 2,
	DCM_OFFSET_PARENT_CHANGED = 4	
	} DCM_offset_data_mask;

typedef enum DCM_check_result {
	DCM_CHECK_POSSIBLE,
	DCM_CHECK_UNKNOWN,	
	DCM_CHECK_NOT_POSSIBLE,	
	DCM_CHECK_NOT_EVALUATED
	} DCM_check_result;

typedef enum DCM_constraint_balance_result {
	DCM_CONSBAL_SUCCEEDED,	
	DCM_CONSBAL_FAILED_PGM,		
	DCM_CONSBAL_ABORTED	
	} DCM_constraint_balance_result;

typedef enum DCM_autodim_status {
	DCM_AUTODIM_NOT_EVALUATED,
	DCM_AUTODIM_ABORTED,
	DCM_AUTODIM_COMPLETED
	} DCM_autodim_status;

typedef enum DCM_autodim_g_type {
	DCM_ADG_POINT,
	DCM_ADG_LINE,
	DCM_ADG_CIRCLE,
	DCM_ADG_ELLIPSE,
	DCM_ADG_PARAMETRIC,
	DCM_ADG_SPLINE,
	DCM_ADG_ALL
	} DCM_autodim_g_type;
	
typedef enum DCM_autodim_d_type {
	DCM_ADD_DISTANCE,
	DCM_ADD_ANGLE,
	DCM_ADD_RADIUS,
	DCM_ADD_MAJOR_RADIUS,
	DCM_ADD_MINOR_RADIUS,
	DCM_ADD_RADII,
	DCM_ADD_DIRECTED_PARALLEL,
	DCM_ADD_DIRECTED_PERPENDICULAR,
	DCM_ADD_ALL
	} DCM_autodim_d_type;
	
typedef enum DCM_autodim_mask_option {
	DCM_ADM_ALL,
	DCM_ADM_SYMMETRIC_PAIRS,
	DCM_ADM_FROM_G,
	DCM_ADM_INTER_G,
	DCM_ADM_FROM_SYMMETRY_AXES,
	DCM_ADM_BETWEEN_PAIRS
	} DCM_autodim_mask_option;

typedef enum DCM_autocon_result {
	DCM_AUTOCON_SUCCEEDED,	
	DCM_AUTOCON_FAILED_PGM,	
	DCM_AUTOCON_ABORTED
	} DCM_autocon_result;

typedef enum DCM_autocon_mask {
	DCM_ACM_IDENTICAL = 1,
	DCM_ACM_SYMMETRIC = 2,
	DCM_ACM_COINCIDENT = 4,
	DCM_ACM_CONCENTRIC = 8,
	DCM_ACM_PARALLEL = 16,
	DCM_ACM_PERPENDICULAR = 32,
	DCM_ACM_TANGENT = 64,
	DCM_ACM_EQUAL_RADIUS = 128,
	DCM_ACM_NORMAL = 256,
	DCM_ACM_EQUAL_DISTANCE = 512,
	DCM_ACM_ALL = 1023
	} DCM_autocon_mask;

typedef enum DCM_node_type {
	DCM_G_NODE,
	DCM_D_NODE,
	DCM_R_NODE,
	DCM_E_NODE,
	DCM_V_NODE,
	DCM_P_NODE
	} DCM_node_type;

typedef enum DCM_journal_options {
	DCM_JOU_OPT_OFF = 0,
	DCM_JOU_OPT_ON = 1,
	DCM_JOU_OPT_XMIT = 2,
	DCM_JOU_OPT_XMIT_INC = 4,
	DCM_JOU_OPT_XMIT_START = 8,
	DCM_JOU_OPT_FRU_OFF = 16
	} DCM_journal_options;

#if defined(__cplusplus)
extern "C" {
#endif
	typedef size_t (*DCM2_fwrite_function)(const void*, size_t, size_t, FILE*);
	typedef int (*DCM2_fflush_function)(FILE* file);
#if defined(__cplusplus)
}
#endif

typedef struct DCM2_file {
	FILE* file;
	DCM2_fwrite_function fwrite;
	DCM2_fflush_function fflush;
	} DCM2_file;

#if defined(__cplusplus)
extern "C" {
#endif
DCM_EXPORT DCM2_file* DCM2_file_construct_full(DCM2_file* safe_file,
	FILE* file_ptr, DCM2_fwrite_function fwrite_fn, 
	DCM2_fflush_function fflush_fn);
#if defined(__cplusplus)
}
#endif

#define DCM2_file_construct(file_obj, file_ptr)	\
	DCM2_file_construct_full(file_obj, file_ptr, &fwrite, &fflush)


typedef enum DCM_debug_message_type
	{
	DCM_DEBUG_MESSAGE_UNREGISTERED_FRUSTUM_FUNCTION
	} DCM_debug_message_type;


typedef enum DCM_ed_alignment {
	DCM_ED_ALIGNMENT_EQUAL,
	DCM_ED_ALIGNMENT_OPPOSITE,
	DCM_ED_ALIGNMENT_CURRENT
	} DCM_ed_alignment;

typedef enum DCM_tan_alignment {
	DCM_TAN_ALIGNMENT_EQUAL,
	DCM_TAN_ALIGNMENT_OPPOSITE,
	DCM_TAN_ALIGNMENT_CURRENT,
	DCM_TAN_ALIGNMENT_FREE
	} DCM_tan_alignment;

typedef enum DCM_bs_status {
	DCM_BS_STATUS_OK,
	DCM_BS_STATUS_NOT_A_SPLINE,
	DCM_BS_STATUS_BAD_DATA,
	DCM_BS_STATUS_OVER_DEFINED,
	DCM_BS_STATUS_NOT_SOLVED
	} DCM_bs_status;

typedef enum DCM_bs_rigidity {
	DCM_BS_RIGIDITY_RIGID,
	DCM_BS_RIGIDITY_SCALABLE,
	DCM_BS_RIGIDITY_FLEXIBLE
	} DCM_bs_rigidity;

typedef enum DCM_bs_periodicity {
	DCM_BS_PERIODICITY_NON_PER,
	DCM_BS_PERIODICITY_PER
	} DCM_bs_periodicity;

typedef enum DCM_bs_rationality {
	DCM_BS_RATIONALITY_NON_RAT,
	DCM_BS_RATIONALITY_RAT
	} DCM_bs_rationality;

typedef enum DCM_bs_dependence {
	DCM_BS_DEPENDENCE_CP,
	DCM_BS_DEPENDENCE_INTERP
	} DCM_bs_dependence;

typedef enum DCM_bs_solving_mode {
	DCM_BS_SOLVING_MODE_STANDARD,
	DCM_BS_SOLVING_MODE_LOCAL
	} DCM_bs_solving_mode;

typedef enum DCM_bs_parameterisation {
	DCM_BS_PARAMETERISATION_FIXED,
	DCM_BS_PARAMETERISATION_VARIABLE
	} DCM_bs_parameterisation;

typedef enum DCM_bs_cp_freedom {
	DCM_BS_CP_FREEDOM_FREE,
	DCM_BS_CP_FREEDOM_FIXED
	} DCM_bs_cp_freedom;

typedef enum DCM_bs_itype {
	DCM_BS_ITYPE_COI,
	DCM_BS_ITYPE_G_COI,
	DCM_BS_ITYPE_DERIV1,
	DCM_BS_ITYPE_DERIV2,
	DCM_BS_ITYPE_CURVATURE,
	DCM_BS_ITYPE_DERIV1_DIR,
	DCM_BS_ITYPE_DERIV1_LEN
	} DCM_bs_itype;

typedef enum DCM_bs_iduration {
	DCM_BS_IDURATION_REFRESH_ONLY,
	DCM_BS_IDURATION_ALWAYS,
	DCM_BS_IDURATION_CREATION_ONLY
	} DCM_bs_iduration;

typedef enum DCM_bs_istatus {
	DCM_BS_ISTATUS_SOLVED,
	DCM_BS_ISTATUS_REMOVED,
	DCM_BS_ISTATUS_OVER_DEFINED,
	DCM_BS_ISTATUS_NOT_SOLVED
	} DCM_bs_istatus;

typedef enum DCM_bs_data_mask {
	DCM_BS_RIGIDITY		   = 0x00000001,
	DCM_BS_PERIODICITY	   = 0x00000002,
	DCM_BS_RATIONALITY	   = 0x00000004,
	DCM_BS_DEPENDENCE	   = 0x00000008,
	DCM_BS_SOLVING_MODE	   = 0x00000010,
	DCM_BS_PARAMETERISATION    = 0x00000020,
	DCM_BS_DEGREE		   = 0x00000040,
	DCM_BS_KNOT_VECTOR	   = 0x00000080,
	DCM_BS_CP_N		   = 0x00000100,
	DCM_BS_CP_G_NODES	   = 0x00000200,
	DCM_BS_CP_VECTORS	   = 0x00000400,
	DCM_BS_CP_WEIGHTS	   = 0x00000800,
	DCM_BS_CP_FREEDOMS	   = 0x00001000,
	DCM_BS_INTERP_N		   = 0x00002000,
	DCM_BS_INTERP_G_NODES	   = 0x00004000,
	DCM_BS_INTERP_V_NODES      = 0x00008000,
	DCM_BS_INTERP_VECTORS	   = 0x00010000,
	DCM_BS_INTERP_PARAMETERS   = 0x00020000,
	DCM_BS_INTERP_TYPES	   = 0x00040000,
	DCM_BS_INTERP_WEIGHTS	   = 0x00080000,
	DCM_BS_INTERP_DURATIONS    = 0x00100000,
	DCM_BS_INTERP_STATUSES     = 0x00200000,
	DCM_BS_INTERP_CON_BAL	   = 0x00400000,
	DCM_BS_INTERP_D_STATUSES   = 0x00800000
	} DCM_bs_data_mask;

typedef void** DCM_g_node_array;
typedef void** DCM_v_node_array;

typedef struct DCM_bs_data {
	unsigned int		data_mask;
	unsigned int		bad_data_mask;
	DCM_bs_rigidity		rigidity;
	DCM_bs_periodicity	periodicity;
	DCM_bs_rationality	rationality;
	DCM_bs_dependence	dependence;
	DCM_bs_solving_mode	solving_mode;
	DCM_bs_parameterisation	parameterisation;
	int			degree;
	double*			knot_vector;
	int			cp_n;
	DCM_g_node_array	cp_g_nodes;
	double*			cp_vectors;
	double*			cp_weights;
	DCM_bs_cp_freedom*	cp_freedoms;
	int			interp_n;
	DCM_g_node_array	interp_g_nodes;
	DCM_v_node_array	interp_v_nodes;
	double*			interp_vectors;
	double*			interp_parameters;
	DCM_bs_itype*		interp_types;
	double*			interp_weights;
	DCM_bs_iduration*	interp_durations;
	DCM_bs_istatus*		interp_statuses;
	int			interp_con_bal;
	d_node_status*		interp_d_statuses;
	} DCM_bs_data;

#ifdef GRIFFON_PROJECT

typedef enum DCM_conic_type {
	DCM_CONIC_TYPE_BEZIER,
	DCM_CONIC_TYPE_FIXED_SHAPE_BEZIER,
	DCM_CONIC_TYPE_FIXED_RHO_BEZIER
	} DCM_conic_type;

typedef enum DCM_conic_shape {
	DCM_CONIC_SHAPE_ELLIPSE,
	DCM_CONIC_SHAPE_PARABOLA,
	DCM_CONIC_SHAPE_HYPERBOLA
	} DCM_conic_shape;

typedef enum DCM_conic_rigidity {
	DCM_CONIC_RIGIDITY_RIGID,
	DCM_CONIC_RIGIDITY_SCALABLE,
	DCM_CONIC_RIGIDITY_FLEXIBLE
	} DCM_conic_rigidity;

typedef struct DCM_conic_data {
	unsigned int data_mask;
	unsigned int bad_data_mask;

	DCM_conic_type type;
	DCM_conic_shape shape;
	DCM_conic_rigidity rigidity;

	double bezier_rho;

	int	cp_n;
	DCM_g_node_array cp_g_nodes;
	double* cp_vectors;

	double axis_direction[2];

	double eccentricity;
	double near_vertex[2];
	double near_focus[2];
	} DCM_conic_data;
#endif

typedef enum DCM_constraint_end {
	DCM_CONSTRAINT_END_ONE,
	DCM_CONSTRAINT_END_TWO
	} DCM_constraint_end;

typedef enum DCM_para_ext_update {
	DCM_PARA_EXT_UPDATE_ERROR				= 0x00000001,
	DCM_PARA_EXT_UPDATE_MIN_END_ERROR			= 0x00000002,
	DCM_PARA_EXT_UPDATE_MIN_END_PARAMETERS_ERROR		= 0x00000004,
	DCM_PARA_EXT_UPDATE_MIN_END_INCOMPATIBLE_START_TYPE	= 0x00000008,
	DCM_PARA_EXT_UPDATE_MAX_END_ERROR			= 0x00000010,
	DCM_PARA_EXT_UPDATE_MAX_END_PARAMETERS_ERROR		= 0x00000020,
	DCM_PARA_EXT_UPDATE_MAX_END_INCOMPATIBLE_START_TYPE	= 0x00000040
	} DCM_para_ext_update;

typedef enum DCM_para_ext_end {
	DCM_PARA_EXT_END_MIN,
	DCM_PARA_EXT_END_MAX
	} DCM_para_ext_end;

typedef enum DCM_para_ext_type {
	DCM_PARA_EXT_TYPE_CUSTOM,
	DCM_PARA_EXT_TYPE_LINEAR
	} DCM_para_ext_type;

typedef enum DCM_para_ext {
	DCM_PARA_EXT_NONE,
	DCM_PARA_EXT_EXTENDED
	} DCM_para_ext;

typedef enum DCM_para_ext_start_type {
	DCM_PARA_EXT_START_TYPE_END,
	DCM_PARA_EXT_START_TYPE_FIXED,
	DCM_PARA_EXT_START_TYPE_VARIABLE
	} DCM_para_ext_start_type;

typedef enum DCM_para_ext_end_type {
	DCM_PARA_EXT_END_TYPE_FIXED,
	DCM_PARA_EXT_END_TYPE_VARIABLE
	} DCM_para_ext_end_type;

typedef enum DCM_ellipse_parameter {
	DCM_ELLIPSE_PARAMETER_PARAMETER,
	DCM_ELLIPSE_PARAMETER_VECTOR
	} DCM_ellipse_parameter;

typedef enum DCM_transform_bias {
	DCM_TRANSFORM_BIAS_NONE,
	DCM_TRANSFORM_BIAS_CHANGE,
	DCM_TRANSFORM_BIAS_DONT_CHANGE
	} DCM_transform_bias;

typedef enum DCM_measured_status {
	DCM_MEASURED_STATUS_UNSUPPORTED_TYPE,
	DCM_MEASURED_STATUS_CANNOT_MEASURE,
	DCM_MEASURED_STATUS_MEASURED
	} DCM_measured_status;

typedef enum DCM_d_rigidity {
	DCM_DIMENSION_NON_RIGID,
	DCM_DIMENSION_RIGID
	} DCM_d_rigidity;

typedef enum DCM_variable_angle_return {
	DCM_VARIABLE_ANGLE_KEEP,
	DCM_VARIABLE_ANGLE_VALUE
	} DCM_variable_angle_return;

#endif
