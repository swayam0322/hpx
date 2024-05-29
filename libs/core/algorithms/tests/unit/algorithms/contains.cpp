//  Copyright (c) 2024 Zakaria Abdi
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <string>
#include <vector>

#include <hpx/init.hpp>
#include "contains_tests.hpp"

////////////////////////////////////////////////////////////////////////////
template <typename IteratorTag>
void test_contains()
{
    using namespace hpx::execution;

    test_contains(IteratorTag());

    test_contains(seq, IteratorTag());
    test_contains(par, IteratorTag());
    test_contains(par_unseq, IteratorTag());

    test_contains_async(seq(task), IteratorTag());
    test_contains_async(par(task), IteratorTag());
    test_contains_async(par_unseq(task), IteratorTag());
}

void contains_test()
{
    test_contains<std::random_access_iterator_tag>();
    test_contains<std::forward_iterator_tag>();
}

////////////////////////////////////////////////////////////////////////////
template <typename IteratorTag>
void test_contains_exception()
{
    using namespace hpx::execution;

    test_contains_exception(IteratorTag());

    test_contains_exception(seq, IteratorTag());
    test_contains_exception(par, IteratorTag());

    test_contains_exception_async(seq(task), IteratorTag());
    test_contains_exception_async(par(task), IteratorTag());
}

void contains_exception_test()
{
    test_contains_exception<std::random_access_iterator_tag>();
    test_contains_exception<std::forward_iterator_tag>();
}

////////////////////////////////////////////////////////////////////////////
template <typename IteratorTag>
void test_contains_bad_alloc()
{
    using namespace hpx::execution;

    test_contains_bad_alloc(seq, IteratorTag());
    test_contains_bad_alloc(par, IteratorTag());

    test_contains_bad_alloc_async(seq(task), IteratorTag());
    test_contains_bad_alloc_async(par(task), IteratorTag());
}

void contains_bad_alloc_test()
{
    test_contains_bad_alloc<std::random_access_iterator_tag>();
    test_contains_bad_alloc<std::forward_iterator_tag>();
}

int hpx_main(hpx::program_options::variables_map& vm)
{
    if (vm.count("seed"))
        seed = vm["seed"].as<unsigned int>();

    std::cout << "Using seed as: " << seed << std::endl;
    gen.seed(seed);

    contains_test();
    contains_exception_test();
    contains_bad_alloc_test();

    return hpx::local::finalize();
}

int main(int argc, char* argv[])
{
    using namespace hpx::program_options;
    options_description desc_commandline(
        "Usage" HPX_APPLICATION_STRING " [options]");

    desc_commandline.add_options()("seed,s", value<unsigned int>(),
        " the random number generator to use for this run");

    std::vector<std::string> cfg = {"hpx.os_threads=all"};

    hpx::local::init_params init_args;
    init_args.desc_cmdline = desc_commandline;
    init_args.cfg = cfg;

    HPX_TEST_EQ_MSG(hpx::local::init(hpx_main, argc, argv, init_args), 0,
        "HPX main exited with non-zero status");

    return hpx::util::report_errors();
}
