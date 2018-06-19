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

  base::FilePath home;
  if (!PathService::Get(base::DIR_HOME, &home))
    return base::FilePath();

  // If Brave is installed via Snap, use the sandboxed home directory.
  base::FilePath snap_user_data_dir =
    home.Append("snap").Append("brave").Append("current");
  if (base::DirectoryExists(snap_user_data_dir)) {
    result = snap_user_data_dir;
  } else {
    result = home;
  }

  return result.Append(".config").Append("brave");
}
