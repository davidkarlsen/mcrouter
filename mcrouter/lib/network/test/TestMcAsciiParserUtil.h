/*
 *  Copyright (c) 2015, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <stddef.h>
#include <memory>
#include <vector>

namespace folly {
class IOBuf;
}  // folly

namespace facebook { namespace memcache {

/**
 * Given total data length and max piece size, generates all possible
 * combinations to split data in chunks.
 */
std::vector<std::vector<size_t>> genChunkedDataSets(size_t length,
                                                    size_t maxPieceSize);

/**
 * Given total data length and max piece size, returns number of
 * combinations to split data in chunks.
 */
size_t chunkedDataSetsCnt(size_t length, size_t maxPieceSize);

std::unique_ptr<folly::IOBuf> chunkData(folly::IOBuf data,
                                        const std::vector<size_t>& pieces);

}}  // facebook::memcache
