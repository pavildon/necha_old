#!/usr/bin/env bash

zig build test

TEST_BIN=$(find . -name test -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -f2- -d" ")

lldb $TEST_BIN

