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

#ifndef INCLUDE_MODULES_BK_BLE_TYPES_H_
#define INCLUDE_MODULES_BK_BLE_TYPES_H_

#include <common/bk_typedef.h>

/**
 * @brief ble APIs Version 1.0
 * @addtogroup bk_ble_api_v1 New ble API group
 * @{
 */


typedef enum
{
    BK_BLE_CONTROLLER_STACK_TYPE_BLE_4,
    BK_BLE_CONTROLLER_STACK_TYPE_BLE_5_X,
    BK_BLE_CONTROLLER_STACK_TYPE_BTDM_5_2,
}BK_BLE_CONTROLLER_STACK_TYPE;


typedef enum
{
    BK_BLE_HOST_STACK_TYPE_RW_4,
    BK_BLE_HOST_STACK_TYPE_RW_5_X,
    BK_BLE_HOST_STACK_TYPE_RW_5_2,
    BK_BLE_HOST_STACK_TYPE_ETHERMIND,
}BK_BLE_HOST_STACK_TYPE;

/**
 * @brief hci type enum
 */
typedef enum
{
    BK_BLE_HCI_TYPE_CMD = 1,
    BK_BLE_HCI_TYPE_ACL = 2,
    BK_BLE_HCI_TYPE_SCO = 3,
    BK_BLE_HCI_TYPE_EVT = 4,
}BK_BLE_HCI_TYPE;


/**
 * @brief ble api return enum
 */
typedef bk_err_t ble_err_t;

#define BK_ERR_BLE_SUCCESS               BK_OK                      /**< success */
#define BK_ERR_BLE_FAIL                  BK_FAIL                    /**< fail        */
#define BK_ERR_BLE_NO_MEM                BK_ERR_NO_MEM              /**<  no mem       */
#define BK_ERR_BLE_PROFILE               (BK_ERR_BLE_BASE - 1)      /**<  profile err       */
#define BK_ERR_BLE_CREATE_DB             (BK_ERR_BLE_BASE - 2)      /**< bk_ble_create_db err        */
#define BK_ERR_BLE_CMD_NOT_SUPPORT       (BK_ERR_BLE_BASE - 3)      /**< unknow cmd err        */
#define BK_ERR_BLE_UNKNOW_IDX            (BK_ERR_BLE_BASE - 4)      /**< index err, suchas conn_ind        */
#define BK_ERR_BLE_BLE_STATUS            (BK_ERR_BLE_BASE - 5)      /**<  ble status not match       */
#define BK_ERR_BLE_ADV_DATA              (BK_ERR_BLE_BASE - 6)      /**<  adv data err, such as too long       */
#define BK_ERR_BLE_CMD_RUN               (BK_ERR_BLE_BASE - 7)      /**< cmd run err        */
#define BK_ERR_BLE_INIT_CREATE           (BK_ERR_BLE_BASE - 8)      /**< create init err, such as bk_ble_create_init        */
#define BK_ERR_BLE_INIT_STATE            (BK_ERR_BLE_BASE - 9)      /**<  current init status not match       */
#define BK_ERR_BLE_ATTC_WRITE            (BK_ERR_BLE_BASE - 10)     /**<  att write err       */
#define BK_ERR_BLE_ATTC_WRITE_UNREGISTER (BK_ERR_BLE_BASE - 11)     /**<  att handle is not regist       */




/// max ble adv data len
#define BK_BLE_MAX_ADV_DATA_LEN           (0x1F)

/// BD address length
#define BK_BLE_GAP_BD_ADDR_LEN       (6)
/// Maximal length of the Device Name value
#define BK_BLE_APP_DEVICE_NAME_MAX_LEN      (18)



/**
 * @brief for ble_attm_desc_t, build database perm,
 *
 */

#define BK_BLE_PERM_SET(access, right) \
    (((BK_BLE_PERM_RIGHT_ ## right) << (BK_BLE_ ## access ## _POS)) & (BK_BLE_ ## access ## _MASK))

#define BK_BLE_PERM_GET(perm, access)\
    (((perm) & (BK_BLE_ ## access ## _MASK)) >> (BK_BLE_ ## access ## _POS))



/**
 * @brief normal perm, for BK_BLE_PERM_SET
 * @attention you cant use this direct, use BK_BLE_PERM_SET(RD, ENABLE) instead
 * @brief
 *   15   14   13   12   11   10    9    8    7    6    5    4    3    2    1    0
 * +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
 * |EXT | WS | I  | N  | WR | WC | RD | B  |    NP   |    IP   |   WP    |    RP   |
 * +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
 *
 * Bit [0-1]  : Read Permission         (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 * Bit [2-3]  : Write Permission        (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 * Bit [4-5]  : Indication Permission   (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 * Bit [6-7]  : Notification Permission (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = SEC_CON)
 *
 * Bit [8]    : Broadcast permission
 * Bit [9]    : Read Command accepted
 * Bit [10]   : Write Command accepted
 * Bit [11]   : Write Request accepted
 * Bit [12]   : Send Notification
 * Bit [13]   : Send Indication
 * Bit [14]   : Write Signed accepted
 * Bit [15]   : Extended properties present
 */

typedef enum
{
    /// Read Permission Mask
    BK_BLE_RP_MASK             = 0x0003,
    BK_BLE_RP_POS              = 0,
    /// Write Permission Mask
    BK_BLE_WP_MASK             = 0x000C,
    BK_BLE_WP_POS              = 2,
    /// Indication Access Mask
    BK_BLE_IP_MASK            = 0x0030,
    BK_BLE_IP_POS             = 4,
    /// Notification Access Mask
    BK_BLE_NP_MASK            = 0x00C0,
    BK_BLE_NP_POS             = 6,
    /// Broadcast descriptor present
    BK_BLE_BROADCAST_MASK     = 0x0100,
    BK_BLE_BROADCAST_POS      = 8,
    /// Read Access Mask
    BK_BLE_RD_MASK            = 0x0200,
    BK_BLE_RD_POS             = 9,
    /// Write Command Enabled attribute Mask
    BK_BLE_WRITE_COMMAND_MASK = 0x0400,
    BK_BLE_WRITE_COMMAND_POS  = 10,
    /// Write Request Enabled attribute Mask
    BK_BLE_WRITE_REQ_MASK     = 0x0800,
    BK_BLE_WRITE_REQ_POS      = 11,
    /// Notification Access Mask
    BK_BLE_NTF_MASK           = 0x1000,
    BK_BLE_NTF_POS            = 12,
    /// Indication Access Mask
    BK_BLE_IND_MASK           = 0x2000,
    BK_BLE_IND_POS            = 13,
    /// Write Signed Enabled attribute Mask
    BK_BLE_WRITE_SIGNED_MASK  = 0x4000,
    BK_BLE_WRITE_SIGNED_POS   = 14,
    /// Extended properties descriptor present
    BK_BLE_EXT_MASK           = 0x8000,
    BK_BLE_EXT_POS            = 15,
} bk_ble_perm_mask;


/**
 * @brief Attribute Extended permissions, for BK_BLE_PERM_SET
 * @attention you cant use this direct, use BK_BLE_PERM_SET(EKS, ENABLE) instead
 * @brief
 *
 * Extended Value permission bit field
 *
 *   15   14   13   12   11   10    9    8    7    6    5    4    3    2    1    0
 * +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
 * | RI |UUID_LEN |EKS |                       Reserved                            |
 * +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
 *
 * Bit [0-11] : Reserved
 * Bit [12]   : Encryption key Size must be 16 bytes
 * Bit [13-14]: UUID Length             (0 = 16 bits, 1 = 32 bits, 2 = 128 bits, 3 = RFU)
 * Bit [15]   : Trigger Read Indication (0 = Value present in Database, 1 = Value not present in Database)
 */
typedef enum
{
    /// Check Encryption key size Mask
    BK_BLE_EKS_MASK         = 0x1000,
    BK_BLE_EKS_POS          = 12,
    /// UUID Length
    BK_BLE_UUID_LEN_MASK    = 0x6000,
    BK_BLE_UUID_LEN_POS     = 13,
    /// Read trigger Indication
    BK_BLE_RI_MASK          = 0x8000,
    BK_BLE_RI_POS           = 15,
} bk_ble_ext_perm_mask;


/**
 * @brief Service permissions, for BK_BLE_PERM_SET
 * @attention you cant use this direct, use BK_BLE_PERM_SET(SVC_UUID_LEN, UUID_16) instead
 * @brief
 *
 *    7    6    5    4    3    2    1    0
 * +----+----+----+----+----+----+----+----+
 * |SEC |UUID_LEN |DIS |  AUTH   |EKS | MI |
 * +----+----+----+----+----+----+----+----+
 *
 * Bit [0]  : Task that manage service is multi-instantiated (Connection index is conveyed)
 * Bit [1]  : Encryption key Size must be 16 bytes
 * Bit [2-3]: Service Permission      (0 = NO_AUTH, 1 = UNAUTH, 2 = AUTH, 3 = Secure Connect)
 * Bit [4]  : Disable the service
 * Bit [5-6]: UUID Length             (0 = 16 bits, 1 = 32 bits, 2 = 128 bits, 3 = RFU)
 * Bit [7]  : Secondary Service       (0 = Primary Service, 1 = Secondary Service)
 */
typedef enum
{
    /// Task that manage service is multi-instantiated
    BK_BLE_SVC_MI_MASK        = 0x01,
    BK_BLE_SVC_MI_POS         = 0,
    /// Check Encryption key size for service Access
    BK_BLE_SVC_EKS_MASK       = 0x02,
    BK_BLE_SVC_EKS_POS        = 1,
    /// Service Permission authentication
    BK_BLE_SVC_AUTH_MASK      = 0x0C,
    BK_BLE_SVC_AUTH_POS       = 2,
    /// Disable the service
    BK_BLE_SVC_DIS_MASK       = 0x10,
    BK_BLE_SVC_DIS_POS        = 4,
    /// Service UUID Length
    BK_BLE_SVC_UUID_LEN_MASK  = 0x60,
    BK_BLE_SVC_UUID_LEN_POS   = 5,
    /// Service type Secondary
    BK_BLE_SVC_SECONDARY_MASK = 0x80,
    BK_BLE_SVC_SECONDARY_POS  = 7,
} bk_ble_svc_perm_mask;


/*
 * @brief Attribute & Service access mode, for BK_BLE_PERM_SET
 * @attention you cant use this direct, use BK_BLE_PERM_SET(RD, ENABLE) instead
 *
 */

enum
{
    /// Disable access
    BK_BLE_PERM_RIGHT_DISABLE   = 0,
    /// Enable access
    BK_BLE_PERM_RIGHT_ENABLE   = 1,
};


/*
 * @brief Attribute & Service access rights, for BK_BLE_PERM_SET
 * @attention you cant use this direct, use BK_BLE_PERM_SET(SVC_AUTH, UNAUTH) instead
 *
 */
enum
{
    /// No Authentication
    BK_BLE_PERM_RIGHT_NO_AUTH  = 0,
    /// Access Requires Unauthenticated link
    BK_BLE_PERM_RIGHT_UNAUTH   = 1,
    /// Access Requires Authenticated link
    BK_BLE_PERM_RIGHT_AUTH     = 2,
    /// Access Requires Secure Connection link
    BK_BLE_PERM_RIGHT_SEC_CON  = 3,
};

/*
 * @brief Attribute & Service UUID Length, for BK_BLE_PERM_SET
 * @attention you cant use this direct, use BK_BLE_PERM_SET(SVC_UUID_LEN, UUID_16) instead
 *
 */
enum
{
    /// 16  bits UUID
    BK_BLE_PERM_RIGHT_UUID_16         = 0,
    /// 32  bits UUID
    BK_BLE_PERM_RIGHT_UUID_32         = 1,
    /// 128 bits UUID
    BK_BLE_PERM_RIGHT_UUID_128        = 2,
    /// Invalid
    BK_BLE_PERM_RIGHT_UUID_RFU        = 3,
};

/*
 * @brief for ble api async call result in ble_at_cmd_cb's cmd
 */
typedef enum
{
    BLE_CMD_NONE,
    /// ADV_CMD:FOR BLE 5.1
    BLE_CREATE_ADV,
    BLE_SET_ADV_DATA,
    BLE_SET_RSP_DATA,
    BLE_START_ADV,
    BLE_STOP_ADV,
    BLE_DELETE_ADV,
    /// ADV_CMD:FOR BLE 4.2
    BLE_INIT_ADV,
    BLE_DEINIT_ADV,
    /// SCAN_CMD:FOR BLE 5.1
    BLE_CREATE_SCAN,
    BLE_START_SCAN,
    BLE_STOP_SCAN,
    BLE_DELETE_SCAN,
    /// SCAN_CMD:FOR BLE 4.2
    BLE_INIT_SCAN,
    BLE_DEINIT_SCAN,
    /// conn
    BLE_CONN_UPDATE_MTU,
    BLE_CONN_UPDATE_PARAM,
    BLE_CONN_DIS_CONN,
    BLE_CONN_READ_PHY,
    BLE_CONN_SET_PHY,

    /// init
    BLE_INIT_CREATE,
    BLE_INIT_START_CONN,
    BLE_INIT_STOP_CONN,
    BLE_INIT_DIS_CONN,
    BLE_INIT_READ_CHAR,
    BLE_INIT_WRITE_CHAR,
    ///config
    BLE_SET_MAX_MTU,

    // PERIODIC
    BLE_CREATE_PERIODIC,
    BLE_START_PERIODIC,
    BLE_STOP_PERIODIC,
    BLE_DELETE_PERIODIC,

    BLE_SET_LOCAL_NAME,
    BLE_GET_LOCAL_NAME,

    BLE_READ_LOCAL_ADDR,
    BLE_CMD_MAX,
} ble_cmd_t;


/*
 * @brief used in bk_ble_set_notice_cb, this enum show as "notice", you must analyse param in same time
 */
typedef enum
{
    /// ble stack init ok, param null
    BLE_5_STACK_OK,
    /// peer write our, param ble_write_req_t
    BLE_5_WRITE_EVENT,
    /// peer read our, param ble_read_req_t
    BLE_5_READ_EVENT,
    /// scan peer adv report, param ble_recv_adv_t
    BLE_5_REPORT_ADV,
    /// mtu change event, param ble_mtu_change_t
    BLE_5_MTU_CHANGE,
    /// as slaver, recv connnect event, param ble_conn_ind_t
    BLE_5_CONNECT_EVENT,
    /// recv disconnect event, param ble_discon_ind_t
    BLE_5_DISCONNECT_EVENT,
    BLE_5_ATT_INFO_REQ,
    /// create db event, param ble_create_db_t
    BLE_5_CREATE_DB,
    /// tx complete event, param null
    BLE_5_TX_DONE,
    ///smp report
    BLE_5_PAIRING_REQ,
    BLE_5_PAIRING_SUCCEED,
    BLE_5_PAIRING_FAILED,
    BLE_5_PARING_PASSKEY_REQ,
    BLE_5_ENCRYPT_EVENT,

    /// as master, recv connect event
    BLE_5_INIT_CONNECT_EVENT,
    BLE_5_INIT_DISCONNECT_EVENT,
    BLE_5_INIT_CONNECT_FAILED_EVENT,

    BLE_5_SDP_REGISTER_FAILED,
    /// get current conn phy result, param ble_read_phy_t
    BLE_5_READ_PHY_EVENT,
    /// recv conn update event, param ble_conn_param_t
    BLE_5_CONN_UPDATA_EVENT,

    BLE_5_PERIODIC_SYNC_CMPL_EVENT,

    BLE_5_DISCOVERY_PRIMARY_SERVICE_EVENT,
    BLE_5_DISCOVERY_CHAR_EVENT,

    BLE_5_RECV_NOTIFY_EVENT,

    BLE_5_ATT_READ_RESPONSE,

    BLE_5_CONN_UPD_PAR_ASK,
} ble_notice_t;

typedef enum{
    CHARAC_NOTIFY,
    CHARAC_INDICATE,
    CHARAC_READ,
    CHARAC_READ_DONE,
    CHARAC_WRITE_DONE,
}CHAR_TYPE;

typedef void (*app_sdp_callback)(unsigned char conidx,uint16_t chars_val_hdl,unsigned char uuid_len,unsigned char *uuid);
typedef void (*app_sdp_charac_callback)(CHAR_TYPE type,uint8 conidx,uint16_t hdl,uint16_t len,uint8 *data);

struct ble_sdp_svc_ind
{
    /// Service UUID Length
    uint8_t  uuid_len;
    /// Service UUID
    uint8_t  uuid[16];
    /// Service start handle
    uint16_t start_hdl;
    /// Service end handle
    uint16_t end_hdl;
};

/// characteristic info
struct ble_sdp_char_inf
{
    /// Characteristic UUID Length
    uint8_t uuid_len;
    /// Characteristic UUID
    uint8_t uuid[16];
    /// Characteristic handle
    uint16_t char_hdl;
    /// Value handle
    uint16_t val_hdl;
    /// Characteristic properties
    uint8_t prop;
    /// End of characteristic offset
    uint8_t char_ehdl_off;
};

/// characteristic description
struct ble_sdp_char_desc_inf
{
     /// UUID length
    uint8_t uuid_len;
    /// UUID
    uint8_t uuid[16];

    uint8_t char_code;
    /// Descriptor handle
    uint16_t desc_hdl;
};

typedef struct
{
    uint8_t conn_idx;
	uint8_t status;
} ble_smp_ind_t;


typedef enum{
	MST_TYPE_SVR_UUID = 0,
	MST_TYPE_ATT_UUID,
	MST_TYPE_ATT_DESC,
	MST_TYPE_SDP_END,

	MST_TYPE_ATTC_SVR_UUID,  ///Service the UUID
	MST_TYPE_ATTC_ATT_UUID,  ///ATT of a service
	MST_TYPE_ATTC_ATT_DESC,  ///ATT DESC of a service
	MST_TYPS_ATTC_PARAM_ERR,  ///The delivered parameter is abnormal or unknown
	MST_TYPE_ATTC_ERR,	 ///if appm_get_init_attc_info return is ok && ble is disconnect,so update the event
	MST_TYPE_ATTC_END,	 ///End of the operation
	MST_TYPE_ATTC_WRITE_RSP,
	MST_TYPE_ATTC_WRITE_NO_RESPONSE,
	MST_TYPE_ATTC_CHARAC_READ_DONE,

	MST_TYPE_MTU_EXC = 0x10,
	MST_TYPE_MTU_EXC_DONE,

	MST_TYPE_UPP_ASK = 0x20,   ///Ask if you agree to update the parameter
	MST_TYPE_UPDATA_STATUS,    ////updata param status


}MASTER_COMMON_TYPE;
typedef void (*app_sdp_comm_callback)(MASTER_COMMON_TYPE type,uint8 conidx,void *param);

enum msg_attc{
	MST_ATTC_ALL = 0,
	MST_ATTC_GET_SVR_UUID_ALL,  ////Gets all the services for this connection
	MST_ATTC_GET_SVR_UUID_BY_SVR_UUID,
	MST_ATTC_GET_ATT_UUID_ALL,  ////Gets all the ATT's for this connection
	MST_ATTC_GET_ATT_DESC_UUID_ALL,  ////Gets all the ATT-DESC's for this connection
	MST_ATTC_SVR_ATT_BY_SVR_UUID, ////Gets all ATT's for this SVR-UUID for this connection
	MST_ATTC_SVR_ATT_DESC_BY_SVR_UUID, ///Gets all ATT-DESC's for this SVR-UUID for this connection
	MST_ATTC_SVR_ATT_AND_DESC_BY_SVR_UUID, ///Gets all ATT and ATT-DESC's for this SVR-UUID for this connection
};

struct ble_attc_wr_rd_op
{
    /// Status of the request
    uint8_t status;
    /// operation sequence number - provided when operation is started
    uint16_t seq_num;
};

struct ble_attc_event_ind
{
    /// Event Type
    enum msg_attc type;

    uint8_t uuid_len;
    uint8_t uuid[16];

    ///if start_hdl = end_hdl = 0,it is invaild
    uint16_t start_hdl;
    uint16_t end_hdl;
};

/**
 * @defgroup bk_ble_api_v1_typedef struct
 * @brief ble struct type
 * @ingroup bk_ble_api_v1_typedef struct
 * @{
 */

typedef struct
{
    uint8_t cmd_idx;      /**< actv_idx */
    ble_err_t status;     /**< The status for this command */
} ble_cmd_param_t;

typedef struct
{
    uint8_t conn_idx;     /**< The index of the connection */
    uint16_t prf_id;      /**< The id of the profile */
    uint16_t att_idx;     /**< The index of the attribute */
    uint16_t length;      /**< The length of the attribute */
    uint8_t status;       /**< Use to know if it's possible to modify the attribute ,can contains authorization or application error code */
} ble_att_info_req_t;

typedef struct
{
    uint8_t conn_idx;     /**< The index of the connection */
    uint16_t prf_id;      /**< The id of the profile */
    uint16_t att_idx;     /**< The index of the attribute */
    uint8_t *value;       /**< The attribute value */
    uint16_t len;         /**< The length of the attribute value */
} ble_write_req_t;

typedef struct
{
    uint8_t conn_idx;     /**< The index of the connection */
    uint16_t prf_id;      /**< The id of the profile */
    uint16_t att_idx;     /**< The index of the attribute */
    uint8_t *value;       /**< The attribute value */
    uint16_t size;        /**< The size of attribute value to read*/
    uint16_t length;      /**< The data length read */
} ble_read_req_t;

typedef struct
{
    uint8_t actv_idx;     /**< The index of the activity */
    uint8_t evt_type;     /**< Event type */
    uint8_t adv_addr_type;/**< Advertising address type: public/random */
    uint8_t adv_addr[6];  /**<Advertising address value */
    uint8_t data_len;     /**< Data length in advertising packet */
    uint8_t *data;        /**< Data of advertising packet */
    uint8_t rssi;         /**< RSSI value for advertising packet (in dBm, between -127 and +20 dBm) */
} ble_recv_adv_t;

typedef struct
{
    uint8_t conn_idx;     /**< The index of connection */
    uint16_t mtu_size;    /**< The MTU size to exchange */
} ble_mtu_change_t;

typedef struct
{
    /// The index of connection
    uint8_t conn_idx;
    /// Peer address type
    uint8_t peer_addr_type;
    /// Peer BT address
    uint8_t peer_addr[6];
    /// Clock accuracy
    uint8_t clk_accuracy;
    /// Connection interval
    uint16_t con_interval;
    /// Connection latency
    uint16_t con_latency;
    /// Link supervision timeout
    uint16_t sup_to;
} ble_conn_ind_t;

typedef struct
{
    /// The index of connection
    uint8_t conn_idx;
    /// Reason of disconnection
    uint8_t reason;
} ble_discon_ind_t;

typedef struct
{
    uint8_t status;      /**< The status for creating db */
    uint8_t prf_id;      /**< The id of the profile */
} ble_create_db_t;

typedef struct
{
    /// 16 bits UUID LSB First
    uint8_t uuid[16];
    /// Attribute Permissions (see enum attm_perm_mask)
    uint16_t perm;
    /// Attribute Extended Permissions (see enum attm_value_perm_mask)
    uint16_t ext_perm;
    /// Attribute Max Size
    /// note: for characteristic declaration contains handle offset
    /// note: for included service, contains target service handle
    uint16_t max_size;
} ble_attm_desc_t;

struct bk_ble_db_cfg
{
    uint16_t prf_task_id;
    ///Service uuid
    uint8_t uuid[16];
    ///Number of db
    uint8_t att_db_nb;
    ///Start handler, 0 means autoalloc
    uint16_t start_hdl;
    ///Attribute database
    ble_attm_desc_t *att_db;
    ///Service config
    uint8_t svc_perm;
};

typedef struct
{
    //TODO put customer specific init configuration here
} ble_init_config_t;

typedef struct
{
    uint8_t addr[BK_BLE_GAP_BD_ADDR_LEN];
} bd_addr_t;

typedef struct
{
    uint8_t  tx_phy;                       /**< The transmitter PHY */
    uint8_t  rx_phy;                       /**< The receiver PHY */
} ble_read_phy_t;

typedef struct
{
    uint8_t  tx_phy;                       /**< The transmitter PHY */
    uint8_t  rx_phy;                       /**< The receiver PHY */
    uint8_t  phy_opt;                       /**< PHY options  */
} ble_set_phy_t;

typedef struct
{
    /// Own address type:  public=0 / random=1 / rpa_or_pub=2 / rpa_or_rnd=3
    uint8_t own_addr_type;
    /// Advertising type (@see enum gapm_adv_type)
    uint8_t adv_type;
    /// Bit field indicating the channel mapping
    uint8_t chnl_map;
    /// Bit field value provided advertising properties (@see enum gapm_adv_prop for bit signification)
    uint16_t adv_prop;
    /// Minimum advertising interval (in unit of 625us). Must be greater than 20ms
    uint32_t adv_intv_min;
    /// Maximum advertising interval (in unit of 625us). Must be greater than 20ms
    uint32_t adv_intv_max;
    /// Indicate on which PHY primary advertising has to be performed (@see enum gapm_phy_type)
    /// Note that LE 2M PHY is not allowed and that legacy advertising only support LE 1M PHY
    uint8_t prim_phy;
    /// Indicate on which PHY secondary advertising has to be performed (@see enum gapm_phy_type)
    uint8_t second_phy;
} ble_adv_param_t;

typedef struct
{
    /// Own address type (@see enum gapm_own_addr)
    uint8_t own_addr_type;
    /// on which the advertising packets should be received
    uint8_t scan_phy;
    /// Scan interval
    uint16_t scan_intv;
    /// Scan window
    uint16_t scan_wd;
} ble_scan_param_t;

typedef struct
{
    /// Connection interval minimum
    uint16_t intv_min;
    /// Connection interval maximum
    uint16_t intv_max;
    /// Connection latency
    uint16_t con_latency;
    /// Link supervision timeout
    uint16_t sup_to;
    /// on which the advertising packets should be received on the primary advertising physical channel
    uint8_t init_phys;
} ble_conn_param_t;


typedef struct
{

    /// Periodic synchronization type (@see enum gapm_per_sync_type)
//    uint8_t                         type;
    /// Connection index used for periodic sync info reception (only valid for GAPM_PER_SYNC_TYPE_PAST)
//    uint8_t                         conidx;

    /// 1 to disable periodic advertising report, 0 to enable them by default
    uint8_t                         report_disable;


    /// adv sid of advertiser
    uint8_t adv_sid;

    /// Address of advertiser with which synchronization has to be established (used only if use_pal is false)
    bd_addr_t adv_addr;

    uint8_t adv_addr_type;

    /// Number of periodic advertising that can be skipped after a successful receive. Maximum authorized
    /// value is 499
    uint16_t                        skip;
    /// Synchronization timeout for the periodic advertising (in unit of 10ms between 100ms and 163.84s)
    uint16_t                        sync_to;
    /// Type of Constant Tone Extension device should sync on (@see enum gapm_sync_cte_type).
    uint8_t                         cte_type;
} ble_periodic_param_t;


typedef struct
{
    uint8_t is_agree;   ///0:is not agree,1:is agree,0xFF;Let me think about it;other:is agree

    uint8_t conn_idx;

    /// Minimum Connection Event Duration
    uint16_t ce_len_min;
    /// Maximum Connection Event Duration
    uint16_t ce_len_max;

    /// Connection interval minimum
    uint16_t intv_min;
    /// Connection interval maximum
    uint16_t intv_max;
    /// Latency
    uint16_t latency;
    /// Supervision timeout
    uint16_t time_out;
} ble_conn_update_para_ind_t;



struct mst_comm_updata_para
{
    /// Status of the request
    uint8_t is_agree;   ///0:is not agree,1:is agree,0xFF;Let me think about it;other:is agree
    /// Minimum Connection Event Duration
    uint16_t ce_len_min;
    /// Maximum Connection Event Duration
    uint16_t ce_len_max;

    /// Connection interval minimum
    uint16_t intv_min;
    /// Connection interval maximum
    uint16_t intv_max;
    /// Latency
    uint16_t latency;
    /// Supervision timeout
    uint16_t time_out;
};

/**
 * @brief for sync ble api call return
 *
 * most ble api have ble_cmd_cb_t param, you must wait is callback.
 *
 * @param
 * - cmd: cmd id.
 * - param: param
 *
**/
typedef void (*ble_cmd_cb_t)(ble_cmd_t cmd, ble_cmd_param_t *param);

/**
 * @brief for async ble api event.
 *
 * ble event report.
 *
 * @param
 * - notice: event id.
 * - param: param
 *
**/
typedef void (*ble_notice_cb_t)(ble_notice_t notice, void *param);



/**
 * @brief for hci callback.
 *
 * stack report evt, acl to upper
 *
 * @param
 * - buf: payload
 * - len: buf's len
 *
 * @return
 * - BK_ERR_BLE_SUCCESS: succeed
**/
typedef ble_err_t (*ble_hci_to_host_cb)(uint8_t *buf, uint16_t len);

/// Authentication mask
enum gap_auth_mask
{
    /// No Flag set
    GAP_AUTH_NONE    = 0,
    /// Bond authentication
    GAP_AUTH_BOND    = (1 << 0),
    /// Man In the middle protection
    GAP_AUTH_MITM    = (1 << 2),
    /// Secure Connection
    GAP_AUTH_SEC_CON = (1 << 3),
    /// Key Notification
    GAP_AUTH_KEY_NOTIF = (1 << 4)
};

enum gap_auth
{
    /// No MITM No Bonding
    GAP_AUTH_REQ_NO_MITM_NO_BOND  = (GAP_AUTH_NONE),
    /// No MITM Bonding
    GAP_AUTH_REQ_NO_MITM_BOND     = (GAP_AUTH_BOND),
    /// MITM No Bonding
    GAP_AUTH_REQ_MITM_NO_BOND     = (GAP_AUTH_MITM),
    /// MITM and Bonding
    GAP_AUTH_REQ_MITM_BOND        = (GAP_AUTH_MITM | GAP_AUTH_BOND),
    /// SEC_CON and No Bonding
    GAP_AUTH_REQ_SEC_CON_NO_BOND  = (GAP_AUTH_SEC_CON | GAP_AUTH_MITM),
    /// SEC_CON and Bonding
    GAP_AUTH_REQ_SEC_CON_BOND     = (GAP_AUTH_SEC_CON | GAP_AUTH_MITM | GAP_AUTH_BOND),

    GAP_AUTH_REQ_LAST,

    /// Mask of  authentication features without reserved flag
    GAP_AUTH_REQ_MASK             = 0x1F,
};

/// IO Capability Values
enum gap_io_cap
{
    /// Display Only
    GAP_IO_CAP_DISPLAY_ONLY = 0x00,
    /// Display Yes No
    GAP_IO_CAP_DISPLAY_YES_NO,
    /// Keyboard Only
    GAP_IO_CAP_KB_ONLY,
    /// No Input No Output
    GAP_IO_CAP_NO_INPUT_NO_OUTPUT,
    /// Keyboard Display
    GAP_IO_CAP_KB_DISPLAY,
    GAP_IO_CAP_LAST
};

/// Security Defines
enum gap_sec_req
{
    /// No security (no authentication and encryption)
    GAP_NO_SEC = 0x00,
    /// Unauthenticated pairing with encryption
    GAP_SEC1_NOAUTH_PAIR_ENC,
    /// Authenticated pairing with encryption
    GAP_SEC1_AUTH_PAIR_ENC,
    /// Unauthenticated pairing with data signing
    GAP_SEC2_NOAUTH_DATA_SGN,
    /// Authentication pairing with data signing
    GAP_SEC2_AUTH_DATA_SGN,
    /// Secure Connection pairing with encryption
    GAP_SEC1_SEC_CON_PAIR_ENC,
};

/// OOB Data Present Flag Values
enum gap_oob
{
    /// OOB Data not present
    GAP_OOB_AUTH_DATA_NOT_PRESENT = 0x00,
    /// OOB data present
    GAP_OOB_AUTH_DATA_PRESENT,
    GAP_OOB_AUTH_DATA_LAST
};

/**
 * @}
 */


/**
 * @}
 */

#endif /* INCLUDE_MODULES_BK_BLE_TYPES_H_ */
