/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Wed Apr 18 23:17:14 2018. */

#ifndef PB_TEMPERATURE_PB_H_INCLUDED
#define PB_TEMPERATURE_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _Config {
    bool has_target;
    float target;
    bool has_gisteris;
    float gisteris;
    bool has_tuningSensor;
    float tuningSensor;
/* @@protoc_insertion_point(struct:Config) */
} Config;

typedef struct _Notify {
    bool has_current;
    float current;
    bool has_heatingState;
    uint32_t heatingState;
    bool has_coolingState;
    uint32_t coolingState;
/* @@protoc_insertion_point(struct:Notify) */
} Notify;

typedef struct _Temperature {
    bool has_notify;
    Notify notify;
    bool has_config;
    Config config;
/* @@protoc_insertion_point(struct:Temperature) */
} Temperature;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Temperature_init_default                 {false, Notify_init_default, false, Config_init_default}
#define Notify_init_default                      {false, 0, false, 0, false, 0}
#define Config_init_default                      {false, 0, false, 0, false, 0}
#define Temperature_init_zero                    {false, Notify_init_zero, false, Config_init_zero}
#define Notify_init_zero                         {false, 0, false, 0, false, 0}
#define Config_init_zero                         {false, 0, false, 0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define Config_target_tag                        1
#define Config_gisteris_tag                      2
#define Config_tuningSensor_tag                  3
#define Notify_current_tag                       1
#define Notify_heatingState_tag                  2
#define Notify_coolingState_tag                  3
#define Temperature_notify_tag                   1
#define Temperature_config_tag                   2

/* Struct field encoding specification for nanopb */
extern const pb_field_t Temperature_fields[3];
extern const pb_field_t Notify_fields[4];
extern const pb_field_t Config_fields[4];

/* Maximum encoded size of messages (where known) */
#define Temperature_size                         36
#define Notify_size                              17
#define Config_size                              15

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPERATURE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
