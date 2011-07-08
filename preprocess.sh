#!/bin/sh
cat dfvifc_c.h | grep '^DFVINTERFACE_API' | grep -v 'wchar' | sed 's/DFVINTERFACE_API //' | sed 's/const //g' | sed 's/dfv_//' > prototypes
