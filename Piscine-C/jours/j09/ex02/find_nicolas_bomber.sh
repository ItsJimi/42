#!/bin/sh
grep -E 'Bomber.*Nicolas' $1 | cut -c16- | rev | cut -c15- | rev
