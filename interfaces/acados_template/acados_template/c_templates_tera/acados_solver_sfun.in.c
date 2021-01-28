/*
 * Copyright 2019 Gianluca Frison, Dimitris Kouzoupis, Robin Verschueren,
 * Andrea Zanelli, Niels van Duijkeren, Jonathan Frey, Tommaso Sartor,
 * Branimir Novoselnik, Rien Quirynen, Rezart Qelibari, Dang Doan,
 * Jonas Koenemann, Yutao Chen, Tobias Schöls, Jonas Schlagenhauf, Moritz Diehl
 *
 * This file is part of acados.
 *
 * The 2-Clause BSD License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.;
 */

#define S_FUNCTION_NAME   acados_solver_sfunction_{{ model.name }}
#define S_FUNCTION_LEVEL  2

#define MDL_START

// acados
#include "acados/utils/print.h"
#include "acados_c/sim_interface.h"
#include "acados_c/external_function_interface.h"

// example specific
#include "{{ model.name }}_model/{{ model.name }}_model.h"
#include "acados_solver_{{ model.name }}.h"

#include "simstruc.h"

{% if simulink_opts.samplingtime == "t0" -%}
#define SAMPLINGTIME {{ solver_options.time_steps[0] }}
{%- elif simulink_opts.samplingtime == "-1" -%}
#define SAMPLINGTIME -1
{%- else -%}
  {{ throw(message = "simulink_opts.samplingtime must be '-1' or 't0', got val") }}
{%- endif %}

static void mdlInitializeSizes (SimStruct *S)
{
    // specify the number of continuous and discrete states
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

  {#- compute number of input ports #}
  {%- set n_inputs = 0 -%}
  {%- if dims.nbx_0 > 0 -%}  {#- lbx_0, ubx_0 #}
    {%- set n_inputs = n_inputs + 2 -%}
  {%- endif -%}
  {%- if dims.np > 0 -%}  {#- parameters #}
    {%- set n_inputs = n_inputs + 1 -%}
  {%- endif -%}
  {%- if dims.ny > 0 -%}  {#- y_ref -#}
    {%- set n_inputs = n_inputs + 1 -%}
  {%- endif -%}
  {%- if dims.ny_e > 0 -%}  {#- y_ref_e #}
    {%- set n_inputs = n_inputs + 1 -%}
  {%- endif -%}
  {%- if dims.nbx > 0 -%}  {#- lbx, ubx #}
    {%- set n_inputs = n_inputs + 2 -%}
  {%- endif -%}
  {%- if dims.nbx_e > 0 -%}  {#- lbx_e, ubx_e #}
    {%- set n_inputs = n_inputs + 2 -%}
  {%- endif -%}
  {%- if dims.nbu > 0 -%}  {#- lbu, ubu #}
    {%- set n_inputs = n_inputs + 2 -%}
  {%- endif -%}
  {%- if dims.ng > 0 -%}  {#- lg, ug #}
    {%- set n_inputs = n_inputs + 2 -%}
  {%- endif -%}
  {%- if dims.nh > 0 -%}  {#- lh, uh #}
    {%- set n_inputs = n_inputs + 2 -%}
  {%- endif -%}

  {#- optional inputs #}
  {%- for key, val in simulink_opts.inputs -%}
    {%- if val != 0 and val != 1 -%}
      {{ throw(message = "simulink_opts.inputs must be 0 or 1, got val") }}
    {%- endif -%}
  {%- endfor -%}
  {%- if dims.ny_0 > 0 and simulink_opts.inputs.cost_W_0 %}  {#- cost_W_0 #}
    {%- set n_inputs = n_inputs + 1 %}
  {%- endif -%}
  {%- if dims.ny > 0 and simulink_opts.inputs.cost_W %}  {#- cost_W #}
    {%- set n_inputs = n_inputs + 1 %}
  {%- endif -%}
  {%- if dims.ny_e > 0 and simulink_opts.inputs.cost_W_e %}  {#- cost_W_e #}
    {%- set n_inputs = n_inputs + 1 %}
  {%- endif -%}

    // specify the number of input ports
    if ( !ssSetNumInputPorts(S, {{ n_inputs }}) )
        return;

    // specify the number of output ports
    {%- set_global n_outputs = 0 %}
    {%- for key, val in simulink_opts.outputs %}
      {%- if val == 1 %}
        {%- set_global n_outputs = n_outputs + val %}
      {%- elif val != 0 %}
        {{ throw(message = "simulink_opts.outputs must be 0 or 1, got val") }}
      {%- endif %}
    {%- endfor %}
    if ( !ssSetNumOutputPorts(S, {{ n_outputs }}) )
        return;

    // specify dimension information for the input ports
    {%- set i_input = 0 %}{# note here i_input is 0-based #}
  {%- if dims.nbx_0 > 0 %}
    // lbx_0
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nbx_0 }});
    {%- set i_input = i_input + 1 %}
    // ubx_0
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nbx_0 }});
  {%- endif %}

  {%- if dims.ny > 0 %}
    {%- set i_input = i_input + 1 %}
    // y_ref
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.N }} * {{ dims.ny }});
  {%- endif %}

  {%- if dims.ny_e > 0 %}
    {%- set i_input = i_input + 1 %}
    // y_ref_e
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.ny_e }});
  {%- endif %}

  {%- if dims.np > 0 %}
    {%- set i_input = i_input + 1 %}
    // parameters
    ssSetInputPortVectorDimension(S, {{ i_input }}, ({{ dims.N }}+1) * {{ dims.np }});
  {%- endif %}

  {%- if dims.nbx > 0 and dims.N > 1 %}
    {%- set i_input = i_input + 1 %}
    // lbx
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ (dims.N-1) * dims.nbx }});
    {%- set i_input = i_input + 1 %}
    // ubx
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ (dims.N-1) * dims.nbx }});
  {%- endif %}

  {%- if dims.nbx_e > 0 and dims.N > 0 %}
    {%- set i_input = i_input + 1 %}
    // lbx_e
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nbx_e }});
    {%- set i_input = i_input + 1 %}
    // ubx_e
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nbx_e }});
  {%- endif %}

  {%- if dims.nbu > 0 %}
    {%- set i_input = i_input + 1 %}
    // lbu
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.N*dims.nbu }});
    {%- set i_input = i_input + 1 %}
    // ubu
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.N*dims.nbu }});
  {%- endif %}

  {%- if dims.ng > 0 %}
    {%- set i_input = i_input + 1 %}
    // lg
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.ng }});
    {%- set i_input = i_input + 1 %}
    // ug
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.ng }});
  {%- endif %}

  {%- if dims.nh > 0 %}
    {%- set i_input = i_input + 1 %}
    // lh
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nh }});
    {%- set i_input = i_input + 1 %}
    // uh
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nh }});
  {%- endif %}

  {%- if dims.ny_0 > 0 and simulink_opts.inputs.cost_W_0 %}  {#- cost_W_0 #}
    {%- set i_input = i_input + 1 %}
    // cost_W_0
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.ny_0 * dims.ny_0 }});
  {%- endif %}

  {%- if dims.ny_0 > 0 and simulink_opts.inputs.cost_W %}  {#- cost_W #}
    {%- set i_input = i_input + 1 %}
    // cost_W
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.ny * dims.ny }});
  {%- endif %}

  {%- if dims.ny_e > 0 and simulink_opts.inputs.cost_W_e %}  {#- cost_W_e #}
    {%- set i_input = i_input + 1 %}
    // cost_W_e
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.ny_e * dims.ny_e }});
  {%- endif %}

    // specify dimension information for the output ports
    {%- set i_output = 0 %}{# note here i_output is 0-based #}
  {%- if simulink_opts.outputs.u0 == 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, {{ dims.nu }} );
  {%- endif %}

  {%- if simulink_opts.outputs.utraj == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, {{ dims.nu * dims.N }} );
  {%- endif %}

  {%- if simulink_opts.outputs.xtraj == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, {{ dims.nx * (dims.N+1) }} );
  {%- endif %}

  {%- if simulink_opts.outputs.solver_status == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, 1 );
  {%- endif %}

  {%- if simulink_opts.outputs.KKT_residual == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, 1 );
  {%- endif %}

  {%- if simulink_opts.outputs.x1 == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, {{ dims.nx }} ); // state at shooting node 1
  {%- endif %}

  {%- if simulink_opts.outputs.CPU_time == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, 1);
  {%- endif %}

  {%- if simulink_opts.outputs.sqp_iter == 1 %}
    {%- set i_output = i_output + 1 %}
    ssSetOutputPortVectorDimension(S, {{ i_output }}, 1 );
  {%- endif %}

    // specify the direct feedthrough status
    // should be set to 1 for all inputs used in mdlOutputs
    {%- for i in range(end=n_inputs) %}
    ssSetInputPortDirectFeedThrough(S, {{ i }}, 1);
    {%- endfor %}

    // one sample time
    ssSetNumSampleTimes(S, 1);
}


#if defined(MATLAB_MEX_FILE)

#define MDL_SET_INPUT_PORT_DIMENSION_INFO
#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO

static void mdlSetInputPortDimensionInfo(SimStruct *S, int_T port, const DimsInfo_T *dimsInfo)
{
    if ( !ssSetInputPortDimensionInfo(S, port, dimsInfo) )
         return;
}

static void mdlSetOutputPortDimensionInfo(SimStruct *S, int_T port, const DimsInfo_T *dimsInfo)
{
    if ( !ssSetOutputPortDimensionInfo(S, port, dimsInfo) )
         return;
}

#endif /* MATLAB_MEX_FILE */


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLINGTIME);
    ssSetOffsetTime(S, 0, 0.0);
}


static void mdlStart(SimStruct *S)
{
    nlp_solver_capsule *capsule = {{ model.name }}_acados_create_capsule();
    {{ model.name }}_acados_create(capsule);

    ssSetUserData(S, (void*)capsule);
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
    nlp_solver_capsule *capsule = ssGetUserData(S);
    InputRealPtrsType in_sign;

    {%- set input_sizes = [dims.nbx_0, dims.ny, dims.ny_e, dims.np, (dims.N-1)*dims.nbx,
          (dims.N)*dims.nbu, dims.ng, dims.nh] -%}

  {%- if dims.ny_0 > 0 and simulink_opts.inputs.cost_W_0 %}  {# cost_W_0 #}
    {%- set input_sizes = input_sizes | concat(with=(dims.ny_0 * dims.ny_0)) %}
  {%- endif %}
  {%- if dims.ny > 0 and simulink_opts.inputs.cost_W %}  {# cost_W #}
    {%- set input_sizes = input_sizes | concat(with=(dims.ny * dims.ny)) %}
  {%- endif %}
  {%- if dims.ny_e > 0 and simulink_opts.inputs.cost_W_e %}  {# cost_W_e #}
    {%- set input_sizes = input_sizes | concat(with=(dims.ny_e * dims.ny_e)) %}
  {%- endif %}

    // local buffer
    {%- set buffer_size = input_sizes | sort | last %}
    real_t buffer[{{ buffer_size }}];

    /* go through inputs */
    {%- set i_input = 0 %}
  {%- if dims.nbx_0 > 0 %}{# lbx_0, ubx_0 #}
    // lbx_0
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});
    for (int i = 0; i < {{ dims.nbx_0 }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, 0, "lbx", buffer);

    // ubx_0
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});
    for (int i = 0; i < {{ dims.nbx_0 }}; i++)
        buffer[i] = (double)(*in_sign[i]);
    ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, 0, "ubx", buffer);
  {%- endif %}

  {% if dims.ny > 0 %}
    // y_ref - stage-variant !!!
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int ii = 0; ii < {{ dims.N }}; ii++)
    {
        for (int jj = 0; jj < {{ dims.ny }}; jj++)
            buffer[jj] = (double)(*in_sign[ii*{{dims.ny}}+jj]);
        ocp_nlp_cost_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "yref", (void *) buffer);
    }
  {%- endif %}


  {% if dims.ny_e > 0 %}
    // y_ref_e
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.ny_e }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, {{ dims.N }}, "yref", (void *) buffer);
  {%- endif %}

  {% if dims.np > 0 %}
    // parameters - stage-variant !!!
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    // update value of parameters
    for (int ii = 0; ii <= {{ dims.N }}; ii++) 
    {
        for (int jj = 0; jj < {{ dims.np }}; jj++)
            buffer[jj] = (double)(*in_sign[ii*{{dims.np}}+jj]);
        {{ model.name }}_acados_update_params(capsule, ii, buffer, {{ dims.np }});
    }
  {%- endif %}


  {% if dims.nbx > 0 %}
    // lbx
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ (dims.N-1) * dims.nbx }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 1; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "lbx", buffer + (ii-1)*{{ dims.nbx }});

    // ubx
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ (dims.N-1) * dims.nbx }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 1; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "ubx", buffer + (ii-1)*{{ dims.nbx }});
  {%- endif %}


  {%- if dims.nbx_e > 0 and dims.N > 0 %}
    // lbx_e
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.nbx_e }}; i++)
        buffer[i] = (double)(*in_sign[i]);
    ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, {{ dims.N }}, "lbx", buffer);

    // ubx_e
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.nbx_e }}; i++)
        buffer[i] = (double)(*in_sign[i]);
    ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, {{ dims.N }}, "ubx", buffer);
  {%- endif %}

  {% if dims.nbu > 0 %}
    // lbu
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.N*dims.nbu }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "lbu", buffer + ii*{{ dims.nbu }});

    // ubu
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.N*dims.nbu }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "ubu", buffer + ii*{{ dims.nbu }});
  {%- endif %}

  {% if dims.ng > 0 %}
    // lg
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.ng }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "lg", buffer);

    // ug
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.ng }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "ug", buffer);
  {%- endif %}

  {% if dims.nh > 0 %}
    // lh
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.nh }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "lh", buffer);

    // uh
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.nh }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_constraints_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "uh", buffer);
  {%- endif %}

  {%- if dims.ny_0 > 0 and simulink_opts.inputs.cost_W_0 %}  {# cost_W_0 #}
    // cost_W_0
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});
    for (int i = 0; i < {{ dims.ny_0 * dims.ny_0 }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, 0, "W", buffer);
  {%- endif %}

  {%- if dims.ny > 0 and simulink_opts.inputs.cost_W %}  {# cost_W #}
    // cost_W
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});
    for (int i = 0; i < {{ dims.ny * dims.ny }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    for (int ii = 1; ii < {{ dims.N }}; ii++)
        ocp_nlp_cost_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, ii, "W", buffer);
  {%- endif %}

  {%- if dims.ny_e > 0 and simulink_opts.inputs.cost_W_e %}  {#- cost_W_e #}
    // cost_W_e
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});
    for (int i = 0; i < {{ dims.ny_e * dims.ny_e }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    ocp_nlp_cost_model_set(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_in, {{ dims.N }}, "W", buffer);
  {%- endif %}

    /* call solver */
    int rti_phase = 0;
    ocp_nlp_solver_opts_set(capsule->nlp_config, capsule->nlp_opts, "rti_phase", &rti_phase);
    int acados_status = {{ model.name }}_acados_solve(capsule);


    /* set outputs */
    // assign pointers to output signals
    real_t *out_u0, *out_utraj, *out_xtraj, *out_status, *out_sqp_iter, *out_KKT_res, *out_x1, *out_cpu_time;
    int tmp_int;

    {%- set i_output = 0 -%}{# note here i_output is 0-based #}
  {%- if simulink_opts.outputs.u0 == 1 %}
    out_u0 = ssGetOutputPortRealSignal(S, {{ i_output }});
    ocp_nlp_out_get(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_out, 0, "u", (void *) out_u0);
  {%- endif %}

  {%- if simulink_opts.outputs.utraj == 1 %}
    {%- set i_output = i_output + 1 -%}
    out_utraj = ssGetOutputPortRealSignal(S, {{ i_output }});
    for (int ii = 0; ii < {{ dims.N }}; ii++)
        ocp_nlp_out_get(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_out, ii,
                        "u", (void *) out_utraj + ii * {{ dims.nu }});
  {%- endif %}

  {%- if simulink_opts.outputs.xtraj == 1 %}
    {%- set i_output = i_output + 1 %}
    out_xtraj = ssGetOutputPortRealSignal(S, {{ i_output }});
    for (int ii = 0; ii < {{ dims.N + 1 }}; ii++)
        ocp_nlp_out_get(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_out, ii,
                        "x", (void *) out_xtraj + ii * {{ dims.nx }});
  {%- endif %}

  {%- if simulink_opts.outputs.solver_status == 1 %}
    {%- set i_output = i_output + 1 %}
    out_status = ssGetOutputPortRealSignal(S, {{ i_output }});
    *out_status = (real_t) acados_status;
  {%- endif %}

  {%- if simulink_opts.outputs.KKT_residual == 1 %}
    {%- set i_output = i_output + 1 %}
    out_KKT_res = ssGetOutputPortRealSignal(S, {{ i_output }});
    *out_KKT_res = (real_t) capsule->nlp_out->inf_norm_res;
  {%- endif %}

  {%- if simulink_opts.outputs.x1 == 1 %}
    {%- set i_output = i_output + 1 %}
    out_x1 = ssGetOutputPortRealSignal(S, {{ i_output }});
    ocp_nlp_out_get(capsule->nlp_config, capsule->nlp_dims, capsule->nlp_out, 1, "x", (void *) out_x1);
  {%- endif %}

  {%- if simulink_opts.outputs.CPU_time == 1 %}
    {%- set i_output = i_output + 1 %}
    out_cpu_time = ssGetOutputPortRealSignal(S, {{ i_output }});
    // get solution time
    ocp_nlp_get(capsule->nlp_config, capsule->nlp_solver, "time_tot", (void *) out_cpu_time);
  {%- endif %}

  {%- if simulink_opts.outputs.sqp_iter == 1 %}
    {%- set i_output = i_output + 1 %}
    out_sqp_iter = ssGetOutputPortRealSignal(S, {{ i_output }});
    // get sqp iter
    ocp_nlp_get(capsule->nlp_config, capsule->nlp_solver, "sqp_iter", (void *) &tmp_int);
    *out_sqp_iter = (real_t) tmp_int;
  {%- endif %}

}

static void mdlTerminate(SimStruct *S)
{
    nlp_solver_capsule *capsule = ssGetUserData(S);

    {{ model.name }}_acados_free(capsule);
    {{ model.name }}_acados_free_capsule(capsule);
}


#ifdef  MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif
