/************************************************************
 * <bsn.cl fy=2014 v=onl>
 *
 *           Copyright 2014 Big Switch Networks, Inc.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 * </bsn.cl>
 ************************************************************
 *
 * Thermal Sensor Management.
 *
 ************************************************************/
#ifndef __ONLP_THERMAL_H__
#define __ONLP_THERMAL_H__

#include <onlp/onlp_config.h>
#include <onlp/onlp.h>
#include <onlp/oids.h>

/* <auto.start.enum(tag:thermal).define> */
/** onlp_thermal_status */
typedef enum onlp_thermal_status_e {
    ONLP_THERMAL_STATUS_PRESENT = (1 << 0),
    ONLP_THERMAL_STATUS_FAILED = (1 << 1),
} onlp_thermal_status_t;

/** onlp_thermal_caps */
typedef enum onlp_thermal_caps_e {
    ONLP_THERMAL_CAPS_GET_TEMPERATURE = (1 << 0),
} onlp_thermal_caps_t;
/* <auto.end.enum(tag:thermal).define> */

/**
 * Thermal sensor information structure.
 */
typedef struct onlp_thermal_info_s {

    /** OID Header */
    onlp_oid_hdr_t hdr;

    /** Status */
    uint32_t status;

    /** Capabilities */
    uint32_t caps;

    /* Current temperature in milli-celsius */
    int mcelsius;

} onlp_thermal_info_t;

/**
 * @brief Initialize the thermal subsystem.
 */
int onlp_thermal_init(void);

/**
 * @brief Retrieve information about the given thermal id.
 * @param id The thermal oid.
 * @param rv [out] Receives the thermal information.
 */
int onlp_thermal_info_get(onlp_oid_t id, onlp_thermal_info_t* rv);


/**
 * @brief Thermal driver ioctl.
 * @param code Thermal ioctl code.
 * @param ... Arguments
 */
int onlp_thermal_ioctl(int code, ...);


/**
 * @brief Thermal OID debug dump.
 * @param id The thermal id.
 * @param pvs The output pvs.
 * @param flags The dump flags.
 */
void onlp_thermal_dump(onlp_oid_t id, aim_pvs_t* pvs, uint32_t flags);

/**
 * @brief Show the given thermal OID.
 * @param id The Thermal OID
 * @param pvs The output pvs
 * @param flags The output flags
 */
void onlp_thermal_show(onlp_oid_t id, aim_pvs_t* pvs, uint32_t flags);




/******************************************************************************
 *
 * Enumeration Support Definitions.
 *
 * Please do not add additional code beyond this point.
 *
 *****************************************************************************/
/* <auto.start.enum(tag:thermal).supportheader> */
/** Enum names. */
const char* onlp_thermal_status_name(onlp_thermal_status_t e);

/** Enum values. */
int onlp_thermal_status_value(const char* str, onlp_thermal_status_t* e, int substr);

/** Enum descriptions. */
const char* onlp_thermal_status_desc(onlp_thermal_status_t e);

/** Enum validator. */
int onlp_thermal_status_valid(onlp_thermal_status_t e);

/** validator */
#define ONLP_THERMAL_STATUS_VALID(_e) \
    (onlp_thermal_status_valid((_e)))

/** onlp_thermal_status_map table. */
extern aim_map_si_t onlp_thermal_status_map[];
/** onlp_thermal_status_desc_map table. */
extern aim_map_si_t onlp_thermal_status_desc_map[];

/** Enum names. */
const char* onlp_thermal_caps_name(onlp_thermal_caps_t e);

/** Enum values. */
int onlp_thermal_caps_value(const char* str, onlp_thermal_caps_t* e, int substr);

/** Enum descriptions. */
const char* onlp_thermal_caps_desc(onlp_thermal_caps_t e);

/** Enum validator. */
int onlp_thermal_caps_valid(onlp_thermal_caps_t e);

/** validator */
#define ONLP_THERMAL_CAPS_VALID(_e) \
    (onlp_thermal_caps_valid((_e)))

/** onlp_thermal_caps_map table. */
extern aim_map_si_t onlp_thermal_caps_map[];
/** onlp_thermal_caps_desc_map table. */
extern aim_map_si_t onlp_thermal_caps_desc_map[];
/* <auto.end.enum(tag:thermal).supportheader> */

#endif /* __ONLP_THERMAL_H__ */
