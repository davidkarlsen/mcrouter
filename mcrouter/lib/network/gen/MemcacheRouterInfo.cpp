/*
 *  Copyright (c) 2017, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#include "MemcacheRouterInfo.h"

#include <unordered_map>

#include <folly/Range.h>
#include <folly/dynamic.h>

#include <mcrouter/routes/ExtraRouteHandleProviderIf.h>
#include <mcrouter/routes/McRouteHandleProvider.h>

#include <mcrouter/lib/routes/NullRoute.h>
#include <mcrouter/routes/AllAsyncRouteFactory.h>
#include <mcrouter/routes/AllFastestRouteFactory.h>
#include <mcrouter/routes/AllInitialRouteFactory.h>
#include <mcrouter/routes/AllMajorityRouteFactory.h>
#include <mcrouter/routes/AllSyncRouteFactory.h>
#include <mcrouter/routes/DevNullRoute.h>
#include <mcrouter/routes/ErrorRouteFactory.h>
#include <mcrouter/routes/FailoverRoute.h>
#include <mcrouter/routes/HashRouteFactory.h>
#include <mcrouter/routes/HostIdRouteFactory.h>
#include <mcrouter/routes/LatestRoute.h>
#include <mcrouter/routes/LoggingRoute.h>
#include <mcrouter/routes/MigrateRouteFactory.h>
#include <mcrouter/routes/MissFailoverRoute.h>
#include <mcrouter/routes/ModifyKeyRoute.h>
#include <mcrouter/routes/OperationSelectorRoute.h>
#include <mcrouter/routes/OutstandingLimitRoute.h>
#include <mcrouter/routes/RandomRouteFactory.h>

#include <mcrouter/routes/McExtraRouteHandleProvider.h>

using namespace facebook::memcache;
using namespace facebook::memcache::mcrouter;

namespace facebook {
namespace memcache {

/* static */ MemcacheRouterInfo::RouteHandleFactoryMap
MemcacheRouterInfo::buildRouteMap() {
  RouteHandleFactoryMap map{
      {"AllAsyncRoute", &makeAllAsyncRoute<MemcacheRouterInfo>},
      {"AllFastestRoute", &makeAllFastestRoute<MemcacheRouterInfo>},
      {"AllInitialRoute", &makeAllInitialRoute<MemcacheRouterInfo>},
      {"AllMajorityRoute", &makeAllMajorityRoute<MemcacheRouterInfo>},
      {"AllSyncRoute", &makeAllSyncRoute<MemcacheRouterInfo>},
      {"DevNullRoute", &makeDevNullRoute<MemcacheRouterInfo>},
      {"ErrorRoute", &makeErrorRoute<MemcacheRouterInfo>},
      {"HashRoute",
       [](RouteHandleFactory<RouteHandleIf>& factory,
          const folly::dynamic& json) {
         return makeHashRoute<MemcacheRouterInfo>(factory, json);
       }},
      {"HostIdRoute", &makeHostIdRoute<MemcacheRouterInfo>},
      {"LatestRoute", &makeLatestRoute<MemcacheRouterInfo>},
      {"LoggingRoute", &makeLoggingRoute<MemcacheRouterInfo>},
      {"MigrateRoute", &makeMigrateRoute<MemcacheRouterInfo>},
      {"MissFailoverRoute", &makeMissFailoverRoute<MemcacheRouterInfo>},
      {"ModifyKeyRoute", &makeModifyKeyRoute<MemcacheRouterInfo>},
      {"NullRoute", &makeNullRoute<MemcacheRouteHandleIf>},
      {"OperationSelectorRoute",
       &makeOperationSelectorRoute<MemcacheRouterInfo>},
      {"RandomRoute", &makeRandomRoute<MemcacheRouterInfo>},
  };
  return map;
}

/* static */
std::unique_ptr<ExtraRouteHandleProviderIf<MemcacheRouterInfo>>
MemcacheRouterInfo::buildExtraProvider() {
  return std::make_unique<McExtraRouteHandleProvider<MemcacheRouterInfo>>();
}

} // memcache
} // facebook
