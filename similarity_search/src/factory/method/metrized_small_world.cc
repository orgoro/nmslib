/**
 * Non-metric Space Library
 *
 * Authors: Bilegsaikhan Naidan (https://github.com/bileg), Leonid Boytsov (http://boytsov.info).
 * With contributions from Lawrence Cayton (http://lcayton.com/).
 *
 * For the complete list of contributors and further details see:
 * https://github.com/searchivarius/NonMetricSpaceLib
 *
 * Copyright (c) 2014
 *
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */

#include "searchoracle.h"
#include "metrized_small_world.h"
#include "methodfactory.h"

namespace similarity {

/*
 * Creating functions.
 */

template <typename dist_t>
Index<dist_t>* CreateMetrizedSmallWorld(bool PrintProgress,
                                        const string& SpaceType,
                                        const Space<dist_t>* space,
                                        const ObjectVector& DataObjects,
                                        const AnyParams& AllParams) {

    return new Metrized_small_world<dist_t>(space, DataObjects, AllParams);
}

/*
 * End of creating functions.
 */

/*
 * Let's register creating functions in a method factory.
 *
 * IMPORTANT NOTE: don't include this source-file into a library.
 * Sometimes C++ carries out a lazy initialization of global objects
 * that are stored in a library. Then, the registration code doesn't work.
 */

REGISTER_METHOD_CREATOR(float,  METH_METRIZED_SMALL_WORLD, CreateMetrizedSmallWorld)
REGISTER_METHOD_CREATOR(double, METH_METRIZED_SMALL_WORLD, CreateMetrizedSmallWorld)
REGISTER_METHOD_CREATOR(int,    METH_METRIZED_SMALL_WORLD, CreateMetrizedSmallWorld)


}



