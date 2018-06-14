/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/common/importer/brave_importer_utils.h"

#include "base/base_paths.h"
#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/path_service.h"

base::FilePath GetBraveUserDataFolder() {
  base::FilePath result;
  if (!PathService::Get(base::DIR_HOME, &result))
    return base::FilePath();

  // TODO: On Ubuntu 16.04, when Brave is installed with Snap, session-store-1 is stored in
  // ./snap/brave/23/.config/brave/session-store-1. Yuck!
  result = result.Append(".config");
  result = result.Append("brave");

  return result;
}
