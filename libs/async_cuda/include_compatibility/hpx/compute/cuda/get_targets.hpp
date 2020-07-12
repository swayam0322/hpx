//  Copyright (c) 2020 STE||AR Group
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/async_cuda/config/defines.hpp>
#include <hpx/async_cuda/get_targets.hpp>

#if defined(HPX_ASYNC_CUDA_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message("The header hpx/compute/cuda/get_targets.hpp is deprecated, \
    please include hpx/async_cuda/get_targets.hpp instead")
#else
#warning "The header hpx/compute/cuda/get_targets.hpp is deprecated, \
    please include hpx/async_cuda/get_targets.hpp instead"
#endif
#endif

namespace hpx { namespace compute { namespace cuda {
    using hpx::cuda::target;
}}}    // namespace hpx::compute::cuda
