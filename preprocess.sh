#!/bin/sh
cat dfvifc_c.h | grep '^DFVINTERFACE_API' | grep -v 'wchar' | sed 's/DFVINTERFACE_API //' | sed 's/const //' | sed 's/dfv_//' > prototypes
