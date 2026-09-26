#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution js.cpp

samplegroup
sample sample01
sample sample02

group group1 100
include_group sample
tg_manual ../manual_data
