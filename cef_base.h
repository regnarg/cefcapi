// Copyright (c) 2014 The cefcapi authors. All rights reserved.
// License: BSD 3-clause.
// Website: https://github.com/CzarekTomczak/cefcapi

#pragma once

#include "include/capi/cef_base_capi.h"

// Set to 1 to check if add_ref() and release()
// are called and to track the total number of calls.
// add_ref will be printed as "+", release as "-".
#define DEBUG_REFERENCE_COUNTING 0

// Print only the first execution of the callback,
// ignore the subsequent.
#define DEBUG_CALLBACK(x) { static int first_call = 1; if (first_call == 1) { first_call = 0; printf(x); } }

// ----------------------------------------------------------------------------
// cef_base_t
// ----------------------------------------------------------------------------

void initialize_cef_base(cef_base_t* base) {
    printf("initialize_cef_base\n");
    // Check if "size" member was set.
    size_t size = base->size;
    // Let's print the size in case sizeof was used
    // on a pointer instead of a structure. In such
    // case the number will be very high.
    printf("cef_base_t.size = %lu\n", (unsigned long)size);
    if (size <= 0) {
        printf("FATAL: initialize_cef_base failed, size member not set\n");
        _exit(1);
    }
}
