/*
 * A simple library to interface with rdm6300 rfid reader.
 *
 * Arad Eizen (https://github.com/arduino12).
 * Benjamin Swart (https://github.com/SvizelPritula).
 */

#ifndef _RDM6300_h_
#define _RDM6300_h_

#include <Arduino.h>
#include <Stream.h>

#define RDM6300_BAUDRATE (9600)
#define RDM6300_PACKET_SIZE (14)
#define RDM6300_PACKET_BEGIN (0x02)
#define RDM6300_PACKET_END (0x03)
#define RDM6300_DEFAULT_TAG_TIMEOUT_MS (300)
#define RDM6300_READ_TIMEOUT (20)

class Rdm6300
{
public:
	void begin(Stream *stream);
	void begin(int rx_pin, uint8_t uart_nr = 1);
	void end(void);
	void set_tag_timeout(uint32_t tag_timeout_ms);
	uint32_t get_tag_id(void);
	uint32_t get_new_tag_id(void);

private:
	void _update(void);
	uint32_t _read_tag_id(void);

	Stream *_stream = NULL;
	uint32_t _tag_id = 0;
	uint32_t _new_tag_id = 0;
	uint32_t _last_tag_id = 0;
	uint32_t _last_tag_ms = 0;
	uint32_t _tag_timeout_ms = RDM6300_DEFAULT_TAG_TIMEOUT_MS;
};

#endif
