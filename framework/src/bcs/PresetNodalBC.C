//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PresetNodalBC.h"

// MOOSE includes
#include "MooseVariableFE.h"

#include "libmesh/numeric_vector.h"

defineLegacyParams(PresetNodalBC);

InputParameters
PresetNodalBC::validParams()
{
  InputParameters params = NodalBC::validParams();
  return params;
}

PresetNodalBC::PresetNodalBC(const InputParameters & parameters) : NodalBC(parameters) {}

void
PresetNodalBC::computeValue(NumericVector<Number> & current_solution)
{
  const dof_id_type & dof_idx = _var.nodalDofIndex();
  current_solution.set(dof_idx, computeQpValue());
}

Real
PresetNodalBC::computeQpResidual()
{
  return _u[_qp] - computeQpValue();
}
