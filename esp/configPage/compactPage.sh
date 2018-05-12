#!/bin/sh
cat ConfigPage_m.html | sed -z -E --expression='s/>[[:space:]]+</></g' | sed -z -E --expression="s/\"/'/g"