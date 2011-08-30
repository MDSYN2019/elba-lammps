/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef BOND_CLASS

BondStyle(dipole,BondDipole)

#else

#ifndef LMP_BOND_DIPOLE_H
#define LMP_BOND_DIPOLE_H

#include "stdio.h"
#include "bond.h"

namespace LAMMPS_NS {

class BondDipole : public Bond {
 public:
  BondDipole(class LAMMPS *);
  ~BondDipole();
  void compute(int, int);
  void coeff(int, char **);
  double equilibrium_distance(int);
  void write_restart(FILE *);
  void read_restart(FILE *);
  double single(int, double, int, int);

 private:
  double *k,*gamma0;

  void allocate();
};

}

#endif
#endif
