
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

#include "grib_accessor_class_section_length.h"

class grib_accessor_g1_message_length_t : public grib_accessor_section_length_t
{
public:
    /* Members defined in g1_message_length */
    const char *sec4_length;
};

class grib_accessor_class_g1_message_length_t : public grib_accessor_class_section_length_t
{
public:
    grib_accessor_class_g1_message_length_t(const char* name) : grib_accessor_class_section_length_t(name) {}
    grib_accessor* create_empty_accessor() override { return new grib_accessor_g1_message_length_t{}; }
    int pack_long(grib_accessor*, const long* val, size_t* len) override;
    int unpack_long(grib_accessor*, long* val, size_t* len) override;
    void init(grib_accessor*, const long, grib_arguments*) override;
};
