#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution js.cpp

samplegroup
sample sample01

group group1 100
include_group sample
tc_manual secret01
tc_manual secret02
tc_manual secret03
tc_manual secret04
tc_manual secret05
