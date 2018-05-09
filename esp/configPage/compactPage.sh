#!/bin/sh
cat ConfigPage.html | sed -z -E --expression='s/>[[:space:]]+</></g' | sed -z -E --expression="s/\"/'/g"