#include <cstdio>

#include <madness/mra/mra.h>
#include <madness/mra/operator.h>

using namespace madness;

double gaussian(const coord_3d& r) {
  double x = r[0];
  double y = r[1];
  double z = r[2];
  
  return exp(-(x*x + y*y + z*z));
}

int main(int argc, char **argv)
{
  initialize(argc, argv);
  World world(SafeMPI::COMM_WORLD);
  startup(world, argc, argv);
  printf("\n");

  FunctionDefaults<3>::set_cubic_cell(-6.0, 6.0);
  real_convolution_3d op = CoulombOperator(world, 1e-4, 1e-6);
  real_function_3d g = real_factory_3d(world).f(gaussian);

  //printf(g.trace(), g.norm2(), inner(g,op(g)));
  printf("g.trace = %18.10f\n", g.trace());
  printf("g.trace = %18.10f\n", g.norm2());
  printf("inner(g,op(g)) = %18.10f\n", inner(g,op(g)));

  finalize();

  printf("Pass here\n");

}
