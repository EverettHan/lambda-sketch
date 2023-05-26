#ifndef FRUSTUM_MIGRATION_H
#define FRUSTUM_MIGRATION_H

#include "CATCGMSkmData_frustum.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
static inline void DCM_migrate_frustum(struct DCM_frustum_functions* frustum)
#else
static void DCM_migrate_frustum(struct DCM_frustum_functions* frustum)
#endif
	{
    if (frustum)
    {
      frustum->g_identify = &DCM_g_identify;
      frustum->point_point = &DCM_point_point;
      frustum->line_point = &DCM_line_point;
      frustum->line_direction = &DCM_line_direction;
      frustum->circle_center = &DCM_circle_center;
      frustum->circle_radius = &DCM_circle_radius;
      frustum->set_radius = &DCM_set_radius;
      frustum->ellipse_center = &DCM_ellipse_center;
      frustum->ellipse_direction = &DCM_ellipse_direction;
      frustum->ellipse_major_radius = &DCM_ellipse_major_radius;
      frustum->ellipse_minor_radius = &DCM_ellipse_minor_radius;
      frustum->set_major_radius = &DCM_set_major_radius;
      frustum->set_minor_radius = &DCM_set_minor_radius;
      frustum->transform = &DCM_transform;
      frustum->dimension_type = &DCM_dimension_type;
      frustum->dimension_value = &DCM_dimension_value;
      frustum->directed_distance = &DCM_directed_distance;
      frustum->dimension_point = &DCM_dimension_point;
      frustum->dimension_point_update = &DCM_dimension_point_update;
      frustum->pattern_multiplier = &DCM_pattern_multiplier;
      frustum->parametric_limits = &DCM_parametric_limits;
      frustum->parametric_period = &DCM_parametric_period;
      frustum->parametric_evaluator = &DCM_parametric_evaluator;
      frustum->parametric_direction = &DCM_parametric_direction;
      frustum->parametric_regenerate = &DCM_parametric_regenerate;
      frustum->parametric_n_discons = &DCM_parametric_n_discons;
      frustum->parametric_discon_data = &DCM_parametric_discon_data;
      frustum->dimension_parameter = &DCM_dimension_parameter;
      frustum->dimension_parameter_update = &DCM_dimension_parameter_update;
      frustum->offset_orientation = &DCM_offset_orientation;
      frustum->offset_distance = &DCM_offset_distance;
      frustum->update_offset_data = &DCM_update_offset_data;
      frustum->spline_changed = &DCM_spline_changed;
      frustum->variable_start_value = &DCM_variable_start_value;
      frustum->variable_new_value = &DCM_variable_new_value;
      frustum->variable_dist_start_sign = &DCM_variable_dist_start_sign;
      frustum->equation_type = &DCM_equation_type;
      frustum->equation_constant_value = &DCM_equation_constant_value;
      frustum->equation_coefficient_value = &DCM_equation_coefficient_value;
      frustum->equation_derivative_value = &DCM_equation_derivative_value;
      frustum->equation_p_node_derivative_value = &DCM_equation_p_node_derivative_value;
      frustum->equation_residual = &DCM_equation_residual;
      frustum->inequality_minimum = &DCM_inequality_minimum;
      frustum->inequality_maximum = &DCM_inequality_maximum;
      frustum->g_status = &DCM_g_status;
      frustum->new_underdefined_status = &DCM_new_underdefined_status;
      frustum->v_status = &DCM_v_status;
      frustum->d_status = &DCM_d_status;
      frustum->e_status = &DCM_e_status;
      frustum->p_status = &DCM_p_status;
      frustum->abort = &DCM_abort;
      frustum->resolve_zero_diamond = &DCM_resolve_zero_diamond;
      frustum->autodim_weight = &DCM_autodim_weight;
      frustum->autodim_dir_weight = &DCM_autodim_dir_weight;
      frustum->automatic_dimension = &DCM_automatic_dimension;
      frustum->automatic_dir_dimension = &DCM_automatic_dir_dimension;
      frustum->automatic_class = &DCM_automatic_class;
      frustum->automatic_constraint = &DCM_automatic_constraint;
      frustum->automatic_constraint3 = &DCM_automatic_constraint3;
      frustum->deduced_class = &DCM_deduced_class;
      frustum->deduced_constraint = &DCM_deduced_constraint;
      frustum->deduced_constraint4 = &DCM_deduced_constraint4;
      frustum->erased_node = &DCM_erased_node;
      frustum->scale_transform = &DCM_scale_transform; 
    }
}

#ifdef __cplusplus
}
#endif

#endif
