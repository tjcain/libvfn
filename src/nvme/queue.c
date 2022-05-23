// SPDX-License-Identifier: LGPL-2.1-or-later or MIT

/*
 * This file is part of libvfn.
 *
 * Copyright (C) 2022 The libvfn Authors. All Rights Reserved.
 *
 * This library (libvfn) is dual licensed under the GNU Lesser General
 * Public License version 2.1 or later or the MIT license. See the
 * COPYING and LICENSE files for more information.
 */

#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vfn/nvme.h"

#include "support/log.h"

struct nvme_cqe *nvme_cq_poll(struct nvme_cq *cq)
{
	struct nvme_cqe *cqe;

	nvme_cq_spin(cq);

	cqe = nvme_cq_get_cqe(cq);
	assert(cqe);

	nvme_cq_update_head(cq);

	return cqe;
}