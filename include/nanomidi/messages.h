/*
 * This file is part of nanomidi.
 *
 * Copyright (C) 2018 Adam Heinrich <adam@adamh.cz>
 *
 * Nanomidi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Nanomidi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with nanomidi.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NANOMIDI_MESSAGES_H
#define NANOMIDI_MESSAGES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup messages MIDI Messages
 *
 * @brief MIDI message definitions and data structures
 *
 * @{
 */

/** @brief MIDI message types */
enum midi_type {
	/** @brief Channel Mode: Note Off */
	MIDI_TYPE_NOTE_OFF = 0x80,
	/** @brief Channel Mode: Note On */
	MIDI_TYPE_NOTE_ON = 0x90,
	/** @brief Channel Mode: Polyphonic Pressure (Aftertouch) */
	MIDI_TYPE_POLYPHONIC_PRESSURE = 0xa0,
	/** @brief Channel Mode: Control Change */
	MIDI_TYPE_CONTROL_CHANGE = 0xb0,
	/** @brief Channel Mode: Program Change */
	MIDI_TYPE_PROGRAM_CHANGE = 0xc0,
	/** @brief Channel Mode: Channel Pressure (Aftertouch) */
	MIDI_TYPE_CHANNEL_PRESSURE = 0xd0,
	/** @brief Channel Mode: Pitch Bend Change */
	MIDI_TYPE_PITCH_BEND = 0xe0,

	/** @brief System Common: MIDI Time Code Quarter Time */
	MIDI_TYPE_TIME_CODE_QUARTER_FRAME = 0xf1,
	/** @brief System Common: Song Position Pointer */
	MIDI_TYPE_SONG_POSITION = 0xf2,
	/** @brief System Common: Song Select */
	MIDI_TYPE_SONG_SELECT = 0xf3,
	/** @brief System Common: Tune Request */
	MIDI_TYPE_TUNE_REQUEST = 0xf6,

	/** @brief System Real Time: Timing Clock */
	MIDI_TYPE_TIMING_CLOCK = 0xf8,
	/** @brief System Real Time: Start */
	MIDI_TYPE_START = 0xfa,
	/** @brief System Real Time: Continue */
	MIDI_TYPE_CONTINUE = 0xfb,
	/** @brief System Real Time: Stop */
	MIDI_TYPE_STOP = 0xfc,
	/** @brief System Real Time: Active Sensing */
	MIDI_TYPE_ACTIVE_SENSE = 0xfe,
	/** @brief System Real Time: System Reset */
	MIDI_TYPE_SYSTEM_RESET = 0xff,

	/** @brief System Exclusive Message (SysEx) */
	MIDI_TYPE_SYSEX = 0x00,
	/** @brief Alias for @ref MIDI_TYPE_SYSEX */
	MIDI_TYPE_SYSTEM_EXCLUSIVE = MIDI_TYPE_SYSEX,
};

/** @brief MIDI message data structure */
struct midi_message {
	/** @brief MIDI message type */
	enum midi_type type;
	/** @brief Channel (0-127) for Channel Mode Messages. */
	uint8_t channel;
	/** @brief MIDI message data representation */
	union data {
		/** @brief Representation of @ref MIDI_TYPE_NOTE_ON */
		struct note_on {
			/** @brief Note code (0-127) */
			uint8_t note;
			/** @brief Note velocity (1-127)
			 *
			 * Velocity 0 is @ref MIDI_TYPE_NOTE_OFF */
			uint8_t velocity;
		} note_on;
		/** @brief Representation of @ref MIDI_TYPE_NOTE_OFF */
		struct note_off {
			/** @brief Note code (0-127) */
			uint8_t note;
			/** @brief Note velocity (0-127) */
			uint8_t velocity;
		} note_off;
		/** @brief Representation of
		@ref MIDI_TYPE_POLYPHONIC_PRESSURE */
		struct polyphonic_pressure {
			/** @brief Note code (0-127) */
			uint8_t note;
			/** @brief Pressure value (0-127) */
			uint8_t pressure;
		} polyphonic_pressure;
		/** @brief Representation of @ref MIDI_TYPE_CONTROL_CHANGE */
		struct control_change {
			/** @brief Control number (0-127) */
			uint8_t controller;
			/** @brief Control value (0-127) */
			uint8_t value;
		} control_change;
		/** @brief Representation of @ref MIDI_TYPE_PROGRAM_CHANGE */
		struct program_change {
			/** @brief Program number (0-127) */
			uint8_t program;
		} program_change;
		/** @brief Representation of @ref MIDI_TYPE_CHANNEL_PRESSURE */
		struct channel_pressure {
			/** @brief Pressure value (0-127) */
			uint8_t pressure;
		} channel_pressure;
		/** @brief Representation of @ref MIDI_TYPE_PITCH_BEND */
		struct pitch_bend {
			/** @brief Pitch bend change value (0-16383) */
			uint16_t value;
		} pitch_bend;
		/** @brief Representation of
		@ref MIDI_TYPE_TIME_CODE_QUARTER_FRAME */
		struct time_code_quarter_frame {
			/** @brief Time code value (0-127) */
			uint8_t value;
		} time_code_quarter_frame;
		/** @brief Representation of @ref MIDI_TYPE_SONG_POSITION */
		struct song_position {
			/** @brief Song position pointer (0-16383) */
			uint16_t position;
		} song_position;
		/** @brief Representation of @ref MIDI_TYPE_SONG_SELECT */
		struct song_select {
			/** @brief Song number (0-127) */
			uint8_t song;
		} song_select;
		/** @brief Representation of @ref MIDI_TYPE_SYSEX */
		struct sysex {
			/** @brief Pointer to SysEx data (excluding "SOX" and
			"EOX" bytes) */
			const char *data;
			/** @brief Length of data in bytes */
			size_t length;
		} sysex;
	} /** @brief MIDI message data representation */ data;
};

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* NANOMIDI_MESSAGES_H */