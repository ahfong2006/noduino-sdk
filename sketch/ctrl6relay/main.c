/*
 *  Copyright (c) 2015 - 2025 MaiKe Labs
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/
#include "user_config.h"
#include "compile.h"

extern ctrl_status_t ctrl_st;

#ifdef CONFIG_ALEXA
void relay1_on_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r1 = 1;

	app_check_set_push_save(&mst);
}

void relay1_off_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r1 = 0;

	app_check_set_push_save(&mst);
}

void relay2_on_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r2 = 1;

	app_check_set_push_save(&mst);
}

void relay2_off_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r2 = 0;

	app_check_set_push_save(&mst);
}

void relay3_on_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r3 = 1;

	app_check_set_push_save(&mst);
}

void relay3_off_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r3 = 0;

	app_check_set_push_save(&mst);
}

void relay4_on_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r4 = 1;

	app_check_set_push_save(&mst);
}

void relay4_off_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r4 = 0;

	app_check_set_push_save(&mst);
}

void relay5_on_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r5 = 1;

	app_check_set_push_save(&mst);
}

void relay5_off_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r5 = 0;

	app_check_set_push_save(&mst);
}

void relay6_on_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r6 = 1;

	app_check_set_push_save(&mst);
}

void relay6_off_saved_and_pub()
{
	relay_status_t mst;
	os_memcpy(&mst, &(ctrl_st.relay_status), sizeof(relay_status_t));
	mst.r6 = 0;

	app_check_set_push_save(&mst);
}

upnp_dev_t upnp_devs[] = {
	{
		.esp_conn = NULL,
		.port = 80,
		.dev_voice_name = "relay 1",
		.way_on = relay1_on_saved_and_pub,
		.way_off = relay1_off_saved_and_pub
	},
	{
		.esp_conn = NULL,
		.port = 81,
		.dev_voice_name = "relay 2",
		.way_on = relay2_on_saved_and_pub,
		.way_off = relay2_off_saved_and_pub
	},
	{
		.esp_conn = NULL,
		.port = 82,
		.dev_voice_name = "relay 3",
		.way_on = relay3_on_saved_and_pub,
		.way_off = relay3_off_saved_and_pub
	},
	{
		.esp_conn = NULL,
		.port = 83,
		.dev_voice_name = "relay 4",
		.way_on = relay4_on_saved_and_pub,
		.way_off = relay4_off_saved_and_pub
	},
	{
		.esp_conn = NULL,
		.port = 84,
		.dev_voice_name = "relay 5",
		.way_on = relay5_on_saved_and_pub,
		.way_off = relay5_off_saved_and_pub
	},
	{
		.esp_conn = NULL,
		.port = 85,
		.dev_voice_name = "relay 6",
		.way_on = relay6_on_saved_and_pub,
		.way_off = relay6_off_saved_and_pub
	}
};

/* {"m":"voice_name", "d":{"ch1":"channel 1", "ch2":"channel 2"}} */
void ICACHE_FLASH_ATTR push_voice_name()
{
	char *msg = (char *)os_zalloc(256);
	if (msg == NULL) {
		INFO("alloc voice name memory failed\r\n");
		return;
	}

	os_sprintf(msg, "{\"ch1\":%s,\"ch2\":%s,\"ch3\":%s,\"ch4\":%s,\"ch5\":%s,\"ch6\":%s}",
				upnp_devs[0].dev_voice_name,
				upnp_devs[1].dev_voice_name,
				upnp_devs[2].dev_voice_name,
				upnp_devs[3].dev_voice_name,
				upnp_devs[4].dev_voice_name,
				upnp_devs[5].dev_voice_name
			);

	mjyun_publish("voice_name", msg);
	INFO("Pushed voice name = %s\r\n", msg);

	os_free(msg);
	msg = NULL;
}
#endif

static void mjyun_stated_cb(mjyun_state_t state)
{
    if (mjyun_state() != state)
        INFO("Platform: mjyun_state error \r\n");

    switch (state)
    {
        case WIFI_IDLE:
            INFO("Platform: WIFI_IDLE\r\n");
            break;
		case WIFI_SMARTLINK_START:
			INFO("Platform: WIFI_SMARTLINK_START\r\n");
			led_set_effect(0);
			break;
        case WIFI_SMARTLINK_LINKING:
            INFO("Platform: WIFI_SMARTLINK_LINKING\r\n");
			led_set_effect(1);
            break;
        case WIFI_SMARTLINK_FINDING:
            INFO("Platform: WIFI_SMARTLINK_FINDING\r\n");
			led_set_effect(0);
            break;
        case WIFI_SMARTLINK_TIMEOUT:
            INFO("Platform: WIFI_SMARTLINK_TIMEOUT\r\n");
            break;
        case WIFI_SMARTLINK_GETTING:
            INFO("Platform: WIFI_SMARTLINK_GETTING\r\n");
			led_set_effect(1);
            break;
        case WIFI_SMARTLINK_OK:
            INFO("Platform: WIFI_SMARTLINK_OK\r\n");
			led_set_effect(1);
            break;
        case WIFI_AP_OK:
            INFO("Platform: WIFI_AP_OK\r\n");
            break;
        case WIFI_AP_ERROR:
            INFO("Platform: WIFI_AP_ERROR\r\n");
            break;
        case WIFI_AP_STATION_OK:
            INFO("Platform: WIFI_AP_STATION_OK\r\n");
            break;
        case WIFI_AP_STATION_ERROR:
            INFO("Platform: WIFI_AP_STATION_ERROR\r\n");
            break;
        case WIFI_STATION_OK:
            INFO("Platform: WIFI_STATION_OK\r\n");
#ifdef CONFIG_ALEXA
			upnp_start(upnp_devs, 6);
#endif
			led_set_effect(1);
            break;
        case WIFI_STATION_ERROR:
            INFO("Platform: WIFI_STATION_ERROR\r\n");
            break;
        case MJYUN_CONNECTING:
            INFO("Platform: MJYUN_CONNECTING\r\n");
            break;
        case MJYUN_CONNECTING_ERROR:
            INFO("Platform: MJYUN_CONNECTING_ERROR\r\n");
            break;
        case MJYUN_CONNECTED:
            INFO("Platform: MJYUN_CONNECTED \r\n");
            break;
        case MJYUN_DISCONNECTED:
            INFO("Platform: MJYUN_DISCONNECTED\r\n");
            break;
        default:
            break;
	}
}

void mjyun_receive(const char *event_name, const char *event_data)
{
	INFO("RECEIVED: key:value [%s]:[%s]", event_name, event_data);

	if (0 == os_strcmp(event_name, "set")) {
		cJSON * pD = cJSON_Parse(event_data);
		if ((NULL != pD) && (cJSON_Object == pD->type)) {
			cJSON * pR1 = cJSON_GetObjectItem(pD, "r1");
			cJSON * pR2 = cJSON_GetObjectItem(pD, "r2");
			cJSON * pR3 = cJSON_GetObjectItem(pD, "r3");
			cJSON * pR4 = cJSON_GetObjectItem(pD, "r4");
			cJSON * pR5 = cJSON_GetObjectItem(pD, "r5");
			cJSON * pR6 = cJSON_GetObjectItem(pD, "r6");

			relay_status_t mst;
			extern ctrl_status_t ctrl_st;
			mst.r1 = ctrl_st.relay_status.r1;
			mst.r2 = ctrl_st.relay_status.r2;
			mst.r3 = ctrl_st.relay_status.r3;
			mst.r4 = ctrl_st.relay_status.r4;
			mst.r5 = ctrl_st.relay_status.r5;
			mst.r6 = ctrl_st.relay_status.r6;

			if ((NULL != pR1) && (cJSON_Number == pR1->type)) {
				if (mst.r1 != pR1->valueint) {
					mst.r1 = pR1->valueint;
				}
			}
			if ((NULL != pR2) && (cJSON_Number == pR2->type)) {
				if (mst.r2 != pR2->valueint) {
					mst.r2 = pR2->valueint;
				}
			}
			if ((NULL != pR3) && (cJSON_Number == pR3->type)) {
				if (mst.r3 != pR3->valueint) {
					mst.r3 = pR3->valueint;
				}
			}
			if ((NULL != pR4) && (cJSON_Number == pR4->type)) {
				if (mst.r4 != pR4->valueint) {
					mst.r4 = pR4->valueint;
				}
			}
			if ((NULL != pR5) && (cJSON_Number == pR5->type)) {
				if (mst.r5 != pR5->valueint) {
					mst.r5 = pR5->valueint;
				}
			}
			if ((NULL != pR6) && (cJSON_Number == pR6->type)) {
				if (mst.r6 != pR6->valueint) {
					mst.r6 = pR6->valueint;
				}
			}

			app_check_set_push_save(&mst);
		} else {
			INFO("%s: Error when parse JSON\r\n", __func__);
		}

		cJSON_Delete(pD);
	}

	/* {"m":"set_voice_name", "d":{"ch1":"channel 1", "ch2":"channel 2"}} */
	if (0 == os_strcmp(event_name, "set_voice_name")) {
		INFO("RX set_voice_name = %s\r\n", event_data);

		cJSON * pD = cJSON_Parse(event_data);
		if ((NULL != pD) && (cJSON_Object == pD->type)) {
			cJSON * pR1 = cJSON_GetObjectItem(pD, "ch1");
			cJSON * pR2 = cJSON_GetObjectItem(pD, "ch2");
			cJSON * pR3 = cJSON_GetObjectItem(pD, "ch3");
			cJSON * pR4 = cJSON_GetObjectItem(pD, "ch4");
			cJSON * pR5 = cJSON_GetObjectItem(pD, "ch5");
			cJSON * pR6 = cJSON_GetObjectItem(pD, "ch6");

			int len;
			bool need_update = false;
			char *pvn;
			if ((NULL != pR1) && (cJSON_String == pR1->type)) {

				pvn = pR1->valuestring;
				len = os_strlen(pvn);
				if ( len > 0 && len <= 31) {
			#ifdef CONFIG_ALEXA
					os_strcpy(upnp_devs[0].dev_voice_name, pvn);
			#endif
					need_update = true;
					os_strcpy(ctrl_st.ch1_voice_name, pvn);
				} else {
					INFO("RX Invalid ch1 voice name\r\n");
				}
			}
			if ((NULL != pR2) && (cJSON_String == pR2->type)) {

				pvn = pR2->valuestring;
				len = os_strlen(pvn);
				if ( len > 0 && len <= 31) {
			#ifdef CONFIG_ALEXA
					os_strcpy(upnp_devs[1].dev_voice_name, pvn);
			#endif
					need_update = true;
					os_strcpy(ctrl_st.ch2_voice_name, pvn);
				} else {
					INFO("RX Invalid ch2 voice name\r\n");
				}
			}

			if ((NULL != pR3) && (cJSON_String == pR3->type)) {

				pvn = pR3->valuestring;
				len = os_strlen(pvn);
				if ( len > 0 && len <= 31) {
			#ifdef CONFIG_ALEXA
					os_strcpy(upnp_devs[2].dev_voice_name, pvn);
			#endif
					need_update = true;
					os_strcpy(ctrl_st.ch3_voice_name, pvn);
				} else {
					INFO("RX Invalid ch3 voice name\r\n");
				}
			}

			if ((NULL != pR4) && (cJSON_String == pR4->type)) {

				pvn = pR4->valuestring;
				len = os_strlen(pvn);
				if ( len > 0 && len <= 31) {
			#ifdef CONFIG_ALEXA
					os_strcpy(upnp_devs[3].dev_voice_name, pvn);
			#endif
					need_update = true;
					os_strcpy(ctrl_st.ch4_voice_name, pvn);
				} else {
					INFO("RX Invalid ch4 voice name\r\n");
				}
			}

			if ((NULL != pR5) && (cJSON_String == pR5->type)) {

				pvn = pR5->valuestring;
				len = os_strlen(pvn);
				if ( len > 0 && len <= 31) {
			#ifdef CONFIG_ALEXA
					os_strcpy(upnp_devs[4].dev_voice_name, pvn);
			#endif
					need_update = true;
					os_strcpy(ctrl_st.ch5_voice_name, pvn);
				} else {
					INFO("RX Invalid ch5 voice name\r\n");
				}
			}

			if ((NULL != pR6) && (cJSON_String == pR6->type)) {

				pvn = pR6->valuestring;
				len = os_strlen(pvn);
				if ( len > 0 && len <= 31) {
			#ifdef CONFIG_ALEXA
					os_strcpy(upnp_devs[4].dev_voice_name, pvn);
			#endif
					need_update = true;
					os_strcpy(ctrl_st.ch6_voice_name, pvn);
				} else {
					INFO("RX Invalid ch6 voice name\r\n");
				}
			}

			if (need_update) {
			#ifdef CONFIG_ALEXA
				upnp_stop(upnp_devs, 6);
				upnp_start(upnp_devs, 6);
			#endif
				param_save();
			}
		}
	}

	/* {"m":"get_voice_name"} */
	/* {"m":"voice_name", "d":{"ch1":"channel 1", "ch2":"channel 2"}} */
	if (0 == os_strcmp(event_name, "get_voice_name")) {
		INFO("RX get_voice_name cmd\r\n");
		push_voice_name();
	}

	if(os_strncmp(event_data, "ota", 3) == 0)
	{
		INFO("OTA: upgrade the firmware!\r\n");
		mjyun_mini_ota_start("ota/dev/nodec/files");
	}
	if(os_strncmp(event_data, "reset", 5) == 0)
	{
		INFO("Reset the system!\r\n");
		system_restart();
	}
}

void mjyun_connected()
{
	// need to update the status into cloud
	app_push_status(NULL);

	// stop to show the wifi status
	wifi_led_disable();
}

void mjyun_disconnected()
{
	// show the wifi status
	wifi_led_enable();
}

const mjyun_config_t mjyun_conf = {
	"MJP1032524580",		/* MK Ctrl6relay */
	//"MJP1923825656",		/* MK Noduino NodeC */
	HW_VERSION,
	FW_VERSION,
	FW_VERSION,				/* 设备上线时，给app发送 online 消息中的附加数据，[选填] */
	"Device Offline",		/* 设备掉线时，给app发送 offline 消息中的附加数据，[选填] */
#ifdef LOW_POWER
	0,
#else
	WITH_MQTT,
#endif
};

void init_yun()
{
	mjyun_statechanged(mjyun_stated_cb);
	mjyun_ondata(mjyun_receive);
	mjyun_onconnected(mjyun_connected);
	mjyun_ondisconnected(mjyun_disconnected);

	mjyun_run(&mjyun_conf);
	wifi_set_sleep_type(MODEM_SLEEP_T);
}

irom void setup()
{
#ifdef DEBUG
	uart_init(115200, 115200);
#endif
	os_delay_us(100);
	INFO("\r\n\r\n\r\n\r\n\r\n\r\n");
	INFO("\r\nWelcom to Noduino Open Ctrl6relay!\r\n");
	INFO("Current firmware is user%d.bin\r\n", system_upgrade_userbin_check()+1);
	INFO("%s", noduino_banner);

	param_load();
	relay_init();

	led_init();
	xkey_init();

	init_yun();

	wifi_set_sleep_type(MODEM_SLEEP_T);
}

void loop()
{
	delay(10*1000);
}
