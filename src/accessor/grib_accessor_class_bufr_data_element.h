
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

#include "grib_accessor_class_gen.h"

class grib_accessor_bufr_data_element_t : public grib_accessor_gen_t
{
public:
    /* Members defined in bufr_data_element */
    long index;
    int type;
    long compressedData;
    long subsetNumber;
    long numberOfSubsets;
    bufr_descriptors_array* descriptors;
    grib_vdarray* numericValues;
    grib_vsarray* stringValues;
    grib_viarray* elementsDescriptorsIndex;
    char* cname;
};

class grib_accessor_class_bufr_data_element_t : public grib_accessor_class_gen_t
{
public:
    grib_accessor_class_bufr_data_element_t(const char* name) : grib_accessor_class_gen_t(name) {}
    grib_accessor* create_empty_accessor() override { return new grib_accessor_bufr_data_element_t{}; }
    int get_native_type(grib_accessor*) override;
    int pack_missing(grib_accessor*) override;
    int is_missing(grib_accessor*) override;
    int pack_double(grib_accessor*, const double* val, size_t* len) override;
    int pack_long(grib_accessor*, const long* val, size_t* len) override;
    int pack_string(grib_accessor*, const char*, size_t* len) override;
    int pack_string_array(grib_accessor*, const char**, size_t* len) override;
    int unpack_double(grib_accessor*, double* val, size_t* len) override;
    int unpack_long(grib_accessor*, long* val, size_t* len) override;
    int unpack_string(grib_accessor*, char*, size_t* len) override;
    int unpack_string_array(grib_accessor*, char**, size_t* len) override;
    int value_count(grib_accessor*, long*) override;
    void destroy(grib_context*, grib_accessor*) override;
    void dump(grib_accessor*, grib_dumper*) override;
    void init(grib_accessor*, const long, grib_arguments*) override;
    int unpack_double_element(grib_accessor*, size_t i, double* val) override;
    grib_accessor* make_clone(grib_accessor*, grib_section*, int*) override;
};
