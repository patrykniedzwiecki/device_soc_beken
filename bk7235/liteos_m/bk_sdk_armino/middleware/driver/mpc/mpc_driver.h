// Copyright (C) 2022 Beken Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <components/log.h>

#define MPC_TAG "mpc"
#define MPC_LOGI(...) BK_LOGI(MPC_TAG, ##__VA_ARGS__)
#define MPC_LOGW(...) BK_LOGW(MPC_TAG, ##__VA_ARGS__)
#define MPC_LOGE(...) BK_LOGE(MPC_TAG, ##__VA_ARGS__)
#define MPC_LOGD(...) BK_LOGD(MPC_TAG, ##__VA_ARGS__)

