
/*
 * (C) Copyright 2005- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * In applying this licence, ECMWF does not waive the privileges and immunities granted to it by
 * virtue of its status as an intergovernmental organisation nor does it submit to any jurisdiction.
 */

#pragma once

#include "grib_accessor_class_unsigned.h"

class grib_accessor_codeflag_t : public grib_accessor_unsigned_t
{
public:
    /* Members defined in codeflag */
    const char* tablename;
};

class grib_accessor_class_codeflag_t : public grib_accessor_class_unsigned_t
{
public:
    grib_accessor_class_codeflag_t(const char* name) : grib_accessor_class_unsigned_t(name) {}
    grib_accessor* create_empty_accessor() override { return new grib_accessor_codeflag_t{}; }
    int value_count(grib_accessor*, long*) override;
    void dump(grib_accessor*, grib_dumper*) override;
    void init(grib_accessor*, const long, grib_arguments*) override;
};
