#include <cstdio>

#include <madness/mra/mra.h>

using namespace madness;

// define a function
double my_func(const coord_1d& r) {
    return std::sin(r[0]);
}

int main(int argc, char** argv) {
    
    initialize(argc, argv);
    
    World world(SafeMPI::COMM_WORLD);
    
    startup(world, argc, argv);

    if(world.rank() == 0) print("");

    FunctionDefaults<1>::set_cubic_cell(0.0, 10.0);
    real_function_1d f = real_factory_1d(world).f(my_func);

    // integral of the function over the whole domain can be calculated using trace.
    double integral = f.trace();

    if(world.rank() == 0) printf("Integral is %18.10f\n", integral);

    finalize();

    return 0;
}