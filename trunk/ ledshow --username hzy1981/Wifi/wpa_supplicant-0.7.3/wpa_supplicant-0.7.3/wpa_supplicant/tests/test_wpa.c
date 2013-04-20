/*
 * Test program for combined WPA authenticator/supplicant
 * Copyright (c) 2006-2007, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#include "includes.h"

#include "wpa_common.h"
#include "eloop.h"
#include "common/ieee802_11_defs.h"
#include "../config.h"
#include "rsn_supp/wpa.h"
#include "rsn_supp/wpa_i.h"
#include "rsn_supp/wpa_ie.h"
//#include "../hostapd/wpa.h"


extern int wpa_debug_level;
extern int wpa_debug_show_keys;





struct wpa {
	u8 auth_addr[ETH_ALEN];
	u8 supp_addr[ETH_ALEN];
	u8 psk[PMK_LEN];

	/* from authenticator */
	u8 auth_eapol_dst[ETH_ALEN];
	u8 *auth_eapol;
	size_t auth_eapol_len;

	/* from supplicant */
	u8 *supp_eapol;
	size_t supp_eapol_len;

	struct wpa_sm *supp;
	struct wpa_authenticator *auth_group;
	struct wpa_state_machine *auth;

	struct wpa_ssid ssid;
	u8 supp_ie[80];
	size_t supp_ie_len;
};

struct wpa g_wpa;
struct wpa_sm_ctx g_ctx;


static int supp_get_bssid(void *ctx, u8 *bssid)
{
	struct wpa *wpa = ctx;
	wpa_printf(MSG_DEBUG, "SUPP: %s", __func__);
	os_memcpy(bssid, wpa->auth_addr, ETH_ALEN);
	return 0;
}

enum wpa_states newpower_time_out_current_state; /*这里用一个static变量保存当前WPA状态*/
static void supp_set_state(void *ctx, enum wpa_states state)
{
	wpa_printf(MSG_DEBUG, "SUPP: %s(state=%d)", __func__, state);
	newpower_time_out_current_state = state;
	if(state == 8)
	{
		recv_mac_event(999);
	}
}

static enum wpa_states supp_get_state(void *ctx)
{
	return newpower_time_out_current_state;
}


static void auth_eapol_rx(void *eloop_data, void *user_ctx)
{
	struct wpa *wpa = eloop_data;

	wpa_printf(MSG_DEBUG, "AUTH: RX EAPOL frame");
#if 0
	wpa_receive(wpa->auth_group, wpa->auth, wpa->supp_eapol,
		    wpa->supp_eapol_len);
#endif
}

extern int wpa_L2_send_pkt(u8 *buf,u16 len);
static int supp_ether_send(void *ctx, const u8 *dest, u16 proto, const u8 *buf,
			   size_t len)
{
	struct wpa *wpa = ctx;
	char * buffer;

	wpa_printf(MSG_DEBUG, "SUPP: %s(dest=" MACSTR " proto=0x%04x "
		   "len=%lu)",
		   __func__, MAC2STR(dest), proto, (unsigned long) len);

	

	buffer = os_malloc(6+6+2+len);
	memcpy(buffer,dest,6);
	memcpy(buffer+6,g_wpa.supp_addr,6);
	//memcpy(buffer+12,&proto,2);
	(*(buffer+12)) = 0x88;
	(*(buffer+13)) = 0x8e;
	memcpy(buffer + 12 + 2 , buf , len);
	dbug_buf("SEND EAPOL FRAME",buffer,len + 14);
	wpa_L2_send_pkt((char*)buffer,len+14);

	os_free(buffer);



	return 0;
}


static u8 * supp_alloc_eapol(void *ctx, u8 type, const void *data,
			     u16 data_len, size_t *msg_len, void **data_pos)
{
	struct ieee802_1x_hdr *hdr;

	wpa_printf(MSG_DEBUG, "SUPP: %s(type=%d data_len=%d)",
		   __func__, type, data_len);

	*msg_len = sizeof(*hdr) + data_len;
	hdr = os_malloc(*msg_len);
	memset(hdr,0x0,*msg_len);
	if (hdr == NULL)
		return NULL;

	hdr->version = 1;
	hdr->type = type;
	hdr->length = host_to_be16(data_len);

	if (data)
		os_memcpy(hdr + 1, data, data_len);
	else
		os_memset(hdr + 1, 0, data_len);

	if (data_pos)
		*data_pos = hdr + 1;

	return (u8 *) hdr;
}


static int supp_get_beacon_ie(void *ctx)
{
	struct wpa *wpa = ctx;
	const u8 *ie;
	size_t ielen;

	wpa_printf(MSG_DEBUG, "SUPP: %s", __func__);
#if 0
	ie = wpa_auth_get_wpa_ie(wpa->auth_group, &ielen);
	if (ie == NULL || ielen < 1)
		return -1;
	if (ie[0] == WLAN_EID_RSN)
		return wpa_sm_set_ap_rsn_ie(wpa->supp, ie, 2 + ie[1]);
	return wpa_sm_set_ap_wpa_ie(wpa->supp, ie, 2 + ie[1]);
#endif
	return 0;
}

extern int __lbs_set_key_material(int key_type,int key_info,u8 *key, u16 key_len);
/** KEY_TYPE_ID */
enum KEY_TYPE_ID {
	KEY_TYPE_ID_WEP = 0,
	KEY_TYPE_ID_TKIP,
	KEY_TYPE_ID_AES
};
static int supp_set_key(void *ctx, enum wpa_alg alg,
			const u8 *addr, int key_idx, int set_tx,
			const u8 *seq, size_t seq_len,
			const u8 *key, size_t key_len)
{





	int ret ;
	int flaggg = 0;
	u8 *buf;
    size_t blen;
    int retttt = 0;
	u8 BOTH_FLAG = 0;
    char *alg_name;


    switch (alg) {
    case WPA_ALG_NONE:
        alg_name = "none";
        break;
    case WPA_ALG_WEP:
        alg_name = "WEP";
        break;
    case WPA_ALG_TKIP:
        alg_name = "TKIP";
        break;
    case WPA_ALG_CCMP:
        alg_name = "CCMP";
        break;
	case WPA_BOTH:
		alg_name = "BOTH";
		break;
    default:
        return -1;
    }

    wpa_printf(MSG_DEBUG, "%s: alg=%s key_idx=%d set_tx=%d seq_len=%d "
           "key_len=%d", __FUNCTION__, alg_name, key_idx, set_tx,
           seq_len, key_len);

	wpa_hexdump(MSG_MSGDUMP, "KEY :", key, key_len);

	if (alg == WPA_ALG_CCMP)
	{
		WPA_RUN_TEST;
		switch(key_idx)
		{
		case 0:
		__lbs_set_key_material(KEY_TYPE_ID_AES,6,(u8*)key,key_len);
		goto ret;
		case 1:
		__lbs_set_key_material(KEY_TYPE_ID_AES,5,(u8*)key,key_len);
		goto ret;
		}
		//
	}
	else if (alg == WPA_ALG_TKIP)
	{
		WPA_RUN_TEST;
		if (BOTH_FLAG > 0) //
		{
			__lbs_set_key_material(KEY_TYPE_ID_TKIP,5,(u8*)key,key_len);
			goto ret;
		}
		WPA_RUN_TEST;
		switch(key_idx)
		{
		case 0:
		__lbs_set_key_material(KEY_TYPE_ID_TKIP,6,(u8*)key,key_len);
		goto ret;
		case 1:
		__lbs_set_key_material(KEY_TYPE_ID_TKIP,5,(u8*)key,key_len);
		goto ret;
		}
		//
	}
	else if (alg == WPA_BOTH)
	{
		__lbs_set_key_material(KEY_TYPE_ID_AES,6,(u8*)key,key_len);
		BOTH_FLAG++;
		goto ret;
	}

	ret:
	return 0;
}


static int supp_mlme_setprotection(void *ctx, const u8 *addr,
				   int protection_type, int key_type)
{
	wpa_printf(MSG_DEBUG, "SUPP: %s(addr=" MACSTR " protection_type=%d "
		   "key_type=%d)",
		   __func__, MAC2STR(addr), protection_type, key_type);
	return 0;
}


static void supp_cancel_auth_timeout(void *ctx)
{
	wpa_printf(MSG_DEBUG, "SUPP: %s", __func__);
}

extern void wpa_sm_set_own_addr(struct wpa_sm *sm, const u8 *addr);
static int init_wpa(const unsigned char * bssid , const unsigned char * supp_addr , const char * psk)
{
	memcpy(g_wpa.auth_addr,bssid,ETH_ALEN);
	memcpy(g_wpa.supp_addr,supp_addr,ETH_ALEN);
	memcpy(g_wpa.psk,psk,PMK_LEN);
	dbug_buf("DBUG PSK ##########################" , psk,PMK_LEN);
	supp_init(&g_wpa);

	memcpy((g_wpa.supp->bssid),bssid,ETH_ALEN);
	wpa_sm_set_own_addr(g_wpa.supp,supp_addr);
	wpa_sm_set_pmk(g_wpa.supp,psk,PMK_LEN);

	

	//
}

int Ox0000008F(const unsigned char * bssid , const unsigned char * supp_addr , const char * psk)
{
	return init_wpa(bssid,supp_addr,psk);
}

static void * get_network_ctx(void * p)
{
	wpa_printf(MSG_DEBUG,"RUNNING get_network_ctx\n");
	return &g_ctx;
}



static int supp_init(struct wpa *wpa)
{
	struct wpa_sm_ctx *ctx = &g_ctx;//os_zalloc(sizeof(*ctx));
	if (ctx == NULL)
		return -1;

	ctx->ctx = wpa;
	ctx->msg_ctx = wpa;
	ctx->set_state = supp_set_state;
	ctx->get_state = supp_get_state;
	ctx->get_bssid = supp_get_bssid;
	ctx->ether_send = supp_ether_send;
	ctx->get_beacon_ie = supp_get_beacon_ie;
	ctx->alloc_eapol = supp_alloc_eapol;
	ctx->set_key = supp_set_key;
	ctx->mlme_setprotection = supp_mlme_setprotection;
	ctx->cancel_auth_timeout = supp_cancel_auth_timeout;
	ctx->get_network_ctx = get_network_ctx;
	wpa->supp = wpa_sm_init(ctx);

	wpa_sm_drop_sa(wpa->supp);

	return 0;
}



static void supp_eapol_rx(void *eloop_data, void *user_ctx)
{
	struct wpa *wpa = eloop_data;

	wpa_printf(MSG_DEBUG, "SUPP: RX EAPOL frame");
	wpa_sm_rx_eapol(wpa->supp, wpa->auth_addr, wpa->auth_eapol,
			wpa->auth_eapol_len);
}


static int auth_send_eapol(void *ctx, const u8 *addr, const u8 *data,
			   size_t data_len, int encrypt)
{
	struct wpa *wpa = ctx;

	wpa_printf(MSG_DEBUG, "AUTH: %s(addr=" MACSTR " data_len=%lu "
		   "encrypt=%d)",
		   __func__, MAC2STR(addr), (unsigned long) data_len, encrypt);

	os_free(wpa->auth_eapol);
	wpa->auth_eapol = os_malloc(data_len);
	if (wpa->auth_eapol == NULL)
		return -1;
	os_memcpy(wpa->auth_eapol_dst, addr, ETH_ALEN);
	os_memcpy(wpa->auth_eapol, data, data_len);
	wpa->auth_eapol_len = data_len;
	eloop_register_timeout(0, 0, supp_eapol_rx, wpa, NULL);

	return 0;
}


static const u8 * auth_get_psk(void *ctx, const u8 *addr, const u8 *prev_psk)
{
	struct wpa *wpa = ctx;
	wpa_printf(MSG_DEBUG, "AUTH: %s (addr=" MACSTR " prev_psk=%p)",
		   __func__, MAC2STR(addr), prev_psk);
	if (prev_psk)
		return NULL;
	return wpa->psk;
}






