/********************************************************************** 
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#ifndef FC__CIVCLIENT_H
#define FC__CIVCLIENT_H

#include "packets.h"		/* enum report_type */
#include "game.h"		/* enum client_states */

/*
 * Every TIMER_INTERVAL milliseconds real_timer_callback is
 * called. TIMER_INTERVAL has to stay 500 because real_timer_callback
 * also updates the timeout info.
 */
#define TIMER_INTERVAL 500

void handle_packet_input(void *packet, int type);

void send_unit_info(struct unit *punit);
void send_move_unit(struct unit *punit);
void send_goto_unit(struct unit *punit, int dest_x, int dest_y);
void send_report_request(enum report_type type);
void send_attribute_block_request(void);
void send_turn_done(void);

void user_ended_turn(void);

void set_client_state(enum client_states newstate);
enum client_states get_client_state(void);

void client_remove_cli_conn(struct connection *pconn);

extern char sound_plugin_name[512];
extern char sound_set_name[512];
extern char server_host[512];
extern char player_name[512];
extern char metaserver[512];
extern int  server_port;
extern bool auto_connect;
extern bool waiting_for_end_turn;
extern bool turn_done_sent;

extern int seconds_to_turndone;

void wait_till_request_got_processed(int request_id);
bool client_is_observer(void);
void real_timer_callback(void);

void client_game_init(void);
void client_game_free(void);

#endif  /* FC__CIVCLIENT_H */
