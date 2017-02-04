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

/*
 * GPIO13(D4) control the 1st relay
 * GPIO12(D5) control the 2nd relay
 * GPIO14(D6) control the 3rd relay
 * GPIO16(D7) control the 4th relay
 * GPIO4 (D8) control the 5th relay
 * GPIO5 (D9) control the 6th relay
 */
irom void relay_all_on()
{
	INFO("set all relay on\r\n");
	digitalWrite(D4, HIGH);
	digitalWrite(D5, HIGH);
	digitalWrite(D6, HIGH);
	digitalWrite(D7, HIGH);
	digitalWrite(D8, HIGH);
	digitalWrite(D9, HIGH);
}

irom void relay_all_off()
{
	INFO("set all relay off\r\n");
	digitalWrite(D4, LOW);
	digitalWrite(D5, LOW);
	digitalWrite(D6, LOW);
	digitalWrite(D7, LOW);
	digitalWrite(D8, LOW);
	digitalWrite(D9, LOW);
}

irom void relay_init()
{
	pinMode(D4, OUTPUT);
	pinMode(D5, OUTPUT);
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);
	pinMode(D8, OUTPUT);
	pinMode(D9, OUTPUT);

	relay_set_status(NULL);
}

irom void relay_set_status(relay_status_t *st)
{
	if(st == NULL) {
		extern ctrl_status_t ctrl_st;
		st = &(ctrl_st.relay_status);
	}

	digitalWrite(D4, (st->r1) & 0x1);
	digitalWrite(D5, (st->r2) & 0x1);
	digitalWrite(D6, (st->r3) & 0x1);
	digitalWrite(D7, (st->r4) & 0x1);
	digitalWrite(D8, (st->r5) & 0x1);
	digitalWrite(D9, (st->r6) & 0x1);
}

irom void relay_get_status(relay_status_t *st)
{
	st->r1 = digitalRead(D4);
	st->r1 = digitalRead(D5);
	st->r3 = digitalRead(D6);
	st->r4 = digitalRead(D7);
	st->r5 = digitalRead(D8);
	st->r6 = digitalRead(D9);
}
