#!/bin/ksh -p
#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#

#
# Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
#

#
# ID: create_004
#
# DESCRIPTION:
#        Verify can create 50000 byte file on the smbfs
#
# STRATEGY:
#       1. run "mount -F smbfs //server/public /export/mnt"
#       2. dd and rm can get the right message
#

. $STF_SUITE/include/libtest.ksh

tc_id="create004"
tc_desc=" Verify can create files on the smbfs"
print_test_case $tc_id - $tc_desc

if [[ $STC_CIFS_CLIENT_DEBUG == 1 ]] || \
	[[ *:${STC_CIFS_CLIENT_DEBUG}:* == *:$tc_id:* ]]; then
    set -x
fi

server=$(server_name) || return

testdir_init $TDIR
smbmount_clean $TMNT
smbmount_init $TMNT

cmd="mount -F smbfs //$TUSER:$TPASS@$server/public $TMNT"
cti_execute -i '' FAIL $cmd
if [[ $? != 0 ]]; then
	cti_fail "FAIL: smbmount can't mount the public share"
	return
else
	cti_report "PASS: smbmount can mount the public share"
fi

# create 50000 byte file
cmd="dd if=/dev/zero of=$TMNT/file50000 bs=500 count=100"
cti_execute_cmd $cmd
if [[ $? != 0 ]]; then
	cti_fail "FAIL: failed to dd a 50000b file"
	return
else
	cti_report "PASS: dd a 50000b file successfully"
fi

size=$(file_size $TMNT/file50000)
if ((size != 50000)); then
	cti_fail "FAIL: the file size($size) is != 50000"
	return
else
	cti_report "PASS: the file size($size) is 50000, it is right"
fi


# remove file
cmd="rm $TMNT/file50000"
cti_execute_cmd $cmd
if [[ $? != 0 ]]; then
	cti_fail "FAIL: failed to rm the file50000 file"
	return
else
	cti_report "PASS: rm the file50000 file successfully"
fi

if [[  -f "$TMNT/file50000" ]]; then
	cti_fail "FAIL: the file50000 should not exist, but it exists"
	return
else
	cti_report "PASS: the file50000 exists, it is right"
fi

smbmount_clean $TMNT
cti_pass "${tc_id}: PASS"
