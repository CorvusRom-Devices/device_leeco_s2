/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>

#include "property_service.h"
#include "vendor_init.h"

void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties() {
    property_override("ro.build.description", "redfin-user 11 RQ3A.210605.005 7349499 release-keys");
    property_override("ro.vendor.build.description", "redfin-user 11 RQ3A.210605.005 7349499 release-keys");
    property_override("ro.system.build.description", "redfin-user 11 RQ3A.210605.005 7349499 release-keys");
    property_override("ro.bootimage.build.description", "redfin-user 11 RQ3A.210605.005 7349499 release-keys");
    property_override("ro.product.build.description", "redfin-user 11 RQ3A.210605.005 7349499 release-keys");
    property_override("ro.build.fingerprint", "google/redfin/redfin:11/RQ3A.210605.005/7349499:user/release-keys");
    property_override("ro.vendor.build.fingerprint", "google/redfin/redfin:11/RQ3A.210605.005/7349499:user/release-keys");
    property_override("ro.bootimage.build.fingerprint", "google/redfin/redfin:11/RQ3A.210605.005/7349499:user/release-keys");
    property_override("ro.system.build.fingerprint", "google/redfin/redfin:11/RQ3A.210605.005/7349499:user/release-keys");
    property_override("ro.product.build.fingerprint", "google/redfin/redfin:11/RQ3A.210605.005/7349499:user/release-keys");
    property_override("ro.oem_unlock_supported", "0");
}
